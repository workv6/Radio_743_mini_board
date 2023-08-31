
#include "main.h"
#include "DIALOG.h"
#include "k_module.h"
#include "struct.h"
#include "mp3play.h"

extern long time_to_sleep;
extern __mp3ctrl * mp3ctrl;

extern int z;

extern GUI_CONST_STORAGE GUI_FONT GUI_FontTahoma16;
extern GUI_CONST_STORAGE GUI_BITMAP bmicon_mafon;
void MP3_Start_app(WM_HWIN hWin, uint16_t xpos, uint16_t ypos);
extern GUI_CONST_STORAGE GUI_FONT GUI_FontTahoma24;
extern u8 get_directory_file (u8 Cur_Dir, u16 num_file,char* selected_file_name);
 extern u8 file_name[];
 int files_in_dir;
 extern u8 eeprom_buffer[];
 extern EEData_t  *EEData;
 u8 dir_temp[200];
 extern volatile u8 player_status;;
  volatile u8 global_play_start = 0;
 typedef struct {
  GUI_TIMER_HANDLE  hTimer;
  const GUI_FONT  * pFont;
  const char      * pText;
  GUI_COLOR         TextColor;
  int               xSizeText;
  int               xPos;
  int               yPos;
  int               xSize;
  int               ySize;
  int               dx;
  int               vxPos;
  int               vyPos;
} TICKER_CONTEXT;

typedef struct {
  WM_HWIN           hWin;
  TICKER_CONTEXT    Ticker;
} TICKER_CONTEXT_WM;

typedef struct {
  TICKER_CONTEXT_WM * pTickerWM;
} TICKER_INFO;

 #define TICKER_BaKCOLOR   GUI_CYAN

K_ModuleItem_Typedef  mafon_app =
{
  1,
  "MP3",
  &bmicon_mafon, //
  MP3_Start_app,
  NULL,
};

#define ID_FRAMEWIN_0   (GUI_ID_USER + 0x00)
#define ID_BUTTON_0   (GUI_ID_USER + 0x01)
#define ID_BUTTON_1   (GUI_ID_USER + 0x02)
#define ID_BUTTON_2   (GUI_ID_USER + 0x03)
#define ID_BUTTON_3   (GUI_ID_USER + 0x04)
#define ID_PROGBAR_0   (GUI_ID_USER + 0x05)
#define ID_TEXT_0   (GUI_ID_USER + 0x06)
#define ID_LISTWHEEL_0   (GUI_ID_USER + 0x07)
#define ID_SLIDER_0   (GUI_ID_USER + 0x08)
#define ID_swipe_0   (GUI_ID_USER + 0x09)


 uint8_t *String;
 uint8_t beg_string[100];


 static void _MessageBox(const char * pText, const char * pCaption) {
  WM_HWIN hBox;

  hBox = MESSAGEBOX_Create(pText, pCaption, GUI_MESSAGEBOX_CF_MODAL | GUI_MESSAGEBOX_CF_MOVEABLE);
  WM_SetStayOnTop(hBox, 1);
  WM_BringToTop(hBox);
  GUI_ExecCreatedDialog(hBox);

}
  uint8_t z_buf[30];
//                   ук на строку      размер окна символов
void scroll_string(uint8_t *Str, uint8_t window_size)
{
  char i=0;
     while(i<window_size)
     {
       z_buf[i++] = *Str++;
       if (*Str == '\0') {z_buf[i++] = 0x20;z_buf[i++] = 0x20;break;} //

     }
     z_buf[i++] = 0x20;
     z_buf[i]=0;
}

int scroll(uint8_t window_size,int8_t step)
{
    scroll_string(String,window_size);

    if (*String != '\0')
    {
      String+=step;
      return 0;
    }
    else
    {
      String = &beg_string[0];
      return 1;
    }
}



  // Конвертирование строки из DOS(866) в Win1251
void ConvertStringDosTo1251 ( char *str )
{
	static const uint8_t table[128] = {
			0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,	// 00 - 0F
			0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF, // 10 - 1F
			0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF, // 20 - 2F
			0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, // 30 - 3F
			0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, // 40 - 4F
			0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, // 50 - 5F
			0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF, // 60 - 6F
			0xA8, 0xB8, 0xAA, 0xBA, 0xAF, 0xDF, 0xA1, 0xA2, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF  // 70 - 7F
	};
	int i;

	for ( i = 0; i < strlen ( str ); i ++ )
		if ( str [ i ] > 127 )
			str [ i ] = table [ (int) (str[i] - 128) ];
} // ConvertStringDosTo1251

