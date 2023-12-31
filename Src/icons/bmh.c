/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                           www.segger.com                           *
**********************************************************************
*                                                                    *
* C-file generated by                                                *
*                                                                    *
*        Bitmap Converter (ST) for emWin V5.32.                      *
*        Compiled Oct  8 2015, 11:58:22                              *
*                                                                    *
*        (c) 1998 - 2015 Segger Microcontroller GmbH & Co. KG        *
*                                                                    *
**********************************************************************
*                                                                    *
* Source file: bmh                                                   *
* Dimensions:  40 * 20                                               *
* NumColors:   16bpp: 65536                                          *
*                                                                    *
**********************************************************************
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif


static GUI_CONST_STORAGE unsigned char _acbmh[] = {
  /* ABS: 003 Pixels @ 000,000 */ 0, 3, 0xFF, 0xFF, 0x0C, 0x42, 0x04, 0x40,
  /* RLE: 032 Pixels @ 003,000 */ 32, 0x00, 0x41,
  /* ABS: 008 Pixels @ 035,000 */ 0, 8, 0x00, 0x40, 0x10, 0x84, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x10, 0x84,
  /* RLE: 005 Pixels @ 003,001 */ 5, 0xF7, 0xBD,
  /* RLE: 001 Pixels @ 008,001 */ 1, 0x13, 0xA5,
  /* RLE: 005 Pixels @ 009,001 */ 5, 0xF7, 0xBD,
  /* ABS: 002 Pixels @ 014,001 */ 0, 2, 0x17, 0xBD, 0x13, 0xA5,
  /* RLE: 005 Pixels @ 016,001 */ 5, 0xF7, 0xBD,
  /* RLE: 015 Pixels @ 021,001 */ 15, 0x13, 0xA5,
  /* ABS: 008 Pixels @ 036,001 */ 0, 8, 0x00, 0x00, 0x17, 0xBD, 0xFF, 0xFF, 0xFF, 0xFF, 0x08, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84,
  /* RLE: 004 Pixels @ 004,002 */ 4, 0x13, 0xA5,
  /* RLE: 001 Pixels @ 008,002 */ 1, 0xFF, 0xFF,
  /* RLE: 005 Pixels @ 009,002 */ 5, 0x13, 0xA5,
  /* ABS: 002 Pixels @ 014,002 */ 0, 2, 0xF7, 0xBD, 0xFF, 0xFF,
  /* RLE: 004 Pixels @ 016,002 */ 4, 0x13, 0xA5,
  /* ABS: 002 Pixels @ 020,002 */ 0, 2, 0x13, 0x84, 0xD7, 0xBE,
  /* RLE: 014 Pixels @ 022,002 */ 14, 0xFF, 0xFF,
  /* ABS: 026 Pixels @ 036,002 */ 0, 26, 0x04, 0x40, 0x08, 0x42, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x41, 0x0C, 0x83, 0xD7, 0xBE, 0x04, 0x40, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x00, 0x40, 0xDF, 0xEF, 0x04, 0x41, 0x00, 0x40, 0x04, 0x41, 0x04, 0x41,
        0x04, 0x40, 0x08, 0x42, 0xDF, 0xEF, 0x04, 0x40, 0x04, 0x41, 0x08, 0x41, 0x04, 0x41, 0x04, 0x40, 0x10, 0x84,
  /* RLE: 014 Pixels @ 022,003 */ 14, 0xFF, 0xFF,
  /* ABS: 014 Pixels @ 036,003 */ 0, 14, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x41, 0x0C, 0x83, 0xD7, 0xBE, 0x04, 0x40, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x40, 0xDF, 0xEF, 0x04, 0x41,
  /* RLE: 004 Pixels @ 010,004 */ 4, 0x08, 0x41,
  /* ABS: 008 Pixels @ 014,004 */ 0, 8, 0x08, 0x82, 0xDF, 0xEF, 0x04, 0x41, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x41, 0x13, 0x84,
  /* RLE: 014 Pixels @ 022,004 */ 14, 0xFF, 0xFF,
  /* ABS: 014 Pixels @ 036,004 */ 0, 14, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x41, 0x0C, 0x83, 0xD7, 0xBE, 0x04, 0x40, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x40, 0xDF, 0xEF, 0x04, 0x41,
  /* RLE: 004 Pixels @ 010,005 */ 4, 0x08, 0x41,
  /* ABS: 008 Pixels @ 014,005 */ 0, 8, 0x08, 0x82, 0xDF, 0xEF, 0x04, 0x41, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x41, 0x13, 0x84,
  /* RLE: 014 Pixels @ 022,005 */ 14, 0xFF, 0xFF,
  /* ABS: 014 Pixels @ 036,005 */ 0, 14, 0x04, 0x41, 0x08, 0x42, 0xF7, 0xBD, 0xFF, 0xFF, 0x04, 0x41, 0x0C, 0x83, 0xD7, 0xBE, 0x04, 0x40, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x40, 0xDF, 0xEF, 0x04, 0x41,
  /* RLE: 004 Pixels @ 010,006 */ 4, 0x08, 0x41,
  /* ABS: 008 Pixels @ 014,006 */ 0, 8, 0x08, 0x82, 0xDF, 0xEF, 0x04, 0x41, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x41, 0x13, 0x84,
  /* RLE: 014 Pixels @ 022,006 */ 14, 0xFF, 0xFF,
  /* ABS: 014 Pixels @ 036,006 */ 0, 14, 0x04, 0x41, 0x08, 0x41, 0x00, 0x40, 0x10, 0x84, 0x04, 0x41, 0x0C, 0x83, 0xD7, 0xBE, 0x04, 0x40, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x40, 0xDF, 0xEF, 0x04, 0x41,
  /* RLE: 004 Pixels @ 010,007 */ 4, 0x08, 0x41,
  /* ABS: 008 Pixels @ 014,007 */ 0, 8, 0x08, 0x82, 0xDF, 0xEF, 0x04, 0x41, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x41, 0x13, 0x84,
  /* RLE: 014 Pixels @ 022,007 */ 14, 0xFF, 0xFF,
  /* ABS: 014 Pixels @ 036,007 */ 0, 14, 0x04, 0x41, 0x08, 0x41, 0x08, 0x41, 0x10, 0x84, 0x04, 0x41, 0x0C, 0x83, 0xD7, 0xBE, 0x04, 0x40, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x40, 0xDF, 0xEF, 0x04, 0x41,
  /* RLE: 004 Pixels @ 010,008 */ 4, 0x08, 0x41,
  /* ABS: 008 Pixels @ 014,008 */ 0, 8, 0x08, 0x82, 0xDF, 0xEF, 0x04, 0x41, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x41, 0x13, 0x84,
  /* RLE: 014 Pixels @ 022,008 */ 14, 0xFF, 0xFF,
  /* ABS: 014 Pixels @ 036,008 */ 0, 14, 0x04, 0x41, 0x08, 0x41, 0x08, 0x41, 0x10, 0x84, 0x04, 0x41, 0x0C, 0x83, 0xD7, 0xBE, 0x04, 0x40, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x40, 0xDF, 0xEF, 0x04, 0x41,
  /* RLE: 004 Pixels @ 010,009 */ 4, 0x08, 0x41,
  /* ABS: 008 Pixels @ 014,009 */ 0, 8, 0x08, 0x82, 0xDF, 0xEF, 0x04, 0x41, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x41, 0x13, 0x84,
  /* RLE: 014 Pixels @ 022,009 */ 14, 0xFF, 0xFF,
  /* ABS: 014 Pixels @ 036,009 */ 0, 14, 0x04, 0x41, 0x08, 0x41, 0x08, 0x41, 0x10, 0x84, 0x04, 0x41, 0x0C, 0x83, 0xD7, 0xBE, 0x04, 0x40, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x40, 0xDF, 0xEF, 0x04, 0x41,
  /* RLE: 004 Pixels @ 010,010 */ 4, 0x08, 0x41,
  /* ABS: 008 Pixels @ 014,010 */ 0, 8, 0x08, 0x82, 0xDF, 0xEF, 0x04, 0x41, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x41, 0x13, 0x84,
  /* RLE: 014 Pixels @ 022,010 */ 14, 0xFF, 0xFF,
  /* ABS: 014 Pixels @ 036,010 */ 0, 14, 0x04, 0x41, 0x08, 0x41, 0x08, 0x41, 0x10, 0x84, 0x04, 0x41, 0x0C, 0x83, 0xD7, 0xBE, 0x04, 0x40, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x40, 0xDF, 0xEF, 0x04, 0x41,
  /* RLE: 004 Pixels @ 010,011 */ 4, 0x08, 0x41,
  /* ABS: 008 Pixels @ 014,011 */ 0, 8, 0x08, 0x82, 0xDF, 0xEF, 0x04, 0x41, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x41, 0x13, 0x84,
  /* RLE: 014 Pixels @ 022,011 */ 14, 0xFF, 0xFF,
  /* ABS: 014 Pixels @ 036,011 */ 0, 14, 0x04, 0x41, 0x08, 0x41, 0x04, 0x41, 0x10, 0x84, 0x04, 0x41, 0x0C, 0x83, 0xD7, 0xBE, 0x04, 0x40, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x40, 0xDF, 0xEF, 0x04, 0x41,
  /* RLE: 004 Pixels @ 010,012 */ 4, 0x08, 0x41,
  /* ABS: 008 Pixels @ 014,012 */ 0, 8, 0x08, 0x82, 0xDF, 0xEF, 0x04, 0x41, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x41, 0x13, 0x84,
  /* RLE: 014 Pixels @ 022,012 */ 14, 0xFF, 0xFF,
  /* ABS: 014 Pixels @ 036,012 */ 0, 14, 0x04, 0x41, 0x08, 0x41, 0x08, 0x41, 0x10, 0x84, 0x04, 0x41, 0x0C, 0x83, 0xD7, 0xBE, 0x04, 0x40, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x40, 0xDF, 0xEF, 0x04, 0x41,
  /* RLE: 004 Pixels @ 010,013 */ 4, 0x08, 0x41,
  /* ABS: 008 Pixels @ 014,013 */ 0, 8, 0x08, 0x82, 0xDF, 0xEF, 0x04, 0x41, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x41, 0x13, 0x84,
  /* RLE: 014 Pixels @ 022,013 */ 14, 0xFF, 0xFF,
  /* ABS: 014 Pixels @ 036,013 */ 0, 14, 0x04, 0x41, 0x04, 0x41, 0x08, 0x41, 0xD7, 0xBE, 0x04, 0x41, 0x0C, 0x83, 0xD7, 0xBE, 0x04, 0x40, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x40, 0xDF, 0xEF, 0x04, 0x41,
  /* RLE: 004 Pixels @ 010,014 */ 4, 0x08, 0x41,
  /* ABS: 008 Pixels @ 014,014 */ 0, 8, 0x08, 0x82, 0xDF, 0xEF, 0x04, 0x41, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x41, 0x13, 0x84,
  /* RLE: 014 Pixels @ 022,014 */ 14, 0xFF, 0xFF,
  /* ABS: 014 Pixels @ 036,014 */ 0, 14, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x41, 0x0C, 0x83, 0xD7, 0xBE, 0x04, 0x40, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x40, 0xDF, 0xEF, 0x04, 0x41,
  /* RLE: 004 Pixels @ 010,015 */ 4, 0x08, 0x41,
  /* ABS: 008 Pixels @ 014,015 */ 0, 8, 0x08, 0x82, 0xDF, 0xEF, 0x04, 0x41, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x41, 0x13, 0x84,
  /* RLE: 014 Pixels @ 022,015 */ 14, 0xFF, 0xFF,
  /* ABS: 014 Pixels @ 036,015 */ 0, 14, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x41, 0x0C, 0x83, 0xD7, 0xBE, 0x00, 0x00, 0x04, 0x40, 0x04, 0x40, 0x04, 0x40, 0x00, 0x00, 0xDF, 0xEF, 0x00, 0x40,
  /* RLE: 004 Pixels @ 010,016 */ 4, 0x04, 0x40,
  /* ABS: 008 Pixels @ 014,016 */ 0, 8, 0x04, 0x41, 0xD7, 0xBE, 0x00, 0x00, 0x00, 0x40, 0x04, 0x40, 0x04, 0x40, 0x00, 0x00, 0x10, 0x83,
  /* RLE: 014 Pixels @ 022,016 */ 14, 0xFF, 0xFF,
  /* ABS: 006 Pixels @ 036,016 */ 0, 6, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0xFF, 0xFF, 0x08, 0x82, 0x04, 0x41,
  /* RLE: 034 Pixels @ 002,017 */ 34, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 036,017 */ 0, 7, 0x00, 0x00, 0x10, 0x83, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0xBD, 0x00, 0x00, 0x04, 0x40,
  /* RLE: 032 Pixels @ 003,018 */ 32, 0x04, 0x41,
  /* ABS: 007 Pixels @ 035,018 */ 0, 7, 0x04, 0x40, 0x00, 0x00, 0xDF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xD7, 0xBE,
  /* RLE: 033 Pixels @ 002,019 */ 33, 0x0C, 0x83,
  /* RLE: 001 Pixels @ 035,019 */ 1, 0x0C, 0x82,
  /* RLE: 004 Pixels @ 036,019 */ 4, 0xFF, 0xFF,
  0
};  // 872 for 800 pixels

GUI_CONST_STORAGE GUI_BITMAP bmbmh = {
  40, // xSize
  20, // ySize
  80, // BytesPerLine
  16, // BitsPerPixel
  (unsigned char *)_acbmh,  // Pointer to picture data
  NULL,  // Pointer to palette
  GUI_DRAW_RLE16
};

/*************************** End of file ****************************/
