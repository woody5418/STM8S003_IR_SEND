#include "led.h"
#include "delay.h"


void LED_Init(void)
{       
    //����LED�Ĺܽ�Ϊ���ģʽ 
    GPIO_Init(GPIOD, GPIO_PIN_3,   GPIO_MODE_OUT_PP_HIGH_FAST );  // LED ��-ģ��
    GPIO_Init(GPIOD, GPIO_PIN_4, GPIO_MODE_OUT_PP_HIGH_FAST ); //IR -ģ�� ����
    GPIO_Init(GPIOA, GPIO_PIN_3, GPIO_MODE_OUT_PP_HIGH_FAST ); //LED -������
    GPIO_WriteLow(LED_PORT, LED_1);
    GPIO_WriteLow(GPIOD, GPIO_PIN_4);
    GPIO_WriteLow(GPIOA, GPIO_PIN_3);
}


void LED_Config(GPIO_Pin_TypeDef led, u8 state)
{
    if(ON == state) 
    {
        GPIO_WriteLow(GPIOD, led);
    }
    else
    {
        GPIO_WriteHigh(GPIOD, led);
    }
}

void LED_REVERSE(void)
{
    LED_Config(LED_1, OFF);// ��
    GPIO_WriteHigh(GPIOA, GPIO_PIN_3);

    delay_ms(100);
    LED_Config(LED_1, ON);//  ��
    GPIO_WriteLow(GPIOA, GPIO_PIN_3);
    delay_ms(100);
}

void YES_STUDY(void)
{
    LED_Config(LED_1, ON);//  ��
    
    GPIO_WriteLow(GPIOA, GPIO_PIN_3);
    delay_ms(300);
    
    LED_Config(LED_1, OFF);// ��
    
    GPIO_WriteHigh(GPIOA, GPIO_PIN_3);
    delay_ms(300);
    
    LED_Config(LED_1, ON);//  ��
    
    GPIO_WriteLow(GPIOA, GPIO_PIN_3);
    delay_ms(300);
}

void LED_Show(void)
{
    LED_Config(LED_1, OFF);// ��
    delay_ms(50);
    LED_Config(LED_1, ON);//  ��
    delay_ms(50);
    
    LED_Config(LED_1, OFF);// ��
    delay_ms(50);
    LED_Config(LED_1, ON);//  ��
    delay_ms(50);
    
    LED_Config(LED_1, OFF);// ��
    delay_ms(50);
    LED_Config(LED_1, ON);//  ��
    delay_ms(50);
    
    LED_Config(LED_1, OFF);// ��
    delay_ms(50);
    LED_Config(LED_1, ON);//  ��
    delay_ms(50);
    
    LED_Config(LED_1, OFF);// ��
    delay_ms(50);
    LED_Config(LED_1, ON);//  ��
    delay_ms(50);
}















