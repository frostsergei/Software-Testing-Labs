
#include "stm32f3xx_hal.h"

void setPin(uint32_t s);
void resetPin(uint32_t s);
void outChar(char c, int offset);
void outString(char* str, int offset);