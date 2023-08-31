

/* Includes ------------------------------------------------------------------*/
#include "main.h"
//#include "cmsis_os.h"
#include "fatfs.h"
#include "usb_device.h"
//#include "rm68120.h"
#include "ili9806.h"
#include "GUI.h"
#include "WM.h"
#include "time.h"
#include "sht21.h"
#include <string.h>
#include <stdio.h>
      //   extern RTC_HandleTypeDef hrtc;
char bready_radio = 0;
u8 bad_ssid[25];
u16 binet=0;
u8 err_received = 0;
volatile uint8_t VolLevel = 1;
 int datchik_check;
 u8 first_state = 0;
int fade_counter = 240000;
char show_time_flag = 0;
char synch_time_flag = 1;
char temper_show_flag = 0;
char show_st=0;
int last_station;
u8 good_state = 0;
u8 bad_state = 0;
u8 no_internet = 0;
u8 bad_connect =0;
u8 list_flag = 0;
    RTC_DateTypeDef sdatestructureget;
    RTC_TimeTypeDef stimestructureget;
    extern   void load_wifi(u8* sb);
    extern void reset_esp32(void);
extern   const   uint8_t MonthNames[];
extern const string WeekDayNames[];
extern  void wifi_settings_Framewin(void);
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana23;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana32;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana42;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana45_rus;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana45;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana96;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana220;
extern GUI_CONST_STORAGE GUI_BITMAP bmmute;
extern GUI_CONST_STORAGE GUI_BITMAP bmmute_empty;
 extern RTC_HandleTypeDef RtcHandle;
extern GUI_CONST_STORAGE GUI_BITMAP bmbeh;
extern GUI_CONST_STORAGE GUI_BITMAP bmbffh;
extern GUI_CONST_STORAGE GUI_BITMAP bmbfh;
extern GUI_CONST_STORAGE GUI_BITMAP bmblh;
extern GUI_CONST_STORAGE GUI_BITMAP bmbmh;
extern GUI_CONST_STORAGE GUI_BITMAP bmbmmh;
extern float temperature;
extern int page;
char pizdec = 0;
int time_to_change;
 //uint8_t Get_Vol_Level(void);
// void set_radio_volume(char Level);
char doll_string[40];
char eur_string[20];
char need_draw_date = 0;
char but_mute_half;
int last_volume;
char mute_half_pressed;
int sch_mute;
u8 mute_pressed;
void get_station_to_list(char buf);
extern void save_wifi(u8* sb);
extern float humidity;
uint8_t next_enable;
char new_st;
char info_get = 0;
char _ssid,ssid_index;
uint8_t wfstations[600];
uint8_t stations[50] [100];
uint8_t ee_stations[5][100];
char tempstr[200];
char ip_string[25];
char ssid_string[105];
char rssi_string[105];
char but_mute = 3;
extern char but_mute_half;
 int rssi;
 char settings_wifi;
 char prev_button; // запомнить туда предыдущую станцию.
 u8 button_back_press = 0;
 char button_1_press,button_2_press,button_3_press,button_4_press,button_5_press;
struct tm ntp_time;
time_t my_time;
struct tm out_time={0};
void draw_date(void);
extern   void board_init(void);
extern UART_HandleTypeDef huart1;
 extern UART_HandleTypeDef huart2;
void StartDefaultTask(void);
void set_station(char num_wifi);
 //osThreadId defaultTaskHandle;
extern SRAM_HandleTypeDef hsram1;
extern RTC_HandleTypeDef RtcHandle;
char saved_station;
char new_msg_meta;
char mute_half;
char wifi_module_ready = 0;
u16 button_pointer;
u8 no_internet_counter;
//extern void GPSThread(void const * argument);
extern void GUIThread(void const * argument);
extern void FS_AppThread(void const *argument);
extern void CreateRadioFramewin( uint16_t xpos, uint16_t ypos);
void printf2(uint8_t *buf,int len);
void rtc_show(void);
DMA_HandleTypeDef hdma_sai1_a;
DMA_HandleTypeDef hdma_sai1_b;

//uint8_t last_volume;
uint8_t stopped_err = 0;
uint8_t play_ok = 0;
//uint8_t err_no_play = 0;
uint8_t check_start_play = 0;
uint8_t set_volume;
uint8_t station_pressed = 255;
uint8_t current_station;
uint8_t next_st,prev_st,vol_plus,vol_minus;
extern uint16_t ee_station,ee_volume;
//u8 card_present;
extern unsigned char button_press[];
extern unsigned char button_release[];
uint8_t ee1,ee2,ee3,ee4,ee5;
extern uint16_t tim_b1,tim_b2,tim_b3,tim_b4,tim_b5;
extern uint32_t ADC_Val;
extern ALIGN_32BYTES ( uint16_t   aADCxConvertedData[]);
u8 buttons;
u8 wifi_next_station = 0;
uint32_t batt_buff[20];
uint8_t batt_buff_pointer;
u8 battery_percent;
u8 b_up,b_down,b_left,b_right,b_down,b_ok;
u8 izb[5];
char p_dwn,p_up;
u8 wifi_reboot;

int start_timer_ee1;
int start_timer_ee2;
int start_timer_ee3;
int start_timer_ee4;
int start_timer_ee5;
extern char sdssidNames[25][32];

int str_index;
char string_buffer0[1512];
char string_buffer1[1512];

char string_buf0[12];
char string_buf1[12];

char new_msg_valuta = 0;
char start_sentence;
volatile char ready_radio = 0;

char meta_string[200];
char next_station = 0;

u8 blast_station=0; //

extern char RxByte;
extern char Rx1Byte;


const string ssidNames[] =
  {
   "TP-LINK_CF06",
   "xutor-gora" , //тиурула
   "VIPs",        //тиурула вип
   "WiFi_Roof",
   "v6_3thrd",     //TP-LINK_CF06

  };
const string wifiPass[] =
  {
      "56541229",
   "0009648770" ,
   "0009910025",
   "0009648770",
   "12345678",
    //"56541229",
  };
#define PWR_REGULATOR_VOLTAGE_SCALE0  (0U)


 

uint16_t qqq;
int main(void)
    {
       /* Enable I-Cache---------------------------------------------------------*/
       SCB_EnableICache();
       /* Enable D-Cache---------------------------------------------------------*/
      SCB_EnableDCache();

       HAL_Init();
       SystemClock_Config();
      // Clock_Config();
       board_init(); // периферия проца
      MUTE_ON;
      
       HAL_Delay(100);
       GUI_Init();  // инит экрана
       HAL_Delay(100);
       
  //     LCD_Display_Dir(7);
       LCD_Scan_Dir(6); // перевернули его (6-норм, 5 - на 180 град)
       
       //GUI_Clear();
/*
       LCD_WR_REG(0x0C00);
       qqq = LCD_RD_DATA();
       LCD_WR_REG(0xDB00);
       qqq = LCD_RD_DATA();
       LCD_WR_REG(0xDC00);
       qqq = LCD_RD_DATA();
*/ 
       lcd_pwm_init(); // дали подсветку 
       GUI_SetColor(GUI_RED);
       GUI_SetFont(&GUI_FontVerdana42);
       GUI_SetBkColor( 0xb4c9f4);
       GUI_Clear(); // очистили экран
       
       FS_manevr();     // считали из карты настройки
        MX_USB_DEVICE_Init(); // проинитили USB
       StartDefaultTask();


    }






void check_meta(char *pbuf)
    {
       volatile int len_in = 0;
       volatile int len_out = 0;
       len_in = strlen(pbuf);
       len_out = Utf8toUsci(pbuf, tempstr, 100);
     if (len_out<=0)
         {
          strcpy(meta_string,&pbuf[13]);
         }
     else
         {
          strcpy(meta_string,&tempstr[13]);
         }
     new_msg_meta = 1;
    }

