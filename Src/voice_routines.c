

#include "main.h"
#include "cmsis_os.h"
#include "fatfs.h"

extern SAI_HandleTypeDef hsai_BlockA1;
__IO int16_t                 UpdatePointer = -1;
__IO BUFFER_StateTypeDef buffer_offset;


extern unsigned char button_press[];
extern unsigned char button_release[];
 extern unsigned char _1_[];
uint8_t     PlayBuff[PLAY_BUFF_SIZE];


void HAL_SAI_TxCpltCallback(SAI_HandleTypeDef *hsai)
{

  buffer_offset = BUFFER_OFFSET_FULL;
  UpdatePointer = PLAY_BUFF_SIZE/2;

}

void HAL_SAI_TxHalfCpltCallback(SAI_HandleTypeDef *hsai)
{
  buffer_offset = BUFFER_OFFSET_HALF;
  UpdatePointer = 0;
}

void audio_stop(void)
{
  HAL_SAI_DMAStop(&hsai_BlockA1);
}

void audio_start(void)
{
  HAL_SAI_Transmit_DMA(&hsai_BlockA1, (uint8_t *)PlayBuff, PLAY_BUFF_SIZE/2);
}

void fill_buffer_from_flash(int address)       // fill 2048 bytes
    {
       W25qxx_ReadPage(&PlayBuff[0],address,0,256) ;
       W25qxx_ReadPage(&PlayBuff[256],address+1,0,256) ;
       W25qxx_ReadPage(&PlayBuff[512],address+2,0,256) ;
       W25qxx_ReadPage(&PlayBuff[768],address+3,0,256) ;

        W25qxx_ReadPage(&PlayBuff[1024],address+4,0,256) ;
        W25qxx_ReadPage(&PlayBuff[1280],address+5,0,256) ;
        W25qxx_ReadPage(&PlayBuff[1536],address+6,0,256) ;
        W25qxx_ReadPage(&PlayBuff[1792],address+7,0,256) ;
    }

void play_sound(int adress, int length)
{
  int start,end;
  int pointer;
  start = adress;
  end = adress + (length / 256 )+1;
   pointer = start;
  buffer_offset = BUFFER_OFFSET_NONE;

  fill_buffer_from_flash(adress); // заполнить буфер звука из флэша по адресу
  pointer+=8;
 // W25qxx_ReadBytes(PlayBuff, adress, PLAY_BUFF_SIZE);             //прочесть 2048 байт в буфер играния по адресу adress
//  pointer = adress + PLAY_BUFF_SIZE;


  audio_start();
  while(pointer<end)
  {
                                       if(buffer_offset == BUFFER_OFFSET_HALF) //прерывание по дма на половину буфера
                                        {

                                                 W25qxx_ReadPage(&PlayBuff[0],adress,0,256) ;
                                                 W25qxx_ReadPage(&PlayBuff[256],adress+1,0,256) ;
                                                 W25qxx_ReadPage(&PlayBuff[512],adress+2,0,256) ;
                                                 W25qxx_ReadPage(&PlayBuff[768],adress+3,0,256) ;

                                                 adress+=4;
                                                 pointer+=4;
                                                 buffer_offset = BUFFER_OFFSET_NONE;  //подготовим первую половину буфера, проигрываем вторую

                                        }


                                        if(buffer_offset == BUFFER_OFFSET_FULL) //прерывание по дма отыграли весь буфер
                                        {


                                                 W25qxx_ReadPage(&PlayBuff[1024],adress,0,256) ;
                                                 W25qxx_ReadPage(&PlayBuff[1280],adress+1,0,256) ;
                                                 W25qxx_ReadPage(&PlayBuff[1536],adress+2,0,256) ;
                                                 W25qxx_ReadPage(&PlayBuff[1792],adress+3,0,256) ;
                                                  adress+=4;
                                                 pointer+=4;
                                                 buffer_offset = BUFFER_OFFSET_NONE;
                                        }

  }
  audio_stop();

}

 void DataToFlash(uint8_t *buffer512, uint32_t index) {
  uint32_t sector_index = index / 8;
  if (index % 8 == 0) {
    W25qxx_EraseSector(sector_index);
  }
  W25qxx_WritePage(&buffer512[0],   index + 0, 0, 256);
  W25qxx_WritePage(&buffer512[256], index + 1, 0, 256);
}


int flash_write(char *buff,int adress, int length)
     {
       uint32_t index = adress, i = 0, total = length,count;
       uint8_t sector[512];

for (; i < total; i += 512, index += 2) {
   count = (i + 512 > total ? total - i : 512);
   memcpy(sector,&buff[i], count);
   DataToFlash(sector, index);
}
return index+1;
     }



void voice_to_flash(void)
{
   int q = 0;
 // flash_write(op,0, 84780);
  q = flash_write(button_press,q, 14252);
  q = flash_write(button_release,q, 15952);
  //122
}


void _play_sound(void)
{

  buffer_offset = BUFFER_OFFSET_NONE;


  HAL_SAI_Transmit_DMA(&hsai_BlockA1, (uint8_t *)_1_,8595);
 //  while ( buffer_offset !=   BUFFER_OFFSET_FULL)
//       {
 //            GUI_X_Delay(20);
 //      }
//  HAL_SAI_DMAStop(&hsai_BlockA1);

}




