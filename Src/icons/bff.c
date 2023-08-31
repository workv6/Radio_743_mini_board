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
* Source file: bff                                                   *
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



static GUI_CONST_STORAGE unsigned char _acbff[] = {
  /* RLE: 009 Pixels @ 000,000 */ 9, 0xFF, 0xFF,
  /* ABS: 002 Pixels @ 009,000 */ 0, 2, 0xDF, 0xEF, 0x13, 0xA5,
  /* RLE: 009 Pixels @ 011,000 */ 9, 0x10, 0x84,
  /* RLE: 001 Pixels @ 020,000 */ 1, 0x17, 0xBD,
  /* RLE: 018 Pixels @ 021,000 */ 18, 0xFF, 0xFF,
  /* ABS: 002 Pixels @ 009,001 */ 0, 2, 0x13, 0x84, 0x04, 0x40,
  /* RLE: 010 Pixels @ 011,001 */ 10, 0x04, 0x41,
  /* RLE: 001 Pixels @ 021,001 */ 1, 0xF7, 0xBD,
  /* RLE: 013 Pixels @ 022,001 */ 13, 0xFF, 0xFF,
  /* ABS: 006 Pixels @ 005,002 */ 0, 6, 0xDF, 0xEF, 0xFF, 0xFF, 0xDF, 0xEF, 0xFF, 0xFF, 0x10, 0x83, 0x04, 0x41,
  /* RLE: 009 Pixels @ 011,002 */ 9, 0x08, 0x41,
  /* ABS: 004 Pixels @ 020,002 */ 0, 4, 0x04, 0x41, 0xF7, 0xBD, 0xFF, 0xFF, 0xDF, 0xEF,
  /* RLE: 008 Pixels @ 024,002 */ 8, 0xFF, 0xFF,
  /* ABS: 003 Pixels @ 002,003 */ 0, 3, 0xDF, 0xEF, 0x13, 0x84, 0x0C, 0x83,
  /* RLE: 004 Pixels @ 005,003 */ 4, 0x0C, 0x42,
  /* RLE: 001 Pixels @ 009,003 */ 1, 0x08, 0x42,
  /* RLE: 011 Pixels @ 010,003 */ 11, 0x08, 0x41,
  /* RLE: 001 Pixels @ 021,003 */ 1, 0x08, 0x42,
  /* RLE: 004 Pixels @ 022,003 */ 4, 0x0C, 0x42,
  /* ABS: 008 Pixels @ 026,003 */ 0, 8, 0x0C, 0x83, 0x17, 0xBD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0xEF, 0x0C, 0x42, 0x04, 0x41,
  /* RLE: 006 Pixels @ 004,004 */ 6, 0x04, 0x40,
  /* RLE: 011 Pixels @ 010,004 */ 11, 0x04, 0x41,
  /* RLE: 005 Pixels @ 021,004 */ 5, 0x04, 0x40,
  /* ABS: 010 Pixels @ 026,004 */ 0, 10, 0x04, 0x41, 0x04, 0x41, 0x10, 0x84, 0xFF, 0xFF, 0xFF, 0xFF, 0x10, 0x83, 0x04, 0x40, 0x08, 0x41, 0x10, 0x83, 0x13, 0xA5,
  /* RLE: 016 Pixels @ 006,005 */ 16, 0x13, 0x84,
  /* ABS: 012 Pixels @ 022,005 */ 0, 12, 0x13, 0xA5, 0x13, 0x84, 0x13, 0x84, 0x13, 0x84, 0x0C, 0x42, 0x04, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xDF, 0xEF, 0x08, 0x41, 0x04, 0x41, 0x10, 0x84,
  /* RLE: 022 Pixels @ 004,006 */ 22, 0xFF, 0xFF,
  /* ABS: 010 Pixels @ 026,006 */ 0, 10, 0xDF, 0xEF, 0x0C, 0x42, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xFF, 0xFF, 0xDF, 0xEF,
  /* RLE: 019 Pixels @ 006,007 */ 19, 0xFF, 0xFF,
  /* ABS: 009 Pixels @ 025,007 */ 0, 9, 0xDF, 0xEF, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD,
  /* RLE: 023 Pixels @ 004,008 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 027,008 */ 0, 7, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD,
  /* RLE: 023 Pixels @ 004,009 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 027,009 */ 0, 7, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD,
  /* RLE: 023 Pixels @ 004,010 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 027,010 */ 0, 7, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD,
  /* RLE: 023 Pixels @ 004,011 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 027,011 */ 0, 7, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD,
  /* RLE: 023 Pixels @ 004,012 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 027,012 */ 0, 7, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD,
  /* RLE: 023 Pixels @ 004,013 */ 23, 0xFF, 0xFF,
  /* ABS: 007 Pixels @ 027,013 */ 0, 7, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD,
  /* RLE: 023 Pixels @ 004,014 */ 23, 0xFF, 0xFF,
  /* ABS: 009 Pixels @ 027,014 */ 0, 9, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x82, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xFF, 0xFF, 0xDF, 0xEF,
  /* RLE: 019 Pixels @ 006,015 */ 19, 0xFF, 0xFF,
  /* ABS: 009 Pixels @ 025,015 */ 0, 9, 0xDF, 0xEF, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD,
  /* RLE: 023 Pixels @ 004,016 */ 23, 0xFF, 0xFF,
  /* ABS: 008 Pixels @ 027,016 */ 0, 8, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xDF, 0xEF,
  /* RLE: 020 Pixels @ 005,017 */ 20, 0x10, 0x84,
  /* ABS: 011 Pixels @ 025,017 */ 0, 11, 0x13, 0xA5, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xD7, 0xBE, 0xF7, 0xBD, 0x04, 0x40,
  /* RLE: 018 Pixels @ 006,018 */ 18, 0x04, 0x41,
  /* ABS: 012 Pixels @ 024,018 */ 0, 12, 0x04, 0x40, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xD7, 0xBE, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,019 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,019 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xD7, 0xBE, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,020 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,020 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xD7, 0xBE, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,021 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,021 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,022 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,022 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x82, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xD7, 0xBE, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,023 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,023 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,024 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,024 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xF7, 0xBD, 0x04, 0x40,
  /* RLE: 018 Pixels @ 006,025 */ 18, 0x04, 0x41,
  /* ABS: 011 Pixels @ 024,025 */ 0, 11, 0x04, 0x40, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xDF, 0xEF,
  /* RLE: 021 Pixels @ 005,026 */ 21, 0xF7, 0xBD,
  /* ABS: 009 Pixels @ 026,026 */ 0, 9, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xFF, 0xFF,
  /* RLE: 021 Pixels @ 005,027 */ 21, 0xDF, 0xEF,
  /* ABS: 010 Pixels @ 026,027 */ 0, 10, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,028 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,028 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xD7, 0xBE, 0xF7, 0xBD, 0x04, 0x41,
  /* RLE: 004 Pixels @ 006,029 */ 4, 0x08, 0x41,
  /* ABS: 002 Pixels @ 010,029 */ 0, 2, 0x04, 0x41, 0x04, 0x41,
  /* RLE: 007 Pixels @ 012,029 */ 7, 0x08, 0x41,
  /* RLE: 003 Pixels @ 019,029 */ 3, 0x04, 0x41,
  /* ABS: 014 Pixels @ 022,029 */ 0, 14, 0x08, 0x41, 0x08, 0x41, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,030 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,030 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x82, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,031 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,031 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x82, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xD7, 0xBE, 0xF7, 0xBD, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,032 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,032 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,033 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,033 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,034 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,034 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x82, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xF7, 0xBD, 0x04, 0x40,
  /* RLE: 019 Pixels @ 006,035 */ 19, 0x04, 0x41,
  /* ABS: 011 Pixels @ 025,035 */ 0, 11, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xD7, 0xBE, 0x0C, 0x42,
  /* RLE: 018 Pixels @ 006,036 */ 18, 0x0C, 0x83,
  /* ABS: 010 Pixels @ 024,036 */ 0, 10, 0x0C, 0x82, 0x10, 0x83, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD,
  /* RLE: 023 Pixels @ 004,037 */ 23, 0xFF, 0xFF,
  /* ABS: 012 Pixels @ 027,037 */ 0, 12, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xDF, 0xEF, 0x10, 0x83, 0x10, 0x84, 0x10, 0x83, 0x10, 0x83,
  /* RLE: 007 Pixels @ 009,038 */ 7, 0x10, 0x84,
  /* RLE: 001 Pixels @ 016,038 */ 1, 0x10, 0x83,
  /* RLE: 007 Pixels @ 017,038 */ 7, 0x10, 0x84,
  /* ABS: 012 Pixels @ 024,038 */ 0, 12, 0x10, 0x83, 0x10, 0x84, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xD7, 0xBE, 0xF7, 0xBD, 0x04, 0x40,
  /* RLE: 018 Pixels @ 006,039 */ 18, 0x04, 0x41,
  /* ABS: 012 Pixels @ 024,039 */ 0, 12, 0x04, 0x40, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,040 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,040 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x82, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xD7, 0xBE, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,041 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,041 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xF7, 0xBD, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,042 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,042 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x82, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xD7, 0xBE, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,043 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,043 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xD7, 0xBE, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,044 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,044 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xD7, 0xBE, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,045 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,045 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xD7, 0xBE, 0xF7, 0xBD, 0x04, 0x40,
  /* RLE: 019 Pixels @ 006,046 */ 19, 0x04, 0x41,
  /* ABS: 010 Pixels @ 025,046 */ 0, 10, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xFF, 0xFF,
  /* RLE: 021 Pixels @ 005,047 */ 21, 0xD7, 0xBE,
  /* ABS: 009 Pixels @ 026,047 */ 0, 9, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xDF, 0xEF,
  /* RLE: 020 Pixels @ 005,048 */ 20, 0x13, 0xA5,
  /* ABS: 011 Pixels @ 025,048 */ 0, 11, 0x17, 0xBD, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xD7, 0xBE, 0xF7, 0xBD, 0x04, 0x40,
  /* RLE: 018 Pixels @ 006,049 */ 18, 0x04, 0x41,
  /* ABS: 012 Pixels @ 024,049 */ 0, 12, 0x04, 0x40, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,050 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,050 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xD7, 0xBE, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,051 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,051 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x82, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xD7, 0xBE, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,052 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,052 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xD7, 0xBE, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,053 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,053 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,054 */ 18, 0x08, 0x41,
  /* ABS: 012 Pixels @ 024,054 */ 0, 12, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xF7, 0xBD, 0xF7, 0xBD, 0x04, 0x41,
  /* RLE: 014 Pixels @ 006,055 */ 14, 0x08, 0x41,
  /* ABS: 016 Pixels @ 020,055 */ 0, 16, 0x04, 0x41, 0x04, 0x41, 0x08, 0x41, 0x08, 0x41, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x83, 0xD7, 0xBE, 0x08, 0x41, 0x04, 0x41, 0xD7, 0xBE, 0xD7, 0xBE, 0x04, 0x41,
  /* RLE: 018 Pixels @ 006,056 */ 18, 0x08, 0x41,
  /* ABS: 011 Pixels @ 024,056 */ 0, 11, 0x04, 0x41, 0x08, 0x42, 0xFF, 0xFF, 0x10, 0x84, 0x04, 0x40, 0x0C, 0x82, 0xDF, 0xEF, 0x08, 0x41, 0x04, 0x41, 0x13, 0x84, 0xFF, 0xFF,
  /* RLE: 022 Pixels @ 005,057 */ 22, 0xDF, 0xEF,
  /* ABS: 009 Pixels @ 027,057 */ 0, 9, 0x0C, 0x82, 0x04, 0x40, 0x0C, 0x83, 0xFF, 0xFF, 0x0C, 0x83, 0x04, 0x41, 0x08, 0x41, 0x10, 0x84, 0x13, 0xBD,
  /* RLE: 020 Pixels @ 006,058 */ 20, 0x13, 0xA5,
  /* ABS: 009 Pixels @ 026,058 */ 0, 9, 0x0C, 0x83, 0x04, 0x41, 0x04, 0x41, 0x13, 0xBD, 0xFF, 0xFF, 0xDF, 0xEF, 0x08, 0x42, 0x04, 0x41, 0x04, 0x41,
  /* RLE: 021 Pixels @ 005,059 */ 21, 0x04, 0x40,
  /* ABS: 008 Pixels @ 026,059 */ 0, 8, 0x04, 0x41, 0x04, 0x41, 0x10, 0x83, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0xEF, 0x10, 0x84,
  /* RLE: 022 Pixels @ 004,060 */ 22, 0x08, 0x42,
  /* ABS: 004 Pixels @ 026,060 */ 0, 4, 0x0C, 0x82, 0x13, 0xA5, 0xFF, 0xFF, 0xFF, 0xFF,
  0
};  // 1552 for 1830 pixels

GUI_CONST_STORAGE GUI_BITMAP bmbff = {
  30, // xSize
  61, // ySize
  60, // BytesPerLine
  16, // BitsPerPixel
  (unsigned char *)_acbff,  // Pointer to picture data
  NULL,  // Pointer to palette
  GUI_DRAW_RLE16
};

/*************************** End of file ****************************/
