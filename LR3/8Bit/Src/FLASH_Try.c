#include "FLASH_Try.h"

#include "stm32f3xx_hal.h"

void flash_unlock()
{
FLASH->KEYR = FLASH_KEY1;
FLASH->KEYR = FLASH_KEY2;
}

void flash_lock()
{
FLASH->CR |= FLASH_CR_LOCK;
}

uint8_t flash_ready(void) {
return !(FLASH->SR & FLASH_SR_BSY);
}
void flash_erase_all_pages(void) {
FLASH->CR |= FLASH_CR_MER; //Устанавливаем бит стирания ВСЕХ страниц
FLASH->CR |= FLASH_CR_STRT; //Начать стирание
while(!flash_ready()); // Ожидание готовности.. Хотя оно уже наверное ни к чему здесь...
FLASH->CR &= FLASH_CR_MER;
}

void flash_erase_page(uint32_t address) {
FLASH->CR|= FLASH_CR_PER; //Устанавливаем бит стирания одной страницы
FLASH->AR = address; // Задаем её адрес
FLASH->CR|= FLASH_CR_STRT; // Запускаем стирание
while(!flash_ready());
FLASH->CR&= ~FLASH_CR_PER; //Сбрасываем бит обратно
}

void flash_write(uint32_t address,uint32_t data) 
{
FLASH->CR |= FLASH_CR_PG; //Разрешаем программирование флеша
while(!flash_ready()); //Ожидаем готовности флеша к записи
*(__IO uint16_t*)address = (uint16_t)data; //Пишем младшие 2 бата
while(!flash_ready());
address+=2;
data>>=16;
*(__IO uint16_t*)address = (uint16_t)data; //Пишем старшие 2 байта
while(!flash_ready());
FLASH->CR &= ~(FLASH_CR_PG); //Запрещаем программирование флеша
}

uint32_t flash_read(uint16_t address) 
{
  return (*(__IO uint32_t*) address);
}