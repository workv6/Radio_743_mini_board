

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dialog.h"
#include "messagebox.h"
//#include "k_rtc.h"
#include "k_log.h"
//#include "k_storage.h"
#include "k_module.h"
#include "main.h"
#include "k_res.c"
//#include "cpu_utils.h"
char obnov = 0;
extern uint8_t stations[50] [100];
extern uint8_t current_station;
//extern GUI_CONST_STORAGE GUI_BITMAP bmterm;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana45_rus;
extern GUI_CONST_STORAGE GUI_BITMAP bmbeh;
extern GUI_CONST_STORAGE GUI_BITMAP bmbffh;
extern GUI_CONST_STORAGE GUI_BITMAP bmbfh;
extern GUI_CONST_STORAGE GUI_BITMAP bmblh;
extern GUI_CONST_STORAGE GUI_BITMAP bmbmh;
extern GUI_CONST_STORAGE GUI_BITMAP bmbmmh;
extern char new_msg_meta;
extern char new_st;
extern char meta_string[];

 extern u8 battery_percent;
 extern u8 card_present;
 u8 sat_present = 0;
    uint8_t sec, min, hour, day, month;
 uint16_t year;
 extern u8 battery_low;
 extern const   uint8_t MonthNames[];
 extern const string WeekDayNames[];
 extern float humidity;
 extern float temperature;
 extern float pressure;

#define MSD_DISK_UNIT        1

extern GUI_CONST_STORAGE GUI_BITMAP bmsat;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontSegment762;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana23;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana32;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana42;
#define ID_TIMER_TIME                  (GUI_ID_USER + 0x00)
#define ID_BUTTON_BKGND                (GUI_ID_USER + 0x01)
#define ID_ICONVIEW_MENU               (GUI_ID_USER + 0x02)
#define ID_MENU_LOG                    (GUI_ID_USER + 0x03)
#define ID_MENU_EXIT                   (GUI_ID_USER + 0x05)
#define ID_FRAMEWIN_KERNELLOG         (GUI_ID_USER + 0x20)
#define ID_BUTTON_CANCEL_KERNELLOG    (GUI_ID_USER + 0x21)
#define ID_MULTIEDIT_KERNELLOG        (GUI_ID_USER + 0x22)
#define ID_BUTTON_CLEAR_KERNELLOG     (GUI_ID_USER + 0x23)


ICONVIEW_Handle hIcon = 0;


//static WM_HWIN  hPerformance = 0;
//static WM_HWIN  hProcess = 0;
static WM_HWIN  hLog = 0;
extern GUI_CONST_STORAGE GUI_BITMAP bmusb;
extern GUI_CONST_STORAGE GUI_BITMAP bmicon_term;
extern RTC_HandleTypeDef RtcHandle;

   // RTC_DateTypeDef sdatestructureget;
   // RTC_TimeTypeDef stimestructureget;


/* Array of menu items
static MENU_ITEM _aMenuItems[] =
{
  {"Kernel Log"         , ID_MENU_LOG,  0},     // меню кнопки терминала, сюда можно добавить вс€чины, только нужно придумать
  {0                    , 0           ,  MENU_IF_SEPARATOR},
  {"Cancel"             , ID_MENU_EXIT, 0},
};

*/

 /*
static const GUI_WIDGET_CREATE_INFO _aKernelLogDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "Kernel Log", ID_FRAMEWIN_KERNELLOG, 0, 20, 280, 260, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Exit", ID_BUTTON_CANCEL_KERNELLOG, 5, 210, 80, 40, 0, 0x0, 0 }, // button
   { BUTTON_CreateIndirect, "Clear", ID_BUTTON_CLEAR_KERNELLOG, 185, 210, 80, 40, 0, 0x0, 0 }, // button
  { MULTIEDIT_CreateIndirect, "Multiedit", ID_MULTIEDIT_KERNELLOG, 1, 1, 270, 200, 0, 0x0, 0 },
};
  */

/**
 обновим окно терминала
  */
void k_UpdateLog(char *Msg)
{
  WM_HWIN hItem;

  if(hLog != 0)
  {
    hItem = WM_GetDialogItem(hLog, ID_MULTIEDIT_KERNELLOG);
    MULTIEDIT_SetText(hItem, Msg);
    MULTIEDIT_SetCursorOffset(hItem, LOG_IN_ptr);
  }
}
/**
терминал. в будущем можно добавить функций
  */
static void _cbKernelLogDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:

    hItem = pMsg->hWin;
    FRAMEWIN_SetTitleVis(hItem, 0);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_MULTIEDIT_KERNELLOG);
    MULTIEDIT_SetFont(hItem, GUI_FONT_8_1);
    MULTIEDIT_SetTextColor(hItem, MULTIEDIT_CI_READONLY, GUI_GREEN);
    MULTIEDIT_SetBkColor(hItem, MULTIEDIT_CI_READONLY, GUI_DARKGRAY);
    MULTIEDIT_SetReadOnly(hItem, 1);
    MULTIEDIT_SetText(hItem, (char *)pLOG_CacheBuffer);
    MULTIEDIT_SetCursorOffset(hItem, LOG_IN_ptr);
    MULTIEDIT_SetAutoScrollV(hItem, 1);
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_CANCEL_KERNELLOG: /* нажали отмена, и закроем окно */
      switch(NCode) {
      case WM_NOTIFICATION_RELEASED:
        GUI_EndDialog(pMsg->hWin, 0);         // кнопку отпустили, окошко закрываем
        hLog = 0;
         printf("Terminal close \r\n");
        break;
      }
      break;

     case ID_BUTTON_CLEAR_KERNELLOG: /* нажали clear, и clear окно */
      switch(NCode) {
      case WM_NOTIFICATION_RELEASED:
      //  GUI_EndDialog(pMsg->hWin, 0);         // кнопку отпустили, окошко закрываем
      //  hLog = 0;
        k_LogInit();
         printf("Terminal clear \r\n");
        break;
      }
      break;

    case ID_MULTIEDIT_KERNELLOG: /* Notifications sent by 'Multiedit' */
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        break;
      }
      break;
    }
    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}