void check_valuta(char *pbuf)
    {
       strcpy(doll_string,pbuf);
    }

 int check_rssi(char *pbuf)
    {
      char s,d=13;
      char low,high,rssi;
      for (s=0;s<4;s++)
          {
           rssi_string[s] =  pbuf[d+s];
          }
      // strcpy(rssi_string,&pbuf[13]);
      high  = pbuf[9]-0x30;
      low  = pbuf[10]-0x30;
      rssi = high*10 + low;
      strcpy(rssi_string,&pbuf[8]);
     return rssi;
    }



void rtc_add_hours(struct tm* time, int hours)
{
    const int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    time->tm_hour += hours;
    if (time->tm_hour < 24) return;
    time->tm_hour -= 24;
    //if (time->tm_wday < 6) { time->tm_wday++;}
    //else time->tm_wday = 0;
    int vis = 0;
    if (time->tm_year & 3 == 0) vis = 1;  //(1901..2099)
    //if (time->tm_yday < 364 + vis) time->tm_yday++;
    //else tm_yday = 0;
    if ((vis==1)&&(time->tm_mon == 1))
    {
        if (time->tm_mday < 29) {time->tm_mday++; return;}
    }else
    {
        if ((time->tm_mon < 0)||(time->tm_mon > 11)) time->tm_mon = 0;
        if (time->tm_mday < mdays[time->tm_mon]) {time->tm_mday++; return;}
    }
    time->tm_mday = 1;
    if (time->tm_mon < 11) { time->tm_mon++; return;}
    time->tm_year++;
}

void ip_get (char *pbuf)
    {

      strcpy(ip_string,&pbuf[16]);

    }


int check_date_time(char *pbuf)
    {
     int year;
     u8 month;
     u8 day;
     u8 hour,min,sec;


           year = ((pbuf[13]-0x30)*1000);
           if (year!=2000) return 0;
           year+= ((pbuf[14]-0x30)*100);
           year+= ((pbuf[15]-0x30)*10);
           year+= ((pbuf[16]-0x30));

     month = ((pbuf[18]-0x30)*10);
     month+= ((pbuf[19]-0x30));


     day= ((pbuf[21]-0x30)*10);
     day+= ((pbuf[22]-0x30));

     hour = ((pbuf[24]-0x30)*10);
     hour+= ((pbuf[25]-0x30));

     min= ((pbuf[27]-0x30)*10);
     min+= ((pbuf[28]-0x30));

     sec= ((pbuf[30]-0x30)*10);
     sec+= ((pbuf[31]-0x30));

     //printf("Time %02d.%02d.%02d \r\n",hour,min,sec);
    // printf("Date %02d.%02d.%d \r\n",day,month,year);
     if (hour>23) return 0;


     ntp_time.tm_year = year-1900;
     ntp_time.tm_mon = month;
     ntp_time.tm_mday = day;
     ntp_time.tm_hour = hour;
     ntp_time.tm_min = min;
     ntp_time.tm_sec = sec;

    // rtc_add_hours(&ntp_time, 2);
    // ntp_time.tm_mon = ntp_time.tm_mon+1;
     RTC_CalendarConfig();
   
   // my_time = mktime(&ntp_time) + 3600*2; //


   // out_time = localtime(&my_time);
   // out_time->tm_mon+=1;
     
     need_draw_date=1;
     
     return 1;
    }


u8 start_sen,str_ind;

#ifndef OLD_KBD
 char y_buf=0;   // 1 for old keyboard
#else 
 char y_buf=1;
#endif 


 void keybrd_parse(uint8_t buffer) {

 //static
   
#ifndef OLD_KBD
 if (buffer == 'K')      
#else 
 if (buffer == 'K' || buffer == 'k')      //|| buffer == 'k' for old keyboard
#endif 
     
      {
         if (start_sen==0)
             {
              start_sen = 1;
              str_ind = 0;
             }
      }
     else if (buffer == 'r')
      {
         if (start_sen==0)
             {
              start_sen = 1;
              str_ind = 0;
             }
      }


     else if ( buffer == '\r')
         {
             buttons = 1;
             start_sen = 0;
         }


        if (start_sen)
        {
           if (y_buf ==0)
               {
                string_buf0[str_ind] = buffer;
                string_buf0[str_ind + 1] = 0;
                str_ind ++;
                if (str_ind >= sizeof(string_buf0) / sizeof(string_buf0[0]) - 1) start_sen = 0;
               }
           else
               {
                string_buf1[str_ind] = buffer;
                string_buf1[str_ind + 1] = 0;
                str_ind ++;
                if (str_ind >= sizeof(string_buf1) / sizeof(string_buf1[0]) - 1) start_sen = 0;
               }
        }

}
 u8 check_stations_wifi(void)
     {
      char zx_buf=0;
      char tem_str[30];
      char ss_names[25][32];
      int s;
      char tes;
      char bb;
      u8 i;


     for (zx_buf=0;zx_buf<25;zx_buf++)
         {
            s = 1;
             ss_names[zx_buf] [s-1] =0;
            while(1)
           {
            tes = sdssidNames[zx_buf][s];
            if (tes!='"')
                {
                   ss_names[zx_buf] [s-1] = tes;
                }
            else
                {
                   ss_names[zx_buf] [s-1] = 0;
                   break;
                }
            s++;
            if (s>32) break;
           }
         }
     // имеем список, который можно сравнить с пришедшим списком доступных сетей.
    zx_buf = 0;
     s=11;
     bb=0;
    while(zx_buf==0)
        {
          tem_str[bb]=wfstations[s];
          if (tem_str[bb]==0)
              {
                // мы дошли до конца списка станций, все ничего не нашли
                tes = 26;
                break;
              }
          if (tem_str[bb]==',')
              {
               tem_str[bb]=0;
               // выбрали станцию, и сравним ее с 5 станциями с карты
               for(tes=0;tes<25;tes++)
                   {
                    if (bad_ssid[tes] == 1) continue;
                    if ( !strcmp((const char *)tem_str, ss_names[tes])){zx_buf = 1;break;}
                   }
                    bb=0;
               s++;
               tem_str[bb] = 0;
              }
          else
              {
               bb++;
               s++;
              }

        }
    return tes;

                  //здесь модуль поднял АР и ждет, нихуя не деламши
                  // у нас есть список станций вокруг и список станций из SD
       }

 


 void get_list_stations(u8 o)
     {

               if (o==1)
                   {
                      strcpy(wfstations,string_buffer0);
                   }
               else if (o==2)
                   {
                      strcpy(wfstations,string_buffer1);
                   }
      list_flag = 1; //          
     }


void check_err(u8 z)
{
   if (z==1)
                   {
                    if (strncmp(&string_buffer0[12], "task_wdt",8) ==0) pizdec = 1;
                     if (strncmp(&string_buffer0[10], "task_wdt",8) ==0) pizdec = 1;
                   }
   else if (z==2)
                   {
                    if (strncmp(&string_buffer1[12], "task_wdt",8) ==0)  pizdec = 1;
                     if (strncmp(&string_buffer1[10], "task_wdt",8) ==0)  pizdec = 1;
                   }
}

