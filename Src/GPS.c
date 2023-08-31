/* Includes ------------------------------------------------------------------*/
#include "main.h"

#include "sd.h"
#include "ff_gen_drv.h"
#include "sd_diskio.h"
#include "cmsis_os.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern u8 sat_present;
#define GPS_BUFFER_SIZE 1024 // 150
uint8_t nmea[GPS_BUFFER_SIZE], nmea_index = 0, start_sentence = 0;
u8 need_set_time_date = 1;
#define bool u8
#define false 0
#define true 1
struct tm gps_time = { 0 };
volatile char time_set = false, date_set = false, gps_valid = false;
u8 GGA_flag = 0;

long lat_prev = 0, lon_prev = 0, alt_prev = 0, course_prev = 0, speed_prev = 0, dt_prev = 0;
u8 has_date = 0;
unsigned long last_dt = 0;
struct Controller_ControlFrame current = { 0, 0, 0, 0, 0, 0 };
int recs = 0;

struct tm ttime;

extern UART_HandleTypeDef huart2;

uint16_t uart_buf;


 int atoin(const char* s, int n) {
    char buf[10];
    memcpy(buf, s, n);
    buf[n] = '\0';
    return atoi(buf);
}

long my_abs(long a) {
    return (a > 0 ? a : -a);
}

int checksum() {
    int cs = 0;
    for (int i = 1; nmea[i] && nmea[i] != '*'; i ++) {
        cs = cs ^ (signed char)nmea[i];
    }
    return cs;
}

u8 valid_coord() {
    u8 valid = (
        current.lat >= -180000000L && current.lat <= 180000000L &&
        current.lon >= -180000000L && current.lon <= 180000000L &&
        current.dt >= 1262304000L && current.dt <= 2524608000L // 2010-01-01 .. 2050-01-01
	);

    return valid;
}


int get_token(char* data, int index, char** out) {
    // strtok can`t handle multiple delims in a row (like ,,,,, in "GNRMC,210842.086,V,,,,,0.92,269.72,010718,,,N")
    const char delim = ',';
    unsigned int start = 0;
    unsigned int pos = 0;
    while (true){
        char c = data[pos++];
        if (c == 0) break;
        if (c == delim || c == '*'){
            if (index == 0){ // needed delim found
                *out = data+start;
                return pos - start -1;
            }
            if (index == 1){ // save start here
                start = pos;
            }
            index--;
        }
    }
    return 0;
}

char parse_packet_nmea(char *_nmea[], bool isGGA) {
    char flushed = 0;

    char *time0 = _nmea[1];
    char *slat  = _nmea[isGGA ? 2 : 3];
    bool isN    = ((*_nmea[isGGA ? 3 : 4]) == 'N');
    char *slon  = _nmea[isGGA ? 4 : 5];
    bool isE    = ((*_nmea[isGGA ? 5 : 6]) == 'E');

    double lat_start = (double)atoin(slat, 2);
    double lat_end   = (double)atof(slat + 2) / 60;
    double _lat      = lat_start + lat_end;

    double lon_start = (double)atoin(slon, 3);
    double lon_end   = (double)atof(slon + 3) / 60;
    double _lon      = lon_start + lon_end;

    ttime.tm_hour = atoin(time0 + 0, 2);
    ttime.tm_min  = atoin(time0 + 2, 2);
    ttime.tm_sec  = atoin(time0 + 4, 2);

    double xlat = _lat * (isN ? 1 : -1);
    double xlon = _lon * (isE ? 1 : -1);

    current.lat = xlat * 1000000;
    current.lon = xlon * 1000000;

    current.dt = mktime(&ttime);

    if (valid_coord()) {
        int delta = (int)(current.dt - dt_prev);

        if (delta == 0) {
            return 2; // same coordinate
        }

        if (lat_prev == 0 || (dt_prev != 0 && (delta > 1))) { // first coord or delta(dt) > 1
           // if (buffer_offset > SECTOR_SIZE - sizeof(struct Controller_ControlFrame)) { // sector overflow
                //flush_sector();
               // flushed = 1;
           // }

           // buffer_offset += controller_control_frame(&sector_buffer[buffer_offset]);
           // set_bit(&ch.hdr[0], 1);
        } else {
            long lat_delta    = (current.lat    - lat_prev),
                 lon_delta    = (current.lon    - lon_prev),
                 alt_delta    = (current.alt    - alt_prev),
                 course_delta = (current.course - course_prev),
                 speed_delta  = (current.speed  - speed_prev);
            if (my_abs(lat_delta) > 127 || my_abs(lon_delta) > 127 || my_abs(alt_delta) > 127 || my_abs(course_delta) > 127 || my_abs(speed_delta) > 127) { // deltas overflow
               // if (buffer_offset > SECTOR_SIZE - sizeof(struct Controller_ControlFrame)) { // sector overflow
                    //flush_sector();
                   // flushed = 1;
              //  }

               // buffer_offset += controller_control_frame(&sector_buffer[buffer_offset]);
               // set_bit(&ch.hdr[0], 1);
           // } else {
               // if (buffer_offset > SECTOR_SIZE - sizeof(struct Controller_DiffFrame)) { // sector overflow
                    //flush_sector();
                   // flushed = 1;

                   // buffer_offset += controller_control_frame(&sector_buffer[buffer_offset]);
                   // set_bit(&ch.hdr[0], 1);
                //} else {
                  //  buffer_offset += controller_diff_frame(&sector_buffer[buffer_offset], (int)lat_delta, (int)lon_delta, (int)alt_delta, (int)course_delta, (int)speed_delta);
                  //  set_bit(&ch.hdr[0], 0);
                //}
            }
        }

        lat_prev    = current.lat;
        lon_prev    = current.lon;
        alt_prev    = current.alt;
        course_prev = current.course;
        speed_prev  = current.speed;
        dt_prev     = current.dt;
    } else {
    	return 3; // invalid coordinate
    }

    return flushed;
}

