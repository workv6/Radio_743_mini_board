#ifndef __ILI9806_H
#define __ILI9806_H
#include "main.h"

//#define Lcd_Light_ON   GPIOA->BSRRL = GPIO_Pin_8;
//#define Lcd_Light_OFF  GPIOA->BSRRH  = GPIO_Pin_8;


#define u16 uint16_t
#define vu16 volatile uint16_t
#define u8  uint8_t
#define u32 uint32_t

extern u16  POINT_COLOR;
extern u16  BACK_COLOR;


//#define	LCD_LED PBout(15)  		//LCD??    		 PB15





#define Bank1_LCD_C    ((u32)0xc0000000)
#define Bank1_LCD_D    ((u32)0xc0020000)		//

typedef struct
{
	u16		width;		//LCD ??
	u16		height;		//LCD ??
	u16		id;			//LCD ID
	u8 		dir;			//????????:0,??;1,???
	u16		touch_x;		//??????
	u16		touch_y;		//??????
}_lcd_dev;

extern _lcd_dev lcd_dev;


//??????
#define L2R_U2D  0 //????,????
#define L2R_D2U  1 //????,????
#define R2L_U2D  2 //????,????
#define R2L_D2U  3 //????,????

#define U2D_L2R  4 //????,????
#define U2D_R2L  5 //????,????
#define D2U_L2R  6 //????,????
#define D2U_R2L  7 //????,????

#define DFT_SCAN_DIR  L2R_U2D  //???????

//????
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000
#define BLUE         	 0x001F
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //??
#define BRRED 			 0XFC07 //???
#define GRAY  			 0X8430 //??
//GUI??

#define DARKBLUE      	 0X01CF	//???
#define LIGHTBLUE      	 0X7D7C	//???
#define GRAYBLUE       	 0X5458 //???
//?????PANEL???

#define LIGHTGREEN     	 0X841F //???
//#define LIGHTGRAY        0XEF5B //???(PANNEL)
#define LGRAY 			 0XC618 //???(PANNEL),?????

#define LGRAYBLUE        0XA651 //????(?????)
#define LBBLUE           0X2B12 //????(???????)

void TFTLCD_Init(void);													   	//???
u16 LCD_ReadPoint(u16 x,u16 y);

void LCD_DisplayOn(void);													//???
void LCD_DisplayOff(void);													//???
void LCD_Clear(u16 Color);	 												//??
void LCD_SetBackLight(u32 pwm);
void LCD_SetCursor(u16 Xpos, u16 Ypos);										//????
void LCD_DrawPoint(u16 x,u16 y);											//??
void LCD_Fast_DrawPoint(u16 x,u16 y,u16 color);								//????
u16  LCD_ReadPoint(u16 x,u16 y); 											//??
void LCD_Draw_Circle(u16 x0,u16 y0,u8 r);						 			//??
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2);							//??
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2);		   				//???
void LCD_Fill(u16 x, u16 y, u16 width, u16 height, u16 color);		   				//????
void LCD_Color_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 *color);				//??????
void LCD_ShowChar(u16 x,u16 y,u8 num,u8 size,u8 mode);						//??????
void LCD_ShowNum(u16 x,u16 y,u32 num,u8 len,u8 size);  						//??????
void LCD_ShowxNum(u16 x,u16 y,u32 num,u8 len,u8 size,u8 mode);				//?? ??
void LCD_ShowString(u16 x,u16 y,u16 width,u16 height,u8 size,u8 *p);		//???????,12/16??

void LCD_WR_REG(vu16 regval);
void LCD_WR_DATA(vu16 data);
u16 LCD_RD_DATA(void);
void LCD_WriteReg(u16 LCD_Reg, u16 LCD_RegValue);
u16 LCD_ReadReg(u16 LCD_Reg);
void LCD_WriteRAM_Prepare(void);
void LCD_WriteRAM(u16 RGB_Code);
void LCD_Scan_Dir(u8 dir);									//???????
void LCD_Display_Dir(u8 dir);								//????????

#endif