void radio_parse(uint8_t buffer) {
static char x_buf=0;
/* E (34241) main: reboot это радио присылает в момент ребута */
if (buffer == '#' || buffer == '{'    || buffer == 'E')
      {
         if (start_sentence==0)
             {
              start_sentence = 1;
              str_index = 0;
             }
      }
      else if ( buffer == '\n')
         {
            if (x_buf == 0)
                {
                 if (strncmp((const char *)string_buffer0, "E (", 3) == 0)  check_err(1);
                // if (strncmp((const char *)string_buffer0, "#WIFI.TRY",9)==0)  first_state = 1;
                 if (strncmp((const char *)string_buffer0, "#WIFI.LIST",10)==0) get_list_stations(1);
                 if (strncmp((const char *)string_buffer0, "{\"USD\":",7) ==0) check_valuta(&string_buffer0[7]);
                 if (strncmp((const char *)string_buffer0, "##CLI.ICY4#:",12) ==0)  wifi_module_ready = 1;
                 if (strncmp((const char *)string_buffer0, "##CLI.ICY0#: Ready",18) ==0)  bready_radio = 1; //##CLI.ICY0#: Ready
                 if (strncmp((const char *)string_buffer0, "##CLI.META#:", 12) == 0)  check_meta(&string_buffer0[0]);
                 /*##CLI.STOPPED# from clientConnect*/
                 if (strncmp((const char *)string_buffer0, "##CLI.STOPPED# from try re", 26) == 0)  no_internet = 1;
                 if (strncmp((const char *)string_buffer0, "##CLI.STOPPED# from invali", 26) == 0)  no_internet = 1;
                 if (strncmp((const char *)string_buffer0, "##RSSI:", 7) == 0) rssi = check_rssi(&string_buffer0[0]);
                 if (strncmp((const char *)string_buffer0, "##SYS.DATE#:", 12) == 0) check_date_time(&string_buffer0[0]);
                 if (strncmp((const char *)string_buffer0, "#CLI.LISTNUM#:",14) ==0) get_station_to_list(0);
                 if (strncmp((const char *)string_buffer0, "#INFO:",6) ==0) info_get = 1;
                 if (strncmp((const char *)string_buffer0, "#WIFI.STATION#",14) ==0) _ssid = 1;
                 if (strncmp((const char *)string_buffer0, "##CLI.PLAYING#",14) ==0)
                     {
                       play_ok = 1;
                       stopped_err = 0; // обнулим ошибки, станция нащлась и вещает, переключать не нужно
                     }

                  x_buf = 1;
                }
            else
                {
                 if (strncmp((const char *)string_buffer1, "E (", 3) == 0)  check_err(2);
                  //if (strncmp((const char *)string_buffer1,  "##CLI.BAD_INET", 14) == 0)  check_bad_inet(); //no_internet = 1;
                  // if (strncmp((const char *)string_buffer1, "mE",2)==0)     check_no_internet(&string_buffer1[0]);//    no_internet = 1;
                   if (strncmp((const char *)string_buffer1, "{\"USD\":",7) ==0)  check_valuta(&string_buffer1[7]);
                 //  if (strncmp((const char *)string_buffer1, "#WIFI.SCAN",10)==0) good_state = 1;
                  // if (strncmp((const char *)string_buffer1, "#WIFI.TRY",9)==0)  first_state = 1;
                   if (strncmp((const char *)string_buffer1, "#WIFI.LIST",10)==0) get_list_stations(2);
                   if (strncmp((const char *)string_buffer1, "##CLI.ICY4#:", 12) ==0)  wifi_module_ready = 1;
                   if (strncmp((const char *)string_buffer1, "##CLI.ICY0#: Ready",18) ==0)
                      bready_radio = 1;
                   //if (strncmp((const char *)string_buffer1, "main: Try next AP", 17) == 0)  next_enable = 1;
                  // if (strncmp((const char *)string_buffer1, "main: reboot", 12) == 0)  wifi_reboot = 1;
                   if (strncmp((const char *)string_buffer1, "##CLI.META#:", 12) == 0)  check_meta(&string_buffer1[0]);
                   if (strncmp((const char *)string_buffer1,  "##CLI.STOPPED# from try re", 26) == 0)  no_internet = 1;
                    if (strncmp((const char *)string_buffer1, "##CLI.STOPPED# from invali", 26) == 0)  no_internet = 1;
                   if (strncmp((const char *)string_buffer1, "##RSSI:", 7) == 0) rssi = check_rssi(&string_buffer1[0]);
                // if (strncmp((const char *)string_buffer1, "##CLI.VOL#", 10) == 0) check_volume(&string_buffer1[0]);
                 if (strncmp((const char *)string_buffer1,  "##SYS.DATE#:", 12) == 0) check_date_time(&string_buffer1[0]);
                 if (strncmp((const char *)string_buffer1,  "#CLI.LISTNUM#:",14) ==0) get_station_to_list(1);
                 if (strncmp((const char *)string_buffer1,  "#INFO:",6) ==0) info_get = 1;
                  if (strncmp((const char *)string_buffer1, "#WIFI.STATION#",14) ==0) _ssid = 1;
                  if (strncmp((const char *)string_buffer1, "##CLI.PLAYING#",14) ==0)
                     {
                       play_ok = 1;
                       stopped_err = 0; // обнулим ошибки, станция нащлась и вещает, переключать не нужно
                     }
                  x_buf = 0;
                }


            start_sentence = 0;
         }
         if (start_sentence)
        {
           if (x_buf ==0)
               {
                string_buffer0[str_index] = buffer;
                string_buffer0[str_index + 1] = 0;
                str_index ++;
                if (str_index >= sizeof(string_buffer0) / sizeof(string_buffer0[0]) - 1) start_sentence = 0;
               }
           else
               {
                string_buffer1[str_index] = buffer;
                string_buffer1[str_index + 1] = 0;
                str_index ++;
                if (str_index >= sizeof(string_buffer1) / sizeof(string_buffer1[0]) - 1) start_sentence = 0;
               }
        }

}

  void CEOL(uint8_t str_leght, uint8_t max_str_leght)     // добивает строку TempStr пробелами начиная с позиции str_leght
{
     char TempStr[40];
     char aaa[50];
   if (str_leght<max_str_leght)  // добиваем пробелами
  {
    for(int a=str_leght;a<max_str_leght;a++)
    { sprintf(aaa," "); strcat(TempStr,aaa); }
  }
}







 void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
   if (UartHandle->Instance == USART1)
  {
    radio_parse(RxByte);
    HAL_UART_Receive_IT(&huart1,&RxByte,1);
  }

  if (UartHandle->Instance == USART2)
  {
    keybrd_parse(Rx1Byte);
    HAL_UART_Receive_IT(&huart2,&Rx1Byte,1);
  }

}

void printf2(uint8_t *buf,int len)
    {
       HAL_UART_Transmit(&huart1, buf, len, 100);
    }










 void station_save(u8 st)  // приходит номер станции, который нужно записать
     {
        u8 x,xx;
        u8 tstr[30];
        u8 z[3];
        u8 b=0;

        if (current_station == izb[st]) goto exit_func;   // такая станция уже записана на эту же кнопку
        /*for (x=0;x<5;x++)
            {
             if (current_station == izb[x])   // если текущая станция  уже есть на избраной кнопке то забываем ее
                 {

                 }

            }*/
        // вернем имя без избранной станции
        x =  strlen(stations[izb[st]]);
        
        for ( xx=4;xx<x;xx++)
            { tstr[b++] = stations[izb[st]][xx];}
        tstr[xx-4]=0;
        sprintf (stations[izb[st]], tstr);
      // strncpy(tstr,stations[izb[st]],x);




        sprintf(z,"\(%d\) ",st+1);  //подготовим номер избраной станции в скобочках

         new_st = 1;
        strcpy(ee_stations[st],z);
        strcat( ee_stations[st],stations[current_station]);
        izb[st] =  current_station;
        sprintf(stations[current_station], ee_stations[st]); //станция видима избранной сразу
        set_eeprom_backup();// сохранили избранную станцию
      exit_func:
     }

 void station_set(u8 st)
     {
       u8 tbuf[30];
       //char xn;
      // new_st=1;
       //prev_station = current_station;
       //button_pointer = st;
      //
      // izb[0]=0; izb[1]=0;izb[2]=0;izb[3]=0;izb[4]=0;

      // station_pressed = st;
       current_station = st;
       sprintf(tbuf,"cli.play(\"%d\")\r\n\0",st);
      // xn =  strlen(tbuf);
       printf2(tbuf,strlen(tbuf));
       play_ok = 0;
       stopped_err = 0;
       check_start_play = 1; // нужно ждать от радио play_ok, иначе нихрена не играет и надо сбрасывать....



     }







