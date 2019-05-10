#include "key.h"
#include "led.h"
#include "tim1.h"
#include "delay.h"


u8 KEY_STUDY=0;  //进入学习模式
//u8 LED_Low=0;
u8 key_led_flag=0;
u16 Bijiao_buffer[280];

void KEY_Init(void)
{       
    GPIO_Init(GPIOC, GPIO_PIN_7, GPIO_MODE_IN_PU_NO_IT);         
}


void key_study(void)
{
  if(GPIO_ReadInputPin(GPIOC, GPIO_PIN_7) == 0)
   {
     delay_ms(10);
     if(GPIO_ReadInputPin(GPIOC, GPIO_PIN_7) == 0)
     {
       KEY_STUDY=1; // 进入学习模式
       IR_STA_CNT=0;
       key_led_flag=1;
       IR_FLAG_REMOVE=0;
       IR_FLAG_300=0;
       t_cnt=0;
     }
   }
}

//void Key_Exti_Init(void)
//{
  	/* 与按键相连的引脚设置为输入模式 */
    //GPIO_Init(GPIOC, GPIO_PIN_7, GPIO_MODE_IN_PU_IT);	
	/* 将GPIOD端口设置为下降沿触发中断--因为按键按下时产生一个低电平 */
    //EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOC, EXTI_SENSITIVITY_FALL_ONLY);
//}

/*
// C7外部中断
#pragma vector=5+2  // PORTC.7
__interrupt void EXTI_PORTC_IRQHandler(void)
{
    EXTI_Sensitivity_TypeDef  Keyexti_Type;
    Keyexti_Type = EXTI_GetExtIntSensitivity(EXTI_PORT_GPIOC);
    switch (Keyexti_Type)	// 得到当前发生的是哪种中断类型 
    {
	case EXTI_SENSITIVITY_FALL_LOW :	// 低电平触发 

             break;
	case EXTI_SENSITIVITY_RISE_ONLY :	// 上升沿触发 

              break;
	case EXTI_SENSITIVITY_FALL_ONLY :	// 下降沿触发 
        // 判断是哪个引脚发生外部中断 
              if (!GPIO_ReadInputPin(GPIOC, GPIO_PIN_7)) 
                 {	
                    //GPIO_WriteReverse(GPIOA, GPIO_PIN_1);
                   KEY_STUDY=1; // 进入学习模式
		 }
		break;
	case EXTI_SENSITIVITY_RISE_FALL :	// 高电平触发 

		break;
	default:
	 	break;
	}
  
  
}
*/