static void _AddMenuItem(MENU_Handle hMenu, MENU_Handle hSubmenu, const char* pText, U16 Id, U16 Flags)
{
  MENU_ITEM_DATA Item;
  Item.pText    = pText;
  Item.hSubmenu = hSubmenu;
  Item.Flags    = Flags;
  Item.Id       = Id;
  MENU_AddItem(hMenu, &Item);
}



/**
  * @brief  Callback routine of desktop window.
  * @param  pMsg: pointer to data structure of type WM_MESSAGE
  * @retval None
  */
static void _cbBk(WM_MESSAGE * pMsg) {

  MENU_MSG_DATA* pData;
  uint32_t NCode, Id;
  static uint8_t sel = 0;

  switch (pMsg->MsgId)
  {



  case WM_PAINT:
     GUI_SetBkColor(0xaec8d7);
    //GUI_SetBkColor(0x8dbbd3 );
    GUI_Clear();
    //GUI_SetColor(0x8dbbd3 );
   // GUI_FillRect(0, 140, 850 ,300);
    //GUI_SetFont(&GUI_FontSegment762);
    GUI_SetFont(&GUI_FontVerdana42);
   GUI_SetColor(GUI_BLACK);
   //GUI_DispStringHCenterAt("Cоедин€юсь с WIFI",440,80);
   // GUI_DispStringAt("123456789",10,200);
   // if(hIcon)
   // {
   //   WM_BringToBottom(hIcon);
   // }
    break;

  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;

    switch (NCode)
    {

    case WM_NOTIFICATION_CHILD_DELETED:

      break;

    case WM_NOTIFICATION_CLICKED:

      break;

    case WM_NOTIFICATION_RELEASED:


      break;

    default:
      break;
    }
    break;
   default:
    WM_DefaultProc(pMsg);
  }
}


static void _cbTray(WM_MESSAGE * pMsg) {                   // обработка тре€ и всего что в нем должно происходить
  int xSize, ySize;
  static uint8_t TempStr[50];
  static WM_HTIMER hTimerTime;
   u8 str[20];



  WM_HWIN hWin;

  hWin = pMsg->hWin;
  switch (pMsg->MsgId)
  {
  case WM_CREATE:
    hTimerTime = WM_CreateTimer(hWin, ID_TIMER_TIME, 10000, 0);          // таймер дл€ обновлени€ всей хрени

    break;

  case WM_DELETE:
    WM_DeleteTimer(hTimerTime);

    break;

  case WM_TIMER:
    if( WM_GetTimerId(pMsg->Data.v) == ID_TIMER_TIME)
    {


      WM_InvalidateWindow(hWin);                                          // обновим окно

      WM_RestartTimer(pMsg->Data.v, 10000);                       // ѕерезапустим таймер
    }

    break;

  case WM_PAINT:// перерисовка основного верхнего окошка
    xSize = WM_GetWindowSizeX(hWin);
    ySize = WM_GetWindowSizeY(hWin);
   if (obnov==0)
       {
          obnov = 1;
    /* Draw background */
   // GUI_SetColor(0xaec8d7);

    //GUI_FillRect(0, 0, xSize , ySize);
       }





    // GUI_SetFont(&GUI_FontVerdana23);
    //sprintf((char *)str,"%d  ",battery_percent);
   // GUI_DispStringAt((char *)str, 5, 30);
   /*
    GUI_SetFont(&GUI_FontVerdana32);
    if (temperature>0) sprintf(TempStr,"+"); else sprintf(TempStr,"");

   */
    //sprintf((char *)TempStr,"%2.0f mm",pressure/133.3333);

   // GUI_DispStringAt((char *)TempStr, 700, 35);






    break;

  default:
    WM_DefaultProc(pMsg);
  }
}

/**
  перерисовка кнопки

static void _OnPaint(BUTTON_Handle hObj) {
  int Index;

  GUI_RECT Rect;
  Index = (WIDGET_GetState(hObj) & BUTTON_STATE_PRESSED) ? 1 : 0;



  WM_GetClientRect(&Rect);
  //GUI_DrawBitmap(&bmterm , 0, 0);//bmicon_term
}
       */
/**
  * @brief  callback for background button
  * @param  pMsg: pointer to data structure of type WM_MESSAGE
  * @retval None

static void _cbButton(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
    case WM_PAINT:
      _OnPaint(pMsg->hWin);      // перерисовка кнопки
      break;
    default:

      BUTTON_Callback(pMsg);      // функци€ обработчика нажати€ на кнопку
      break;
  }
}

   */
void k_InitMenu(void)
{

  WM_HWIN  hItem;
  uint8_t i = 0;


  WM_SetCallback(WM_HBKWIN, _cbBk);

  WM_CreateWindowAsChild(0,                                                             // верхнее окошко трей
                         0,
                         LCD_GetXSize(),
                         70,                                                  // “олщина верхнего окошка
                         WM_HBKWIN,
                         WM_CF_SHOW  ,
                         _cbTray,                                        // ќбработчик тре€ и всего что там творитс€
                         0);

}



