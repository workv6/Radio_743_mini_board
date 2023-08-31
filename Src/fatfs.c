#include "fatfs.h"

uint8_t retSD;    /* Return value for SD */
extern char SDPath[];   /* SD logical drive path */
FATFS SDFatFS;    /* File system object for SD logical drive */
FIL SDFile;       /* File object for SD */


void MX_FATFS_Init(void) 
{
  /*## FatFS: Link the SD driver ###########################*/
  retSD = FATFS_LinkDriver(&SD_Driver, SDPath);
}


DWORD get_fattime(void)
{
  return 0;
}