void parse_nmea() {
    int len;
    char *token;

    if (strstr(nmea, "GGA") != NULL) {

      GGA_flag = 1;

        len = get_token(nmea, 1, &token);
        if (len == 10 || len == 9) {
            gps_time.tm_hour = atoin(token + 0, 2);
            gps_time.tm_min  = atoin(token + 2, 2);
            gps_time.tm_sec  = atoin(token + 4, 2);

            time_set = true;

            len = get_token(nmea, 4, &token);
            if (len == 1) {
                gps_valid = (token[0] == 'N' || token[0] == 'S');
            }
        }
    } else {
        len = get_token(nmea, 1, &token);
        if (len == 10 || len == 9) {
            gps_time.tm_hour = atoin(token + 0, 2);
            gps_time.tm_min  = atoin(token + 2, 2);
            gps_time.tm_sec  = atoin(token + 4, 2);

            time_set = true;

            len = get_token(nmea, 9, &token);
            if (len == 6) {
                gps_time.tm_mday  = atoin(token + 0, 2);
                gps_time.tm_mon   = atoin(token + 2, 2);
                gps_time.tm_year  = atoin(token + 4, 2);
                if (gps_time.tm_year >= 18 && gps_time.tm_year <= 55) {
                    date_set = true;

                    len = get_token(nmea, 2, &token);
                    if (len == 1) {
                        gps_valid = (token[0] == 'A');


                    }
                }
            }
        }
    }
}


 void gps_received(uint8_t buffer) {

        if (buffer == '$') {
            start_sentence = 1;
            nmea_index = 0;
        } else if (buffer == '\r' || buffer == '\n') {
            if ((strncmp((const char *)nmea, "$GPRMC", 6) == 0 || strncmp((const char *)nmea, "$GNRMC", 6) == 0) ||
                (strncmp((const char *)nmea, "$GPGGA", 6) == 0 || strncmp((const char *)nmea, "$GNGGA", 6) == 0) ||
                (strncmp((const char *)nmea, "$GLRMC", 6) == 0 || strncmp((const char *)nmea, "$GLGGA", 6) == 0)) {
               //printf("%s \r\n",nmea);
                  parse_nmea();
            }

            start_sentence = 0;
        }
        if (start_sentence) {
            nmea[nmea_index] = buffer;
            nmea[nmea_index + 1] = 0;
            nmea_index ++;
            if (nmea_index >= sizeof(nmea) / sizeof(nmea[0]) - 1) {
                start_sentence = 0;
            }
        }

}

 void GPSThread(void const * argument)
{
  MX_USART2_UART_Init();
__HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);

  for(;;)
  {
   osDelay(1);
    if (need_set_time_date)         //
         {
           if (date_set == 1)               //
           {
            RTC_CalendarConfig();       //     RTC
            need_set_time_date = 0;    //
            printf ("RTC update successful\r\n");
           }
         }

    if (gps_valid ==1)
    {
     sat_present = 1;
    }
    else
    {
     sat_present = 0;
    }
  }

}




void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle) {


}