
/* Includes ------------------------------------------------------------------*/
#include "bsp_driver_sd.h"

/* Extern variables ---------------------------------------------------------*/

extern SD_HandleTypeDef hsd2;


uint8_t BSP_SD_Init(void)
{
  uint8_t sd_state = MSD_OK;
  /* Check if the SD card is plugged in the slot */
  if (BSP_SD_IsDetected() != SD_PRESENT)
  {
    return MSD_ERROR_SD_NOT_PRESENT;
  }
  /* HAL SD initialization */
  sd_state = HAL_SD_Init(&hsd2);
  /* Configure SD Bus width (4 bits mode selected) */
  if (sd_state == MSD_OK)
  {
    /* Enable wide operation */
    if (HAL_SD_ConfigWideBusOperation(&hsd2, SDMMC_BUS_WIDE_4B) != HAL_OK)
    {
      sd_state = MSD_ERROR;
    }
  }

  return sd_state;
}



uint8_t BSP_SD_DeInit(void)
{
  uint8_t sd_state = MSD_OK;


  /* HAL SD deinitialization */
  if(HAL_SD_DeInit(&hsd2) != HAL_OK)
  {
    sd_state = MSD_ERROR;
  }

  /* Msp SD deinitialization */
HAL_SD_MspDeInit(&hsd2);

  return  sd_state;
}




uint8_t BSP_SD_ITConfig(void)
{

  return (uint8_t)0;
}


uint8_t BSP_SD_ReadBlocks(uint32_t *pData, uint32_t ReadAddr, uint32_t NumOfBlocks, uint32_t Timeout)
{
  uint8_t sd_state = MSD_OK;

  if (HAL_SD_ReadBlocks(&hsd2, (uint8_t *)pData, ReadAddr, NumOfBlocks, Timeout) != HAL_OK)
  {
    sd_state = MSD_ERROR;
  }

  return sd_state;
}


uint8_t BSP_SD_WriteBlocks(uint32_t *pData, uint32_t WriteAddr, uint32_t NumOfBlocks, uint32_t Timeout)
{
  uint8_t sd_state = MSD_OK;

  if (HAL_SD_WriteBlocks(&hsd2, (uint8_t *)pData, WriteAddr, NumOfBlocks, Timeout) != HAL_OK)
  {
    sd_state = MSD_ERROR;
  }

  return sd_state;
}
 /*

uint8_t BSP_SD_ReadBlocks_DMA(uint32_t *pData, uint32_t ReadAddr, uint32_t NumOfBlocks)
{
  uint8_t sd_state = MSD_OK;

 // /* Read block(s) in DMA transfer mode
  if (HAL_SD_ReadBlocks_DMA(&hsd2, (uint8_t *)pData, ReadAddr, NumOfBlocks) != HAL_OK)
  {
    sd_state = MSD_ERROR;
  }

  return sd_state;
}


uint8_t BSP_SD_WriteBlocks_DMA(uint32_t *pData, uint32_t WriteAddr, uint32_t NumOfBlocks)
{
  uint8_t sd_state = MSD_OK;

  ///* Write block(s) in DMA transfer mode
  if (HAL_SD_WriteBlocks_DMA(&hsd2, (uint8_t *)pData, WriteAddr, NumOfBlocks) != HAL_OK)
  {
    sd_state = MSD_ERROR;
  }

  return sd_state;
}
  */

uint8_t BSP_SD_Erase(uint32_t StartAddr, uint32_t EndAddr)
{
  uint8_t sd_state = MSD_OK;

  if (HAL_SD_Erase(&hsd2, StartAddr, EndAddr) != HAL_OK)
  {
    sd_state = MSD_ERROR;
  }

  return sd_state;
}


uint8_t BSP_SD_GetCardState(void)
{
  return ((HAL_SD_GetCardState(&hsd2) == HAL_SD_CARD_TRANSFER ) ? SD_TRANSFER_OK : SD_TRANSFER_BUSY);
}


void BSP_SD_GetCardInfo(HAL_SD_CardInfoTypeDef *CardInfo)
{
  /* Get SD card Information */
  HAL_SD_GetCardInfo(&hsd2, CardInfo);
}


void HAL_SD_AbortCallback(SD_HandleTypeDef *hsd)
{
  BSP_SD_AbortCallback();
}


void HAL_SD_TxCpltCallback(SD_HandleTypeDef *hsd)
{
  BSP_SD_WriteCpltCallback();
}


void HAL_SD_RxCpltCallback(SD_HandleTypeDef *hsd)
{
  BSP_SD_ReadCpltCallback();
}


__weak void BSP_SD_AbortCallback(void)
{

}

/**
  * @brief BSP Tx Transfer completed callback
  * @retval None
  */
__weak void BSP_SD_WriteCpltCallback(void)
{

}

/**
  * @brief BSP Rx Transfer completed callback
  * @retval None
  */
__weak void BSP_SD_ReadCpltCallback(void)
{

}