u16 check_buttons(void)
    {

       if (buttons ==1)
           {
             bright_lcd_set(80); //480 minimum
             fade_counter = 30000;
             buttons = 0;
              if (y_buf == 0)
                {
                   if (strncmp((const char *)string_buf0, "K5 0",4) == 0)    b_up = 1;// up
                   if (strncmp((const char *)string_buf0, "K9 0",4) == 0)    b_down = 1;// down
                   if (strncmp((const char *)string_buf0, "K7 0",4) == 0)    b_ok = 1;//ok

                    if (strncmp((const char *)string_buf0,"k8 0",4) == 0)
                         {
                            if (but_mute_half==3) {but_mute_half = 1;}
                            else if (but_mute_half == 2){but_mute_half = 0;}
                         }
                    if (strncmp((const char *)string_buf0,"k6 0",4) == 0)
                         {
                            if (but_mute==3) {but_mute = 1;}
                            else if (but_mute == 2){but_mute = 0;}
                         }


                  if (strncmp((const char *)string_buf0, "K4 1",4) == 0)   {new_st =1;show_st=1;b_ok=1;time_to_change = 5000;button_pointer = izb[0];}
                  if (strncmp((const char *)string_buf0, "rep 4",5) == 0)  {
                     new_st =1;
                     show_st=1;
                     b_ok=1;button_pointer = izb[0];
                     station_save(0);}
                  if (strncmp((const char *)string_buf0, "K3 1",4) == 0)    {new_st =1;show_st=1;b_ok=1;time_to_change = 5000;button_pointer =izb[1];}
                  if (strncmp((const char *)string_buf0, "rep 3",5) == 0)  {new_st =1;show_st=1;b_ok=1;button_pointer = izb[1];station_save(1);}
                  if (strncmp((const char *)string_buf0, "K2 1",4) == 0)    {new_st =1;show_st=1;b_ok=1;time_to_change = 5000;button_pointer = izb[2];}
                  if (strncmp((const char *)string_buf0, "rep 2",5) == 0)  {new_st =1;show_st=1;b_ok=1;button_pointer = izb[2];station_save(2);}
                  if (strncmp((const char *)string_buf0, "K1 1",4) == 0)    {new_st =1;show_st=1;b_ok=1;time_to_change = 5000;button_pointer = izb[3];}
                  if (strncmp((const char *)string_buf0, "rep 1",5) == 0)  {new_st =1;show_st=1;b_ok=1;button_pointer = izb[3];station_save(3);}
                  if (strncmp((const char *)string_buf0, "K0 1",4) == 0)   {new_st =1;show_st=1;b_ok=1;time_to_change = 5000;button_pointer =izb[4];}
                  if (strncmp((const char *)string_buf0, "rep 0",5) == 0)  {new_st =1;show_st=1;b_ok=1;button_pointer = izb[4];station_save(4);}



                }
            else
                {
                   if (strncmp((const char *)string_buf1, "k5 0",4) == 0)    b_up = 1;// up
                   if (strncmp((const char *)string_buf1, "k9 0",4) == 0)    b_down = 1;// down
                   if (strncmp((const char *)string_buf1, "k7 0",4) == 0)    b_ok = 1;//ok


                   if (strncmp((const char *)string_buf1,"k8 0",4) == 0)
                         {
                           if (but_mute_half==3) {but_mute_half = 1;}
                           else if (but_mute_half == 2){but_mute_half = 0;}
                         }

                   if (strncmp((const char *)string_buf1,"k6 0",4) == 0)
                         {
                            if (but_mute==3) {but_mute = 1;}
                            else if (but_mute == 2){but_mute = 0;}
                         }

                  if (strncmp((const char *)string_buf1, "k4 1",4) == 0)   {new_st =1;show_st=1;b_ok=1;time_to_change = 5000;last_station=256;button_pointer = izb[0];}
                  if (strncmp((const char *)string_buf1, "rep 4",5) == 0)  {new_st =1;show_st=1;b_ok=1;time_to_change = 5000;button_pointer = izb[0];station_save(0);}
                  if (strncmp((const char *)string_buf1, "k3 1",4) == 0)    {new_st =1;show_st=1;b_ok=1;time_to_change = 5000;last_station=256;;button_pointer =izb[1];}
                  if (strncmp((const char *)string_buf1, "rep 3",5) == 0)  {new_st =1;show_st=1;b_ok=1;time_to_change = 5000;button_pointer = izb[1];station_save(1);}
                  if (strncmp((const char *)string_buf1, "k2 1",4) == 0)    {new_st =1;show_st=1;b_ok=1;time_to_change = 5000;last_station=256;button_pointer = izb[2];}
                  if (strncmp((const char *)string_buf1, "rep 2",5) == 0)  {new_st =1;show_st=1;b_ok=1;time_to_change = 5000;button_pointer = izb[2];station_save(2);}
                  if (strncmp((const char *)string_buf1, "k1 1",4) == 0)    {new_st =1;show_st=1;b_ok=1;time_to_change = 5000;last_station=256;button_pointer = izb[3];}
                  if (strncmp((const char *)string_buf1, "rep 1",5) == 0)  {new_st =1;show_st=1;b_ok=1;time_to_change = 5000;button_pointer = izb[3];station_save(3);}
                  if (strncmp((const char *)string_buf1, "k0 1",4) == 0)   {new_st =1;show_st=1;b_ok=1;time_to_change = 5000;last_station=256;button_pointer =izb[4];}
                  if (strncmp((const char *)string_buf1, "rep 0",5) == 0)  {new_st =1;show_st=1;b_ok=1;time_to_change = 5000;button_pointer = izb[4];station_save(4);}

#ifndef OLD_KBD
                  y_buf = 0;  // comment for old keyboard
#endif                  
                }
           }
       else
           {
            return 0;
           }


    }



     //ssidNames[]
     //wifiPass[]
