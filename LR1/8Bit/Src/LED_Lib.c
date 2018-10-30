#include "LED_Lib.h"
#include "stm32f3xx_hal.h"
#include <string.h>

#define P GPIOE 

#define S1 GPIO_PIN_8 //NE
#define S2 GPIO_PIN_9 //N
#define S3 GPIO_PIN_10
#define S4 GPIO_PIN_11
#define S5 GPIO_PIN_12
#define S6 GPIO_PIN_13
#define S7 GPIO_PIN_14 //SW
#define S8 GPIO_PIN_15 //W

uint32_t word[8]=
{GPIO_PIN_8,
GPIO_PIN_9,
GPIO_PIN_10,
GPIO_PIN_11,
GPIO_PIN_12,
GPIO_PIN_13,
GPIO_PIN_14,
GPIO_PIN_15};

void setPin(uint32_t s)
{HAL_GPIO_WritePin(P,s,SET);}

void resetPin(uint32_t s)
{HAL_GPIO_WritePin(P,s,RESET);}

void outChar(char c, int offset)
{
for(int i=0;i<8;i++)
if(c&(1<<i)) 
setPin(word[(i+offset)%8]);
else 
resetPin(word[(i+offset)%8]);
}

void outString(char* str, int offset)
{
  //uint8_t siz=(int)(sizeof(str)/sizeof(char));
  int siz=strlen(str);
for(int i=0;i<siz;i++)
{outChar(str[i], offset);

} 
}