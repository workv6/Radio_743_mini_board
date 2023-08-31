/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "sd.h"
#include "ff_gen_drv.h"
#include "sd_diskio.h"
#include "cmsis_os.h"
#include "GUI.h"
//#include "struct.h"
 extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana32;
u8 sleep_s;
//extern EEData_t  *EEData;   // ??????
/* Private variables ---------------------------------------------------------*/
FATFS SDFatFs;  /* File system object for SD card logical drive */
FIL file;     /* File object */
FRESULT res;
char SDPath[4]; /* SD card logical drive path */
extern struct _ts_event ts_event;
//static uint8_t isInitialized = 0;
extern u8 sleep;
u8 event_SD;
extern u16 button_timer;
u8 card_present = 0;
long time_to_sleep;
u8    filename[40];
u8 buf[100];

char sdssidNames[25][32];
char sdwifiPass[25][32];


 char str_temp[50];

uint8_t test_fat(void);

uint32_t k_StorageGetFree (void);
uint32_t   tot_sect = 0;







uint32_t k_StorageGetFree (void)
{
   uint32_t   fre_clust = 0;

  FATFS *fs;
  res = FR_INT_ERR;


    fs = &SDFatFs;
    res = f_getfree("0:", (DWORD *)&fre_clust, &fs);

  if(res == FR_OK)
  {
    tot_sect = (fs->n_fatent - 2) * fs->csize;
    return (fre_clust * fs->csize);
  }
  else
  {
    return 0;
  }
}






 void FS_manevr(void)
{
// u16 time_detect = 50;
  volatile u16 lines;

//  MX_FATFS_Init();

  if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_6)==GPIO_PIN_RESET)
    {
      card_present = 1;

      if ( BSP_SD_Init() == MSD_OK)
      {
       if(FATFS_LinkDriver(&SD_Driver, SDPath) == 0)
      {
        if(f_mount(&SDFatFs, (TCHAR const*)SDPath, 0) == FR_OK)
        {
          lines = k_StorageGetFree ();
          sprintf(filename,"0:/station.txt");
          res = f_open(&file, filename, FA_OPEN_EXISTING | FA_READ);
          if (res == FR_OK) {
            //f_read (&file, void* buff, UINT btr, UINT* br);
             // to fix
            for (lines = 0; (f_eof (&file) == 0); lines ++)
            {
               if (lines==26) break; // защита от большого количества записей на сд карте
              f_gets ((char *)sdssidNames[lines], sizeof (sdssidNames[lines]), &file);
            }

             // sprintf (str_temp,"% d строк в файле \r \n", lines);
          }
          else
              {
               sprintf((char *)str_temp,"Файл  на SD карте не обнаружен");
               GUI_DispStringHCenterAt(str_temp,440, 330);
                 HAL_Delay(3000);
              }
          f_mount(NULL, (TCHAR const*)"", 0);
        }
      }
      }
      else
      {
        sprintf((char *)str_temp,"Проблема SD карты");
               GUI_DispStringHCenterAt(str_temp,440, 330);
                 HAL_Delay(3000); 
        
      }
    }
  else
      {
        // sprintf (str_temp,"% d строк в файле \r \n", lines);
         sprintf((char *)str_temp,"SD карта не обнаружена");
         GUI_DispStringHCenterAt(str_temp,440, 330);
          HAL_Delay(3000); 
      }

    

     // GUI_SetFont(&GUI_FontVerdana42);
      GUI_DispStringAtCEOL    ( (char *)"", 0, 330);


}





uint8_t BSP_SD_IsDetected(void)
{
 volatile uint8_t status = SD_NOT_PRESENT;


  /* Check SD card detect pin */
  if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_6)==GPIO_PIN_RESET)
  {
    status = SD_PRESENT;
  }




  return status;
}