void set_station(char num_wifi)
    {
       char bbuf[50];
       char za = 0;
            za = sprintf(bbuf,"wifi.con(\"%s\"\,\"%s\")\r\n",ssidNames[num_wifi],wifiPass[num_wifi]);
            printf2(bbuf,za/*strlen(tbuf)*/);
            GUI_SetFont(&GUI_FontVerdana32);
            GUI_SetBkColor(0xb4c9f4);
            GUI_SetColor(GUI_BLACK);
            GUI_DispStringAtCEOL     (" ", 0,125);
            GUI_DispStringAtCEOL     (" ", 0,165);
            GUI_DispStringHCenterAt(ssidNames[num_wifi],440,125);
            GUI_DispStringHCenterAt(wifiPass[num_wifi],440,165);
            HAL_Delay(300);
            sprintf(bbuf,"sys.boot\r\n");
            printf2(bbuf,10);
            HAL_Delay(300);
    }






 void check_all (void)
     {
       char e;
       uint8_t TempStr2[51];
        __IO uint8_t xn;
         u8 tbuf[60];
         uint16_t temp_volume;
         if (show_time_flag==1)
             {
               show_time_flag=0;
               rtc_show();
               if ((stimestructureget.Minutes == 0 || stimestructureget.Minutes == 30) && synch_time_flag == 1)
                {
                  synch_time_flag = 0;
                  sprintf((char *)tbuf,"sys.date\r\n");
                  printf2(tbuf,10);
                  HAL_Delay(100);
                }
               else if (stimestructureget.Minutes != 0 && stimestructureget.Minutes != 30 && synch_time_flag == 0) synch_time_flag = 1;

                 
             }
         if (need_draw_date==1)
             {
                need_draw_date = 0;
                 draw_date();
             }



/*

                //but_mute_half
                if (but_mute_half==1)    // to fix
                    {
                       but_mute_half = 2;
                       //last_volume = ee_volume;
                       sch_mute = 0;
                       GUI_DrawBitmap(&bmmute, 730 , 250);
                          GUI_SetFont(&GUI_FontVerdana32);
                          GUI_SetBkColor(0xb4c9f4);
                          GUI_SetColor(GUI_BLACK);
                          GUI_DispStringHCenterAt("1/2",760,370);
                       //VolLevel =  Get_Vol_Level();
                       last_volume = VolLevel;
                       //set_radio_volume(VolLevel/2);
                       VolLevel = 0;
                    }

                if (but_mute_half==0)
                    {
                     but_mute_half = 3;
                     mute_half = 0;

                     GUI_SetColor(0xb4c9f4);
                     GUI_FillRect  (730,  250,   820,  405);
                    // VolLevel =  Get_Vol_Level();
                     last_volume = VolLevel;
                     //set_radio_volume(VolLevel);
                    }







                if (but_mute==1)  //off sound
                    {
                       MUTE_ON;
                        but_mute = 2;
                        sch_mute = 0;
                        GUI_DrawBitmap(&bmmute, 730 , 250);
                        last_volume = VolLevel;
                        VolLevel = 0;
                        //set_radio_volume(VolLevel);
                    }

                if (but_mute==0)
                    {
                     but_mute = 3;
                     mute_pressed = 0;
                     GUI_SetColor( 0xb4c9f4);
                     GUI_FillRect  (730,  250,   820,  405);
                    // VolLevel =  Get_Vol_Level();
                     last_volume = VolLevel;
                     //set_radio_volume(VolLevel);
                    MUTE_ON;
                    }
*/
                if (b_down==1)
                    {

                         if (button_pointer>=1)
                           {
                           // prev_button = button_pointer; // для гашения предыдущей кнопки
                              if (last_station==256) last_station = button_pointer;
                            button_pointer--;
                            new_st =1;       // переключим станцию
                            show_st=1;
                            time_to_change = 10000;
                           }

                         if (button_pointer== 0)
                           {
                                   GUI_SetFont(&GUI_FontVerdana32);
                                   sprintf((char *)tbuf, "Начало списка");
                                   GUI_DispStringHCenterAt((char *)tbuf, 440, 370);
                           }
                      else
                          {
                                GUI_SetFont(&GUI_FontVerdana32);
                                GUI_DispStringAtCEOL    ( (char *)" ", 0, 370);
                          }


                       b_down=0;
                    }

                 if (b_up==1)
                    {
                       time_to_change = 10000;
                      if (button_pointer<(saved_station-1))
                           {

                            if (last_station==256)  last_station = button_pointer; // дошли до конца?
                            button_pointer++;
                            new_st =1;  // переключим станцию
                            show_st=1;

                           }
                       if (button_pointer==(saved_station-1))
                           {
                                   GUI_SetFont(&GUI_FontVerdana32);
                                   sprintf((char *)tbuf, "Конец списка");
                                   GUI_DispStringHCenterAt((char *)tbuf, 440, 370);
                           }
                      else
                          {
                                GUI_SetFont(&GUI_FontVerdana32);
                                GUI_DispStringAtCEOL    ( (char *)" ", 0, 370);
                          }

                       b_up=0;
                    }




                      if (new_st==1)   // новая станция выбрана
                      {
                         if (show_st==1)  // разрешение показать станцию
                             {
                              GUI_SetColor(GUI_BLACK);
                              GUI_SetFont(&GUI_FontVerdana42);
                              GUI_DispStringAtCEOL    ( (char *)"", 0, 330);
                              sprintf((char *)tbuf, "%s ",stations[button_pointer]);  //current_station
                              GUI_DispStringHCenterAt((char *)tbuf, 440, 330);
                              show_st=0;
                             }
                          if ( time_to_change>1)   // время есть посмотреть на выбранную станцию и сделать выбор , включать или нет
                              {
                                
                                 GUI_DispStringAtCEOL    ( (char *)"", 0, 400); // затрем мету так захотел шеф.
                                
                                 if (b_ok==1)           //нажали на кнопку выбрать
                                     {
                                         GUI_SetFont(&GUI_FontVerdana32);
                                         GUI_DispStringAtCEOL    ( (char *)" ", 0, 370);
                                        
                                         
                                         
                                        b_ok = 0;
                                        last_station=256; // забыли станцию на возврат
                                        station_set(button_pointer);     // переключим радио на button_pointer станцию
                                        sprintf(tbuf,"cli.vol(\"255\")\r\n\0");
                                        xn =  strlen(tbuf);
                                        printf2(tbuf,xn);
                                        new_st=0;
                                        ee_station = button_pointer;
                                        set_eeprom_backup();   // запомним текущую проигрываемую
                                     }
                              }
                         else
                             {    // время закончилось, выведем предыдущую станцию
                                if (last_station<=255)
                                    {
                                       GUI_SetFont(&GUI_FontVerdana32);
                                      GUI_DispStringAtCEOL    ( (char *)" ", 0, 370);  // сотрем надпись о последней станции из списка
                                      GUI_SetColor(GUI_BLACK);
                                      GUI_SetFont(&GUI_FontVerdana42);
                                      GUI_DispStringAtCEOL    ( (char *)"", 0, 330);
                                      sprintf((char *)tbuf, "%s ",stations[last_station]);  //current_station
                                      GUI_DispStringHCenterAt((char *)tbuf, 440, 330);
                                      GUI_SetFont(&GUI_FontVerdana32);
                                      GUI_DispStringAtCEOL    ( (char *)"", 0, 400);
                                      for(e=0;e<50;e++)
                                        {
                                          if (meta_string[e]==0x0d)
                                          {
                                            TempStr2[e] = 0;
                                            break;
                                          }
                                            else
                                          {
                                            TempStr2[50] = 0;  
                                            TempStr2[e]= meta_string[e];
                                          }
                                        }
                                      GUI_DispStringHCenterAt((char *)TempStr2, 440, 400); // вывели затертую мету от проигрываемой станции  назад
                                      
                                      
                                      button_pointer = last_station;
                                      last_station = 256;
                                    }
                             }


                      }

                              if (b_ok==1)           //нажали на кнопку выбрать
                                     {
                                          GUI_SetFont(&GUI_FontVerdana42);
                                         // GUI_DispStringAtCEOL    ( (char *)" ", 0,370);
                                          GUI_DispStringAtCEOL    ( (char *)"", 0, 330);
                              sprintf((char *)tbuf, "%s ",stations[button_pointer]);  //current_station
                              GUI_DispStringHCenterAt((char *)tbuf, 440, 330);
                                        b_ok = 0;
                                     }



                          //  if (set_volume)
                             // {
                             //   bright_lcd_set(80); //480 minimum
                             //   fade_counter = 30000;
                             // }

     }

 void draw_date(void)
     {
         static uint8_t TempStr[50];
         u8 str[20];
         char tbuf[50];
       uint8_t x;



    GUI_DrawGradientV(0, 0, 853 , 70,  0x85aaf1,0xb9cff6);
     GUI_SetColor(0x8aaaea);
    GUI_DrawHLine(71, 0, 853);
    GUI_DrawHLine(72, 0, 853);
    GUI_DrawHLine(73, 0, 853);
    GUI_SetColor(GUI_BLACK);
    GUI_SetTextMode(GUI_TM_TRANS);
    
    if (doll_string[0] != 0)
    {
    for(x=0;x<6;x++)
       tbuf[x] = doll_string[x];
                              
    tbuf[x] = 0;
    tbuf[0] = 0x20;
    GUI_SetFont(&GUI_FontVerdana32);
    GUI_DispStringAt((char *)tbuf, 760, 3);
    GUI_DispStringAt((char *)"$", 746, 2);
    }
    
    GUI_SetFont(&GUI_FontVerdana45);

       HAL_RTC_GetTime(&RtcHandle, &stimestructureget, RTC_FORMAT_BIN);
       HAL_RTC_GetDate(&RtcHandle, &sdatestructureget, RTC_FORMAT_BIN);

/*   sprintf(TempStr,"%2d ",  sdatestructureget.Date);//      Дата
    GUI_DispStringHCenterAt((char *)TempStr,245, 5);

    sprintf(str,"%c%c%c ",  MonthNames[((sdatestructureget.Month-1) * 3)], MonthNames[((sdatestructureget.Month-1) * 3)+1],MonthNames[((sdatestructureget.Month-1) * 3)+2]);   //   Месяц
    GUI_DispStringHCenterAt((char *)str,320, 5);
   // strcat( TempStr,str);
    sprintf(str,"20%d, ",  sdatestructureget.Year);                                                                                                                                                                                                                                                //   Год
     GUI_DispStringHCenterAt((char *)str,420, 5);
    // strcat( TempStr,str);
    sprintf((char *)str, WeekDayNames[DayOfWeek(sdatestructureget.Year, sdatestructureget.Month,sdatestructureget.Date)]);    //      День недели
    // strcat( TempStr,str);
    GUI_DispStringAt((char *)str,480, 5);
*/
       
    sprintf(TempStr,"%2d ",  sdatestructureget.Date);//      Дата
    sprintf(str,"%c%c%c ",  MonthNames[((sdatestructureget.Month-1) * 3)], MonthNames[((sdatestructureget.Month-1) * 3)+1],MonthNames[((sdatestructureget.Month-1) * 3)+2]);   //   Месяц
    strcat( TempStr,str);
    sprintf(str,"20%d, ",  sdatestructureget.Year);                                                                                                                                                                                                                                                //   Год
     strcat( TempStr,str);
    sprintf((char *)str, WeekDayNames[DayOfWeek(sdatestructureget.Year, sdatestructureget.Month,sdatestructureget.Date)]);    //      День недели
     strcat( TempStr,str);
    GUI_DispStringAt((char *)TempStr,200, 5);
    
    GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
     }

 void rtc_show(void)
{
//RTC
      char TempStr[100];
      char TempStr2[30];
      char data[10];
      int ypos = 50;
      int ystep = 50;
      int xpos = 854/2;
      int e;
      GUI_SetColor(GUI_BLACK);
       /* Get the RTC current Time */
    //HAL_RTC_GetTime(&RtcHandle, &stimestructureget, RTC_FORMAT_BIN);
    /* Get the RTC current Date */
   // HAL_RTC_GetDate(&RtcHandle, &sdatestructureget, RTC_FORMAT_BIN);
      ypos+=ystep;
      GUI_SetFont(&GUI_FontVerdana220);
      sprintf((char *)TempStr, "%02d:%02d", stimestructureget.Hours , stimestructureget.Minutes);
      GUI_DispStringHCenterAt((char *)TempStr,xpos, ypos);
      GUI_SetFont(&GUI_FontVerdana96);
      sprintf((char *)TempStr, "%02d",stimestructureget.Seconds);
      GUI_DispStringAt((char *)TempStr,xpos+270, ypos+30);

      if ((new_msg_meta==1))     //(new_st==1)||
                  {
                      new_msg_meta = 0;
                      GUI_SetFont(&GUI_FontVerdana32);
                      GUI_DispStringAtCEOL    ( (char *)"", 0, 400);
                      for(e=0;e<50;e++)
                      {
                        if (meta_string[e]==0x0d)
                        {
                         TempStr2[e] = 0;
                         break;
                        }
                        else
                        {
                         TempStr2[50] = 0;  
                         TempStr2[e]= meta_string[e];
                        }
                      }
                      GUI_DispStringHCenterAt((char *)TempStr2, 440, 400);
                     
                  }
   }

 




     u8  set_SD_station(char num_wifi)  //передача модулю команды
    {
       char bbuf[50];
       char za = 0;
       char e=0;
       char n,k;
       char ssid_buf[32];
       char pass_buf[32];
       ssid_buf[0]=0;
       pass_buf[0]=0;
       if (num_wifi==26) return num_wifi; // все все 25 перебрали, выходим отсюда, нет станций

      strcpy(tempstr,sdssidNames[num_wifi]);
      char *pch = strtok(tempstr,",\n");

      sprintf(ssid_buf,pch,strlen(pch));
      pch = strtok(NULL,",\n");
      sprintf(pass_buf,pch,strlen(pch));


                    sprintf(rssi_string,"wifi.con(%s\,%s)\r\n",ssid_buf,pass_buf);
                    printf2(rssi_string,strlen(rssi_string));
                    GUI_SetBkColor(0xb4c9f4);
                    GUI_SetColor(GUI_BLACK);
                    GUI_SetFont(&GUI_FontVerdana42);
                    GUI_DispStringAtCEOL(" ",0, 330);
                    sprintf((char *)rssi_string,"Подключаюсь к %s",ssid_buf);
                    GUI_DispStringHCenterAt(rssi_string,440, 330);
                    save_wifi(ssid_buf);
                    HAL_Delay(300);
                    sprintf(rssi_string,"sys.boot\r\n");
                    printf2(rssi_string,10);
            return  num_wifi;
     }


 void show_time(void)
     {
         if (show_time_flag==1)
                            {
                             show_time_flag=0;
                             rtc_show();
                            }
     }
 u8 check_internet(void)
     {
         u8 tbuf[11];
         binet=0;
         while (new_msg_valuta==0)
           {
              HAL_Delay(100);
              if (doll_string[0]!=0)
                  {
                   new_msg_valuta = (doll_string[0]!=0x2D)?1:2;
                  }
            show_time();
            if (wifi_module_ready==1) new_msg_valuta = 3; //поднята точка доступа есп32
             binet++;
       if ( binet > 300)
           {
            sprintf(tbuf,"sys.boot\r\n");
            printf2(tbuf,10);
            HAL_NVIC_SystemReset();  // висим - уарт повис
           }
           }
         
         
         
         binet = 0;
         while (bready_radio==0)      // ждем когда модуль выйдет после ребута
           {
               HAL_Delay(100);
              binet++;
       if ( binet > 300)
           {
            sprintf(tbuf,"sys.boot\r\n");
            printf2(tbuf,10);
            HAL_NVIC_SystemReset();  // висим - уарт повис
           }

            show_time();
            if (wifi_module_ready==1) break;
           }
         return new_msg_valuta;
     }

 void exit_no_internet_td(void)
     {
        u8 tbuf[50];
        u8 temp;
        wifi_module_ready  = 0;
        sprintf(tbuf,"wifi.con(\"\",\"\")\r\n");
        printf2(tbuf,strlen(tbuf));
        HAL_Delay(500);
        sprintf(tbuf,"sys.boot\r\n");
        printf2(tbuf,10);
        binet = 0;
        while (wifi_module_ready==0)
            {
              show_time();
              HAL_Delay(100);
              binet++;
       if ( binet == 300)
           {
            sprintf(tbuf,"sys.boot\r\n");
            printf2(tbuf,10);
            HAL_NVIC_SystemReset();  // висим - уарт повис
           }
            }


     }





 void wait_ready(void)
     {
         u8 tbuf[50];
               while (bready_radio==0)      // ждем когда модуль выйдет после ребута
           {
              HAL_Delay(100);
              binet++;
       if ( binet == 200)
           {
            sprintf(tbuf,"sys.boot\r\n");
            printf2(tbuf,10);
            HAL_NVIC_SystemReset();  // висим - уарт повис
           }

            show_time();
            if (wifi_module_ready==1) break;
           }

     }




 void turn_on_station(void)
     {
        char xn;
        u8 tbuf[50];
        saved_station = 0;
         HAL_Delay(500);
      sprintf(tbuf,"cli.list\r\n");
      printf2(tbuf,10);
      HAL_Delay(500);



      // if (saved_station == 0)
      //   {
       //     HAL_NVIC_SystemReset();   // TO FIX
      //   }
      get_eeprom_backup();    // узнаем текущую станцию
      if (ee_station>saved_station) ee_station = 0;
      for(xn=0;xn<5;xn++)   // cкопируем названия избранных станций
         {
         strcpy(ee_stations[xn],stations[izb[xn]]);
         }

      button_pointer = ee_station;
      station_set(button_pointer);     // переключим радио на button_pointer станцию
     }
 
 
 
  u8 try_connect(void)
     {
        u8 temp;
        u8 bs = 0;
        while (bs<26)
            {
             bs = set_SD_station(check_stations_wifi()); //  даем команду на подключение к станции
             if (bs==26) break;
              wifi_module_ready = 0;
              new_msg_valuta = 0;
              bready_radio = 0;
              doll_string[0]=0;
             temp = check_internet(); // мониторим подключение по доллару, если его не получили нет инета
             if (temp==1) { blast_station = bs; return 1;}// станция подключена и есть инет
             if (temp==2) bad_ssid[bs] = 1;
            }
            return 255;// нету ниодной 


     }


