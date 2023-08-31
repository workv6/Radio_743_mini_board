  /* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "fatfs.h"
#include "usb_device.h"
// #include "rm68120.h"
#include "ili9806.h"
#include "GUI.h"
#include "WM.h"
#include "time.h"

  extern RTC_HandleTypeDef RtcHandle;
  extern struct tm ntp_time;
  extern u8 bad_connect;
 // extern uint8_t ee1,ee2,ee3,ee4,ee5;
  extern time_t my_time;
  uint16_t ee_station,ee_volume;
  RTC_DateTypeDef sdatestructure;
  RTC_TimeTypeDef stimestructure;
 extern u8 izb[];

   int16_t used_UTC = 3;
/* Days names definition */
const string WeekDayNames[7] =
  {"Воскресенье" ,
   "Понедельник",
   "Вторник",
   "Среда",
   "Четверг",
   "Пятница",
   "Суббота"};

/* Months names definition */
const   uint8_t MonthNames[] = {'я', 'н', 'в', 'ф', 'е', 'в', 'м', 'а', 'р', 'а', 'п', 'р',
                                  'м', 'а', 'й', 'и', 'ю', 'н', 'и', 'ю', 'л', 'а', 'в', 'г',
                                  'с', 'е', 'н', 'о', 'к', 'т', 'н', 'о', 'я', 'д', 'е', 'к'};


bool IsLeapYear(u16 nYear)
{
  if (nYear % 4 != 0) return FALSE;
  if (nYear % 100 != 0) return TRUE;
  return (bool)(nYear % 400 == 0);
}

uint16_t CountOfFeb29(uint16_t nYear)
{
  uint16_t nCount = 0;

  if (nYear > 0)
  {
    nCount = 1; /* Year 0 is a leap year */
    nYear--;    /* Year nYear is not in the period */
  }
  nCount += nYear / 4 - nYear / 100 + nYear / 400;
  return nCount;
}

uint16_t DayOfWeek(uint16_t nYear, uint16_t nMonth, uint16_t nDay)
{
  uint16_t nDayOfWeek = 0;
  uint16_t pnDaysBeforeMonth[14] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

  /* The day of Jan 1, nYear */
  nDayOfWeek = 6 + nYear % 7 + CountOfFeb29(nYear) % 7 + 14; /* + 14 : makes nDayOfWeek >= 0 */

  /* The day of nMonth 1, nYear */
  nDayOfWeek += pnDaysBeforeMonth[ nMonth ];
  if ( nMonth > 2 && IsLeapYear(nYear))
  {
    nDayOfWeek++;
  }

  /* The day of nMonth nDay, nYear */
  nDayOfWeek += nDay - 1;
  nDayOfWeek %= 7;
  /* return the number of the day in the week */
  return nDayOfWeek;
}


void RTC_CalendarConfig(void)
{


  sdatestructure.Year = ntp_time.tm_year-100;
  sdatestructure.Month = ntp_time.tm_mon;
  sdatestructure.Date = ntp_time.tm_mday;
  sdatestructure.WeekDay = ntp_time.tm_wday;

  if(HAL_RTC_SetDate(&RtcHandle,&sdatestructure,RTC_FORMAT_BIN) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  stimestructure.Hours = ntp_time.tm_hour;
  stimestructure.Minutes = ntp_time.tm_min;
  stimestructure.Seconds = ntp_time.tm_sec/*+1*/;
  stimestructure.TimeFormat = RTC_HOURFORMAT12_AM;
  stimestructure.DayLightSaving = RTC_DAYLIGHTSAVING_NONE ;
  stimestructure.StoreOperation = RTC_STOREOPERATION_RESET;

  if (HAL_RTC_SetTime(&RtcHandle, &stimestructure, RTC_FORMAT_BIN) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  /*##-3- Writes a data in a RTC Backup data Register1 #######################*/
  HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR1, 0x32F2);
}


void set_eeprom_backup(void)
{
  HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR3, ee_station);
  HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR4, ee_volume);
  HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR8,  izb[0]);
  HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR9,  izb[1]);
  HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR10, izb[2]);
  HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR11, izb[3]);
  HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR12, izb[4]);



}

void set_defaults(void)
{
  HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR3, 0);
  HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR4, 55);
  HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR7, 0xaa55);
  HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR8, 0);
  HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR9, 1);
  HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR10, 2);
  HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR11, 3);
  HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR12, 4);
}

