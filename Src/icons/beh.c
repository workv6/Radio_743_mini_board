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
* Source file: beh                                                   *
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



static GUI_CONST_STORAGE unsigned char _acbeh[] = {
  /* ABS: 003 Pixels @ 000,000 */ 0, 3, 0xFF, 0xFF, 0xFF, 0xFF, 0x13, 0x85,
  /* RLE: 033 Pixels @ 003,000 */ 33, 0x10, 0x84,
  /* RLE: 005 Pixels @ 036,000 */ 5, 0xFF, 0xFF,
  /* ABS: 002 Pixels @ 001,001 */ 0, 2, 0x00, 0x00, 0x04, 0x40,
  /* RLE: 033 Pixels @ 003,001 */ 33, 0x00, 0x40,
  /* ABS: 007 Pixels @ 036,001 */ 0, 7, 0x04, 0x40, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0C, 0x83, 0x04, 0x40, 0xD7, 0xBE,
  /* RLE: 033 Pixels @ 003,002 */ 33, 0xFF, 0xFF,
  /* ABS: 006 Pixels @ 036,002 */ 0, 6, 0x00, 0x00, 0x10, 0x84, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x41, 0x0C, 0x83,
  /* RLE: 034 Pixels @ 002,003 */ 34, 0xFF, 0xFF,
  /* ABS: 006 Pixels @ 036,003 */ 0, 6, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x41, 0x08, 0x82,
  /* RLE: 034 Pixels @ 002,004 */ 34, 0xFF, 0xFF,
  /* ABS: 006 Pixels @ 036,004 */ 0, 6, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x41, 0x08, 0x82,
  /* RLE: 034 Pixels @ 002,005 */ 34, 0xFF, 0xFF,
  /* ABS: 006 Pixels @ 036,005 */ 0, 6, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x41, 0x08, 0x82,
  /* RLE: 034 Pixels @ 002,006 */ 34, 0xFF, 0xFF,
  /* ABS: 006 Pixels @ 036,006 */ 0, 6, 0x04, 0x41, 0x04, 0x41, 0x0C, 0x82, 0xDF, 0xEF, 0x04, 0x41, 0x08, 0x82,
  /* RLE: 016 Pixels @ 002,007 */ 16, 0xFF, 0xFF,
  /* ABS: 002 Pixels @ 018,007 */ 0, 2, 0xF7, 0xBD, 0x13, 0xA5,
  /* RLE: 016 Pixels @ 020,007 */ 16, 0xFF, 0xFF,
  /* ABS: 006 Pixels @ 036,007 */ 0, 6, 0x04, 0x41, 0x08, 0x41, 0x08, 0x40, 0x0C, 0x83, 0x04, 0x41, 0x08, 0x82,
  /* RLE: 016 Pixels @ 002,008 */ 16, 0xFF, 0xFF,
  /* ABS: 003 Pixels @ 018,008 */ 0, 3, 0x13, 0xA5, 0x04, 0x40, 0xDF, 0xEF,
  /* RLE: 015 Pixels @ 021,008 */ 15, 0xFF, 0xFF,
  /* ABS: 006 Pixels @ 036,008 */ 0, 6, 0x04, 0x41, 0x08, 0x41, 0x04, 0x41, 0x10, 0x84, 0x04, 0x41, 0x08, 0x82,
  /* RLE: 012 Pixels @ 002,009 */ 12, 0xFF, 0xFF,
  /* ABS: 008 Pixels @ 014,009 */ 0, 8, 0xDF, 0xEF, 0x10, 0x83, 0xD7, 0xBE, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x00, 0x40, 0xF7, 0xBD,
  /* RLE: 014 Pixels @ 022,009 */ 14, 0xFF, 0xFF,
  /* ABS: 006 Pixels @ 036,009 */ 0, 6, 0x04, 0x41, 0x08, 0x41, 0x08, 0x41, 0x10, 0x84, 0x04, 0x41, 0x08, 0x82,
  /* RLE: 014 Pixels @ 002,010 */ 14, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 016,010 */ 0, 7, 0x04, 0x41, 0x08, 0x41, 0x08, 0x42, 0x0C, 0x42, 0xF7, 0xBD, 0x04, 0x40, 0x13, 0xA5,
  /* RLE: 013 Pixels @ 023,010 */ 13, 0xFF, 0xFF,
  /* ABS: 006 Pixels @ 036,010 */ 0, 6, 0x04, 0x41, 0x08, 0x41, 0x04, 0x41, 0x10, 0x84, 0x04, 0x41, 0x08, 0x82,
  /* RLE: 015 Pixels @ 002,011 */ 15, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 017,011 */ 0, 7, 0x0C, 0x83, 0x00, 0x40, 0x10, 0x84, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0xBD, 0xDF, 0xEF,
  /* RLE: 012 Pixels @ 024,011 */ 12, 0xFF, 0xFF,
  /* ABS: 006 Pixels @ 036,011 */ 0, 6, 0x04, 0x41, 0x08, 0x41, 0x04, 0x41, 0x10, 0x84, 0x04, 0x41, 0x08, 0x82,
  /* RLE: 016 Pixels @ 002,012 */ 16, 0xFF, 0xFF,
  /* ABS: 002 Pixels @ 018,012 */ 0, 2, 0x0C, 0x83, 0x13, 0xA5,
  /* RLE: 016 Pixels @ 020,012 */ 16, 0xFF, 0xFF,
  /* ABS: 006 Pixels @ 036,012 */ 0, 6, 0x04, 0x41, 0x08, 0x41, 0x04, 0x41, 0x10, 0x84, 0x04, 0x41, 0x08, 0x82,
  /* RLE: 034 Pixels @ 002,013 */ 34, 0xFF, 0xFF,
  /* ABS: 006 Pixels @ 036,013 */ 0, 6, 0x04, 0x41, 0x04, 0x41, 0x04, 0x40, 0x0C, 0x84, 0x04, 0x41, 0x08, 0x82,
  /* RLE: 034 Pixels @ 002,014 */ 34, 0xFF, 0xFF,
  /* ABS: 006 Pixels @ 036,014 */ 0, 6, 0x04, 0x41, 0x08, 0x42, 0x13, 0xA5, 0xFF, 0xFF, 0x04, 0x41, 0x08, 0x82,
  /* RLE: 034 Pixels @ 002,015 */ 34, 0xFF, 0xFF,
  /* ABS: 006 Pixels @ 036,015 */ 0, 6, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x41, 0x0C, 0x83,
  /* RLE: 034 Pixels @ 002,016 */ 34, 0xFF, 0xFF,
  /* ABS: 006 Pixels @ 036,016 */ 0, 6, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x41, 0x08, 0x42,
  /* RLE: 034 Pixels @ 002,017 */ 34, 0xFF, 0xFF,
  /* ABS: 008 Pixels @ 036,017 */ 0, 8, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0xFF, 0xFF, 0x0C, 0x83, 0x00, 0x40, 0x13, 0xA5, 0xD7, 0xBE,
  /* RLE: 032 Pixels @ 004,018 */ 32, 0xF7, 0xBD,
  /* ABS: 007 Pixels @ 036,018 */ 0, 7, 0x00, 0x00, 0x10, 0x84, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x41, 0x04, 0x41,
  /* RLE: 033 Pixels @ 003,019 */ 33, 0x00, 0x40,
  /* ABS: 004 Pixels @ 036,019 */ 0, 4, 0x08, 0x42, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0
};  // 408 for 800 pixels

GUI_CONST_STORAGE GUI_BITMAP bmbeh = {
  40, // xSize
  20, // ySize
  80, // BytesPerLine
  16, // BitsPerPixel
  (unsigned char *)_acbeh,  // Pointer to picture data
  NULL,  // Pointer to palette
  GUI_DRAW_RLE16
};

/*************************** End of file ****************************/