u8 perebor_wifi(void)
     {
        u8 s=0;
              while(s<255)
         {
           wifi_module_ready = 0;
           new_msg_valuta = 0;
           bready_radio = 0;

                  s = try_connect();
                   if (s==1) break;

         }  // вызов подпрограммы сканирования и выбора wifi станций с подключением
         return s;
     }


 void no_wifi_task(void)
     {
        u8 tbuf[50];
        u8 t;
        u8 s;

                   GUI_SetFont(&GUI_FontVerdana42);
                   GUI_DispStringAtCEOL(" ",0, 330);
                   GUI_DispStringHCenterAt("Нет доступных WIFI",440, 330);
                   binet=0;
                 while(1)
                     {

                        // тут можно дать команду модулю искать точки доступа еще раз
                           if (show_time_flag==1)
                            {
                               show_time_flag=0;
                               binet++;
                               rtc_show();
                               
                                     GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
                                     if (binet==25)
                                         {
                                            binet = 0;
                                            t = 3;
                                            for(s=0;s<25;s++)
                                                {
                                                   bad_ssid[s]=0;
                                                }

                                            s=0;
                                            exit_no_internet_td();
                                           s =  perebor_wifi();
                                           if (s==1) break;
                                         }

                            }
                     }

     GUI_SetFont(&GUI_FontVerdana42);
     GUI_DispStringAtCEOL(" ",0, 330);
     }


 void show_blabla_and_play(void)
     {
        u8 tbuf[50];
        u8 t;
        u8 xn,x;
         long temp_bckup;
        //здесь мы подключены к точке доступа и ESP32 имеет IP
     //draw_tray(0);
     sprintf(tbuf,"cli.vol(\"254\")\r\n");//громкость на максимум
     printf2(tbuf,strlen("cli.vol(\"254\")\r\n"));
      HAL_Delay(500);
    
     sprintf(tbuf,"sys.date\r\n");//Далее тащим время дату всяк хуйню и подключаемся к станции
     printf2(tbuf,10);
      HAL_Delay(500);
      turn_on_station();
    //  ee_volume = 255;
    //                      sprintf(tbuf,"cli.vol(\"%d\")\r\n\0",ee_volume);
    //                      xn =  strlen(tbuf);
    //                      printf2(tbuf,xn);
    // draw_tray(0);
    // show_valuta = 1;
     temper_show_flag = 1;

      GUI_SetColor(GUI_BLACK);
      GUI_SetTextMode(GUI_TM_TRANS);
      GUI_SetFont(&GUI_FontVerdana45_rus);
                          for(x=0;x<6;x++)
                          {
                           tbuf[x] = doll_string[x];
                          } // сохраним доллар в памяти
                          temp_bckup = (uint32_t)(tbuf[1]<<24 |tbuf[2]<<16 | tbuf[4]<<8 | tbuf[5]);
                          HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR13,temp_bckup );


                         // GUI_DrawGradientV(580, 410, 735 , 479, 0xb9cff6, 0x85aaf1);
                              tbuf[x] = 0;
                                 tbuf[0] = 0x20;
                              GUI_SetFont(&GUI_FontVerdana32);
                             
                              GUI_DispStringAt((char *)tbuf, 760, 3);
                               GUI_DispStringAt((char *)"$", 746, 2);
                               
                               
                               GUI_SetFont(&GUI_FontVerdana42); 
                               
                               
                             //  GUI_DispStringAtCEOL(" ",0, 330);
                              GUI_DispStringAtCEOL    ( (char *)"", 0, 330);
                             
                              sprintf((char *)tbuf, "%s ",stations[button_pointer]);  //current_station
                              GUI_DispStringHCenterAt((char *)tbuf, 440, 330);
                              GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
     }
 
 void try_to_connect(void)
 {
   list_flag=0;
   char t=0,s=0;
   doll_string[0]=0;
   u8 tbuf[50];
      new_msg_meta = 0;
      GUI_SetFont(&GUI_FontVerdana42); 
      GUI_DispStringAtCEOL    ( (char *)" ",  0, 330);
      sprintf((char *)tbuf, "Поиск доступных WIFI");  //
      GUI_DispStringHCenterAt((char *)tbuf, 440, 330);
      GUI_SetFont(&GUI_FontVerdana32);
      GUI_DispStringAtCEOL    ( (char *)" ", 0, 400);

      while(list_flag==0) // ждем когда придет флаг что пришел список станций
     {
       show_time();
       if (check_internet())// модуль прислал валюту? он уже в сети
       {
          t = 0;
          break; 
       }
     }
     
     if (t==0)
     {
                     bready_radio =0;
                     new_msg_valuta = 0;
                     wifi_module_ready = 0;
                     s = perebor_wifi();
                     if (s==255) no_wifi_task();
     }
      show_blabla_and_play();
      no_internet = 0;
      bad_state = 0;
      bad_connect = 0;
      save_bad_connect();
      list_flag=0;
 }
 
 
  void try_to_connect2(void)
 {
   list_flag=0;
   char t=0,s=0;
   doll_string[0]=0;
   u8 tbuf[50];
      new_msg_meta = 0;
      GUI_SetFont(&GUI_FontVerdana42); 
      GUI_DispStringAtCEOL    ( (char *)" ",  0, 330);
      sprintf((char *)tbuf, "Поиск доступных WIFI");  //
      GUI_DispStringHCenterAt((char *)tbuf, 440, 330);
      GUI_SetFont(&GUI_FontVerdana32);
      GUI_DispStringAtCEOL    ( (char *)" ", 0, 400);
   binet = 0;
         
             

      while(list_flag==0) // ждем когда придет флаг что пришел список станций
     {
         show_time(); //Показываем время
         GUI_DispStringAtCEOL    ( (char *)" ", 0, 400); // стираем мету
        binet++; // ведем счетчик
        if ( binet > 4000)
           {
              binet = 0;
              reset_esp32();// по переполнению счетчика сброс есп32
           }
     }
     
    
                     bready_radio =0;
                     new_msg_valuta = 0;
                     wifi_module_ready = 0;
                     s = perebor_wifi();
                     if (s==255) no_wifi_task();
    
      show_blabla_and_play();
      no_internet = 0;
      bad_state = 0;
      bad_connect = 0;
      save_bad_connect();
      list_flag=0;
 }
 

