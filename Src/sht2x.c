#include "main.h"
#include "i2c_routines.h"

#define SHT21_ADDR							0x80

#define SHT21_CMD_TEMPERATURE		0xE3
#define SHT21_CMD_HUMIDITY			0xE5
#define SHT21_USER_REG					0xE7
#define SHT21_SOFT_RESET				0xFE


void I2C1_config (void)
{
  initI2C();
/*	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	I2C_InitTypeDef I2C_InitStructure;


  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);


	I2C_InitStructure.I2C_Ack = I2C_Ack_Disable;
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	I2C_InitStructure.I2C_ClockSpeed = 200000;
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStructure.I2C_OwnAddress1 = 0x0B;

	I2C_Init(I2C1,&I2C_InitStructure);
	I2C_Cmd(I2C1,ENABLE);
*/
}



void I2C1_write(unsigned char HW_address, unsigned char sub, unsigned char data)
{
  i2c_start();
  HAL_Delay(10);
  i2c_write(0x80);
  wait_ack();
  HAL_Delay(10);
  i2c_write(sub);
  wait_ack();
  HAL_Delay(10);
  i2c_write(data);
  wait_ack();
  HAL_Delay(10);
  i2c_stop();
 /*
	int ticks = I2C_TIMEOUT;			// number of flag checks before stop i2c transmition

	I2C_GenerateSTART(I2C1, ENABLE);
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT)&&ticks) {ticks--;}
	if (ticks == 0) return;
	ticks = I2C_TIMEOUT;

	I2C_Send7bitAddress(I2C1, HW_address, I2C_Direction_Transmitter);
	while((!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)) && ticks) {ticks--;}
	if (ticks == 0) return;
	ticks = I2C_TIMEOUT;

	if (sub != 0xFF)
	{
		I2C_SendData(I2C1, sub);
		while((!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))&&ticks) {ticks--;}
		if (ticks == 0) return;
		ticks = I2C_TIMEOUT;
	}

	I2C_SendData(I2C1, data);
	while((!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))&&ticks) {ticks--;}
	if (ticks == 0) return;
	ticks = I2C_TIMEOUT;

	I2C_GenerateSTOP(I2C1, ENABLE);
	while((I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY)) && ticks) {ticks--;}
	if (ticks == 0) return;
*/
}

char I2C1_read (unsigned char HW_address, unsigned char sub)
{
	char data;
          i2c_start();
          HAL_Delay(10);
  i2c_write(0x80);
  wait_ack();
  i2c_write(sub);
  wait_ack();

    HAL_Delay(100);
  i2c_start();
  i2c_write(0x81);
  wait_ack();
  data = i2c_read(0);
 // wait_ack ();

  i2c_stop();
  return data;

}

void I2C1_read_buf (unsigned char HW_address, unsigned char sub, unsigned char * p_buf, unsigned char buf_size)
{
  i2c_start();
  i2c_write(0x80);
  wait_ack();
  i2c_write(sub);
  wait_ack();
//  i2c_stop();

  i2c_start();
//  wait_ack ();
  i2c_write(0x81);
  wait_ack();
    HAL_Delay(100);
  for (uint8_t i=0; i<buf_size-1; i++)
  {
    p_buf[i] = i2c_read(1);
  }
  p_buf[buf_size-1] = i2c_read(0);
   // wait_ack ();

  i2c_stop();

}

void SHT21_Init (void)
{
	I2C1_config();
}

float SHT21_ReadTemp (void)
{
	uint8_t tmp8[3];
	float ret;

	I2C1_read_buf(SHT21_ADDR,SHT21_CMD_TEMPERATURE,tmp8, 3);

	ret = -46.85 + 175.72*(float)(tmp8[0]<<8 | (tmp8[1] & 0xFC))/65536;

	return (float) (-46.85 + 175.72*(float)(tmp8[0]<<8 | (tmp8[1] & 0xFC))/65536);
}

float SHT21_ReadHumidity (void)
{
	uint8_t tmp8[3];
	float ret;

	I2C1_read_buf(SHT21_ADDR,SHT21_CMD_HUMIDITY,tmp8, 3);

	ret = -6 + 125*(float)(tmp8[0]<<8 | (tmp8[1] & 0xFC))/65536;

	return ret;
}