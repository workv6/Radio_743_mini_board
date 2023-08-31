

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"


   #define RTC_CLOCK_SOURCE_LSE

 #define u8  uint8_t
#define u16 uint16_t
#define u32 uint32_t

 #define RTC_ASYNCH_PREDIV  0x7F
#define RTC_SYNCH_PREDIV   0x00FF

   #define bool char
   #define false 0
   #define true 1
     typedef uint8_t* string;
   #define FALSE  0
#define TRUE  !FALSE
/*
struct _ts_event
{
    uint16_t    x1;
    uint16_t    y1;
    uint16_t    x2;
    uint16_t    y2;
    uint16_t    x3;
    uint16_t    y3;
    uint16_t    x4;
    uint16_t    y4;
    uint16_t    x5;
    uint16_t    y5;
    uint8_t     touch_point;
    uint8_t     Key_Sta;
};
  */
#define ID_TEXT_0           (GUI_ID_USER + 0x06)
#define ID_TEXT_1           (GUI_ID_USER + 0x07)
#define ID_TEXT_2           (GUI_ID_USER + 0x08)
#define ID_TEXT_3           (GUI_ID_USER + 0x09)
#define ID_TEXT_4           (GUI_ID_USER + 0x0a)

#define WRITE_ADD	0x70
#define READ_ADD	0x71

#define Detect_touch_Pin GPIO_PIN_2
#define Detect_touch_GPIO_Port GPIOD


#define cs_spi_flash_Pin       GPIO_PIN_11
#define cs_spi_flash_GPIO_Port GPIOB


#define station_1_key       GPIO_PIN_13
#define station_1_Port      GPIOB
#define station_2_key       GPIO_PIN_1
#define station_2_Port      GPIOB
#define station_3_key       GPIO_PIN_0
#define station_3_Port      GPIOB
#define station_4_key       GPIO_PIN_5
#define station_4_Port      GPIOC
//#define station_5_key       GPIO_PIN_4
//#define station_5_Port      GPIOC
#define return_key          GPIO_PIN_12
#define return_Port         GPIOB


#define up_key                GPIO_PIN_2
#define up_key_Port           GPIOC
#define down_key              GPIO_PIN_10
#define down_key_Port         GPIOB
#define left_key              GPIO_PIN_3
#define left_key_Port         GPIOC
#define right_key             GPIO_PIN_0
#define right_key_Port        GPIOC
#define izb_key             GPIO_PIN_12
#define izb_key_Port        GPIOC

#define inf_key             GPIO_PIN_10
#define inf_key_Port        GPIOC

#define spisok_key             GPIO_PIN_11
#define spisok_key_Port        GPIOC

#define play_key             GPIO_PIN_15
#define play_key_Port        GPIOA

#define back_key             GPIO_PIN_7
#define back_key_Port        GPIOC

#define ok_key             GPIO_PIN_2
#define ok_key_Port        GPIOE
     
//#define  mute_port              GPIOB
//#define  mute_pin               GPIO_PIN_7
     
#define  mute_port              GPIOC
#define  mute_pin               GPIO_PIN_6
     
     // GPIOA.1 for old board, GPIOA.4 for mini board (2.1)
#define       ESP32_RESET_PORT          GPIOA
#define       ESP32_RESET_PIN           GPIO_PIN_4
     
    
//#define OLD_KBD 1   // дл€ старого экземпл€ра
     
// mute on - pin = 1 дл€ подключени€ через транзистор (bc547), если напр€мую - mute_on - pin = 0    
  
     
#define HW210     // красна€ плата
     // провод па€етс€ напр€мую к пину Mute (ближе к перемычке питани€)
#ifdef HW210
#define MUTE_OFF          HAL_GPIO_WritePin(mute_port, mute_pin, GPIO_PIN_RESET)
#define MUTE_ON         HAL_GPIO_WritePin(mute_port, mute_pin, GPIO_PIN_SET)     
#else
#define MUTE_ON          HAL_GPIO_WritePin(mute_port, mute_pin, GPIO_PIN_RESET)
#define MUTE_OFF         HAL_GPIO_WritePin(mute_port, mute_pin, GPIO_PIN_SET)     
#endif
#define button_up_press                  (( up_key_Port->IDR &   up_key) ==     (uint32_t)RESET)
#define button_down_press                (( down_key_Port->IDR & down_key) ==   (uint32_t)RESET)
#define button_left_press                (( left_key_Port->IDR & left_key) ==   (uint32_t)RESET)
#define button_right_press               (( right_key_Port->IDR & right_key) == (uint32_t)RESET)


//#define button_1_press                (( station_1_Port->IDR &   station_1_key) == (uint32_t)RESET)
//#define button_2_press                (( station_2_Port->IDR &   station_2_key) == (uint32_t)RESET)
//#define button_3_press                (( station_3_Port->IDR &   station_3_key) == (uint32_t)RESET)
//#define button_4_press                (( station_4_Port->IDR &   station_4_key) == (uint32_t)RESET)
//#define button_5_press                (( station_5_Port->IDR &   station_5_key) == (uint32_t)RESET)

#define button_ok_press                 (( ok_key_Port->IDR &  ok_key) == (uint32_t)RESET)
//#define button_back_press               (( back_key_Port->IDR &  back_key) == (uint32_t)RESET)
#define button_list_press               (( spisok_key_Port->IDR &  spisok_key) == (uint32_t)RESET)
#define button_play_press               (( play_key_Port->IDR &  play_key) == (uint32_t)RESET)
#define button_return_press             (( return_Port->IDR &  return_key) == (uint32_t)RESET)
#define button_izb_press                (( izb_key_Port->IDR &   izb_key) == (uint32_t)RESET)
#define button_inf_press                (( inf_key_Port->IDR &   inf_key) == (uint32_t)RESET)
#define SRAM_MEMORY_WIDTH               FMC_NORSRAM_MEM_BUS_WIDTH_16
/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);


#define MIN_ADC_VALUE   2130
#define MAX_ADC_VALUE   2555
#define ADC_CONVERTED_DATA_BUFFER_SIZE   ((uint32_t)  10)


typedef enum
{
  BUFFER_OFFSET_NONE = 0,
  BUFFER_OFFSET_HALF,
  BUFFER_OFFSET_FULL,
}BUFFER_StateTypeDef;

#define PLAY_BUFF_SIZE     2048

/* USER CODE BEGIN EFP */
#define Key_Down 0x01
#define Key_Up   0x00
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Detect_SDIO_Pin GPIO_PIN_6
#define Detect_SDIO_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */
#pragma pack(push, 1)
struct Controller_ControlFrame {
    long dt, lat, lon, alt, course, speed; // 6*4 bytes
};
struct Controller_DiffFrame {
    char dlon, dlat, dalt, dcourse, dspeed; // 5*1 bytes
};

#pragma pack(pop)



#define TIMx                           TIM4
#define TIMx_CLK_ENABLE()              __HAL_RCC_TIM4_CLK_ENABLE()
/* Definition for TIMx Channel Pins */
#define TIMx_CHANNEL_GPIO_PORT()       __HAL_RCC_GPIOD_CLK_ENABLE();
#define TIMx_GPIO_PORT_CHANNEL1        GPIOD
#define TIMx_GPIO_PIN_CHANNEL1         GPIO_PIN_12
#define TIMx_GPIO_AF_CHANNEL1          GPIO_AF2_TIM4


#define    maxbright 499
#define    minbright 50

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