void StartDefaultTask(void) //(void const * argument)
{
    char x,t=0,s=0;//,a=0;
    long temp_bckup;
 int vol_count;
 //int  kos=0;
 int timeout = 0;
 u8 tbuf[50];
 u8 wf_buf[32];
 char xn;
 //char bs = 0;
 //u8 no_station=0;
       char buff[2];
       // отправим запрос клавиатуре на выдачу данных
      buff[0] = 0x55;
      buff[1] = 0x0d;
      but_mute_half = 3;
      last_station = 256;
      // set_bat_buf();
      lcd_pwm_init();
      get_eeprom_backup();
      bright_lcd_set(80); //480 minimum
      draw_date();
    // draw_tray(30);
    // vs();  //выведем состояния запомненой предыдущей валюты
     //MUTE_ON;

     GUI_SetBkColor(0xb4c9f4);
     GUI_SetColor(GUI_BLACK);
     GUI_SetFont(&GUI_FontVerdana42);
      sprintf(tbuf,"sys.boot\r\n");
      printf2(tbuf,10);
      HAL_Delay(300);
 //------------------------------------------ начнем женитьбу с есп32 ----------------------------------------
     
    try_to_connect(); 
      
    MUTE_OFF; //mute off  
      
  for(;;)
  {

     check_buttons();
     check_all ();
     if (no_internet==1) try_to_connect2();
     if (pizdec==1)
     {
       pizdec=0;
       reset_esp32();
       try_to_connect2();
     }
     HAL_Delay(10);

   }
  

}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
   if (htim->Instance == TIM7) {
    HAL_IncTick();
  }

}

  uint8_t utf_hi_char;
