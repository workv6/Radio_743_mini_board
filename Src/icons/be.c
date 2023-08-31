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
* Source file: be                                                    *
* Dimensions:  30 * 61                                               *
* NumColors:   16bpp: 65536                                          *
*                                                                    *
**********************************************************************
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif



static GUI_CONST_STORAGE unsigned char _acbe[] = {
  /* RLE: 009 Pixels @ 000,000 */ 9, 0xFF, 0xFF,
  /* RLE: 001 Pixels @ 009,000 */ 1, 0xF7, 0xBD,
  /* RLE: 009 Pixels @ 010,000 */ 9, 0x10, 0x84,
  /* ABS: 002 Pixels @ 019,000 */ 0, 2, 0x13, 0xA5, 0xDF, 0xEF,
  /* RLE: 017 Pixels @ 021,000 */ 17, 0xFF, 0xFF,
  /* RLE: 001 Pixels @ 008,001 */ 1, 0xDF, 0xEF,
  /* RLE: 010 Pixels @ 009,001 */ 10, 0x04, 0x41,
  /* ABS: 002 Pixels @ 019,001 */ 0, 2, 0x04, 0x40, 0x10, 0x84,
  /* RLE: 013 Pixels @ 021,001 */ 13, 0xFF, 0xFF,
  /* ABS: 006 Pixels @ 004,002 */ 0, 6, 0xDF, 0xEF, 0xFF, 0xFF, 0xDF, 0xEF, 0xFF, 0xFF, 0xF7, 0xBD, 0x04, 0x41,
  /* RLE: 009 Pixels @ 010,002 */ 9, 0x08, 0x41,
  /* ABS: 004 Pixels @ 019,002 */ 0, 4, 0x04, 0x41, 0x0C, 0x83, 0xFF, 0xFF, 0xDF, 0xEF,
  /* RLE: 009 Pixels @ 023,002 */ 9, 0xFF, 0xFF,
  /* ABS: 002 Pixels @ 002,003 */ 0, 2, 0xF7, 0xBD, 0x0C, 0x83,
  /* RLE: 004 Pixels @ 004,003 */ 4, 0x0C, 0x42,
  /* RLE: 001 Pixels @ 008,003 */ 1, 0x08, 0x42,
  /* RLE: 011 Pixels @ 009,003 */ 11, 0x08, 0x41,
  /* RLE: 001 Pixels @ 020,003 */ 1, 0x08, 0x42,
  /* RLE: 004 Pixels @ 021,003 */ 4, 0x0C, 0x42,
  /* ABS: 009 Pixels @ 025,003 */ 0, 9, 0x0C, 0x82, 0x10, 0x84, 0xDF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x13, 0x84, 0x04, 0x41, 0x04, 0x41,
  /* RLE: 005 Pixels @ 004,004 */ 5, 0x04, 0x40,
  /* RLE: 012 Pixels @ 009,004 */ 12, 0x04, 0x41,
  /* RLE: 005 Pixels @ 021,004 */ 5, 0x04, 0x40,
  /* ABS: 009 Pixels @ 026,004 */ 0, 9, 0x04, 0x41, 0x08, 0x42, 0xD7, 0xBE, 0xFF, 0xFF, 0xF7, 0xBD, 0x04, 0x41, 0x04, 0x41, 0x08, 0x42, 0x10, 0x84,
  /* RLE: 016 Pixels @ 005,005 */ 16, 0x13, 0x84,
  /* ABS: 013 Pixels @ 021,005 */ 0, 13, 0x13, 0xA5, 0x13, 0x84, 0x13, 0x84, 0x13, 0xA5, 0x10, 0x83, 0x08, 0x41, 0x04, 0x41, 0x0C, 0x83, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x08, 0x42, 0xDF, 0xEF,
  /* RLE: 022 Pixels @ 004,006 */ 22, 0xFF, 0xFF,
  /* ABS: 009 Pixels @ 026,006 */ 0, 9, 0x13, 0xA5, 0x04, 0x41, 0x08, 0x41, 0xD7, 0xBE, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83, 0xFF, 0xFF, 0xDF, 0xEF,
  /* RLE: 021 Pixels @ 005,007 */ 21, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,007 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,008 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,008 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,009 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,009 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,010 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,010 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,011 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,011 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,012 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,012 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,013 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,013 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,014 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,014 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,015 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,015 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,016 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,016 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,017 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,017 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,018 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,018 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,019 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,019 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,020 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,020 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,021 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,021 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,022 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,022 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,023 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,023 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,024 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,024 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 012 Pixels @ 003,025 */ 12, 0xFF, 0xFF,
  /* ABS: 002 Pixels @ 015,025 */ 0, 2, 0xDF, 0xEF, 0xF7, 0xBD,
  /* RLE: 009 Pixels @ 017,025 */ 9, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,025 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 011 Pixels @ 003,026 */ 11, 0xFF, 0xFF,
  /* ABS: 003 Pixels @ 014,026 */ 0, 3, 0xDF, 0xEF, 0x0C, 0x83, 0xDF, 0xEF,
  /* RLE: 009 Pixels @ 017,026 */ 9, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,026 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 011 Pixels @ 003,027 */ 11, 0xFF, 0xFF,
  /* ABS: 002 Pixels @ 014,027 */ 0, 2, 0x0C, 0x83, 0x10, 0x84,
  /* RLE: 010 Pixels @ 016,027 */ 10, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,027 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 010 Pixels @ 003,028 */ 10, 0xFF, 0xFF,
  /* ABS: 003 Pixels @ 013,028 */ 0, 3, 0x10, 0x84, 0x04, 0x41, 0xD7, 0xBE,
  /* RLE: 010 Pixels @ 016,028 */ 10, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,028 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 009 Pixels @ 003,029 */ 9, 0xFF, 0xFF,
  /* ABS: 003 Pixels @ 012,029 */ 0, 3, 0x13, 0x84, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 011 Pixels @ 015,029 */ 11, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,029 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 008 Pixels @ 003,030 */ 8, 0xFF, 0xFF,
  /* ABS: 004 Pixels @ 011,030 */ 0, 4, 0x13, 0xA5, 0x04, 0x41, 0x04, 0x41, 0x17, 0xBD,
  /* RLE: 011 Pixels @ 015,030 */ 11, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,030 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 007 Pixels @ 003,031 */ 7, 0xFF, 0xFF,
  /* ABS: 009 Pixels @ 010,031 */ 0, 9, 0x13, 0xA5, 0x04, 0x40, 0x04, 0x41, 0x08, 0x41, 0x08, 0x42, 0x0C, 0x83, 0x10, 0x84, 0x17, 0xBD, 0xD7, 0xBE,
  /* RLE: 007 Pixels @ 019,031 */ 7, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,031 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 007 Pixels @ 003,032 */ 7, 0xFF, 0xFF,
  /* ABS: 009 Pixels @ 010,032 */ 0, 9, 0x13, 0xA5, 0x10, 0x83, 0x0C, 0x42, 0x08, 0x41, 0x04, 0x41, 0x04, 0x41, 0x04, 0x41, 0x04, 0x40, 0xF7, 0xBD,
  /* RLE: 007 Pixels @ 019,032 */ 7, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,032 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 009 Pixels @ 003,033 */ 9, 0xFF, 0xFF,
  /* ABS: 006 Pixels @ 012,033 */ 0, 6, 0xDF, 0xEF, 0xD7, 0xBE, 0x13, 0xA5, 0x08, 0x41, 0x04, 0x41, 0x13, 0xA5,
  /* RLE: 008 Pixels @ 018,033 */ 8, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,033 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 011 Pixels @ 003,034 */ 11, 0xFF, 0xFF,
  /* ABS: 003 Pixels @ 014,034 */ 0, 3, 0x13, 0x84, 0x04, 0x40, 0x13, 0x84,
  /* RLE: 009 Pixels @ 017,034 */ 9, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,034 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 010 Pixels @ 003,035 */ 10, 0xFF, 0xFF,
  /* ABS: 003 Pixels @ 013,035 */ 0, 3, 0xDF, 0xEF, 0x08, 0x41, 0x10, 0x83,
  /* RLE: 010 Pixels @ 016,035 */ 10, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,035 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 010 Pixels @ 003,036 */ 10, 0xFF, 0xFF,
  /* ABS: 002 Pixels @ 013,036 */ 0, 2, 0x13, 0xA5, 0x0C, 0x83,
  /* RLE: 011 Pixels @ 015,036 */ 11, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,036 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 009 Pixels @ 003,037 */ 9, 0xFF, 0xFF,
  /* ABS: 003 Pixels @ 012,037 */ 0, 3, 0xDF, 0xEF, 0x10, 0x84, 0xDF, 0xEF,
  /* RLE: 011 Pixels @ 015,037 */ 11, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,037 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 009 Pixels @ 003,038 */ 9, 0xFF, 0xFF,
  /* ABS: 002 Pixels @ 012,038 */ 0, 2, 0xDF, 0xEF, 0xDF, 0xEF,
  /* RLE: 012 Pixels @ 014,038 */ 12, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,038 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,039 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,039 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,040 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,040 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,041 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,041 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,042 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,042 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,043 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,043 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,044 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,044 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,045 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,045 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,046 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,046 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,047 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,047 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,048 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,048 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,049 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,049 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,050 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,050 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,051 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,051 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,052 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,052 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,053 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,053 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,054 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 026,054 */ 0, 7, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83,
  /* RLE: 023 Pixels @ 003,055 */ 23, 0xFF, 0xFF,
  /* ABS: 009 Pixels @ 026,055 */ 0, 9, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x0C, 0x83, 0x04, 0x40, 0x10, 0x83, 0xFF, 0xFF, 0xDF, 0xEF,
  /* RLE: 021 Pixels @ 005,056 */ 21, 0xFF, 0xFF,
  /* ABS: 008 Pixels @ 026,056 */ 0, 8, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0x10, 0x84, 0x04, 0x40, 0x08, 0x42, 0xDF, 0xEF,
  /* RLE: 022 Pixels @ 004,057 */ 22, 0xFF, 0xFF,
  /* ABS: 008 Pixels @ 026,057 */ 0, 8, 0x13, 0xA5, 0x04, 0x41, 0x08, 0x41, 0xD7, 0xBE, 0xF7, 0xBD, 0x04, 0x41, 0x04, 0x41, 0x0C, 0x42,
  /* RLE: 021 Pixels @ 004,058 */ 21, 0x13, 0xA5,
  /* ABS: 010 Pixels @ 025,058 */ 0, 10, 0x10, 0x84, 0x08, 0x41, 0x04, 0x41, 0x0C, 0x83, 0xFF, 0xFF, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x41, 0x04, 0x41, 0x04, 0x41,
  /* RLE: 020 Pixels @ 005,059 */ 20, 0x04, 0x40,
  /* ABS: 009 Pixels @ 025,059 */ 0, 9, 0x04, 0x41, 0x04, 0x41, 0x08, 0x41, 0xD7, 0xBE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x13, 0xA5, 0x0C, 0x83,
  /* RLE: 022 Pixels @ 004,060 */ 22, 0x08, 0x42,
  /* ABS: 004 Pixels @ 026,060 */ 0, 4, 0x10, 0x84, 0xDF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF,
  0
};  // 1316 for 1830 pixels

GUI_CONST_STORAGE GUI_BITMAP bmbe = {
  30, // xSize
  61, // ySize
  60, // BytesPerLine
  16, // BitsPerPixel
  (unsigned char *)_acbe,  // Pointer to picture data
  NULL,  // Pointer to palette
  GUI_DRAW_RLE16
};

/*************************** End of file ****************************/
