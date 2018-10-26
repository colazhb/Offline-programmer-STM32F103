
#ifndef  __FLASH_FILE_TYPE_DEF_H__
#define  __FLASH_FILE_TYPE_DEF_H__

#include <stm32f10x_conf.h>
#define FILE_NAME_MAX_LEN 30
#define FILE_MAX_NUM 4
#define FILE_BIN_START_ADDR 0x100
#define FILE_BIN_BLOCK 0x10

typedef struct  
	{
	uint8_t id;
	uint8_t flag;
	uint8_t times;
	uint16_t date;
	uint32_t crc;
	uint32_t fileSize;
	uint32_t binaddr;
	uint32_t destaddr;
	uint8_t fileName[FILE_NAME_MAX_LEN];
	}FILE_INFO_CB ;
	
typedef union
{
	FILE_INFO_CB fileInfo;
	uint8_t buf[sizeof(FILE_INFO_CB)];
}FLASH_UN;
extern FLASH_UN file_info_array[FILE_MAX_NUM];
#endif
