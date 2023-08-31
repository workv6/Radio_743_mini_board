#include "main.h"
#include "rm68120.h"




//LCD的画笔颜色和背景色
u16 POINT_COLOR=0x0000;	//画笔颜色
u16 BACK_COLOR=0xFFFF;  //背景色


_lcd_dev lcd_dev;


void LCD_delay(u32 nCount)
{
	__IO u32 i;
	for(i=0;i<100000;i++)
		for(; nCount != 0; nCount--);

     //   HAL_Delay(nCount);
}

void LCD_WR_REG(u16 regval)
{
	*(__IO u16 *) (Bank1_LCD_C) = regval;
}


void LCD_WR_DATA(u16 data)
{
//	*(__IO u16 *) (Bank1_LCD_D) = data;
        uint16_t tmp;
        tmp = (uint16_t)(data>>8 | data<<8);
        *(__IO u16 *) (Bank1_LCD_D) = tmp;
    
/*      *(__IO u16 *) (Bank1_LCD_D) = data&0xFF00;
     *(__IO u16 *) (Bank1_LCD_D) = (data&0x00FF)<<8;    
*/
}

/*
****************************************************************
*??: ???
*???: ????
****************************************************************
*/
    u8 b1, b2, *ptr;
u16 LCD_RD_DATA(void)
{
	u16 data;

      //  ptr = (u8 *)0x60010000;
       // b1 = ptr[0];
      //  b2 = ptr[1];

       // data = b1 * 256 + b2;

	 data =*(__IO u16 *)Bank1_LCD_D;
	return data;
}

/*
****************************************************************
*??: ????
*??: ????????
****************************************************************
*/
void LCD_WriteReg(u16 regval, u16 data)
{
	LCD_WR_REG(regval);
	LCD_WR_DATA(data);
}



/*
****************************************************************
*功能: 设定光标位置
*参数: 横纵坐标值
****************************************************************
*/
void LCD_SetCursor(u16 x, u16 y)
{
	LCD_WR_REG(0X2A00);		/* column address control set */
	LCD_WR_DATA(x>>8);	/* 先高8位，然后低8位 */
	LCD_WR_DATA(x&0xff);	/* 设置起始点和结束点*/

	LCD_WR_REG(0X2B00);		/* page address control set */
	LCD_WR_DATA(y>>8);
	LCD_WR_DATA(y&0xff);
}

/*
****************************************************************
*功能: 读取某个点的颜色
*参数: 横纵坐标值
****************************************************************
*/
u16 LCD_ReadPoint(u16 x, u16 y)
{
	u16 r=0,g=0,b=0,color =0;
	if(x>=lcd_dev.width||y>=lcd_dev.height)
        return 0;	//超过了范围,直接返回
	LCD_SetCursor(x,y);
	LCD_WR_REG(0x2E00);		//发送读GRAM指令
	r=LCD_RD_DATA();		//dummy Read
	LCD_delay(2);
	r=LCD_RD_DATA();		//实际坐标颜色
	LCD_delay(2);
	b=LCD_RD_DATA();
	g=r&0XFF;
	g<<=8;
	color = (((r>>11)<<11)|((g>>10)<<5)|(b>>11));
	return color;
}

/*
****************************************************************
*功能: 画点
*参数: 横纵坐标值
****************************************************************
*/
void LCD_DrawPoint(u16 x,u16 y)
{
	LCD_SetCursor(x,y);		//设置光标位置
	LCD_WR_REG(0x2C00);		//开始写入GRAM
	LCD_WR_DATA(POINT_COLOR);
}

/*
****************************************************************
*功能: 快速画点
*参数: 横纵坐标值
****************************************************************
*/

void LCD_Fast_DrawPoint(u16 x, u16 y, u16 color)
{
	LCD_WR_REG(0X2A00);		/* column address control set */
	LCD_WR_DATA(x>>8);	/* 先高8位，然后低8位 */
	LCD_WR_DATA(x&0xff);	/* 设置起始点和结束点*/

	LCD_WR_REG(0X2B00);		/* page address control set */
	LCD_WR_DATA(y>>8);
	LCD_WR_DATA(y&0xff);

	LCD_WR_REG(0x2C00);		//开始写入GRAM
	LCD_WR_DATA(color);
}



/*
****************************************************************
*功能: 设置LCD扫描方向
*参数:
****************************************************************
*/
void LCD_Scan_Dir(u8 dir)
{
	u16 regval=0;
	u16 dirreg=0;
	u16 temp;
        lcd_dev.width = 480;
          lcd_dev.height = 854;
	if(lcd_dev.dir == 1)//横屏显示
	{
		switch(dir)//方向转换
		{
			case 0:dir=6;break;
			case 1:dir=7;break;
			case 2:dir=4;break;
			case 3:dir=5;break;
			case 4:dir=1;break;
			case 5:dir=0;break;
			case 6:dir=3;break;
			case 7:dir=2;break;
		}
	}

	switch(dir)
	{
		case L2R_U2D://从左到右,从上到下
			regval|=(0<<7)|(0<<6)|(0<<5);
			break;
		case L2R_D2U://从左到右,从下到上
			regval|=(1<<7)|(0<<6)|(0<<5);
			break;
		case R2L_U2D://从右到左,从上到下
			regval|=(0<<7)|(1<<6)|(0<<5);
			break;
		case R2L_D2U://从右到左,从下到上
			regval|=(1<<7)|(1<<6)|(0<<5);
			break;
		case U2D_L2R://从上到下,从左到右
			regval|=(0<<7)|(0<<6)|(1<<5);
			break;
		case U2D_R2L://从上到下,从右到左
			regval|=(0<<7)|(1<<6)|(1<<5);
			break;
		case D2U_L2R://从下到上,从左到右
			regval|=(1<<7)|(0<<6)|(1<<5);
			break;
		case D2U_R2L://从下到上,从右到左
			regval|=(1<<7)|(1<<6)|(1<<5);
			break;
	}
	dirreg=0X3600;
	LCD_WriteReg(dirreg,regval);
	if((regval&0X20)||lcd_dev.dir==1)
	{
		if(lcd_dev.width<lcd_dev.height)//交换X,Y
		{
			temp=lcd_dev.width;
			lcd_dev.width=lcd_dev.height;
			lcd_dev.height=temp;
 		}
	}
	else
	{
		if(lcd_dev.width>lcd_dev.height)//交换X,Y
		{
			temp=lcd_dev.width;
			lcd_dev.width=lcd_dev.height;
			lcd_dev.height=temp;
 		}
	}
	LCD_WR_REG(0x2A00);
//	LCD_WR_DATA(0);
//	LCD_WR_DATA(0);
//	LCD_WR_DATA((lcd_dev.width-1)>>8);
//	LCD_WR_DATA((lcd_dev.width-1)&0XFF);
 	*(__IO u16 *) (Bank1_LCD_D) = (0);
	*(__IO u16 *) (Bank1_LCD_D) = (0);
	*(__IO u16 *) (Bank1_LCD_D) = ((lcd_dev.width-1)>>8);
	*(__IO u16 *) (Bank1_LCD_D) = ((lcd_dev.width-1)&0XFF);     
        
	LCD_WR_REG(0x2B00);
/*	LCD_WR_DATA(0);
	LCD_WR_DATA(0);
	LCD_WR_DATA((lcd_dev.height-1)>>8);
	LCD_WR_DATA((lcd_dev.height-1)&0XFF);
*/
         *(__IO u16 *) (Bank1_LCD_D) = (0);
	*(__IO u16 *) (Bank1_LCD_D) = (0);
	*(__IO u16 *) (Bank1_LCD_D) = ((lcd_dev.height-1)>>8);
	*(__IO u16 *) (Bank1_LCD_D) = ((lcd_dev.height-1)&0XFF);  

}