// except 0401 --> 0xa2 = Ё, 0451 --> 0xb5 = ё
const unsigned char utf_recode[] =
{
    0x41,0xa0,0x42,0xa1,0xe0,0x45,0xa3,0xa4,0xa5,0xa6,0x4b,0xa7,0x4d,0x48,0x4f,
    0xa8,0x50,0x43,0x54,0xa9,0xaa,0x58,0xe1,0xab,0xac,0xe2,0xad,0xae,0x62,0xaf,0xb0,0xb1,
    0x61,0xb2,0xb3,0xb4,0xe3,0x65,0xb6,0xb7,0xb8,0xb9,0xba,0xbb,0xbc,0xbd,0x6f,
    0xbe,0x70,0x63,0xbf,0x79,0xe4,0x78,0xe5,0xc0,0xc1,0xe6,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7
};

 #define UNKCHAR ' '
char CharUsci2Ansi1251(uint16_t q)
{
  if (q == 0x401) return 'Ё';
  if (q == 0x451) return 'ё';
  if ((q >= 0x410)&&(q <= 0x44F)) return (char)(q-0x410+'А');
  return UNKCHAR;
}
int Utf8toUsci(char* s_utf8, char* s_ansi, int size)
{
  int res = 0;
  char c, a;
  uint16_t u = 0;
  int len = 0;
  while (size > 0)
  {
    c = *s_utf8;
    if (c == 0)
    {
      break;
    }else if((int8_t)c > 0)
    {
      *s_ansi = c;
      s_ansi++;
      size--;
      res++;
    }else if ((c & 0xC0) == 0x80)
    {
      if (len == 0)
      {
        return -1;
      }
      if (len > 0)
      {
        u <<= 6;
        u += c & 0x3F;
        len--;
        if (len == 0)
        {
          if (u != 0xFEFF)
          {
            *s_ansi = CharUsci2Ansi1251(u);
            s_ansi++;
            res++;
          }
        }
        size--;
      }else if (len < 0)
      {
        len++;
      }
    }else if ((c & 0xE0) == 0xC0)
    {
      if (len |= 0) return -1;
      len = 1;
      u = (uint16_t)(c & 0x1F);
    }else if ((c & 0xF0) == 0xE0)
    {
      if (len |= 0) return -1;
      len = 2;
      u = (uint16_t)(c & 0x0F);
    }else if ((c & 0xF8) == 0xF0)
    {
      if (len |= 0) return -1;
      len = -3;
      *s_ansi = UNKCHAR;
      s_ansi++;
      size--;
      res++;
    }else
    {
      return -1;
    }
    *s_utf8++;
  }
  *s_ansi = 0;
  return res;
}




void get_station_to_list(char buf)
    {

       char k=0;
       char z;
       char temp;
       char izb_ee[100];
       if (buf ==0)
           {
            for (z=20;z<120;z++)
             {
              temp = string_buffer0[z];

              if (temp==',')
                  {
                     stations[saved_station] [k] = 0;
                     break;
                  }

              stations[saved_station] [k] = temp;
              k++;

           }
           }
       else
           {
             for (z=20;z<100;z++)
             {
              temp = string_buffer1[z];

              if (temp==',')
                  {
                     stations[saved_station] [k] = 0;
                     break;
                  }
              stations[saved_station] [k] = temp;
              k++;

           }
           }

     if (Utf8toUsci(stations[saved_station], tempstr, 50)>0)    strcpy(stations[saved_station],tempstr);


     if (saved_station ==izb[0])
         {
          sprintf(izb_ee,"(1)   ");
          strcat ( izb_ee,stations[saved_station]);
          sprintf( stations[saved_station],izb_ee);
         }
     if (saved_station ==izb[1])
         {
           sprintf(izb_ee,"(2) ");
           strcat ( izb_ee,stations[saved_station]);
           sprintf( stations[saved_station],izb_ee);
         }
     if (saved_station ==izb[2])
         {
          sprintf(izb_ee,"(3) ");
          strcat (izb_ee ,stations[saved_station]);
          sprintf( stations[saved_station],izb_ee);
         }
     if (saved_station ==izb[3])
         {
          sprintf(izb_ee,"(4) ");
          strcat ( izb_ee,stations[saved_station]);
          sprintf( stations[saved_station],izb_ee);
         }
     if (saved_station ==izb[4])
         {
           sprintf(izb_ee,"(5) ");
           strcat (izb_ee,stations[saved_station]);
           sprintf( stations[saved_station],izb_ee);
         }

     saved_station ++;
    }

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc)
    {
       HAL_RTC_GetTime(hrtc, &stimestructureget, RTC_FORMAT_BIN);
       HAL_RTC_GetDate(hrtc, &sdatestructureget, RTC_FORMAT_BIN);
       // rtc_time = rtc_to_timestamp(&sdatestructure, &stimestructure);
       show_time_flag = 1;
    }


 void HAL_RTCEx_AlarmBEventCallback(RTC_HandleTypeDef *hrtc)
{
  need_draw_date = 1;
}

void Error_Handler(void)
{

}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{
 }
#endif /* USE_FULL_ASSERT */


