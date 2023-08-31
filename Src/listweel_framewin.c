#include "main.h"
#include "DIALOG.h"
#include "k_module.h"
 #include "cmsis_os.h"



extern  u8 button_back_press;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana42;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana32;
extern char ip_string[];
extern char ssid_string[];
extern uint8_t str_z[50];
extern char rssi_string[];
extern char rssi;

extern u8 st_refresh_name;
extern char next_station;
extern char saved_station;
extern uint8_t current_station;
extern uint16_t ee_station;
extern uint8_t next_st,prev_st,vol_plus,vol_minus;;
extern uint8_t play_ok;
extern  char str_fl[];

extern uint8_t stations[50] [100];
extern uint8_t current_station;
extern uint8_t stopped_err;
//extern uint8_t err_no_play;
extern uint8_t check_start_play;
extern uint16_t ee_station,ee_volume;
extern uint8_t set_volume;
extern uint8_t station_pressed;
extern uint8_t play_ok;
extern uint8_t next_enable;


extern u8 buttons;
u8 exit_enable = 0;
int zz;
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0  (GUI_ID_USER + 0x00)
#define ID_LISTWHEEL_0  (GUI_ID_USER + 0x01)




static const GUI_WIDGET_CREATE_INFO _listweelCreate[] = {
  {FRAMEWIN_CreateIndirect, " ", ID_FRAMEWIN_0, 5, 65, 845, 330, 0, 0x0, 0 },
  {LISTWHEEL_CreateIndirect, "Listwheel", ID_LISTWHEEL_0, 1, 1, 834, 290, 0, 0x0, 0 },
  //{TEXT_CreateIndirect, str_z, ID_TEXT_1, 0, 44, 640, 44, 0, 0x0, 0 },
  //{TEXT_CreateIndirect, str_z, ID_TEXT_2, 0, 88, 640, 44, 0, 0x0, 0 },
  //{TEXT_CreateIndirect, str_z, ID_TEXT_3, 0, 132, 640, 44, 0, 0x0, 0 },
  //{TEXT_CreateIndirect, str_z, ID_TEXT_4, 0, 176, 640, 44, 0, 0x0, 0 }

};



static int _OwnerDraw(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo) {
switch (pDrawItemInfo->Cmd) {
case WIDGET_DRAW_OVERLAY:
  GUI_SetColor(GUI_BROWN);
  GUI_DrawRect(0,0,833,275);
  GUI_SetColor(GUI_BLACK);
  GUI_DrawHLine(132, 0, 833);
  GUI_DrawHLine(177, 0, 833);
break;
default:
return LISTWHEEL_OwnerDraw(pDrawItemInfo);
}
return 0;
}

