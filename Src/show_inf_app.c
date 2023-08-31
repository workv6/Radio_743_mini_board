#include "main.h"
#include "DIALOG.h"
#include "k_module.h"




extern  u8 button_back_press;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana42;
extern char ip_string[];
extern char ssid_string[];
extern uint8_t str_z[50];
extern char rssi_string[];
extern char rssi;
extern char y_buf;
extern u8 buttons;
extern char string_buf0[];
extern char string_buf1[];
 //extern uint8_t ee_stations[5][100];

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0  (GUI_ID_USER + 0x00)





static const GUI_WIDGET_CREATE_INFO _ainfCreate[] = {
  { FRAMEWIN_CreateIndirect, "����������", ID_FRAMEWIN_0, 85, 145, 645, 270, 0, 0x0, 0 },
  {TEXT_CreateIndirect, str_z, ID_TEXT_0, 0, 0, 640, 44, 0, 0x0, 0 },
  {TEXT_CreateIndirect, str_z, ID_TEXT_1, 0, 44, 640, 44, 0, 0x0, 0 },
  {TEXT_CreateIndirect, str_z, ID_TEXT_2, 0, 88, 640, 44, 0, 0x0, 0 },
  {TEXT_CreateIndirect, str_z, ID_TEXT_3, 0, 132, 640, 44, 0, 0x0, 0 },
  {TEXT_CreateIndirect, str_z, ID_TEXT_4, 0, 176, 640, 44, 0, 0x0, 0 }

};




/*********************************************************************
*
*       _cbDialog
*/
static void _cbinf(WM_MESSAGE * pMsg) {
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


                case WM_TIMER: // ������� �������
                    sprintf(tbuf,"wifi.rssi\r\n");
                    printf2(tbuf,11);

                       if (rssi>70) sprintf(temp_string,"������");
                       else if (rssi>60) sprintf(temp_string,"������");
                       else if (rssi>50) sprintf(temp_string,"�������");
                       else sprintf(temp_string,"��������");




                       hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
                       TEXT_SetFont(hItem, &GUI_FontVerdana42);

                       sprintf(tbuf,"������� ������� %s",temp_string);
                       TEXT_SetText(hItem,tbuf);


                    WM_RestartTimer(pMsg->Data.v, 1000);
                break;





  case WM_INIT_DIALOG:
    //
    // Initialization of 'Framewin'
    //
    hItem = pMsg->hWin;
    hTimer =  WM_CreateTimer ( WM_GetClientWindow ( hItem ), 0, 1000, 0 );
    FRAMEWIN_SetTitleHeight(hItem, 45);
    FRAMEWIN_SetFont       (hItem, &GUI_FontVerdana42);
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER);
    FRAMEWIN_SetText       (hItem, " ���������� ");



                        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
                       TEXT_SetFont(hItem, &GUI_FontVerdana42);
                       //TEXT_SetBkColor(hItem, 0xaec8d7);
                       sprintf(tbuf,"���� WIFI: %s",ssid_string);
                       TEXT_SetText(hItem,tbuf);

                       hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
                       //TEXT_SetBkColor(hItem, 0xaec8d7);
                       TEXT_SetFont(hItem, &GUI_FontVerdana42);
                       sprintf(tbuf,"%s",ip_string);
                       TEXT_SetText(hItem,tbuf);



                       if (rssi>70) sprintf(temp_string,"������");
                       else if (rssi>60) sprintf(temp_string,"������");
                       else if (rssi>50) sprintf(temp_string,"�������");
                       else sprintf(temp_string,"��������");
                       hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
                       TEXT_SetFont(hItem, &GUI_FontVerdana42);

                       sprintf(tbuf,"������� ������� %s",temp_string);
                       TEXT_SetText(hItem,tbuf);
                       /**
                       hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
                       TEXT_SetFont(hItem, &GUI_FontVerdana42);
                       TEXT_SetBkColor(hItem, 0xaec8d7);
                       //sprintf(tbuf," 4 %s",ee_stations[3]);
                       TEXT_SetText(hItem,tbuf);

                       hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);
                       TEXT_SetFont(hItem, &GUI_FontVerdana42);
                       TEXT_SetBkColor(hItem, 0xaec8d7);
                       //sprintf(tbuf," 5 %s",ee_stations[4]);
                       TEXT_SetText(hItem,tbuf);
                        */




    break;

  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;


  case WM_PAINT:
    xSize = WM_GetWindowSizeX(pMsg->hWin);
    ySize = WM_GetWindowSizeY(pMsg->hWin);
    GUI_SetColor(0xaec8d7);
    //GUI_Clear();
   // GUI_FillRect(0, 0, xSize-1 , ySize-1);

    //GUI_DrawGradientV(0, 0, xSize - 1, ySize - 1, GUI_GRAY, GUI_CYAN);
   break;

     case WM_DELETE:


     break;

  default:
    WM_DefaultProc(pMsg);
    break;
  }
  }



void chk_butt_light(void)
    {
       if (buttons ==1)
           {
             buttons = 0;
              if (y_buf == 0)
                {
                  if (strncmp((const char *)string_buf0,"k12 1",5) == 0)button_back_press = 1;
                  y_buf = 1;
                }
            else
                {
                  if (strncmp((const char *)string_buf1,"k12 1",5) == 0) button_back_press = 1;
                  y_buf = 0;
                }
           }
    }





 void InfFramewin(void) {
     //WM_HWIN         hBkWheel,hBkWin;
     WM_HWIN hWin;


 hWin = GUI_CreateDialogBox(_ainfCreate, GUI_COUNTOF(_ainfCreate), _cbinf, WM_HBKWIN, 0, 0);
  WM_SetStayOnTop(hWin, 1);
 while (!button_back_press)
     {
      chk_butt_light();
      osDelay(100);
     }
      button_back_press = 0;

         WM_DeleteWindow(hWin);


}

