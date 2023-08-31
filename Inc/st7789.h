#include "main.h"
#include "cmsis_os.h"

#define ST7789_TFTWIDTH_240 	240
#define ST7789_TFTHEIGHT_240 	240

extern uint16_t scr_width;
extern uint16_t scr_height;


#define scr_w         240
#define scr_h         240

#define ST7789_240x240_XSTART 0
#define ST7789_240x240_YSTART 0

#define ST_CMD_DELAY   0x80    // special signifier for command lists

#define ST7789_NOP     0x00
#define ST7789_SWRESET 0x01
#define ST7789_RDDID   0x04
#define ST7789_RDDST   0x09

#define ST7789_SLPIN   0x10
#define ST7789_SLPOUT  0x11
#define ST7789_PTLON   0x12
#define ST7789_NORON   0x13

#define ST7789_INVOFF  0x20
#define ST7789_INVON   0x21
#define ST7789_DISPOFF 0x28
#define ST7789_DISPON  0x29
#define ST7789_CASET   0x2A
#define ST7789_RASET   0x2B
#define ST7789_RAMWR   0x2C
#define ST7789_RAMRD   0x2E

#define ST7789_PTLAR   0x30
#define ST7789_COLMOD  0x3A
#define ST7789_MADCTL  0x36

#define ST7789_MADCTL_MY  0x80
#define ST7789_MADCTL_MX  0x40
#define ST7789_MADCTL_MV  0x20
#define ST7789_MADCTL_ML  0x10
#define ST7789_MADCTL_RGB 0x00

#define ST7789_RDID1   0xDA
#define ST7789_RDID2   0xDB
#define ST7789_RDID3   0xDC
#define ST7789_RDID4   0xDD

// Color definitions
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

typedef enum {
	scr_normal = 0,
	scr_CW     = 1,
	scr_CCW    = 2,
	scr_180    = 3
} ScrOrientation_TypeDef;

// ST7735 dc
# define  ST7735_DC_PORT      GPIOC
# define  ST7735_DC_PIN       GPIO_PIN_5 // 

// ST7735 RST  
# define  ST7735_RST_PORT     GPIOC
# define  ST7735_RST_PIN      GPIO_PIN_4     //

// ST7735 CS (Chip Select)  
# define  ST7735_CS_PORT      GPIOC
# define  ST7735_CS_PIN       GPIO_PIN_0 //  

// CS pin  
# define  CS_L() ST7735_CS_PORT->BSRRH = ST7735_CS_PIN;// (ST7735_CS_PORT, ST7735_CS_PIN)
# define  CS_H() ST7735_CS_PORT->BSRRL = ST7735_CS_PIN;

// dc pin  
# define  DC_L() ST7735_DC_PORT->BSRRH = ST7735_DC_PIN;
# define  DC_H() ST7735_DC_PORT->BSRRL = ST7735_DC_PIN;

//  
# define  RST_L() ST7735_RST_PORT->BSRRH = ST7735_RST_PIN;
# define  RST_H() ST7735_RST_PORT->BSRRL = ST7735_RST_PIN;