// Конвертирование строки из Win1251 в DOS(866)
void ConvertString1251ToDos ( char *str )
{
	static const uint8_t table[128] = {
			0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, // 00 - 0F
			0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, // 10 - 1F
			0xD0, 0xF6, 0xF7, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xF0, 0xD9, 0xF2, 0xDB, 0xDC, 0xDD, 0xDE, 0xF4, // 20 - 2F
			0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF1, 0xF9, 0xF3, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF, // 30 - 3F
			0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, // 40 - 4F
			0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0xF5, // 50 - 5F
			0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, // 60 - 6F
			0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF  // 70 - 7F
	};
	int i;

	for ( i = 0; i < strlen ( str ); i ++ )
		if ( str [ i ] > 127 )
			str [ i ] = table [ (int)(str[i] - 128) ];
} // ConvertStringDosTo1251



static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "MP3 Player", ID_FRAMEWIN_0, 0, 41, 240, 279, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Settings", ID_BUTTON_0, 175, 202, 50, 45, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Prev", ID_BUTTON_1, 120, 202, 50, 45, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Next", ID_BUTTON_2, 65, 202, 50, 45, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Play", ID_BUTTON_3, 3, 202, 58, 45, 0, 0x0, 0 },
  { PROGBAR_CreateIndirect, "Progbar", ID_PROGBAR_0, 0, 180, 230, 20, 0, 0x0, 0 },

  { TEXT_CreateIndirect, " ", ID_TEXT_0, 0, 148, 230, 34, 0, 0x0, 0 },
  { LISTWHEEL_CreateIndirect, "Listwheel", ID_LISTWHEEL_0, 1, 1, 190, 140, 0, 0x0, 0 },
  { SLIDER_CreateIndirect, "Slider", ID_SLIDER_0, 195, 7, 30, 132, 8, 0x0, 0 },
//  {SWIPELIST_CreateIndirect, "swipe", ID_swipe_0, 195, 7, 30, 132, 8, 0x0, 0 },
};


static int _OwnerPlaylistDraw(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo) {
switch (pDrawItemInfo->Cmd) {
case WIDGET_DRAW_OVERLAY:
  GUI_SetColor(GUI_BROWN);
  GUI_DrawRect(0,0,189,139);
  GUI_SetColor(GUI_BLACK);
  //GUI_DrawHLine(29, 0, 90);
  //GUI_DrawHLine(60, 0, 90);
break;
default:
return LISTWHEEL_OwnerDraw(pDrawItemInfo);
}
return 0;
}

