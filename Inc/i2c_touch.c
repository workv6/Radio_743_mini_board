#include "main.h"

#include "i2c_routines.h"

//Touch Status	 





uint8_t ft6x0x_read_data(void);

struct _ts_event ts_event; 


void TOUCH_RdParFrPCTPFun(uint8_t *PCTP_Par,uint8_t ValFlag)
{	uint8_t k;

	i2c_start();
	i2c_write(READ_ADD);
	wait_ack ();	
	for(k=0;k<ValFlag;k++)
	{
		if(k==(ValFlag-1))  *(PCTP_Par+k)=i2c_read(0);
		else                *(PCTP_Par+k)=i2c_read(1);
	}		
	i2c_stop();
}





uint8_t ft6x0x_read_data(void)
{	
  uint8_t buf[13] = {0}; uint8_t ret = 0;


		TOUCH_RdParFrPCTPFun(buf, 13);
                ts_event.touch_point = buf[2] & 0xf;



					switch (ts_event.touch_point) 
					{

						    case 2:
						           	ts_event.x2 = (uint16_t)(buf[9] & 0x0F)<<8 | (uint16_t)buf[10];
						           	ts_event.y2 = (uint16_t)(buf[11] & 0x0F)<<8 | (uint16_t)buf[12];
						
						    case 1:
						           	ts_event.x1 = (uint16_t)(buf[3] & 0x0F)<<8 | (uint16_t)buf[4];
						           	ts_event.y1 = (uint16_t)(buf[5] & 0x0F)<<8 | (uint16_t)buf[6];
				
						    break;
						    default:
						    return 0;
					}


    
	return ret;
}


