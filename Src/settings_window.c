#include "main.h"
#include "DIALOG.h"
#include "k_module.h"


extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana23;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontVerdana16;
extern GUI_CONST_STORAGE GUI_BITMAP bmicon_settings;
void CreateSettings(WM_HWIN hWin, uint16_t xpos, uint16_t ypos);


uint16_t ee_time_from_sat,ee_bright,ee_volume,ee_utc,ee_sound_onoff;
uint16_t  temp_time_from_sat , temp_bright , temp_volume , temp_utc , temp_sound_onoff;

K_ModuleItem_Typedef  settings_app =
{
  4,
  "Настройки",
  &bmicon_settings, //
  CreateSettings,
  NULL,
};


#define ID_FRAMEWIN_0 (GUI_ID_USER + 0x00)
#define ID_BUTTON_0 (GUI_ID_USER + 0x01)
#define ID_BUTTON_1 (GUI_ID_USER + 0x02)
#define ID_SPINBOX_0 (GUI_ID_USER + 0x04)
#define ID_TEXT_0 (GUI_ID_USER + 0x06)
#define ID_CHECKBOX_0 (GUI_ID_USER + 0x07)
#define ID_SLIDER_0 (GUI_ID_USER + 0x08)
#define ID_TEXT_1 (GUI_ID_USER + 0x09)
#define ID_SLIDER_1 (GUI_ID_USER + 0x0A)
#define ID_TEXT_2 (GUI_ID_USER + 0x0B)
#define ID_CHECKBOX_1 (GUI_ID_USER + 0x0C)

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aSettingsCreate[] = {
  { FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 320, 420, 0, 0x64, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 0, 345, 80, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_1, 230, 345, 80, 40, 0, 0x0, 0 },
  { SPINBOX_CreateIndirect, "Spinbox", ID_SPINBOX_0, 10, 182, 90, 60, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_0, 133, 205, 37, 20, 0, 0x64, 0 },//utc
  { CHECKBOX_CreateIndirect, "Checkbox", ID_CHECKBOX_0, 8, 18, 230, 20, 0, 0x0, 0 },
  { SLIDER_CreateIndirect, "Slider", ID_SLIDER_0, 10, 66, 80, 40, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_1, 110, 74, 116, 20, 0, 0x64, 0 },
  { SLIDER_CreateIndirect, "Slider", ID_SLIDER_1, 10, 126, 80, 40, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_2, 110, 132, 116, 20, 0, 0x64, 0 },
   { CHECKBOX_CreateIndirect, "Checkbox", ID_CHECKBOX_1, 10, 277, 136, 20, 0, 0x0, 0 },
};



/*********************************************************************
*
*       _cbDialog
*/
static void _cbSettings(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'Framewin'
    //
    hItem = pMsg->hWin;
    FRAMEWIN_SetText(hItem, "Настройки");
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    FRAMEWIN_SetFont(hItem, &GUI_FontVerdana23);
    //
    // Initialization of 'Button'
    //
     hItem = WM_GetDialogItem(pMsg->hWin, ID_SLIDER_0);


    SLIDER_SetRange( hItem,50, 499);
    SLIDER_SetValue(hItem,maxbright - ee_bright);


    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
    BUTTON_SetText(hItem, "Применить");
    BUTTON_SetFont(hItem, &GUI_FontVerdana16);
    //
    // Initialization of 'Button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
    BUTTON_SetFont(hItem, &GUI_FontVerdana16);
    BUTTON_SetText(hItem, "Отмена");
    //
    // Initialization of 'Spinbox'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_SPINBOX_0);
    SPINBOX_SetFont(hItem, &GUI_FontVerdana16);
    SPINBOX_SetRange(hItem, -12, 12);
    SPINBOX_SetValue(hItem, ee_utc);
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetFont(hItem, &GUI_FontVerdana16);
    TEXT_SetText(hItem, "UTC");
    //
    // Initialization of 'Checkbox'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_0);
    CHECKBOX_SetText(hItem, "Настроить время от спутника");
    CHECKBOX_SetFont(hItem, &GUI_FontVerdana16);
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
    TEXT_SetFont(hItem, &GUI_FontVerdana16);
    TEXT_SetText(hItem, "Яркость экрана");
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
    TEXT_SetFont(hItem, &GUI_FontVerdana16);
    TEXT_SetText(hItem, "Громкость звука");
        //
    // Initialization of 'Checkbox'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_1);
    CHECKBOX_SetText(hItem, "Выводить звуки");
    CHECKBOX_SetFont(hItem, &GUI_FontVerdana16);



    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {


    case ID_BUTTON_0: // кнопка применить
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        ee_time_from_sat = temp_time_from_sat;
        ee_bright = temp_bright;
        ee_volume =  temp_volume;
        ee_utc = temp_utc;
        ee_sound_onoff =  temp_sound_onoff;
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
            set_eeprom_backup(); // save all to memory
            printf("Settings save \r\n");
            GUI_EndDialog(pMsg->hWin, 0);         // закроем окошко
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;



    case ID_BUTTON_1: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)

           GUI_EndDialog(pMsg->hWin, 0);         // закроем окошко
           bright_lcd_set(ee_bright);                 // примем старые значения яркости экрана
           printf("Settings close \r\n");


        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_SPINBOX_0: // Notifications sent by 'Spinbox'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
           _play_sound();
        // USER END
        break;
      case WM_NOTIFICATION_MOVED_OUT:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)

        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_0: // Notifications sent by 'Checkbox'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;


    case ID_SLIDER_0: // Notifications sent by 'Slider'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_SLIDER_0);
                    temp_bright = (u16)(maxbright - SLIDER_GetValue(hItem));
                     bright_lcd_set(temp_bright);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_SLIDER_1: // Notifications sent by 'Slider'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;

 case ID_CHECKBOX_1: // Notifications sent by 'Checkbox'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;



  default:
    WM_DefaultProc(pMsg);
    break;
  }
}



void CreateSettings(WM_HWIN hWin, uint16_t xpos, uint16_t ypos) {
 // WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aSettingsCreate, GUI_COUNTOF(_aSettingsCreate), _cbSettings, WM_HBKWIN, 530, 60);
//  return hWin;
}

/*************************** End of file ****************************/
