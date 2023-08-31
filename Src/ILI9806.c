#include "main.h"
#include "ili9806.h"




//LCD�Ļ�����ɫ�ͱ���ɫ
u16 POINT_COLOR=0x0000;	//������ɫ
u16 BACK_COLOR=0xFFFF;  //����ɫ


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
	*(__IO u16 *) (Bank1_LCD_D) = data;
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
*����: �趨���λ��
*����: ��������ֵ
****************************************************************
*/
void LCD_SetCursor(u16 x, u16 y)
{
	LCD_WR_REG(0X2A);		/* column address control set */
	LCD_WR_DATA(x>>8);	/* �ȸ�8λ��Ȼ���8λ */
	LCD_WR_DATA(x&0xff);	/* ������ʼ��ͽ�����*/

	LCD_WR_REG(0X2B);		/* page address control set */
	LCD_WR_DATA(y>>8);
	LCD_WR_DATA(y&0xff);
}

/*
****************************************************************
*����: ��ȡĳ�������ɫ
*����: ��������ֵ
****************************************************************
*/
u16 LCD_ReadPoint(u16 x, u16 y)
{
	u16 r=0,g=0,b=0,color =0;
	if(x>=lcd_dev.width||y>=lcd_dev.height)
        return 0;	//�����˷�Χ,ֱ�ӷ���
	LCD_SetCursor(x,y);
	LCD_WR_REG(0x2E);		//���Ͷ�GRAMָ��
	r=LCD_RD_DATA();		//dummy Read
	LCD_delay(2);
	r=LCD_RD_DATA();		//ʵ��������ɫ
	LCD_delay(2);
	b=LCD_RD_DATA();
	g=r&0XFF;
	g<<=8;
	color = (((r>>11)<<11)|((g>>10)<<5)|(b>>11));
	return color;
}

/*
****************************************************************
*����: ����
*����: ��������ֵ
****************************************************************
*/
void LCD_DrawPoint(u16 x,u16 y)
{
	LCD_SetCursor(x,y);		//���ù��λ��
	LCD_WR_REG(0x2C);		//��ʼд��GRAM
	LCD_WR_DATA(POINT_COLOR);
}

/*
****************************************************************
*����: ���ٻ���
*����: ��������ֵ
****************************************************************
*/

void LCD_Fast_DrawPoint(u16 x, u16 y, u16 color)
{
	LCD_WR_REG(0X2A);		/* column address control set */
	LCD_WR_DATA(x>>8);	/* �ȸ�8λ��Ȼ���8λ */
	LCD_WR_DATA(x&0xff);	/* ������ʼ��ͽ�����*/

	LCD_WR_REG(0X2B);		/* page address control set */
	LCD_WR_DATA(y>>8);
	LCD_WR_DATA(y&0xff);

	LCD_WR_REG(0x2C);		//��ʼд��GRAM
	LCD_WR_DATA(color);
}



/*
****************************************************************
*����: ����LCDɨ�跽��
*����:
****************************************************************
*/
void LCD_Scan_Dir(u8 dir)
{
	u16 regval=0;
	u16 dirreg=0;
	u16 temp;
	if(lcd_dev.dir == 1)//������ʾ
	{
		switch(dir)//����ת��
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
		case L2R_U2D://������,���ϵ���
			regval|=(0<<7)|(0<<6)|(0<<5);
			break;
		case L2R_D2U://������,���µ���
			regval|=(1<<7)|(0<<6)|(0<<5);
			break;
		case R2L_U2D://���ҵ���,���ϵ���
			regval|=(0<<7)|(1<<6)|(0<<5);
			break;
		case R2L_D2U://���ҵ���,���µ���
			regval|=(1<<7)|(1<<6)|(0<<5);
			break;
		case U2D_L2R://���ϵ���,������
			regval|=(0<<7)|(0<<6)|(1<<5);
			break;
		case U2D_R2L://���ϵ���,���ҵ���
			regval|=(0<<7)|(1<<6)|(1<<5);
			break;
		case D2U_L2R://���µ���,������
			regval|=(1<<7)|(0<<6)|(1<<5);
			break;
		case D2U_R2L://���µ���,���ҵ���
			regval|=(1<<7)|(1<<6)|(1<<5);
			break;
	}
	dirreg=0X36;
	LCD_WriteReg(dirreg,regval);
	if((regval&0X20)||lcd_dev.dir==1)
	{
		if(lcd_dev.width<lcd_dev.height)//����X,Y
		{
			temp=lcd_dev.width;
			lcd_dev.width=lcd_dev.height;
			lcd_dev.height=temp;
 		}
	}
	else
	{
		if(lcd_dev.width>lcd_dev.height)//����X,Y
		{
			temp=lcd_dev.width;
			lcd_dev.width=lcd_dev.height;
			lcd_dev.height=temp;
 		}
	}
	LCD_WR_REG(0x2A);
	LCD_WR_DATA(0);
	LCD_WR_DATA(0);
	LCD_WR_DATA((lcd_dev.width-1)>>8);
	LCD_WR_DATA((lcd_dev.width-1)&0XFF);
	LCD_WR_REG(0x2B);
	LCD_WR_DATA(0);
	LCD_WR_DATA(0);
	LCD_WR_DATA((lcd_dev.height-1)>>8);
	LCD_WR_DATA((lcd_dev.height-1)&0XFF);
}