/*********************************************************************
*
*       _cbDialog
*/
static void _listweelinf(WM_MESSAGE * pMsg) {
   char temp_string[20];
  WM_HWIN hItem;
  WM_HTIMER hTimer;
  int     NCode;
  int     Id;
  int     LineHeight;
  int     xSize;
  int     ySize;
  int temp_volume;
  u8 tbuf[100];
 char n;
 __IO uint8_t xn;
 int z;


  switch (pMsg->MsgId) {


                case WM_TIMER: // событие таймера




                 if (next_station==1)
                  {
                     next_station = 0;
                       hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_0);
                      z = LISTWHEEL_GetPos(hItem);

                      if (z<(saved_station-1))
                          {
                           z++;
                          }
                      else
                          {
                           z=0;
                          }
                      zz = z;
                   //   current_station = z;
                     LISTWHEEL_MoveToPos(hItem, z);              //  подвинем колесо
                     LISTWHEEL_SetSel(hItem, z);                 // выберем
                   //  ee_station = z;
                   //  set_eeprom_backup();
                   //  LISTWHEEL_GetItemText(hItem, z,str_fl, 50);
                   //  hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
                    // TEXT_SetFont(hItem, &GUI_FontVerdana42);
                    // TEXT_SetText(hItem, str_fl);

                    // hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
                    // TEXT_SetFont(hItem, &GUI_FontVerdana32);
                    // sprintf(tbuf," - ");
                    // TEXT_SetText(hItem,tbuf);
                   //  next_enable = 1;
                  }

                if (prev_st==1)
                  {
                    prev_st = 0;
                       hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_0);
                      z = LISTWHEEL_GetPos(hItem);

                      if (z>0) //(saved_station-1))
                          {
                           z--;
                            //zz = z;
                          // sprintf(tbuf,"cli.prev\r\n");
                          // printf2(tbuf,10);
                          // play_ok = 0;
                          // stopped_err = 0;
                          // check_start_play = 1;
                          }
                      else
                          {
                           z=saved_station-1;

                           //sprintf(tbuf,"cli.play(\"%d\")\r\n\0",z);
                           //xn =  strlen(tbuf);
                           //printf2(tbuf,xn);
                           //play_ok = 0;
                           //stopped_err = 0;
                           //check_start_play = 1;
                          }
                          zz = z;
                    // current_station = z;
                     LISTWHEEL_MoveToPos(hItem, z);              //  подвинем колесо
                     LISTWHEEL_SetSel(hItem, z);                 // выберем
                    // ee_station = z;
                    // set_eeprom_backup();
                    // LISTWHEEL_GetItemText(hItem, z,str_fl, 50);
                    // hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
                    // TEXT_SetFont(hItem, &GUI_FontVerdana42);
                    // TEXT_SetText(hItem, str_fl);

                    // hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
                    // TEXT_SetFont(hItem, &GUI_FontVerdana32);
                    // sprintf(tbuf," - ");
                    // TEXT_SetText(hItem,tbuf);

                  }



                    WM_RestartTimer(pMsg->Data.v, 100);
                break;





  case WM_INIT_DIALOG:
    //
    // Initialization of 'Framewin'
    //
    hItem = pMsg->hWin;
    hTimer =  WM_CreateTimer ( WM_GetClientWindow ( hItem ), 0, 100, 0 );
    FRAMEWIN_SetTitleHeight(hItem, 45);
    FRAMEWIN_SetFont       (hItem, &GUI_FontVerdana42);
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER);
    FRAMEWIN_SetText       (hItem, " Список станций ");



                      LineHeight    = 45;

   hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_0);
   LISTWHEEL_SetFont(hItem, &GUI_FontVerdana42);
   LISTWHEEL_SetLineHeight(hItem, LineHeight);
   LISTWHEEL_SetSnapPosition(hItem, (310 - LineHeight) / 2);
   LISTWHEEL_SetLBorder(hItem, 10);
   LISTWHEEL_SetOwnerDraw(hItem, _OwnerDraw);
   LISTWHEEL_SetBkColor(hItem, LISTWHEEL_CI_UNSEL, GUI_LIGHTGRAY);
   LISTWHEEL_SetBkColor(hItem, LISTWHEEL_CI_SEL, 0xa1ccc2); //GUI_LIGHTBLUE);
   LISTWHEEL_SetTextAlign   (hItem, GUI_TA_HCENTER);
   for (n=0;n<50;n++)
            {
             if (stations[n][0]!=0)
                   {
                     LISTWHEEL_AddString(hItem,stations[n]);
                   }
            }

                     LISTWHEEL_MoveToPos(hItem, ee_station);        //  подвинем колесо
                     LISTWHEEL_SetSel(hItem, ee_station);                 // выберем








    break;

  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
         switch(Id) {
                    case ID_LISTWHEEL_0: // дотронулись до колеса
                   switch(NCode)
                   {
                    case WM_NOTIFICATION_CLICKED:
                    break;
                    case WM_NOTIFICATION_RELEASED:
                    break;
                  case WM_NOTIFICATION_SEL_CHANGED:
                  //   time_to_sleep = EEData->time_to_sleep*1000;
                  hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_0);
                  z = LISTWHEEL_GetPos(hItem);
                   zz = z;
                  LISTWHEEL_SetSel(hItem, z);
                 // current_station = z;
                   //sprintf(tbuf,"cli.play(\"%d\")\r\n\0",z);
                   //xn =  strlen(tbuf);
                   //printf2(tbuf,xn);
                   //play_ok = 0;
                   //stopped_err = 0;
                  // check_start_play = 1; // нужно ждать от радио play_ok, иначе нихрена не играет и надо сбрасывать....
                   /*
                   LISTWHEEL_GetItemText(hItem, z,str_fl, 50);
                   hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
                   TEXT_SetFont(hItem, &GUI_FontVerdana42);
                   TEXT_SetText(hItem, str_fl);

                   hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
                   TEXT_SetFont(hItem, &GUI_FontVerdana32);
                   sprintf(tbuf," - ");
                   TEXT_SetText(hItem,tbuf);
                   ee_station = z;
                   set_eeprom_backup();*/
                    break;
                   }
                 break;


  case WM_PAINT:
    xSize = WM_GetWindowSizeX(pMsg->hWin);
    ySize = WM_GetWindowSizeY(pMsg->hWin);
    GUI_SetColor(0xaec8d7);
    //GUI_Clear();
    GUI_FillRect(0, 0, xSize-1 , ySize-1);

    //GUI_DrawGradientV(0, 0, xSize - 1, ySize - 1, GUI_GRAY, GUI_CYAN);
   break;

     case WM_DELETE:


     break;

  default:
    WM_DefaultProc(pMsg);
    break;
  }
  }
}















 void listweelFramewin(void) {
    u8 tbuf[100];
    char xn;
     //WM_HWIN         hBkWheel,hBkWin;
     WM_HWIN hWin;


 hWin = GUI_CreateDialogBox(_listweelCreate, GUI_COUNTOF(_listweelCreate), _listweelinf, WM_HBKWIN, 0, 0);
 WM_SetStayOnTop(hWin, 1);
 while (!button_back_press)
     {
       if ( button_up_press)
          {

             prev_st = 1;
             while(button_up_press)
             {
              HAL_Delay(5);
             }
          }

    if ( button_down_press)
          {
             next_station = 1;
             while(button_down_press)
             {
              HAL_Delay(5);
             }
          }

        if ( button_left_press)
          {
             vol_minus = 1;
          }
        if ( button_right_press)
          {
             vol_plus = 1;
          }


              if ( button_ok_press)
          {

             station_pressed =  zz;
             sprintf(tbuf,"cli.play(\"%d\")\r\n\0",zz);
                       xn =  strlen(tbuf);
                       printf2(tbuf,xn);
                       play_ok = 0;
                       stopped_err = 0;
                       check_start_play = 1;
             break;
          }
     }


         WM_DeleteWindow(hWin);


}

