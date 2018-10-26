#include <bsp.h>
#include <sfud.h>
#include <stdio.h>
#include <stdlib.h>
#include "flash_file_type_def.h"

#define SFUD_DEMO_TEST_BUFFER_SIZE                     1024

static void sfud_demo(uint32_t addr, size_t size, uint8_t *data);

static uint8_t sfud_demo_test_buf[SFUD_DEMO_TEST_BUFFER_SIZE];

int main(void) {

    bsp_init();
	file_info_array[0].fileInfo.id=1;
	file_info_array[0].fileInfo.times=5001;
	
	strcpy(&file_info_array[0].fileInfo.fileName,"abcsaldfalsdf.h");
	
	file_info_array[2].fileInfo.id=1;
	file_info_array[2].fileInfo.times=53232;
	strcpy(&file_info_array[2].fileInfo.fileName,"fffqqqqeeee.h");
	
	memcpy(sfud_demo_test_buf,file_info_array,sizeof(file_info_array));
    /* SFUD initialize */
    if (sfud_init() == SFUD_SUCCESS) {
        sfud_demo(0, sizeof(file_info_array), sfud_demo_test_buf);
    }

    while (1) {
        LED_RUN_ON;
        delay(6000000);
        LED_RUN_OFF;
        delay(6000000);
    }
}

/**
 * SFUD demo for the first flash device test.
 *
 * @param addr flash start address
 * @param size test flash size
 * @param size test flash data buffer
 */
static void sfud_demo(uint32_t addr, size_t size, uint8_t *data) {
    sfud_err result = SFUD_SUCCESS;
    const sfud_flash *flash = sfud_get_device_table() + 0;
    size_t i;
		FLASH_UN file_info_array_read[FILE_MAX_NUM];
	  uint8_t charbuf[1024];
    /* prepare write data */

    /* erase test */
    result = sfud_erase(flash, addr, size);
    if (result == SFUD_SUCCESS) {
        printf("Erase the %s flash data finish. Start from 0x%08X, size is %ld.\r\n", flash->name, addr,
                size);
    } else {
        printf("Erase the %s flash data failed.\r\n", flash->name);
        return;
    }
    /* write test */
    result = sfud_write(flash, addr, size, data);
    if (result == SFUD_SUCCESS) {
        printf("Write the %s flash data finish. Start from 0x%08X, size is %ld.\r\n", flash->name, addr,
                size);
    } else {
        printf("Write the %s flash data failed.\r\n", flash->name);
        return;
    }
    /* read test */
    result = sfud_read(flash, addr, size, charbuf);
    if (result == SFUD_SUCCESS) {
        memcpy(file_info_array_read,charbuf,sizeof(file_info_array_read));
			
    } else {
        printf("Read the %s flash data failed.\r\n", flash->name);
    }
    /* data check */
    for (i = 0; i < size; i++) {
        if (data[i] != charbuf[i]) {
            printf("Read and check write data has an error. Write the %s flash data failed.\r\n", flash->name);
			break;
        }
    }
    if (i == size) {
        printf("The %s flash test is success.\r\n", flash->name);
    }
}