/*
****************************************************************
*����: ����LCD��ʾ����
*����: 0  ����     1����
****************************************************************
*/
void LCD_Display_Dir(u8 dir)
{
	if(dir == 0 )	//����
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
	LCD_Scan_Dir(L2R_U2D);	//Ĭ��ɨ�跽��
}

static void LCD_Rst(void)
{
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET); // GPIO_ResetBits(GPIOC, GPIO_Pin_1);
    LCD_delay(100);
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET); //GPIO_SetBits(GPIOC, GPIO_Pin_1);
    LCD_delay(100);
}

/**********************************************
Lcd��ʼ������
***********************************************/
void TFTLCD_Init(void)
{

	LCD_delay(20);
	LCD_Rst();

	 LCD_WR_REG(0XD3);
	 lcd_dev.id = LCD_RD_DATA();		//dummy read
	 lcd_dev.id = LCD_RD_DATA();		//����0x00
	 lcd_dev.id = LCD_RD_DATA();		//����0x98

	 lcd_dev.id <<=8;
	 lcd_dev.id  |= LCD_RD_DATA();	//����0x06

	//************* Start Initial Sequence **********//
	LCD_WR_REG(0xFF);	// EXTC Command Set enable register
	LCD_WR_DATA(0xFF);
	LCD_WR_DATA(0x98);
	LCD_WR_DATA(0x06);

	LCD_WR_REG(0xBA);	// SPI Interface Setting
	LCD_WR_DATA(0xE0);

	LCD_WR_REG(0xBC); // GIP 1
	LCD_WR_DATA(0x03);
	LCD_WR_DATA(0x0F);
	LCD_WR_DATA(0x63);
	LCD_WR_DATA(0x69);
	LCD_WR_DATA(0x01);
	LCD_WR_DATA(0x01);
	LCD_WR_DATA(0x1B);
	LCD_WR_DATA(0x11);
	LCD_WR_DATA(0x70);
	LCD_WR_DATA(0x73);
	LCD_WR_DATA(0xFF);
	LCD_WR_DATA(0xFF);
	LCD_WR_DATA(0x08);
	LCD_WR_DATA(0x09);
	LCD_WR_DATA(0x05);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0xEE);
	LCD_WR_DATA(0xE2);
	LCD_WR_DATA(0x01);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0xC1);

	LCD_WR_REG(0xBD); // GIP 2
	LCD_WR_DATA(0x01);
	LCD_WR_DATA(0x23);
	LCD_WR_DATA(0x45);
	LCD_WR_DATA(0x67);
	LCD_WR_DATA(0x01);
	LCD_WR_DATA(0x23);
	LCD_WR_DATA(0x45);
	LCD_WR_DATA(0x67);

	LCD_WR_REG(0xBE); // GIP 3
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x22);
	LCD_WR_DATA(0x27);
	LCD_WR_DATA(0x6A);
	LCD_WR_DATA(0xBC);
	LCD_WR_DATA(0xD8);
	LCD_WR_DATA(0x92);
	LCD_WR_DATA(0x22);
	LCD_WR_DATA(0x22);

	LCD_WR_REG(0xC7); // Vcom  Control 1
	LCD_WR_DATA(0x1E);

	LCD_WR_REG(0xED); // EN_volt_reg
	LCD_WR_DATA(0x7F);
	LCD_WR_DATA(0x0F);
	LCD_WR_DATA(0x00);

	LCD_WR_REG(0xC0); // Power Control 1
	LCD_WR_DATA(0xE3);
	LCD_WR_DATA(0x0B);
	LCD_WR_DATA(0x00);

	LCD_WR_REG(0xFC);	//LVGL Viltage Setting
	LCD_WR_DATA(0x08);

	LCD_WR_REG(0xDF); // Engineering Setting
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x02);

	LCD_WR_REG(0xF3); // DVDD Voltage Setting
	LCD_WR_DATA(0x74);

	LCD_WR_REG(0xB4); // Display Inversion Control
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x00);

	LCD_WR_REG(0xF7); // �ֱ���ѡ��480x854
	LCD_WR_DATA(0x81);

	LCD_WR_REG(0xB1); // Frame Rate Control 1
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x10);
	LCD_WR_DATA(0x14);

	LCD_WR_REG(0xF1); // Panel Timing Control 1
	LCD_WR_DATA(0x29);
	LCD_WR_DATA(0x8A);
	LCD_WR_DATA(0x07);

	LCD_WR_REG(0xF2); //Panel Timing Control 2
	LCD_WR_DATA(0x40);
	LCD_WR_DATA(0xD2);
	LCD_WR_DATA(0x50);
	LCD_WR_DATA(0x28);

	LCD_WR_REG(0xC1); // Power Control 2
	LCD_WR_DATA(0x17);
	LCD_WR_DATA(0X85);
	LCD_WR_DATA(0x85);
	LCD_WR_DATA(0x20);

	LCD_WR_REG(0xE0);	//Positive Gamma Control
	LCD_WR_DATA(0x00); //P1
	LCD_WR_DATA(0x0C); //P2
	LCD_WR_DATA(0x15); //P3
	LCD_WR_DATA(0x0D); //P4
	LCD_WR_DATA(0x0F); //P5
	LCD_WR_DATA(0x0C); //P6
	LCD_WR_DATA(0x07); //P7
	LCD_WR_DATA(0x05); //P8
	LCD_WR_DATA(0x07); //P9
	LCD_WR_DATA(0x0B); //P10
	LCD_WR_DATA(0x10); //P11
	LCD_WR_DATA(0x10); //P12
	LCD_WR_DATA(0x0D); //P13
	LCD_WR_DATA(0x17); //P14
	LCD_WR_DATA(0x0F); //P15
	LCD_WR_DATA(0x00); //P16

	LCD_WR_REG(0xE1);	//Negative Gamma Correction
	LCD_WR_DATA(0x00); //P1
	LCD_WR_DATA(0x0D); //P2
	LCD_WR_DATA(0x15); //P3
	LCD_WR_DATA(0x0E); //P4
	LCD_WR_DATA(0x10); //P5
	LCD_WR_DATA(0x0D); //P6
	LCD_WR_DATA(0x08); //P7
	LCD_WR_DATA(0x06); //P8
	LCD_WR_DATA(0x07); //P9
	LCD_WR_DATA(0x0C); //P10
	LCD_WR_DATA(0x11); //P11
	LCD_WR_DATA(0x11); //P12
	LCD_WR_DATA(0x0E); //P13
	LCD_WR_DATA(0x17); //P14
	LCD_WR_DATA(0x0F); //P15
	LCD_WR_DATA(0x00); //P16

	LCD_WR_REG(0x35); //Tearing Effect Line ON
	LCD_WR_DATA(0x00);

	LCD_WR_REG(0x3A); //Interface Pixel Format
	LCD_WR_DATA(0x55);

	LCD_WR_REG(0x36); //Memory Access Control
	LCD_WR_DATA(0xA0); //������0x60,������0x00

	LCD_WR_REG(0x11); //Exit Sleep
	LCD_delay(120);
	LCD_WR_REG(0x29); // Display On
	LCD_delay(10);

	//Lcd_Light_ON;	//��������

//	LCD_WR_REG(0x36); //Memory Access Control
//	LCD_WR_DATA(0xA0);//����RGB˳��0XA0:RGB	0XA8:BGR

	LCD_Display_Dir(0);		//0����  1����
							//STemWin����������û���
	LCD_Clear(WHITE);
}


/*
****************************************************************
*����: ��������
*����: ������ɫ��λ��
****************************************************************
*/
void LCD_Clear(u16 color)
{
	u16 x=0,y=0;
	__IO u32 index=0;
	u32 totalpoint = lcd_dev.width;
	totalpoint *= lcd_dev.height;

	LCD_WR_REG(0X2A);		/* column address control set */
	LCD_WR_DATA(x>>8);	/* �ȸ�8λ��Ȼ���8λ */
	LCD_WR_DATA(x&0xff);	/* ������ʼ��ͽ�����*/
	LCD_WR_DATA((lcd_dev.width) >>8);
	LCD_WR_DATA((lcd_dev.width) &0xff);

	LCD_WR_REG(0X2B);		/* page address control set */
	LCD_WR_DATA(y>>8);
	LCD_WR_DATA(y&0xff);
	LCD_WR_DATA((lcd_dev.height) >>8);
	LCD_WR_DATA((lcd_dev.height) &0xff);

	LCD_WR_REG(0x2C);			//д��GRAM

	for( index=0;index < totalpoint ; index++ )
	{
		LCD_WR_DATA( color );
	}
}

