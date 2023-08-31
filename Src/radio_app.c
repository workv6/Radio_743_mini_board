#include "main.h"
#include "DIALOG.h"
#include "k_module.h"



extern long time_to_sleep;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontSegment762;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana42;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana32;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana16;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana62;
extern GUI_CONST_STORAGE GUI_BITMAP bmicon_radio_invert;
extern GUI_CONST_STORAGE GUI_BITMAP bmmute;
extern GUI_CONST_STORAGE GUI_BITMAP bmmute_empty;
void CreateRadioFramewin(uint16_t xpos, uint16_t ypos);
extern void radio_set_freq(unsigned char b, u16 fr);
extern uint8_t station_pressed;
extern char new_msg_meta;

extern char meta_string[];
extern uint8_t stations[80] [100];
extern char p_dwn,p_up;
extern char saved_station;
extern char mute_half;
extern int fade_counter;
 char str_fl[50];
uint16_t     freq;
int page = 0;
extern char but_mute;
extern uint8_t current_station;
extern uint8_t stopped_err;
extern uint8_t err_no_play;
extern uint8_t check_start_play;
extern uint16_t ee_station,ee_volume;
extern uint8_t set_volume;
extern uint8_t next_st,prev_st,vol_plus,vol_minus;
extern uint8_t play_ok;
extern uint8_t next_enable;
extern uint16_t tim_b1,tim_b2,tim_b3,tim_b4,tim_b5;
extern uint8_t ee1,ee2,ee3,ee4,ee5;
u8 st_refresh_name;
extern char prev_button;

extern u8 b_up,b_down,b_left,b_right,b_down,b_ok;
extern u8 izb[];
extern char new_st;

u16 button_pointer;
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0  (GUI_ID_USER + 0x00)



#define ID_TEXT_0           (GUI_ID_USER + 0x06)
#define ID_TEXT_1           (GUI_ID_USER + 0x07)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, " ", ID_FRAMEWIN_0, 5, 71, 635, 405, 0, 0x0, 0 },


 // { BUTTON_CreateIndirect,   "st1", GUI_ID_BUTTON1,    5,  5,    310,  80 },
 // { BUTTON_CreateIndirect,   "st2", GUI_ID_BUTTON2,    5,  80,   310,  80 },
 // { BUTTON_CreateIndirect,   "st3", GUI_ID_BUTTON3,    5,  155,  310,  80 },
 // { BUTTON_CreateIndirect,   "st4", GUI_ID_BUTTON4,    5,  230,  310,  80 },
 // { BUTTON_CreateIndirect,   "st5", GUI_ID_BUTTON5,    5,  305,  310,  80 },
 // { BUTTON_CreateIndirect,   "st6", GUI_ID_BUTTON6,    310,5,   310,  80 },
 // { BUTTON_CreateIndirect,   "st7", GUI_ID_BUTTON7,    310,80,  310,  80 },
 // { BUTTON_CreateIndirect,   "st8", GUI_ID_BUTTON8,    310,155, 310,  80 },
 // { BUTTON_CreateIndirect,   "st9", GUI_ID_BUTTON9,    310,230, 310,  80 },
 // { BUTTON_CreateIndirect,   "st10", GUI_ID_BUTTON0,   310,305, 310,  80 }
 // { IMAGE_CreateIndirect, "Image", GUI_ID_IMAGE0, 730 , 160, 90, 112, WM_CF_BGND, IMAGE_CF_AUTOSIZE, 0 },

};

static int _Pressed;


 static void _OnPaint(BUTTON_Handle hObj) {
  int Index;
  char ac[50];   // буфер для
  GUI_RECT Rect;

  Index = (WIDGET_GetState(hObj) & BUTTON_STATE_PRESSED) ? 1 : 0;
  WM_GetClientRect(&Rect);
    if (Index)
      {
       GUI_SetColor(0xa1ccc3);
       GUI_SetBkColor(0xa1ccc3);
      }
    else
      {
       GUI_SetColor(0xc8dae1);
       GUI_SetBkColor(0xc8dae1);
      }
  GUI_FillRect ( 5,  8,   310,  79);
  GUI_SetColor(0x000000);  // черная кромка
  GUI_DrawRect  (5,  5,   309,  79);


  GUI_SetFont(BUTTON_GetFont(hObj));
  BUTTON_GetText(hObj, ac, sizeof(ac));
  //if (_Pressed) {
  //  strcpy(ac + strlen(ac), "\npressed");
  //}
  GUI_DispStringInRect(ac, &Rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
}




/*

*/


static void _cbButton(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
    case WM_PAINT:
      _OnPaint(pMsg->hWin);
      break;
    default:
      BUTTON_Callback(pMsg); // это нужно
      break;
  }
  if (pMsg->MsgId == WM_TOUCH) {
    if (BUTTON_IsPressed(pMsg->hWin)) {
      if (!_Pressed) {
        _Pressed = 1;
      }
    } else {
      _Pressed = 0;
    }
  }
}

const uint16_t buttons_id[10] = {GUI_ID_BUTTON1,GUI_ID_BUTTON2,GUI_ID_BUTTON3,GUI_ID_BUTTON4,GUI_ID_BUTTON5,GUI_ID_BUTTON6,GUI_ID_BUTTON7,GUI_ID_BUTTON8,GUI_ID_BUTTON9,GUI_ID_BUTTON0};

/*********************************************************************
*
*       _cbDialog
*/
static void _cbRadioDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  WM_HTIMER hTimer;
  int     NCode;
  int     Id;
  int     LineHeight;
  int     xSize;
  int     ySize;
 uint16_t temp_volume;
  u8 tbuf[60];
 int n;
 __IO uint8_t xn;

 BUTTON_Handle hButton;

  switch (pMsg->MsgId) {


              case WM_TIMER: // событие таймера




                   WM_RestartTimer(pMsg->Data.v, 100);
                break;





  case WM_INIT_DIALOG:

    hItem = pMsg->hWin;
    hTimer =  WM_CreateTimer ( WM_GetClientWindow ( hItem ), 0, 1000, 0 );
    FRAMEWIN_SetTitleHeight(hItem, 4);

   //-------------------------------------------------------------------------------- Дадим радио старт на проигрывание станции --------------------------------------
   fade_counter = 60000;
   // station_set(ee_station);
   // button_pointer = ee_station;

    new_st = 1;


    break;

  case WM_PAINT:
    xSize = WM_GetWindowSizeX(pMsg->hWin);
    ySize = WM_GetWindowSizeY(pMsg->hWin);
    GUI_SetColor(0xaec8d7);

    GUI_FillRect(0, 0, xSize-1 , ySize-1);

    //GUI_DrawGradientV(0, 0, xSize - 1, ySize - 1, GUI_GRAY, GUI_CYAN);
   break;

     case WM_DELETE:

     printf("radio_off \r\n");
     break;

  default:
  //  WM_DefaultProc(pMsg);
    break;
  }
  }







 void CreateRadioFramewin(uint16_t xpos, uint16_t ypos) {
     WM_HWIN         hBkWheel,hBkWin;
     WM_HWIN hWin;





 hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbRadioDialog, WM_HBKWIN, 0, 0);



}

