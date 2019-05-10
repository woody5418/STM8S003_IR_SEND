#ifndef __LED_H
#define __LED_H



#include "stm8s.h"

#define LED_PORT            GPIOD	
#define LED_1               GPIO_PIN_3

#define ON       0		/* ����LED���� -- �͵�ƽ*/
#define OFF      1		/* ����LED���� -- �ߵ�ƽ*/

void LED_Init(void);
void IR_Init(void);
void LED_REVERSE(void);
void LED_Show(void);
void YES_STUDY(void);
void LED_Config(GPIO_Pin_TypeDef led, u8 state);


#endif