/*
****************************************************************
*功能: 设置LCD显示方向
*参数: 0  竖屏     1横屏
****************************************************************
*/
void LCD_Display_Dir(u8 dir)
{
	if(dir == 0 )	//竖屏
	{
		lcd_dev.dir = 0;
		lcd_dev.width = 480;
		lcd_dev.height = 854;
	}
	else
	{
		lcd_dev.dir = 1;
		lcd_dev.width = 854;
		lcd_dev.height = 480;
	}
        
	LCD_Scan_Dir(L2R_U2D);	//默认扫描方向
}

static void LCD_Rst(void)
{
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET); // GPIO_ResetBits(GPIOC, GPIO_Pin_1);
    HAL_Delay(100);
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET); //GPIO_SetBits(GPIOC, GPIO_Pin_1);
    HAL_Delay(100);
}

/**********************************************
Lcd初始化函数
***********************************************/
void TFTLCD_Init(void)
{

	HAL_Delay(20);
	LCD_Rst();
        HAL_Delay(120);
    LCD_WR_REG(0x0100); // Software Reset
   HAL_Delay(20);

   
    LCD_WriteReg(0xF000, 0x55);
    LCD_WriteReg(0xF001, 0xAA);
    LCD_WriteReg(0xF002, 0x52);
    LCD_WriteReg(0xF003, 0x08);
    LCD_WriteReg(0xF004, 0x01);

    //GAMMA SETING  RED
    LCD_WriteReg(0xD100, 0x00);
    LCD_WriteReg(0xD101, 0x00);
    LCD_WriteReg(0xD102, 0x1b);
    LCD_WriteReg(0xD103, 0x44);
    LCD_WriteReg(0xD104, 0x62);
    LCD_WriteReg(0xD105, 0x00);
    LCD_WriteReg(0xD106, 0x7b);
    LCD_WriteReg(0xD107, 0xa1);
    LCD_WriteReg(0xD108, 0xc0);
    LCD_WriteReg(0xD109, 0xee);
    LCD_WriteReg(0xD10A, 0x55);
    LCD_WriteReg(0xD10B, 0x10);
    LCD_WriteReg(0xD10C, 0x2c);
    LCD_WriteReg(0xD10D, 0x43);
    LCD_WriteReg(0xD10E, 0x57);
    LCD_WriteReg(0xD10F, 0x55);
    LCD_WriteReg(0xD110, 0x68);
    LCD_WriteReg(0xD111, 0x78);
    LCD_WriteReg(0xD112, 0x87);
    LCD_WriteReg(0xD113, 0x94);
    LCD_WriteReg(0xD114, 0x55);
    LCD_WriteReg(0xD115, 0xa0);
    LCD_WriteReg(0xD116, 0xac);
    LCD_WriteReg(0xD117, 0xb6);
    LCD_WriteReg(0xD118, 0xc1);
    LCD_WriteReg(0xD119, 0x55);
    LCD_WriteReg(0xD11A, 0xcb);
    LCD_WriteReg(0xD11B, 0xcd);
    LCD_WriteReg(0xD11C, 0xd6);
    LCD_WriteReg(0xD11D, 0xdf);
    LCD_WriteReg(0xD11E, 0x95);
    LCD_WriteReg(0xD11F, 0xe8);
    LCD_WriteReg(0xD120, 0xf1);
    LCD_WriteReg(0xD121, 0xfa);
    LCD_WriteReg(0xD122, 0x02);
    LCD_WriteReg(0xD123, 0xaa);
    LCD_WriteReg(0xD124, 0x0b);
    LCD_WriteReg(0xD125, 0x13);
    LCD_WriteReg(0xD126, 0x1d);
    LCD_WriteReg(0xD127, 0x26);
    LCD_WriteReg(0xD128, 0xaa);
    LCD_WriteReg(0xD129, 0x30);
    LCD_WriteReg(0xD12A, 0x3c);
    LCD_WriteReg(0xD12B, 0x4A);
    LCD_WriteReg(0xD12C, 0x63);
    LCD_WriteReg(0xD12D, 0xea);
    LCD_WriteReg(0xD12E, 0x79);
    LCD_WriteReg(0xD12F, 0xa6);
    LCD_WriteReg(0xD130, 0xd0);
    LCD_WriteReg(0xD131, 0x20);
    LCD_WriteReg(0xD132, 0x0f);
    LCD_WriteReg(0xD133, 0x8e);
    LCD_WriteReg(0xD134, 0xff);
    //GAMMA SETING GREEN
    LCD_WriteReg(0xD200, 0x00);
    LCD_WriteReg(0xD201, 0x00);
    LCD_WriteReg(0xD202, 0x1b);
    LCD_WriteReg(0xD203, 0x44);
    LCD_WriteReg(0xD204, 0x62);
    LCD_WriteReg(0xD205, 0x00);
    LCD_WriteReg(0xD206, 0x7b);
    LCD_WriteReg(0xD207, 0xa1);
    LCD_WriteReg(0xD208, 0xc0);
    LCD_WriteReg(0xD209, 0xee);
    LCD_WriteReg(0xD20A, 0x55);
    LCD_WriteReg(0xD20B, 0x10);
    LCD_WriteReg(0xD20C, 0x2c);
    LCD_WriteReg(0xD20D, 0x43);
    LCD_WriteReg(0xD20E, 0x57);
    LCD_WriteReg(0xD20F, 0x55);
    LCD_WriteReg(0xD210, 0x68);
    LCD_WriteReg(0xD211, 0x78);
    LCD_WriteReg(0xD212, 0x87);
    LCD_WriteReg(0xD213, 0x94);
    LCD_WriteReg(0xD214, 0x55);
    LCD_WriteReg(0xD215, 0xa0);
    LCD_WriteReg(0xD216, 0xac);
    LCD_WriteReg(0xD217, 0xb6);
    LCD_WriteReg(0xD218, 0xc1);
    LCD_WriteReg(0xD219, 0x55);
    LCD_WriteReg(0xD21A, 0xcb);
    LCD_WriteReg(0xD21B, 0xcd);
    LCD_WriteReg(0xD21C, 0xd6);
    LCD_WriteReg(0xD21D, 0xdf);
    LCD_WriteReg(0xD21E, 0x95);
    LCD_WriteReg(0xD21F, 0xe8);
    LCD_WriteReg(0xD220, 0xf1);
    LCD_WriteReg(0xD221, 0xfa);
    LCD_WriteReg(0xD222, 0x02);
    LCD_WriteReg(0xD223, 0xaa);
    LCD_WriteReg(0xD224, 0x0b);
    LCD_WriteReg(0xD225, 0x13);
    LCD_WriteReg(0xD226, 0x1d);
    LCD_WriteReg(0xD227, 0x26);
    LCD_WriteReg(0xD228, 0xaa);
    LCD_WriteReg(0xD229, 0x30);
    LCD_WriteReg(0xD22A, 0x3c);
    LCD_WriteReg(0xD22B, 0x4a);
    LCD_WriteReg(0xD22C, 0x63);
    LCD_WriteReg(0xD22D, 0xea);
    LCD_WriteReg(0xD22E, 0x79);
    LCD_WriteReg(0xD22F, 0xa6);
    LCD_WriteReg(0xD230, 0xd0);
    LCD_WriteReg(0xD231, 0x20);
    LCD_WriteReg(0xD232, 0x0f);
    LCD_WriteReg(0xD233, 0x8e);
    LCD_WriteReg(0xD234, 0xff);

    //GAMMA SETING BLUE
    LCD_WriteReg(0xD300, 0x00);
    LCD_WriteReg(0xD301, 0x00);
    LCD_WriteReg(0xD302, 0x1b);
    LCD_WriteReg(0xD303, 0x44);
    LCD_WriteReg(0xD304, 0x62);
    LCD_WriteReg(0xD305, 0x00);
    LCD_WriteReg(0xD306, 0x7b);
    LCD_WriteReg(0xD307, 0xa1);
    LCD_WriteReg(0xD308, 0xc0);
    LCD_WriteReg(0xD309, 0xee);
    LCD_WriteReg(0xD30A, 0x55);
    LCD_WriteReg(0xD30B, 0x10);
    LCD_WriteReg(0xD30C, 0x2c);
    LCD_WriteReg(0xD30D, 0x43);
    LCD_WriteReg(0xD30E, 0x57);
    LCD_WriteReg(0xD30F, 0x55);
    LCD_WriteReg(0xD310, 0x68);
    LCD_WriteReg(0xD311, 0x78);
    LCD_WriteReg(0xD312, 0x87);
    LCD_WriteReg(0xD313, 0x94);
    LCD_WriteReg(0xD314, 0x55);
    LCD_WriteReg(0xD315, 0xa0);
    LCD_WriteReg(0xD316, 0xac);
    LCD_WriteReg(0xD317, 0xb6);
    LCD_WriteReg(0xD318, 0xc1);
    LCD_WriteReg(0xD319, 0x55);
    LCD_WriteReg(0xD31A, 0xcb);
    LCD_WriteReg(0xD31B, 0xcd);
    LCD_WriteReg(0xD31C, 0xd6);
    LCD_WriteReg(0xD31D, 0xdf);
    LCD_WriteReg(0xD31E, 0x95);
    LCD_WriteReg(0xD31F, 0xe8);
    LCD_WriteReg(0xD320, 0xf1);
    LCD_WriteReg(0xD321, 0xfa);
    LCD_WriteReg(0xD322, 0x02);
    LCD_WriteReg(0xD323, 0xaa);
    LCD_WriteReg(0xD324, 0x0b);
    LCD_WriteReg(0xD325, 0x13);
    LCD_WriteReg(0xD326, 0x1d);
    LCD_WriteReg(0xD327, 0x26);
    LCD_WriteReg(0xD328, 0xaa);
    LCD_WriteReg(0xD329, 0x30);
    LCD_WriteReg(0xD32A, 0x3c);
    LCD_WriteReg(0xD32B, 0x4A);
    LCD_WriteReg(0xD32C, 0x63);
    LCD_WriteReg(0xD32D, 0xea);
    LCD_WriteReg(0xD32E, 0x79);
    LCD_WriteReg(0xD32F, 0xa6);
    LCD_WriteReg(0xD330, 0xd0);
    LCD_WriteReg(0xD331, 0x20);
    LCD_WriteReg(0xD332, 0x0f);
    LCD_WriteReg(0xD333, 0x8e);
    LCD_WriteReg(0xD334, 0xff);


    //GAMMA SETING  RED
    LCD_WriteReg(0xD400, 0x00);
    LCD_WriteReg(0xD401, 0x00);
    LCD_WriteReg(0xD402, 0x1b);
    LCD_WriteReg(0xD403, 0x44);
    LCD_WriteReg(0xD404, 0x62);
    LCD_WriteReg(0xD405, 0x00);
    LCD_WriteReg(0xD406, 0x7b);
    LCD_WriteReg(0xD407, 0xa1);
    LCD_WriteReg(0xD408, 0xc0);
    LCD_WriteReg(0xD409, 0xee);
    LCD_WriteReg(0xD40A, 0x55);
    LCD_WriteReg(0xD40B, 0x10);
    LCD_WriteReg(0xD40C, 0x2c);
    LCD_WriteReg(0xD40D, 0x43);
    LCD_WriteReg(0xD40E, 0x57);
    LCD_WriteReg(0xD40F, 0x55);
    LCD_WriteReg(0xD410, 0x68);
    LCD_WriteReg(0xD411, 0x78);
    LCD_WriteReg(0xD412, 0x87);
    LCD_WriteReg(0xD413, 0x94);
    LCD_WriteReg(0xD414, 0x55);
    LCD_WriteReg(0xD415, 0xa0);
    LCD_WriteReg(0xD416, 0xac);
    LCD_WriteReg(0xD417, 0xb6);
    LCD_WriteReg(0xD418, 0xc1);
    LCD_WriteReg(0xD419, 0x55);
    LCD_WriteReg(0xD41A, 0xcb);
    LCD_WriteReg(0xD41B, 0xcd);
    LCD_WriteReg(0xD41C, 0xd6);
    LCD_WriteReg(0xD41D, 0xdf);
    LCD_WriteReg(0xD41E, 0x95);
    LCD_WriteReg(0xD41F, 0xe8);
    LCD_WriteReg(0xD420, 0xf1);
    LCD_WriteReg(0xD421, 0xfa);
    LCD_WriteReg(0xD422, 0x02);
    LCD_WriteReg(0xD423, 0xaa);
    LCD_WriteReg(0xD424, 0x0b);
    LCD_WriteReg(0xD425, 0x13);
    LCD_WriteReg(0xD426, 0x1d);
    LCD_WriteReg(0xD427, 0x26);
    LCD_WriteReg(0xD428, 0xaa);
    LCD_WriteReg(0xD429, 0x30);
    LCD_WriteReg(0xD42A, 0x3c);
    LCD_WriteReg(0xD42B, 0x4A);
    LCD_WriteReg(0xD42C, 0x63);
    LCD_WriteReg(0xD42D, 0xea);
    LCD_WriteReg(0xD42E, 0x79);
    LCD_WriteReg(0xD42F, 0xa6);
    LCD_WriteReg(0xD430, 0xd0);
    LCD_WriteReg(0xD431, 0x20);
    LCD_WriteReg(0xD432, 0x0f);
    LCD_WriteReg(0xD433, 0x8e);
    LCD_WriteReg(0xD434, 0xff);

    //GAMMA SETING GREEN
    LCD_WriteReg(0xD500, 0x00);
    LCD_WriteReg(0xD501, 0x00);
    LCD_WriteReg(0xD502, 0x1b);
    LCD_WriteReg(0xD503, 0x44);
    LCD_WriteReg(0xD504, 0x62);
    LCD_WriteReg(0xD505, 0x00);
    LCD_WriteReg(0xD506, 0x7b);
    LCD_WriteReg(0xD507, 0xa1);
    LCD_WriteReg(0xD508, 0xc0);
    LCD_WriteReg(0xD509, 0xee);
    LCD_WriteReg(0xD50A, 0x55);
    LCD_WriteReg(0xD50B, 0x10);
    LCD_WriteReg(0xD50C, 0x2c);
    LCD_WriteReg(0xD50D, 0x43);
    LCD_WriteReg(0xD50E, 0x57);
    LCD_WriteReg(0xD50F, 0x55);
    LCD_WriteReg(0xD510, 0x68);
    LCD_WriteReg(0xD511, 0x78);
    LCD_WriteReg(0xD512, 0x87);
    LCD_WriteReg(0xD513, 0x94);
    LCD_WriteReg(0xD514, 0x55);
    LCD_WriteReg(0xD515, 0xa0);
    LCD_WriteReg(0xD516, 0xac);
    LCD_WriteReg(0xD517, 0xb6);
    LCD_WriteReg(0xD518, 0xc1);
    LCD_WriteReg(0xD519, 0x55);
    LCD_WriteReg(0xD51A, 0xcb);
    LCD_WriteReg(0xD51B, 0xcd);
    LCD_WriteReg(0xD51C, 0xd6);
    LCD_WriteReg(0xD51D, 0xdf);
    LCD_WriteReg(0xD51E, 0x95);
    LCD_WriteReg(0xD51F, 0xe8);
    LCD_WriteReg(0xD520, 0xf1);
    LCD_WriteReg(0xD521, 0xfa);
    LCD_WriteReg(0xD522, 0x02);
    LCD_WriteReg(0xD523, 0xaa);
    LCD_WriteReg(0xD524, 0x0b);
    LCD_WriteReg(0xD525, 0x13);
    LCD_WriteReg(0xD526, 0x1d);
    LCD_WriteReg(0xD527, 0x26);
    LCD_WriteReg(0xD528, 0xaa);
    LCD_WriteReg(0xD529, 0x30);
    LCD_WriteReg(0xD52A, 0x3c);
    LCD_WriteReg(0xD52B, 0x4a);
    LCD_WriteReg(0xD52C, 0x63);
    LCD_WriteReg(0xD52D, 0xea);
    LCD_WriteReg(0xD52E, 0x79);
    LCD_WriteReg(0xD52F, 0xa6);
    LCD_WriteReg(0xD530, 0xd0);
    LCD_WriteReg(0xD531, 0x20);
    LCD_WriteReg(0xD532, 0x0f);
    LCD_WriteReg(0xD533, 0x8e);
    LCD_WriteReg(0xD534, 0xff);

    //GAMMA SETING BLUE
    LCD_WriteReg(0xD600, 0x00);
    LCD_WriteReg(0xD601, 0x00);
    LCD_WriteReg(0xD602, 0x1b);
    LCD_WriteReg(0xD603, 0x44);
    LCD_WriteReg(0xD604, 0x62);
    LCD_WriteReg(0xD605, 0x00);
    LCD_WriteReg(0xD606, 0x7b);
    LCD_WriteReg(0xD607, 0xa1);
    LCD_WriteReg(0xD608, 0xc0);
    LCD_WriteReg(0xD609, 0xee);
    LCD_WriteReg(0xD60A, 0x55);
    LCD_WriteReg(0xD60B, 0x10);
    LCD_WriteReg(0xD60C, 0x2c);
    LCD_WriteReg(0xD60D, 0x43);
    LCD_WriteReg(0xD60E, 0x57);
    LCD_WriteReg(0xD60F, 0x55);
    LCD_WriteReg(0xD610, 0x68);
    LCD_WriteReg(0xD611, 0x78);
    LCD_WriteReg(0xD612, 0x87);
    LCD_WriteReg(0xD613, 0x94);
    LCD_WriteReg(0xD614, 0x55);
    LCD_WriteReg(0xD615, 0xa0);
    LCD_WriteReg(0xD616, 0xac);
    LCD_WriteReg(0xD617, 0xb6);
    LCD_WriteReg(0xD618, 0xc1);
    LCD_WriteReg(0xD619, 0x55);
    LCD_WriteReg(0xD61A, 0xcb);
    LCD_WriteReg(0xD61B, 0xcd);
    LCD_WriteReg(0xD61C, 0xd6);
    LCD_WriteReg(0xD61D, 0xdf);
    LCD_WriteReg(0xD61E, 0x95);
    LCD_WriteReg(0xD61F, 0xe8);
    LCD_WriteReg(0xD620, 0xf1);
    LCD_WriteReg(0xD621, 0xfa);
    LCD_WriteReg(0xD622, 0x02);
    LCD_WriteReg(0xD623, 0xaa);
    LCD_WriteReg(0xD624, 0x0b);
    LCD_WriteReg(0xD625, 0x13);
    LCD_WriteReg(0xD626, 0x1d);
    LCD_WriteReg(0xD627, 0x26);
    LCD_WriteReg(0xD628, 0xaa);
    LCD_WriteReg(0xD629, 0x30);
    LCD_WriteReg(0xD62A, 0x3c);
    LCD_WriteReg(0xD62B, 0x4A);
    LCD_WriteReg(0xD62C, 0x63);
    LCD_WriteReg(0xD62D, 0xea);
    LCD_WriteReg(0xD62E, 0x79);
    LCD_WriteReg(0xD62F, 0xa6);
    LCD_WriteReg(0xD630, 0xd0);
    LCD_WriteReg(0xD631, 0x20);
    LCD_WriteReg(0xD632, 0x0f);
    LCD_WriteReg(0xD633, 0x8e);
    LCD_WriteReg(0xD634, 0xff);

    //AVDD VOLTAGE SETTING
    LCD_WriteReg(0xB000, 0x05);
    LCD_WriteReg(0xB001, 0x05);
    LCD_WriteReg(0xB002, 0x05);
    //AVEE VOLTAGE SETTING
    LCD_WriteReg(0xB100, 0x05);
    LCD_WriteReg(0xB101, 0x05);
    LCD_WriteReg(0xB102, 0x05);

    //AVDD Boosting
    LCD_WriteReg(0xB600, 0x34);
    LCD_WriteReg(0xB601, 0x34);
    LCD_WriteReg(0xB603, 0x34);
    //AVEE Boosting
    LCD_WriteReg(0xB700, 0x24);
    LCD_WriteReg(0xB701, 0x24);
    LCD_WriteReg(0xB702, 0x24);
    //VCL Boosting
    LCD_WriteReg(0xB800, 0x24);
    LCD_WriteReg(0xB801, 0x24);
    LCD_WriteReg(0xB802, 0x24);
    //VGLX VOLTAGE SETTING
    LCD_WriteReg(0xBA00, 0x14);
    LCD_WriteReg(0xBA01, 0x14);
    LCD_WriteReg(0xBA02, 0x14);
    //VCL Boosting
    LCD_WriteReg(0xB900, 0x24);
    LCD_WriteReg(0xB901, 0x24);
    LCD_WriteReg(0xB902, 0x24);
    //Gamma Voltage
    LCD_WriteReg(0xBc00, 0x00);
    LCD_WriteReg(0xBc01, 0xa0);//vgmp=5.0
    LCD_WriteReg(0xBc02, 0x00);
    LCD_WriteReg(0xBd00, 0x00);
    LCD_WriteReg(0xBd01, 0xa0);//vgmn=5.0
    LCD_WriteReg(0xBd02, 0x00);
    //VCOM Setting
    LCD_WriteReg(0xBe01, 0x3d);//3
    //ENABLE PAGE 0
    LCD_WriteReg(0xF000, 0x55);
    LCD_WriteReg(0xF001, 0xAA);
    LCD_WriteReg(0xF002, 0x52);
    LCD_WriteReg(0xF003, 0x08);
    LCD_WriteReg(0xF004, 0x00);
    //Vivid Color Function Control
    LCD_WriteReg(0xB400, 0x10);
    //Z-INVERSION
    LCD_WriteReg(0xBC00, 0x05);
    LCD_WriteReg(0xBC01, 0x05);
    LCD_WriteReg(0xBC02, 0x05);

    //
    LCD_WriteReg(0xB700, 0x22);//GATE EQ CONTROL
    LCD_WriteReg(0xB701, 0x22);//GATE EQ CONTROL
    LCD_WriteReg(0xC80B, 0x2A);//DISPLAY TIMING CONTROL
    LCD_WriteReg(0xC80C, 0x2A);//DISPLAY TIMING CONTROL
    LCD_WriteReg(0xC80F, 0x2A);//DISPLAY TIMING CONTROL
    LCD_WriteReg(0xC810, 0x2A);//DISPLAY TIMING CONTROL
    //
    //PWM_ENH_OE =1
    LCD_WriteReg(0xd000, 0x01);
    //DM_SEL =1
    LCD_WriteReg(0xb300, 0x10);
    //VBPDA=07h
    LCD_WriteReg(0xBd02, 0x07);
    //VBPDb=07h
    LCD_WriteReg(0xBe02, 0x07);
    //VBPDc=07h
    LCD_WriteReg(0xBf02, 0x07);
    //ENABLE PAGE 2
    LCD_WriteReg(0xF000, 0x55);
    LCD_WriteReg(0xF001, 0xAA);
    LCD_WriteReg(0xF002, 0x52);
    LCD_WriteReg(0xF003, 0x08);
    LCD_WriteReg(0xF004, 0x02);
    //SDREG0 =0
    LCD_WriteReg(0xc301, 0xa9);
    //DS=14
    LCD_WriteReg(0xfe01, 0x94);
    //OSC =60h
    LCD_WriteReg(0xf600, 0x60);
    //TE ON
    LCD_WriteReg(0x3500, 0x00);
    

    //SLEEP OUT 
    LCD_WR_REG(0x1100);
   HAL_Delay(100);
    //DISPLY ON
    LCD_WR_REG(0x2900);
    HAL_Delay(100);
    LCD_WR_REG(0x2C00);

   /*
 LCD_WR_REG(0X1100); //
HAL_Delay(120);  
LCD_WR_REG(0X2900); //
HAL_Delay(10);  
LCD_WR_REG(0X2C00); //
HAL_Delay(20);   
   //ENABLE PAGE 1
LCD_WriteReg(0xF000,0x55);
LCD_WriteReg(0xF001,0xAA);
LCD_WriteReg(0xF002,0x52);
LCD_WriteReg(0xF003,0x08);
LCD_WriteReg(0xF004,0x01);

//GAMMA SETING  RED
LCD_WriteReg(0xD100,0x00);
LCD_WriteReg(0xD101,0x00);
LCD_WriteReg(0xD102,0x1b);
LCD_WriteReg(0xD103,0x44);
LCD_WriteReg(0xD104,0x62);
LCD_WriteReg(0xD105,0x00);
LCD_WriteReg(0xD106,0x7b);
LCD_WriteReg(0xD107,0xa1);
LCD_WriteReg(0xD108,0xc0);
LCD_WriteReg(0xD109,0xee);
LCD_WriteReg(0xD10A,0x55);
LCD_WriteReg(0xD10B,0x10);
LCD_WriteReg(0xD10C,0x2c);
LCD_WriteReg(0xD10D,0x43);
LCD_WriteReg(0xD10E,0x57);
LCD_WriteReg(0xD10F,0x55);
LCD_WriteReg(0xD110,0x68);
LCD_WriteReg(0xD111,0x78);
LCD_WriteReg(0xD112,0x87);
LCD_WriteReg(0xD113,0x94);
LCD_WriteReg(0xD114,0x55);
LCD_WriteReg(0xD115,0xa0);
LCD_WriteReg(0xD116,0xac);
LCD_WriteReg(0xD117,0xb6);
LCD_WriteReg(0xD118,0xc1);
LCD_WriteReg(0xD119,0x55);
LCD_WriteReg(0xD11A,0xcb);
LCD_WriteReg(0xD11B,0xcd);
LCD_WriteReg(0xD11C,0xd6);
LCD_WriteReg(0xD11D,0xdf);
LCD_WriteReg(0xD11E,0x95);
LCD_WriteReg(0xD11F,0xe8);
LCD_WriteReg(0xD120,0xf1);
LCD_WriteReg(0xD121,0xfa);
LCD_WriteReg(0xD122,0x02);
LCD_WriteReg(0xD123,0xaa);
LCD_WriteReg(0xD124,0x0b);
LCD_WriteReg(0xD125,0x13);
LCD_WriteReg(0xD126,0x1d);
LCD_WriteReg(0xD127,0x26);
LCD_WriteReg(0xD128,0xaa);
LCD_WriteReg(0xD129,0x30);
LCD_WriteReg(0xD12A,0x3c);
LCD_WriteReg(0xD12B,0x4A);
LCD_WriteReg(0xD12C,0x63);
LCD_WriteReg(0xD12D,0xea);
LCD_WriteReg(0xD12E,0x79);
LCD_WriteReg(0xD12F,0xa6);
LCD_WriteReg(0xD130,0xd0);
LCD_WriteReg(0xD131,0x20);
LCD_WriteReg(0xD132,0x0f);
LCD_WriteReg(0xD133,0x8e);
LCD_WriteReg(0xD134,0xff);
//GAMMA SETING GREEN
LCD_WriteReg(0xD200,0x00);
LCD_WriteReg(0xD201,0x00);
LCD_WriteReg(0xD202,0x1b);
LCD_WriteReg(0xD203,0x44);
LCD_WriteReg(0xD204,0x62);
LCD_WriteReg(0xD205,0x00);
LCD_WriteReg(0xD206,0x7b);
LCD_WriteReg(0xD207,0xa1);
LCD_WriteReg(0xD208,0xc0);
LCD_WriteReg(0xD209,0xee);
LCD_WriteReg(0xD20A,0x55);
LCD_WriteReg(0xD20B,0x10);
LCD_WriteReg(0xD20C,0x2c);
LCD_WriteReg(0xD20D,0x43);
LCD_WriteReg(0xD20E,0x57);
LCD_WriteReg(0xD20F,0x55);
LCD_WriteReg(0xD210,0x68);
LCD_WriteReg(0xD211,0x78);
LCD_WriteReg(0xD212,0x87);
LCD_WriteReg(0xD213,0x94);
LCD_WriteReg(0xD214,0x55);
LCD_WriteReg(0xD215,0xa0);
LCD_WriteReg(0xD216,0xac);
LCD_WriteReg(0xD217,0xb6);
LCD_WriteReg(0xD218,0xc1);
LCD_WriteReg(0xD219,0x55);
LCD_WriteReg(0xD21A,0xcb);
LCD_WriteReg(0xD21B,0xcd);
LCD_WriteReg(0xD21C,0xd6);
LCD_WriteReg(0xD21D,0xdf);
LCD_WriteReg(0xD21E,0x95);
LCD_WriteReg(0xD21F,0xe8);
LCD_WriteReg(0xD220,0xf1);
LCD_WriteReg(0xD221,0xfa);
LCD_WriteReg(0xD222,0x02);
LCD_WriteReg(0xD223,0xaa);
LCD_WriteReg(0xD224,0x0b);
LCD_WriteReg(0xD225,0x13);
LCD_WriteReg(0xD226,0x1d);
LCD_WriteReg(0xD227,0x26);
LCD_WriteReg(0xD228,0xaa);
LCD_WriteReg(0xD229,0x30);
LCD_WriteReg(0xD22A,0x3c);
LCD_WriteReg(0xD22B,0x4a);
LCD_WriteReg(0xD22C,0x63);
LCD_WriteReg(0xD22D,0xea);
LCD_WriteReg(0xD22E,0x79);
LCD_WriteReg(0xD22F,0xa6);
LCD_WriteReg(0xD230,0xd0);
LCD_WriteReg(0xD231,0x20);
LCD_WriteReg(0xD232,0x0f);
LCD_WriteReg(0xD233,0x8e);
LCD_WriteReg(0xD234,0xff);

//GAMMA SETING BLUE
LCD_WriteReg(0xD300,0x00);
LCD_WriteReg(0xD301,0x00);
LCD_WriteReg(0xD302,0x1b);
LCD_WriteReg(0xD303,0x44);
LCD_WriteReg(0xD304,0x62);
LCD_WriteReg(0xD305,0x00);
LCD_WriteReg(0xD306,0x7b);
LCD_WriteReg(0xD307,0xa1);
LCD_WriteReg(0xD308,0xc0);
LCD_WriteReg(0xD309,0xee);
LCD_WriteReg(0xD30A,0x55);
LCD_WriteReg(0xD30B,0x10);
LCD_WriteReg(0xD30C,0x2c);
LCD_WriteReg(0xD30D,0x43);
LCD_WriteReg(0xD30E,0x57);
LCD_WriteReg(0xD30F,0x55);
LCD_WriteReg(0xD310,0x68);
LCD_WriteReg(0xD311,0x78);
LCD_WriteReg(0xD312,0x87);
LCD_WriteReg(0xD313,0x94);
LCD_WriteReg(0xD314,0x55);
LCD_WriteReg(0xD315,0xa0);
LCD_WriteReg(0xD316,0xac);
LCD_WriteReg(0xD317,0xb6);
LCD_WriteReg(0xD318,0xc1);
LCD_WriteReg(0xD319,0x55);
LCD_WriteReg(0xD31A,0xcb);
LCD_WriteReg(0xD31B,0xcd);
LCD_WriteReg(0xD31C,0xd6);
LCD_WriteReg(0xD31D,0xdf);
LCD_WriteReg(0xD31E,0x95);
LCD_WriteReg(0xD31F,0xe8);
LCD_WriteReg(0xD320,0xf1);
LCD_WriteReg(0xD321,0xfa);
LCD_WriteReg(0xD322,0x02);
LCD_WriteReg(0xD323,0xaa);
LCD_WriteReg(0xD324,0x0b);
LCD_WriteReg(0xD325,0x13);
LCD_WriteReg(0xD326,0x1d);
LCD_WriteReg(0xD327,0x26);
LCD_WriteReg(0xD328,0xaa);
LCD_WriteReg(0xD329,0x30);
LCD_WriteReg(0xD32A,0x3c);
LCD_WriteReg(0xD32B,0x4A);
LCD_WriteReg(0xD32C,0x63);
LCD_WriteReg(0xD32D,0xea);
LCD_WriteReg(0xD32E,0x79);
LCD_WriteReg(0xD32F,0xa6);
LCD_WriteReg(0xD330,0xd0);
LCD_WriteReg(0xD331,0x20);
LCD_WriteReg(0xD332,0x0f);
LCD_WriteReg(0xD333,0x8e);
LCD_WriteReg(0xD334,0xff);

//GAMMA SETING  RED
LCD_WriteReg(0xD400,0x00);
LCD_WriteReg(0xD401,0x00);
LCD_WriteReg(0xD402,0x1b);
LCD_WriteReg(0xD403,0x44);
LCD_WriteReg(0xD404,0x62);
LCD_WriteReg(0xD405,0x00);
LCD_WriteReg(0xD406,0x7b);
LCD_WriteReg(0xD407,0xa1);
LCD_WriteReg(0xD408,0xc0);
LCD_WriteReg(0xD409,0xee);
LCD_WriteReg(0xD40A,0x55);
LCD_WriteReg(0xD40B,0x10);
LCD_WriteReg(0xD40C,0x2c);
LCD_WriteReg(0xD40D,0x43);
LCD_WriteReg(0xD40E,0x57);
LCD_WriteReg(0xD40F,0x55);
LCD_WriteReg(0xD410,0x68);
LCD_WriteReg(0xD411,0x78);
LCD_WriteReg(0xD412,0x87);
LCD_WriteReg(0xD413,0x94);
LCD_WriteReg(0xD414,0x55);
LCD_WriteReg(0xD415,0xa0);
LCD_WriteReg(0xD416,0xac);
LCD_WriteReg(0xD417,0xb6);
LCD_WriteReg(0xD418,0xc1);
LCD_WriteReg(0xD419,0x55);
LCD_WriteReg(0xD41A,0xcb);
LCD_WriteReg(0xD41B,0xcd);
LCD_WriteReg(0xD41C,0xd6);
LCD_WriteReg(0xD41D,0xdf);
LCD_WriteReg(0xD41E,0x95);
LCD_WriteReg(0xD41F,0xe8);
LCD_WriteReg(0xD420,0xf1);
LCD_WriteReg(0xD421,0xfa);
LCD_WriteReg(0xD422,0x02);
LCD_WriteReg(0xD423,0xaa);
LCD_WriteReg(0xD424,0x0b);
LCD_WriteReg(0xD425,0x13);
LCD_WriteReg(0xD426,0x1d);
LCD_WriteReg(0xD427,0x26);
LCD_WriteReg(0xD428,0xaa);
LCD_WriteReg(0xD429,0x30);
LCD_WriteReg(0xD42A,0x3c);
LCD_WriteReg(0xD42B,0x4A);
LCD_WriteReg(0xD42C,0x63);
LCD_WriteReg(0xD42D,0xea);
LCD_WriteReg(0xD42E,0x79);
LCD_WriteReg(0xD42F,0xa6);
LCD_WriteReg(0xD430,0xd0);
LCD_WriteReg(0xD431,0x20);
LCD_WriteReg(0xD432,0x0f);
LCD_WriteReg(0xD433,0x8e);
LCD_WriteReg(0xD434,0xff);

//GAMMA SETING GREEN
LCD_WriteReg(0xD500,0x00);
LCD_WriteReg(0xD501,0x00);
LCD_WriteReg(0xD502,0x1b);
LCD_WriteReg(0xD503,0x44);
LCD_WriteReg(0xD504,0x62);
LCD_WriteReg(0xD505,0x00);
LCD_WriteReg(0xD506,0x7b);
LCD_WriteReg(0xD507,0xa1);
LCD_WriteReg(0xD508,0xc0);
LCD_WriteReg(0xD509,0xee);
LCD_WriteReg(0xD50A,0x55);
LCD_WriteReg(0xD50B,0x10);
LCD_WriteReg(0xD50C,0x2c);
LCD_WriteReg(0xD50D,0x43);
LCD_WriteReg(0xD50E,0x57);
LCD_WriteReg(0xD50F,0x55);
LCD_WriteReg(0xD510,0x68);
LCD_WriteReg(0xD511,0x78);
LCD_WriteReg(0xD512,0x87);
LCD_WriteReg(0xD513,0x94);
LCD_WriteReg(0xD514,0x55);
LCD_WriteReg(0xD515,0xa0);
LCD_WriteReg(0xD516,0xac);
LCD_WriteReg(0xD517,0xb6);
LCD_WriteReg(0xD518,0xc1);
LCD_WriteReg(0xD519,0x55);
LCD_WriteReg(0xD51A,0xcb);
LCD_WriteReg(0xD51B,0xcd);
LCD_WriteReg(0xD51C,0xd6);
LCD_WriteReg(0xD51D,0xdf);
LCD_WriteReg(0xD51E,0x95);
LCD_WriteReg(0xD51F,0xe8);
LCD_WriteReg(0xD520,0xf1);
LCD_WriteReg(0xD521,0xfa);
LCD_WriteReg(0xD522,0x02);
LCD_WriteReg(0xD523,0xaa);
LCD_WriteReg(0xD524,0x0b);
LCD_WriteReg(0xD525,0x13);
LCD_WriteReg(0xD526,0x1d);
LCD_WriteReg(0xD527,0x26);
LCD_WriteReg(0xD528,0xaa);
LCD_WriteReg(0xD529,0x30);
LCD_WriteReg(0xD52A,0x3c);
LCD_WriteReg(0xD52B,0x4a);
LCD_WriteReg(0xD52C,0x63);
LCD_WriteReg(0xD52D,0xea);
LCD_WriteReg(0xD52E,0x79);
LCD_WriteReg(0xD52F,0xa6);
LCD_WriteReg(0xD530,0xd0);
LCD_WriteReg(0xD531,0x20);
LCD_WriteReg(0xD532,0x0f);
LCD_WriteReg(0xD533,0x8e);
LCD_WriteReg(0xD534,0xff);

//GAMMA SETING BLUE
LCD_WriteReg(0xD600,0x00);
LCD_WriteReg(0xD601,0x00);
LCD_WriteReg(0xD602,0x1b);
LCD_WriteReg(0xD603,0x44);
LCD_WriteReg(0xD604,0x62);
LCD_WriteReg(0xD605,0x00);
LCD_WriteReg(0xD606,0x7b);
LCD_WriteReg(0xD607,0xa1);
LCD_WriteReg(0xD608,0xc0);
LCD_WriteReg(0xD609,0xee);
LCD_WriteReg(0xD60A,0x55);
LCD_WriteReg(0xD60B,0x10);
LCD_WriteReg(0xD60C,0x2c);
LCD_WriteReg(0xD60D,0x43);
LCD_WriteReg(0xD60E,0x57);
LCD_WriteReg(0xD60F,0x55);
LCD_WriteReg(0xD610,0x68);
LCD_WriteReg(0xD611,0x78);
LCD_WriteReg(0xD612,0x87);
LCD_WriteReg(0xD613,0x94);
LCD_WriteReg(0xD614,0x55);
LCD_WriteReg(0xD615,0xa0);
LCD_WriteReg(0xD616,0xac);
LCD_WriteReg(0xD617,0xb6);
LCD_WriteReg(0xD618,0xc1);
LCD_WriteReg(0xD619,0x55);
LCD_WriteReg(0xD61A,0xcb);
LCD_WriteReg(0xD61B,0xcd);
LCD_WriteReg(0xD61C,0xd6);
LCD_WriteReg(0xD61D,0xdf);
LCD_WriteReg(0xD61E,0x95);
LCD_WriteReg(0xD61F,0xe8);
LCD_WriteReg(0xD620,0xf1);
LCD_WriteReg(0xD621,0xfa);
LCD_WriteReg(0xD622,0x02);
LCD_WriteReg(0xD623,0xaa);
LCD_WriteReg(0xD624,0x0b);
LCD_WriteReg(0xD625,0x13);
LCD_WriteReg(0xD626,0x1d);
LCD_WriteReg(0xD627,0x26);
LCD_WriteReg(0xD628,0xaa);
LCD_WriteReg(0xD629,0x30);
LCD_WriteReg(0xD62A,0x3c);
LCD_WriteReg(0xD62B,0x4A);
LCD_WriteReg(0xD62C,0x63);
LCD_WriteReg(0xD62D,0xea);
LCD_WriteReg(0xD62E,0x79);
LCD_WriteReg(0xD62F,0xa6);
LCD_WriteReg(0xD630,0xd0);
LCD_WriteReg(0xD631,0x20);
LCD_WriteReg(0xD632,0x0f);
LCD_WriteReg(0xD633,0x8e);
LCD_WriteReg(0xD634,0xff);

//AVDD VOLTAGE SETTING
LCD_WriteReg(0xB000,0x05);
LCD_WriteReg(0xB001,0x05);
LCD_WriteReg(0xB002,0x05);
//AVEE VOLTAGE SETTING
LCD_WriteReg(0xB100,0x05);
LCD_WriteReg(0xB101,0x05);
LCD_WriteReg(0xB102,0x05);

//AVDD Boosting
LCD_WriteReg(0xB600,0x34);
LCD_WriteReg(0xB601,0x34);
LCD_WriteReg(0xB603,0x34);
//AVEE Boosting
LCD_WriteReg(0xB700,0x24);
LCD_WriteReg(0xB701,0x24);
LCD_WriteReg(0xB702,0x24);
//VCL Boosting
LCD_WriteReg(0xB800,0x24);
LCD_WriteReg(0xB801,0x24);
LCD_WriteReg(0xB802,0x24);
//VGLX VOLTAGE SETTING
LCD_WriteReg(0xBA00,0x14);
LCD_WriteReg(0xBA01,0x14);
LCD_WriteReg(0xBA02,0x14);
//VCL Boosting
LCD_WriteReg(0xB900,0x24);
LCD_WriteReg(0xB901,0x24);
LCD_WriteReg(0xB902,0x24);
//Gamma Voltage
LCD_WriteReg(0xBc00,0x00);
LCD_WriteReg(0xBc01,0xa0);//vgmp=5.0
LCD_WriteReg(0xBc02,0x00);
LCD_WriteReg(0xBd00,0x00);
LCD_WriteReg(0xBd01,0xa0);//vgmn=5.0
LCD_WriteReg(0xBd02,0x00);
//VCOM Setting
LCD_WriteReg(0xBe01,0x3d);//3
//ENABLE PAGE 0
LCD_WriteReg(0xF000,0x55);
LCD_WriteReg(0xF001,0xAA);
LCD_WriteReg(0xF002,0x52);
LCD_WriteReg(0xF003,0x08);
LCD_WriteReg(0xF004,0x00);
//Vivid Color Function Control
LCD_WriteReg(0xB400,0x10);
//Z-INVERSION
LCD_WriteReg(0xBC00,0x05);
LCD_WriteReg(0xBC01,0x05);
LCD_WriteReg(0xBC02,0x05);

// add on 20111021
LCD_WriteReg(0xB700,0x22);//GATE EQ CONTROL
LCD_WriteReg(0xB701,0x22);//GATE EQ CONTROL

LCD_WriteReg(0xC80B,0x2A);//DISPLAY TIMING CONTROL
LCD_WriteReg(0xC80C,0x2A);//DISPLAY TIMING CONTROL
LCD_WriteReg(0xC80F,0x2A);//DISPLAY TIMING CONTROL
LCD_WriteReg(0xC810,0x2A);//DISPLAY TIMING CONTROL
// add on 20111021
//PWM_ENH_OE =1
LCD_WriteReg(0xd000,0x01);
//DM_SEL =1
LCD_WriteReg(0xb300,0x10);
//VBPDA=07h
LCD_WriteReg(0xBd02,0x07);
//VBPDb=07h
LCD_WriteReg(0xBe02,0x07);
//VBPDc=07h
LCD_WriteReg(0xBf02,0x07);
//ENABLE PAGE 2
LCD_WriteReg(0xF000,0x55);
LCD_WriteReg(0xF001,0xAA);
LCD_WriteReg(0xF002,0x52);
LCD_WriteReg(0xF003,0x08);
LCD_WriteReg(0xF004,0x02);
//SDREG0 =0
LCD_WriteReg(0xc301,0xa9);
//DS=14
LCD_WriteReg(0xfe01,0x94);
//OSC =60h
LCD_WriteReg(0xf600,0x60);
//TE ON
LCD_WriteReg(0x3500,0x00);
////SLEEP OUT 
//LCD_WriteReg(0x1100);
//LCD_delay(120);
////DISPLY ON
//LCD_WriteReg(0x2900);
//LCD_delay(100);
LCD_WriteReg(0XB000,0X00);  
LCD_WriteReg(0XB001,0X00);  
LCD_WriteReg(0XB002,0X00);  
LCD_WriteReg(0XB100,0X05);  
LCD_WriteReg(0XB101,0X05);  
LCD_WriteReg(0XB102,0X05);  
LCD_WriteReg(0XB600,0X44);  
LCD_WriteReg(0XB601,0X44);  
LCD_WriteReg(0XB602,0X44);  
LCD_WriteReg(0XB700,0X34);  
LCD_WriteReg(0XB701,0X34);  
LCD_WriteReg(0XB702,0X34);  
LCD_WriteReg(0XB800,0X24);
LCD_WriteReg(0XB801,0X24);
LCD_WriteReg(0XB802,0X24);
LCD_WriteReg(0XB900,0X34);
LCD_WriteReg(0XB901,0X34);
LCD_WriteReg(0XB902,0X34);
LCD_WriteReg(0XBA00,0X14);  
LCD_WriteReg(0XBA01,0X14);
LCD_WriteReg(0XBA02,0X14);
LCD_WriteReg(0XBF00,0X01); 
LCD_WriteReg(0XB300,0X07);  
LCD_WriteReg(0XB301,0X07);
LCD_WriteReg(0XB302,0X07);
LCD_WriteReg(0XB900,0X25);
LCD_WriteReg(0XB901,0X25);
LCD_WriteReg(0XB902,0X25);
LCD_WriteReg(0XBC00,0X00);
LCD_WriteReg(0XBC01,0X90);//A0  90  A8
LCD_WriteReg(0XBC02,0X61);//3A  61  00
LCD_WriteReg(0XBD00,0X00);
LCD_WriteReg(0XBD01,0X90);//A0
LCD_WriteReg(0XBD02,0X61);//3A
LCD_WriteReg(0XBE00,0X00);
LCD_WriteReg(0XBE01,0X8F);//8e
LCD_WriteReg(0XF000,0X55);
LCD_WriteReg(0XF001,0XAA);
LCD_WriteReg(0XF002,0X52);
LCD_WriteReg(0XF003,0X08);
LCD_WriteReg(0XF004,0X00);
LCD_WriteReg(0XB400,0X10);
LCD_WriteReg(0XB600,0X02);
LCD_WriteReg(0XB100,0XCC);
LCD_WriteReg(0XB700,0X22);
LCD_WriteReg(0XB701,0X22);
LCD_WriteReg(0XC80B,0X2A);
LCD_WriteReg(0XC80C,0X2A);
LCD_WriteReg(0XC80F,0X2A);
LCD_WriteReg(0XC810,0X2A);
LCD_WriteReg(0XB800,0X01);
LCD_WriteReg(0XB801,0X03);
LCD_WriteReg(0XB802,0X03);
LCD_WriteReg(0XB803,0X03);
LCD_WriteReg(0XBC00,0X05);//05
LCD_WriteReg(0XBC01,0X05);
LCD_WriteReg(0XBC02,0X05);
LCD_WriteReg(0XD000,0X01);
LCD_WriteReg(0XBA00,0X01);
LCD_WriteReg(0XBD02,0X07);
LCD_WriteReg(0XBD03,0X31);
LCD_WriteReg(0XBE02,0X07);
LCD_WriteReg(0XBE03,0X31);
LCD_WriteReg(0XBF02,0X07);
LCD_WriteReg(0XBF03,0X31);
LCD_WriteReg(0XB300,0X00);
LCD_WriteReg(0XBD00,0X07);
LCD_WriteReg(0XBE00,0X07);
LCD_WriteReg(0XBF00,0X07);
LCD_WriteReg(0XF000,0X55);
LCD_WriteReg(0XF001,0XAA);
LCD_WriteReg(0XF002,0X52);
LCD_WriteReg(0XF003,0X08);
LCD_WriteReg(0XF004,0X02);
LCD_WriteReg(0XC301,0XA9);
LCD_WriteReg(0XFE01,0X94);
LCD_WriteReg(0XF600,0X60);
LCD_WriteReg(0X3500,0X00);
LCD_WriteReg(0XF000,0X55);
LCD_WriteReg(0XF001,0XAA);
LCD_WriteReg(0XF002,0X52);
LCD_WriteReg(0XF003,0X08);
LCD_WriteReg(0XF004,0X01);//01
LCD_WriteReg(0X3600,0X00);
LCD_WriteReg(0X3a00,0X77); //

LCD_WR_REG(0X1100); //
HAL_Delay(120);  
LCD_WR_REG(0X2900); //
HAL_Delay(10);  
LCD_WR_REG(0X2C00); //
HAL_Delay(20); 
*/
/*    
    LCD_WriteReg(0x3A00, 0x55);
    LCD_WriteReg(0x3600, 0xA3);
*/
    //    LCD_WR_REG(0x2300);
        

//	LCD_Clear(RED);
}