static WM_HWIN _hBk;
char name_str[200];
int xx;
static void _cbDialog(WM_MESSAGE * pMsg) {




  WM_HWIN hItem;
  WM_HTIMER hTimer;
  int NCode;
  int Id,n;
  int     LineHeight = 16;
   int     xSize;
   int     ySize;


  switch (pMsg->MsgId) {


         case WM_TIMER: // событие таймера


        if ( player_status == s_next)
            {
                time_to_sleep = EEData->time_to_sleep*300; // подсветим ненадолго экран
                  GUI_Delay(100);
                 global_play_start =0;
                 player_status = s_stop;
                 GUI_Delay(100);
                 hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_0);
                  z = LISTWHEEL_GetPos(hItem);              //считали текущую позицию
                  z ++;                                                                // прибавим 1
                  LISTWHEEL_MoveToPos(hItem, z);        //  подвинем колесо
                  LISTWHEEL_SetSel(hItem, z);                 // выберем
                  LISTWHEEL_GetItemText(hItem, z,name_str, sizeof(name_str));   // считаем имя
                  LISTWHEEL_GetItemText(hItem, z,file_name, 140);
                   sprintf (beg_string,file_name);
                  ConvertString1251ToDos (name_str);
                  sprintf(dir_temp,"0:/mp3/");
                  strcat(dir_temp,name_str);
                  global_play_start = 1;
                  player_status = s_play;
                  GUI_Delay(100);

            }

         hItem = WM_GetDialogItem(pMsg->hWin ,ID_PROGBAR_0);
         PROGBAR_SetMinMax(hItem, 0   , mp3ctrl->totsec );
         PROGBAR_SetValue(hItem,mp3ctrl->cursec );

        if (xx == 0)
        {


             if (scroll(30,1)==1)
             {
              xx=30;
              scroll(30,1);
             }
             else
             {
               xx = 2;
             }


        }
         if (xx>0) xx--;
             hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
             TEXT_SetFont(hItem, &GUI_FontTahoma24);
             TEXT_SetText(hItem,  z_buf);

         WM_RestartTimer(pMsg->Data.v, 100);


        break;



    case WM_INIT_DIALOG:
    //
    // Initialization of 'Framewin'
    //
    memset(z_buf,0,30);
    memset(String,0,140);
    scroll(30,1);
    hItem = pMsg->hWin;
    FRAMEWIN_SetTitleHeight(hItem, 24);
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    FRAMEWIN_AddCloseButton(hItem, FRAMEWIN_BUTTON_RIGHT, 0);

    hTimer =  WM_CreateTimer ( WM_GetClientWindow ( hItem ), 0, 3000, 0 );
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetText(hItem, "Ready");
    hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_0);
    LISTWHEEL_SetFont(hItem, &GUI_FontTahoma16);
    LISTWHEEL_SetLineHeight(hItem, LineHeight);
    LISTWHEEL_SetSnapPosition(hItem, (140 - LineHeight) / 2);
    LISTWHEEL_SetLBorder(hItem, 5);
    LISTWHEEL_SetOwnerDraw(hItem, _OwnerPlaylistDraw);
    LISTWHEEL_SetBkColor(hItem, LISTWHEEL_CI_UNSEL, GUI_LIGHTGRAY);
    LISTWHEEL_SetBkColor(hItem, LISTWHEEL_CI_SEL, GUI_LIGHTBLUE);
    for(n=1;n<files_in_dir;n++)
    {
      get_directory_file (1, n,file_name);// iterate_files (1,file_name,n);
      ConvertStringDosTo1251 (file_name);
      LISTWHEEL_AddString(hItem,file_name);
    }
     hItem = WM_GetDialogItem(pMsg->hWin, ID_SLIDER_0);

        SLIDER_SetRange(hItem, 10, 110);
        SLIDER_SetNumTicks(hItem, 10);
        SLIDER_SetValue(hItem,110 - EEData->volume);
     break;



  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {




    case ID_BUTTON_0: // Notifications sent by 'Stop / Settings'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
          time_to_sleep = EEData->time_to_sleep*1000;
      if (global_play_start ==2)
                {
                     player_status = s_stop;
                     GUI_Delay(100);
                     hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
                     BUTTON_SetText(hItem,"Settings");
                     global_play_start =0;
                     hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);      //вернем кнопке плэй ее истинное название
                     BUTTON_SetText(hItem,"Play");
                }
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;



    case ID_BUTTON_1: // Notifications sent by 'Prev'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
          time_to_sleep = EEData->time_to_sleep*1000;
            global_play_start =0;
            player_status = s_stop;
            GUI_Delay(100);
                  hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_0);
                  z = LISTWHEEL_GetPos(hItem);              //считали текущую позицию
                  if (z==0)  z =files_in_dir-1;
                  z --;

                                                                                // уменьшим трек
                  LISTWHEEL_MoveToPos(hItem, z);        //  подвинем колесо
                  LISTWHEEL_SetSel(hItem, z);                 // выберем
                  LISTWHEEL_GetItemText(hItem, z,name_str, sizeof(name_str));   // считаем имя
                  LISTWHEEL_GetItemText(hItem, z,file_name, 140);
                   sprintf (beg_string,file_name);
                   xx=0;
                  ConvertString1251ToDos (name_str);
                   sprintf(dir_temp,"0:/mp3/");
                   strcat(dir_temp,name_str);
                   global_play_start = 1;
                   player_status = s_play;
                    // кнопку плэй перепишем на паузу (на всякий случай)
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
                    BUTTON_SetText(hItem,"Pause");
                    GUI_Delay(100);


        break;
      case WM_NOTIFICATION_RELEASED:
      //  global_play_start = 1;
       //   GUI_Delay(10);
      //   player_status = s_play;
        break;

      }
      break;

    case ID_BUTTON_2: // Notifications sent by 'Next'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
          time_to_sleep = EEData->time_to_sleep*1000;
                 global_play_start =0;      //  себе что плеер выкл и готов к старту
                 player_status = s_stop;    // плееру стоп
                 GUI_Delay(100);                  // дадим плееру осознать что его выключили
                  hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_0);        // разберемся с колесом
                  z = LISTWHEEL_GetPos(hItem);                                                              //считали текущую позицию
                  if ( z == files_in_dir-2) { z = 0 ;}
                  else{
                     z ++; }                                                                                                                // прибавим 1
                  LISTWHEEL_MoveToPos(hItem, z);                                                         //  подвинем колесо
                  LISTWHEEL_SetSel(hItem, z);                                                                  // выберем
                  LISTWHEEL_GetItemText(hItem, z,name_str, sizeof(name_str));    // считаем имя
                  LISTWHEEL_GetItemText(hItem, z,file_name, 140);
                   sprintf (beg_string,file_name);
                   xx=0;
                  ConvertString1251ToDos (name_str);                                               // перевели его в кодировку 1251
                  sprintf(dir_temp,"0:/mp3/");                                                                      // создадим путь для фс с текущим   именем файла
                   strcat(dir_temp,name_str);
                   global_play_start = 1;                                                                           // дадим команду на проигрывание файла
                   player_status = s_play;                                                                        //плееру играть
                   // кнопку плэй перепишем на паузу (на всякий случай)
                      hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
                        BUTTON_SetText(hItem,"Pause");
                   GUI_Delay(100);                                                                                      // вперед
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
      //
        //
        //
        // USER END
        break;
      }
      break;

    case ID_BUTTON_3: // Notifications sent by 'Play'
      switch(NCode) {
              case WM_NOTIFICATION_CLICKED:
                   time_to_sleep = EEData->time_to_sleep*1000;
               break;
       case WM_NOTIFICATION_RELEASED:
         //  if (global_play_start ==2)      // играет
              //  {
                   if (player_status == s_play)
                       {
                        player_status = s_pause;       // команда плееру на паузу
                        GUI_Delay(100);
                        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
                        BUTTON_SetText(hItem,"Play");  // находимся в режиме паузы поэтому на кнопке напишем плэй
                       }
                   else if   (player_status == s_pause)
                       {
                         player_status = s_play;
                        GUI_Delay(100);
                        hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
                        BUTTON_SetText(hItem,"Pause");
                       }


              //  }

            if (player_status == s_stop)     // плеер то выключен и его надо стартануть на воспроизведение
                {
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_0);        // разберемся с колесом
                  z = LISTWHEEL_GetPos(hItem);                                                              //считали текущую позицию
                 LISTWHEEL_GetItemText(hItem, z,name_str, sizeof(name_str));    // считаем имя
                 LISTWHEEL_GetItemText(hItem, z,file_name, 140);
                  sprintf (beg_string,file_name);
                  xx=0;
                 ConvertString1251ToDos (name_str);                                               // перевели его в кодировку 1251
                  sprintf(dir_temp,"0:/mp3/");                                                                      // создадим путь для фс с текущим   именем файла
                   strcat(dir_temp,name_str);
                   global_play_start = 1;
                   player_status = s_play;
                    GUI_Delay(100);
                     hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
                    BUTTON_SetText(hItem,"Pause");
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);      // перепишем кнопку настройки как стоп
                    BUTTON_SetText(hItem,"Stop");
                }


        break;

      }
      break;




    case ID_LISTWHEEL_0: //Выбор файла
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:

        break;
      case WM_NOTIFICATION_RELEASED:

        break;
      case WM_NOTIFICATION_SEL_CHANGED:
          time_to_sleep = EEData->time_to_sleep*1000;
        global_play_start =0;
        player_status = s_stop;
        GUI_Delay(100);
         hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_0);
                  z = LISTWHEEL_GetPos(hItem);
                  LISTWHEEL_SetSel(hItem, z);
                  LISTWHEEL_GetItemText(hItem, z,name_str, sizeof(name_str));
                  LISTWHEEL_GetItemText(hItem, z,file_name, 140);
                  xx=0;
                   sprintf (beg_string,file_name);
                  ConvertString1251ToDos (name_str);
                  sprintf(dir_temp,"0:/mp3/");
                  strcat(dir_temp,name_str);
                   global_play_start = 1;
                    player_status = s_play;
                  GUI_Delay(100);

        break;

      }
      break;





    case ID_SLIDER_0: // Громкость
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        time_to_sleep = EEData->time_to_sleep*1000;
        break;
     case WM_NOTIFICATION_RELEASED:
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_SLIDER_0);
                    EEData->volume = (char)(110 - SLIDER_GetValue(hItem));
                    BSP_AUDIO_OUT_SetVolume(EEData->volume); // отпустили, пропишем это дело в кодек
                    break;
      case WM_NOTIFICATION_VALUE_CHANGED:

        break;

      }
      break;

    }
    break;

      case WM_PAINT:
    xSize = WM_GetWindowSizeX(pMsg->hWin);
    ySize = WM_GetWindowSizeY(pMsg->hWin);

    GUI_DrawGradientV(0, 0, xSize - 1, ySize - 1, GUI_GRAY, GUI_CYAN);



    break;
    case WM_DELETE:
          time_to_sleep = EEData->time_to_sleep*1000;
     I2C_EE_BufferWrite(eeprom_buffer, 0, 255);
     global_play_start  = 0;
     player_status   =  s_stop;
     printf("mp3_off \r\n");
     break;

  default:
    WM_DefaultProc(pMsg);
    break;
  }
}




void MP3_Start_app(WM_HWIN hWin, uint16_t xpos, uint16_t ypos) {

    player_status = s_stop;
    global_play_start = 0;
    phones_switch_to_player();
   files_in_dir = iterate_files (1,file_name,1);
   printf("files in MP3 %d \r\n", files_in_dir ); // узнаем количество файлов в директории
   if (files_in_dir > 0)
   {
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);




   }
   else
   {
     printf("No files in MP3\r\n");
   }

}


