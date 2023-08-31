

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0   (GUI_ID_USER + 0x00)
#define ID_BUTTON_0   (GUI_ID_USER + 0x01)
#define ID_BUTTON_1   (GUI_ID_USER + 0x02)
#define ID_BUTTON_2   (GUI_ID_USER + 0x03)
#define ID_BUTTON_3   (GUI_ID_USER + 0x04)
#define ID_BUTTON_4   (GUI_ID_USER + 0x05)
#define ID_BUTTON_5   (GUI_ID_USER + 0x06)
#define ID_BUTTON_6   (GUI_ID_USER + 0x07)
#define ID_BUTTON_7   (GUI_ID_USER + 0x08)
#define ID_BUTTON_8   (GUI_ID_USER + 0x09)
#define ID_BUTTON_9   (GUI_ID_USER + 0x0A)
#define ID_BUTTON_10   (GUI_ID_USER + 0x0B)
#define ID_LISTVIEW_0   (GUI_ID_USER + 0x0C)
#define ID_EDIT_0   (GUI_ID_USER + 0x0D)
#define ID_TEXT_0   (GUI_ID_USER + 0x0E)
#define ID_BUTTON_11   (GUI_ID_USER + 0x0F)
#define ID_EDIT_1   (GUI_ID_USER + 0x10)
#define ID_TEXT_1   (GUI_ID_USER + 0x11)
#define ID_DROPDOWN_0   (GUI_ID_USER + 0x12)
#define ID_EDIT_2   (GUI_ID_USER + 0x14)
#define ID_TEXT_2   (GUI_ID_USER + 0x15)
#define ID_BUTTON_12   (GUI_ID_USER + 0x16)
#define ID_BUTTON_13   (GUI_ID_USER + 0x17)
#define ID_BUTTON_14   (GUI_ID_USER + 0x18)
#define ID_BUTTON_15   (GUI_ID_USER + 0x19)
#define ID_BUTTON_16   (GUI_ID_USER + 0x1A)
#define ID_BUTTON_17   (GUI_ID_USER + 0x1B)
#define ID_EDIT_3   (GUI_ID_USER + 0x1C)
#define ID_TEXT_3   (GUI_ID_USER + 0x1D)
#define ID_BUTTON_18   (GUI_ID_USER + 0x1E)
#define ID_LISTVIEW_1   (GUI_ID_USER + 0x1F)
#define ID_TEXT_4   (GUI_ID_USER + 0x20)
#define ID_EDIT_4   (GUI_ID_USER + 0x21)
#define ID_BUTTON_19   (GUI_ID_USER + 0x22)
#define ID_BUTTON_20   (GUI_ID_USER + 0x23)
#define ID_BUTTON_21   (GUI_ID_USER + 0x24)
#define ID_BUTTON_22   (GUI_ID_USER + 0x25)
#define ID_BUTTON_23   (GUI_ID_USER + 0x26)
#define ID_BUTTON_24   (GUI_ID_USER + 0x27)
#define ID_BUTTON_25   (GUI_ID_USER + 0x28)
#define ID_BUTTON_26   (GUI_ID_USER + 0x29)



