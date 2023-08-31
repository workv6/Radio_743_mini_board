/* Includes ------------------------------------------------------------------*/
#include "main.h"

#include "sd.h"
#include "ff_gen_drv.h"
#include "sd_diskio.h"
#include "cmsis_os.h"
#include "GUI.h"
#include "WM.h"

#include "k_module.h"
#include "k_mem.h"
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana45_rus;

extern struct _ts_event ts_event;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana42;
extern GUI_CONST_STORAGE GUI_BITMAP bmicon_mafon;
extern  uint16_t ee_station,ee_volume;
static uint8_t TempStr[50];
extern char temper_show_flag;
 int z=499;
  extern float temperature;
  extern RTC_HandleTypeDef RtcHandle;
  extern float humidity;
   extern u8 battery_percent;
      extern unsigned char button_press[];
      extern unsigned char button_release[];
      extern char doll_string[];
      extern char eur_string[];

      long temp_bckup;
 void GUIThread(void const * argument)
     {
        char x,t=0;

               /* Initialize GUI */
       GUI_Init();
       LCD_Scan_Dir(5);
       //LCD_WR_REG(0x36);   //Memory Access Control
       //LCD_WR_DATA(0xa0); //       Развернем экран
       GUI_Clear();


        GUI_SetBkColor( 0xb4c9f4);
        GUI_Clear();

        k_MemInit();
        k_ModuleInit();




        GUI_Exec();

        //GUI_SetColor(GUI_BLACK);
        //GUI_SetTextMode(GUI_TM_TRANS);

        //sprintf((char *)TempStr,"%2.1f%%",humidity);
        // GUI_DrawGradientV(290, 410, 560 , 479, 0xb9cff6, 0x85aaf1); //GUI_DispStringAt((char *)"        ", 370, 420);
        // GUI_DispStringAt((char *)TempStr, 370, 420);

       // GUI_SetTextMode(GUI_TEXTMODE_NORMAL);

        while(1) {
           GUI_Exec(); /* Do the background work ... Update windows etc.) */

           GUI_X_Delay(20);
           HAL_Delay(10);

         /*
           if (temper_show_flag)
               {
                  temper_show_flag =0;
                  GUI_SetColor(GUI_BLACK);
                  GUI_SetTextMode(GUI_TM_TRANS);
                  GUI_SetFont(&GUI_FontVerdana45_rus);
                  sprintf((char *)TempStr,"%2.1f°",temperature);
                  GUI_DrawGradientV(110, 410, 280 , 479, 0xb9cff6, 0x85aaf1); // GUI_DispStringAt((char *)"        ", 120, 420);
                  GUI_DispStringAt((char *)TempStr, 120, 420);
                  sprintf((char *)TempStr,"%2.1f%%",humidity);
                  GUI_DrawGradientV(290, 410, 560 , 479, 0xb9cff6, 0x85aaf1); //GUI_DispStringAt((char *)"        ", 370, 420);
                  GUI_DispStringAt((char *)TempStr, 370, 420);

                  baterry_show();


                  if (show_valuta)     //to fix
                      {
                         show_valuta =0;

                          GUI_SetFont(&GUI_FontVerdana45_rus);
                          for(x=0;x<6;x++)
                          {
                           TempStr[x] = doll_string[x];
                          } // сохраним доллар в памяти
                          temp_bckup = (uint32_t)(TempStr[1]<<24 | TempStr[2]<<16 | TempStr[4]<<8 | TempStr[5]);
                          HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR13,temp_bckup );


                          GUI_DrawGradientV(580, 410, 735 , 479, 0xb9cff6, 0x85aaf1);
                          TempStr[x] = 0;
                          GUI_DispStringAt((char *)"$", 585, 405);
                          GUI_DispStringAt((char *)TempStr, 620, 405);
                          for(x=15;x<20;x++)
                          {
                            TempStr[t] = doll_string[x] ;
                            t++;
                          }  // сохраним евро в памяти
                          temp_bckup = (uint32_t)(TempStr[0]<<24 | TempStr[1]<<16 | TempStr[3]<<8 | TempStr[4]);
                          HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR14,temp_bckup);
                          TempStr[t] =0;
                          GUI_DispCharAt (0x88, 585, 440);
                          GUI_DispStringAt((char *)TempStr, 620, 440);
                      }

                  GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
               }

              */

        }

     }