/*
****************************************************************
*功能: 清屏函数
*参数: 填充的颜色和位置
****************************************************************
*/
void LCD_Clear(u16 color)
{
	u16 x=0,y=0;
	__IO u32 index=0;
	u32 totalpoint = lcd_dev.width;
	totalpoint *= lcd_dev.height;

	LCD_WR_REG(0X2A00);		/* column address control set */
	LCD_WR_DATA(x>>8);	/* 先高8位，然后低8位 */
	LCD_WR_DATA(x&0xff);	/* 设置起始点和结束点*/
	LCD_WR_DATA((lcd_dev.width) >>8);
	LCD_WR_DATA((lcd_dev.width) &0xff);

	LCD_WR_REG(0X2B00);		/* page address control set */
	LCD_WR_DATA(y>>8);
	LCD_WR_DATA(y&0xff);
	LCD_WR_DATA((lcd_dev.height) >>8);
	LCD_WR_DATA((lcd_dev.height) &0xff);

	LCD_WR_REG(0x2C00);			//写入GRAM

	for( index=0;index < totalpoint ; index++ )
	{
		LCD_WR_DATA( color );
	}
}

/*
****************************************************************
*功能: 填充函数
*参数: 填充的颜色和位置
****************************************************************
*/
void LCD_Fill(u16 x, u16 y, u16 width, u16 height, u16 color)
{
	u32 i = 0;

	LCD_WR_REG(0X2A00);
	LCD_WR_DATA( x >> 8 );				/* 先高8位，然后低8位 */
	LCD_WR_DATA( x & 0xff );			/* column start   */
	LCD_WR_DATA( (x+width-1) >> 8 );	/* column end   */
	LCD_WR_DATA( (x+width-1) & 0xff );

  	LCD_WR_REG(0X2B00);
	LCD_WR_DATA( y >> 8 );				/* page start   */
	LCD_WR_DATA( y & 0xff );
	LCD_WR_DATA( (y+height-1) >> 8);	/* page end     */
	LCD_WR_DATA( (y+height-1) & 0xff);

	LCD_WR_REG(0x2c00);					/* memory write */

	for( i=0; i < width*height; i++ )
	{
		LCD_WR_DATA( color );
	}
}

