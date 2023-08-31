#include "main.h"
#include "DIALOG.h"
#include "k_module.h"





extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana42;

uint8_t str_z[50];
 extern uint8_t ee_stations[5][100];
 extern  u8 button_back_press;
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0  (GUI_ID_USER + 0x00)





static const GUI_WIDGET_CREATE_INFO _aizbCreate[] = {
  { FRAMEWIN_CreateIndirect, "Избранное", ID_FRAMEWIN_0, 85, 145, 645, 270, 0, 0x0, 0 },
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
static void _cbizb(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  WM_HTIMER hTimer;
  int     NCode;
  int     Id;
  int     LineHeight;
  int     xSize;
  int     ySize;
  int temp_volume;
  u8 tbuf[30];
 char n;
 __IO uint8_t xn;
 int z;


  switch (pMsg->MsgId) {


                case WM_TIMER: // событие таймера

                  if (button_izb_press)

                   WM_RestartTimer(pMsg->Data.v, 100);
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
    FRAMEWIN_SetText       (hItem, " Избранное ");





                       hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
                       TEXT_SetBkColor(hItem, 0xaec8d7);
                       TEXT_SetFont(hItem, &GUI_FontVerdana42);
                       sprintf(tbuf," 1 %s",ee_stations[0]);
                       TEXT_SetText(hItem,tbuf);

                       hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
                       TEXT_SetFont(hItem, &GUI_FontVerdana42);
                       TEXT_SetBkColor(hItem, 0xaec8d7);
                       sprintf(tbuf," 2 %s",ee_stations[1]);
                       TEXT_SetText(hItem,tbuf);

                       hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
                       TEXT_SetFont(hItem, &GUI_FontVerdana42);
                       TEXT_SetBkColor(hItem, 0xaec8d7);
                       sprintf(tbuf," 3 %s",ee_stations[2]);
                       TEXT_SetText(hItem,tbuf);

                       hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
                       TEXT_SetFont(hItem, &GUI_FontVerdana42);
                       TEXT_SetBkColor(hItem, 0xaec8d7);
                       sprintf(tbuf," 4 %s",ee_stations[3]);
                       TEXT_SetText(hItem,tbuf);

                       hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);
                       TEXT_SetFont(hItem, &GUI_FontVerdana42);
                       TEXT_SetBkColor(hItem, 0xaec8d7);
                       sprintf(tbuf," 5 %s",ee_stations[4]);
                       TEXT_SetText(hItem,tbuf);





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







 void IzbFramewin(void) {
     //WM_HWIN         hBkWheel,hBkWin;
     WM_HWIN hWin;


 hWin = GUI_CreateDialogBox(_aizbCreate, GUI_COUNTOF(_aizbCreate), _cbizb, WM_HBKWIN, 0, 0);
 WM_SetStayOnTop(hWin, 1);
  while (!button_back_press)
     {
      osDelay(100);
     }
 osDelay(100);
 WM_DeleteWindow(hWin);

}