void get_eeprom_backup(void)
{
  uint16_t magic;

  ee_station = HAL_RTCEx_BKUPRead(&RtcHandle, RTC_BKP_DR3);
  ee_volume = HAL_RTCEx_BKUPRead(&RtcHandle, RTC_BKP_DR4);
  magic = HAL_RTCEx_BKUPRead(&RtcHandle, RTC_BKP_DR7);
  izb[0] =  HAL_RTCEx_BKUPRead(&RtcHandle, RTC_BKP_DR8);
  izb[1] =  HAL_RTCEx_BKUPRead(&RtcHandle, RTC_BKP_DR9);
  izb[2] =  HAL_RTCEx_BKUPRead(&RtcHandle, RTC_BKP_DR10);
  izb[3] =  HAL_RTCEx_BKUPRead(&RtcHandle, RTC_BKP_DR11);
  izb[4] =  HAL_RTCEx_BKUPRead(&RtcHandle, RTC_BKP_DR12);




  if (magic == 0x0000) set_defaults();
}

  void save_wifi(u8* sb)
      {
       u32 temp;
       temp =(uint32_t)( sb[0]<<24 | sb[1]<<16 | sb[2]<<8 | sb[3]);
       HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR15, temp);
        temp =(uint32_t)( sb[4]<<24 | sb[5]<<16 | sb[6]<<8 | sb[7]);
       HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR16, temp);
         temp =(uint32_t)( sb[8]<<24 | sb[9]<<16 | sb[10]<<8 | sb[11]);
       HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR17, temp);
        temp =(uint32_t)( sb[12]<<24 | sb[13]<<16 | sb[14]<<8 | sb[15]);
       HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR18, temp);
        temp =(uint32_t)( sb[16]<<24 | sb[17]<<16 | sb[18]<<8 | sb[19]);
       HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR19, temp);
        temp =(uint32_t)( sb[20]<<24 | sb[21]<<16 | sb[22]<<8 | sb[23]);
       HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR20, temp);
       temp =(uint32_t)( sb[24]<<24 | sb[25]<<16 | sb[26]<<8 | sb[27]);
       HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR21, temp);
       temp =(uint32_t)( sb[28]<<24 | sb[29]<<16 | sb[30]<<8 | sb[31]);
       HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR22, temp);


      }

  void save_bad_connect(void)
      {
       HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR23, bad_connect);
      }


  void load_wifi(u8* sb)
      {
       u32 temp;

       bad_connect = HAL_RTCEx_BKUPRead(&RtcHandle, RTC_BKP_DR23);

       temp = HAL_RTCEx_BKUPRead(&RtcHandle, RTC_BKP_DR15);
       sb[0] = temp>>24;
       sb[1] = temp>>16;
       sb[2] = temp>>8;
       sb[3] = temp;

       temp = HAL_RTCEx_BKUPRead(&RtcHandle, RTC_BKP_DR16);
       sb[4] = temp>>24;
       sb[5] = temp>>16;
       sb[6] = temp>>8;
       sb[7] = temp;

       temp = HAL_RTCEx_BKUPRead(&RtcHandle, RTC_BKP_DR17);
       sb[8] = temp>>24;
       sb[9] = temp>>16;
       sb[10] = temp>>8;
       sb[11] = temp;
       temp = HAL_RTCEx_BKUPRead(&RtcHandle, RTC_BKP_DR18);
       sb[12] = temp>>24;
       sb[13] = temp>>16;
       sb[14] = temp>>8;
       sb[15] = temp;
       temp = HAL_RTCEx_BKUPRead(&RtcHandle, RTC_BKP_DR19);
       sb[16] = temp>>24;
       sb[17] = temp>>16;
       sb[18] = temp>>8;
       sb[19] = temp;
       temp = HAL_RTCEx_BKUPRead(&RtcHandle, RTC_BKP_DR20);
       sb[20] = temp>>24;
       sb[21] = temp>>16;
       sb[22] = temp>>8;
       sb[23] = temp;
       temp = HAL_RTCEx_BKUPRead(&RtcHandle, RTC_BKP_DR21);
       sb[24] = temp>>24;
       sb[25] = temp>>16;
       sb[26] = temp>>8;
       sb[27] = temp;
       temp = HAL_RTCEx_BKUPRead(&RtcHandle, RTC_BKP_DR22);
       sb[28] = temp>>24;
       sb[29] = temp>>16;
       sb[30] = temp>>8;
       sb[31] = temp;



      }