/*
****************************************************************
*����: ��亯��
*����: ������ɫ��λ��
****************************************************************
*/
void LCD_Fill(u16 x, u16 y, u16 width, u16 height, u16 color)
{
	u32 i = 0;

	LCD_WR_REG(0X2A);
	LCD_WR_DATA( x >> 8 );				/* �ȸ�8λ��Ȼ���8λ */
	LCD_WR_DATA( x & 0xff );			/* column start   */
	LCD_WR_DATA( (x+width-1) >> 8 );	/* column end   */
	LCD_WR_DATA( (x+width-1) & 0xff );

  	LCD_WR_REG(0X2B);
	LCD_WR_DATA( y >> 8 );				/* page start   */
	LCD_WR_DATA( y & 0xff );
	LCD_WR_DATA( (y+height-1) >> 8);	/* page end     */
	LCD_WR_DATA( (y+height-1) & 0xff);

	LCD_WR_REG(0x2c);					/* memory write */

	for( i=0; i < width*height; i++ )
	{
		LCD_WR_DATA( color );
	}
}

/*
***********************************************************************
*����: ��ˮƽ��
*����: x1 y1  �����λ��
*		 x2 y2  ���յ�λ��
***********************************************************************
*/
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2)
{
	u16 t;
	int xerr=0,yerr=0,delta_x,delta_y,distance;
	int incx,incy,uRow,uCol;
	delta_x=x2-x1; //������������
	delta_y=y2-y1;
	uRow=x1;
	uCol=y1;
	if(delta_x>0)incx=1; //���õ�������
	else if(delta_x==0)incx=0;//��ֱ��
	else {incx=-1;delta_x=-delta_x;}
	if(delta_y>0)incy=1;
	else if(delta_y==0)incy=0;//ˮƽ��
	else{incy=-1;delta_y=-delta_y;}
	if( delta_x>delta_y)distance=delta_x; //ѡȡ��������������
	else distance=delta_y;
	for(t=0;t<=distance+1;t++ )//�������
	{
		LCD_DrawPoint(uRow, uCol);//����
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
*����: ������
*����: ���ζԽ�����
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
*����: ��Բ
*����: ԭ������Ͱ뾶
****************************************************************
*/
void LCD_Draw_Circle(u16 x,u16 y,u8 r)
{
	int a,b;
	int di;
	a=0;b=r;
	di=3-(r<<1);             //�ж��¸���λ�õı�־
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
		//ʹ��Bresenham�㷨��Բ
		if(di<0)di +=4*a+6;
		else
		{
			di+=10+4*(a-b);
			b--;
		}
	}
}





