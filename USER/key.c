#include "key.h"
#include "led.h"
#include "tim1.h"
#include "delay.h"


u8 KEY_STUDY=0;  //����ѧϰģʽ
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
       KEY_STUDY=1; // ����ѧϰģʽ
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
  	/* �밴����������������Ϊ����ģʽ */
    //GPIO_Init(GPIOC, GPIO_PIN_7, GPIO_MODE_IN_PU_IT);	
	/* ��GPIOD�˿�����Ϊ�½��ش����ж�--��Ϊ��������ʱ����һ���͵�ƽ */
    //EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOC, EXTI_SENSITIVITY_FALL_ONLY);
//}

/*
// C7�ⲿ�ж�
#pragma vector=5+2  // PORTC.7
__interrupt void EXTI_PORTC_IRQHandler(void)
{
    EXTI_Sensitivity_TypeDef  Keyexti_Type;
    Keyexti_Type = EXTI_GetExtIntSensitivity(EXTI_PORT_GPIOC);
    switch (Keyexti_Type)	// �õ���ǰ�������������ж����� 
    {
	case EXTI_SENSITIVITY_FALL_LOW :	// �͵�ƽ���� 

             break;
	case EXTI_SENSITIVITY_RISE_ONLY :	// �����ش��� 

              break;
	case EXTI_SENSITIVITY_FALL_ONLY :	// �½��ش��� 
        // �ж����ĸ����ŷ����ⲿ�ж� 
              if (!GPIO_ReadInputPin(GPIOC, GPIO_PIN_7)) 
                 {	
                    //GPIO_WriteReverse(GPIOA, GPIO_PIN_1);
                   KEY_STUDY=1; // ����ѧϰģʽ
		 }
		break;
	case EXTI_SENSITIVITY_RISE_FALL :	// �ߵ�ƽ���� 

		break;
	default:
	 	break;
	}
  
  
}
*/