/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aCANToolCreate[] = {
  { FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 60, 854, 420, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "0", ID_BUTTON_0, 715, 355, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "<-", ID_BUTTON_1, 650, 355, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "D", ID_BUTTON_2, 650, 177, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "7", ID_BUTTON_3, 650, 310, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "8", ID_BUTTON_4, 715, 310, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "6", ID_BUTTON_5, 780, 265, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "3", ID_BUTTON_6, 780, 220, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "5", ID_BUTTON_7, 715, 265, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "4", ID_BUTTON_8, 650, 265, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "2", ID_BUTTON_9, 715, 220, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "1", ID_BUTTON_10, 650, 220, 60, 40, 0, 0x0, 0 },
  { LISTVIEW_CreateIndirect, "Listview", ID_LISTVIEW_0, 1, 1, 256, 396, 0, 0x0, 0 },
  { EDIT_CreateIndirect, "Edit", ID_EDIT_0, 659, 9, 89, 37, 0, 0x64, 0 },
  { TEXT_CreateIndirect, " ID to send", ID_TEXT_0, 588, 12, 61, 31, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Send", ID_BUTTON_11, 758, 16, 80, 45, 0, 0x0, 0 },
  { EDIT_CreateIndirect, "Edit", ID_EDIT_1, 639, 52, 112, 30, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Data to send", ID_TEXT_1, 566, 51, 69, 30, 0, 0x0, 0 },
  { DROPDOWN_CreateIndirect, "Manual", ID_DROPDOWN_0, 627, 90, 73, 18, 0, 0x0, 0 },
  { EDIT_CreateIndirect, "Edit", ID_EDIT_2, 712, 90, 38, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "MS", ID_TEXT_2, 761, 93, 28, 20, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Listen All", ID_BUTTON_12, 266, 10, 80, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Listen Select", ID_BUTTON_13, 266, 57, 80, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Clear All", ID_BUTTON_14, 264, 354, 80, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Clear Select", ID_BUTTON_15, 262, 300, 80, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Save select", ID_BUTTON_16, 266, 199, 80, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Save ALL", ID_BUTTON_17, 265, 152, 80, 40, 0, 0x0, 0 },
  { EDIT_CreateIndirect, "Edit", ID_EDIT_3, 266, 125, 80, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Filename", ID_TEXT_3, 270, 106, 80, 20, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Scroll", ID_BUTTON_18, 265, 247, 80, 40, 0, 0x0, 0 },
  { LISTVIEW_CreateIndirect, "Listview", ID_LISTVIEW_1, 356, 3, 176, 345, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "ID to scroll", ID_TEXT_4, 563, 322, 80, 20, 0, 0x0, 0 },
  { EDIT_CreateIndirect, "Edit", ID_EDIT_4, 560, 348, 66, 28, 0, 0x64, 0 },
  { BUTTON_CreateIndirect, "Scroll select ID", ID_BUTTON_19, 379, 352, 120, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "9", ID_BUTTON_20, 780, 310, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Clear", ID_BUTTON_21, 780, 355, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "A", ID_BUTTON_22, 650, 135, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "B", ID_BUTTON_23, 715, 135, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "C", ID_BUTTON_24, 780, 135, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "E", ID_BUTTON_25, 715, 177, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "F", ID_BUTTON_26, 780, 177, 60, 40, 0, 0x0, 0 },
  
};



/*********************************************************************
*
*       _cbDialog
*/
static void _cbCANTool(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  
  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    
    hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTVIEW_0);
    LISTVIEW_AddColumn(hItem, 30, "N", GUI_TA_HCENTER | GUI_TA_VCENTER);
    LISTVIEW_AddColumn(hItem, 40, "ID", GUI_TA_HCENTER | GUI_TA_VCENTER);
    LISTVIEW_AddColumn(hItem, 120, "DATA", GUI_TA_HCENTER | GUI_TA_VCENTER);
    LISTVIEW_AddRow(hItem, NULL);
    LISTVIEW_SetGridVis(hItem, 1);
    LISTVIEW_AddColumn(hItem, 65, "Time", GUI_TA_HCENTER | GUI_TA_VCENTER);
    //
    // Initialization of 'Edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
    EDIT_SetText(hItem, "123");
    //
    // Initialization of 'Edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_1);
    EDIT_SetText(hItem, "123");
    //
    // Initialization of 'Manual'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0);
    DROPDOWN_AddString(hItem, "Timer");
    DROPDOWN_AddString(hItem, "Answer");
    //
    // Initialization of 'Edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_2);
    EDIT_SetText(hItem, "123");
    //
    // Initialization of 'Edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_3);
    EDIT_SetText(hItem, "a123.txt");
    //
    // Initialization of 'Listview'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTVIEW_1);
    LISTVIEW_AddColumn(hItem, 30, "ID", GUI_TA_HCENTER | GUI_TA_VCENTER);
    LISTVIEW_AddColumn(hItem, 80, "DATA", GUI_TA_HCENTER | GUI_TA_VCENTER);
    LISTVIEW_AddColumn(hItem, 60, "Time", GUI_TA_HCENTER | GUI_TA_VCENTER);
    LISTVIEW_AddRow(hItem, NULL);
    LISTVIEW_SetGridVis(hItem, 1);
    //
    // Initialization of 'Edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_4);
    EDIT_SetText(hItem, "123");
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by '0'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_1: // Notifications sent by '<-'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_2: // Notifications sent by 'D'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_3: // Notifications sent by '7'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_4: // Notifications sent by '8'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_5: // Notifications sent by '6'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_6: // Notifications sent by '3'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_7: // Notifications sent by '5'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_8: // Notifications sent by '4'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_9: // Notifications sent by '2'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_10: // Notifications sent by '1'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_LISTVIEW_0: // Notifications sent by 'Listview'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_SEL_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_EDIT_0: // Notifications sent by 'Edit'
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
    case ID_BUTTON_11: // Notifications sent by 'Send'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_EDIT_1: // Notifications sent by 'Edit'
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
    case ID_DROPDOWN_0: // Notifications sent by 'Manual'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_SEL_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_EDIT_2: // Notifications sent by 'Edit'
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
    case ID_BUTTON_12: // Notifications sent by 'Listen All'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_13: // Notifications sent by 'Listen Select'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_14: // Notifications sent by 'Clear All'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_15: // Notifications sent by 'Clear Select'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_16: // Notifications sent by 'Save select'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_17: // Notifications sent by 'Save ALL'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_EDIT_3: // Notifications sent by 'Edit'
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
    case ID_BUTTON_18: // Notifications sent by 'Scroll'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_LISTVIEW_1: // Notifications sent by 'Listview'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_SEL_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_EDIT_4: // Notifications sent by 'Edit'
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
    case ID_BUTTON_19: // Notifications sent by 'Scroll select ID'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_20: // Notifications sent by '9'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_21: // Notifications sent by 'Clear'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_22: // Notifications sent by 'A'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_23: // Notifications sent by 'B'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_24: // Notifications sent by 'C'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_25: // Notifications sent by 'E'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_26: // Notifications sent by 'F'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
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
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}


WM_HWIN CreateCANTool(void);
WM_HWIN CreateCANTool(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aCANToolCreate, GUI_COUNTOF(_aCANToolCreate), _cbCANTool, WM_HBKWIN, 0, 0);
  return hWin;
}


