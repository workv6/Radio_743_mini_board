

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32h7xx_it.h"
#include "cmsis_os.h"


/* External variables --------------------------------------------------------*/
//extern PCD_HandleTypeDef hpcd_USB_OTG_FS;
extern TIM_HandleTypeDef htim7;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern SAI_HandleTypeDef hsai_BlockA1;
extern PCD_HandleTypeDef hpcd_USB_OTG_FS;
uint16_t tim_b1,tim_b2,tim_b3,tim_b4,tim_b5;
extern RTC_HandleTypeDef RtcHandle;
extern int fade_counter;
extern int time_to_change;
extern int start_timer_ee1,start_timer_ee2,start_timer_ee3,start_timer_ee4,start_timer_ee5;
/******************************************************************************/
/*           Cortex Processor Interruption and Exception Handlers          */
/******************************************************************************/




/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */
   u8 tbuf[11];
  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
            sprintf(tbuf,"sys.boot\r\n");
            printf2(tbuf,10);
            HAL_NVIC_SystemReset();  // висим - уарт повис  // тут совсем пиздец.
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}



/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}



/******************************************************************************/
/* STM32H7xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32h7xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles TIM7 global interrupt.
  */
void TIM7_IRQHandler(void)
{
  /* USER CODE BEGIN TIM7_IRQn 0 */

  /* USER CODE END TIM7_IRQn 0 */
  HAL_TIM_IRQHandler(&htim7);
  /* USER CODE BEGIN TIM7_IRQn 1 */
 // if (fade_counter>0) fade_counter--;


   if (time_to_change>0) time_to_change--;

  /* USER CODE END TIM7_IRQn 1 */
}

/**
  * @brief This function handles USB On The Go FS global interrupt.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}


void EXTI2_IRQHandler(void)
{
  if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_2)==GPIO_PIN_RESET)
   {
     HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_2);

   }
}

void EXTI9_5_IRQHandler(void)
{

    if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_6)==GPIO_PIN_RESET)
   {
     HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);


   }
 __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_6);
}


void USART1_IRQHandler(void)
{
  HAL_UART_IRQHandler(&huart1);
}


void USART2_IRQHandler(void)
{

  HAL_UART_IRQHandler(&huart2);

}

extern DMA_HandleTypeDef hdma_usart2_rx;

void DMA1_Stream2_IRQHandler(void)
{
   HAL_DMA_IRQHandler(&hdma_usart2_rx);

}



void RTC_Alarm_IRQHandler(void)
{
  HAL_RTC_AlarmIRQHandler(&RtcHandle);
}



void OTG_FS_IRQHandler(void)
{
  /* USER CODE BEGIN OTG_FS_IRQn 0 */

  /* USER CODE END OTG_FS_IRQn 0 */
  HAL_PCD_IRQHandler(&hpcd_USB_OTG_FS);
  /* USER CODE BEGIN OTG_FS_IRQn 1 */

  /* USER CODE END OTG_FS_IRQn 1 */
}