/*
***********************************************************************
*功能: 画水平线
*参数: x1 y1  线起点位置
*		 x2 y2  线终点位置
***********************************************************************
*/
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2)
{
	u16 t;
	int xerr=0,yerr=0,delta_x,delta_y,distance;
	int incx,incy,uRow,uCol;
	delta_x=x2-x1; //计算坐标增量
	delta_y=y2-y1;
	uRow=x1;
	uCol=y1;
	if(delta_x>0)incx=1; //设置单步方向
	else if(delta_x==0)incx=0;//垂直线
	else {incx=-1;delta_x=-delta_x;}
	if(delta_y>0)incy=1;
	else if(delta_y==0)incy=0;//水平线
	else{incy=-1;delta_y=-delta_y;}
	if( delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴
	else distance=delta_y;
	for(t=0;t<=distance+1;t++ )//画线输出
	{
		LCD_DrawPoint(uRow, uCol);//画点
		xerr+=delta_x ;
		yerr+=delta_y ;
		if(xerr>distance)
		{
			xerr-=distance;
			uRow+=incx;
		}
		if(yerr>distance)
		{
			yerr-=distance;
			uCol+=incy;
		}
	}
}


/*
****************************************************************
*功能: 画矩形
*参数: 矩形对角坐标
****************************************************************
*/
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2)
{
	LCD_DrawLine(x1,y1,x2,y1);
	LCD_DrawLine(x1,y1,x1,y2);
	LCD_DrawLine(x1,y2,x2,y2);
	LCD_DrawLine(x2,y1,x2,y2);
}

/*
****************************************************************
*功能: 画圆
*参数: 原点坐标和半径
****************************************************************
*/
void LCD_Draw_Circle(u16 x,u16 y,u8 r)
{
	int a,b;
	int di;
	a=0;b=r;
	di=3-(r<<1);             //判断下个点位置的标志
	while(a<=b)
	{
		LCD_DrawPoint(x+a,y-b);             //5
 		LCD_DrawPoint(x+b,y-a);             //0
		LCD_DrawPoint(x+b,y+a);             //4
		LCD_DrawPoint(x+a,y+b);             //6
		LCD_DrawPoint(x-a,y+b);             //1
 		LCD_DrawPoint(x-b,y+a);
		LCD_DrawPoint(x-a,y-b);             //2
  		LCD_DrawPoint(x-b,y-a);             //7
		a++;
		//使用Bresenham算法画圆
		if(di<0)di +=4*a+6;
		else
		{
			di+=10+4*(a-b);
			b--;
		}
	}
}





