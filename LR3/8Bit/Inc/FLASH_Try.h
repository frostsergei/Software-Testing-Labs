#include "stm32f3xx_hal.h"

void flash_unlock();
void flash_lock();
uint8_t flash_ready(void);
void flash_erase_all_pages(void);
void flash_erase_page(uint32_t address); 
void flash_write(uint32_t address,uint32_t data); 
uint32_t flash_read(uint16_t address); 
