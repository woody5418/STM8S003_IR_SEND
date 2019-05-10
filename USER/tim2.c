#include "tim2.h"
#include "uart.h"

void TIM2_Configuration_set_1ms(void)
{
  TIM2_DeInit();
  TIM2_TimeBaseInit(TIM2_PRESCALER_16,1000);
  TIM2_ITConfig( TIM2_IT_UPDATE , ENABLE);
  
  TIM2_SetCounter(0x0000); 
  
  TIM2_Cmd(ENABLE);
 
}

void GPIO_Configuration()
{
  GPIO_DeInit(GPIOD);
  GPIO_Init(GPIOD, GPIO_PIN_0, GPIO_MODE_OUT_PP_LOW_FAST);
}




#pragma vector=13+2
__interrupt void TIM2_IRQ()
{
  static unsigned int j;
  j++;
  if(j==1000)
  {
    j=0;
    GPIO_WriteReverse(GPIOD, GPIO_PIN_0);//1s取一次反
 }
 
   TIM2_ClearITPendingBit(TIM2_IT_UPDATE); //清中断标志位
}



