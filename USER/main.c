#include "stm8s.h"
#include "delay.h"
#include "sysclock.h"
#include "tim1.h"
#include "flash_eeprom.h"
#include "led.h"
#include "key.h"
#include "uart.h"
#include "adc.h"

u8 Write_Flag=0;


int main(void)
{ 
  u16 ADC_Value; 
  u8 eeprom_flag=0;
  
  SystemClock_Init(); 
  TIM1_Init(); 
  delay_init(16);
  ADC_Init();
  Init_EEPROM();
  LED_Init();
  KEY_Init();
  enableInterrupts(); 	/* 开启总中断 */ 
  LED_Show();
  ReadEEPROM(TIM_IR_BUFFER,IR_FLAG_REMOVE);

  while (1)
  { 
    if(eeprom_flag==0)
    {
      eeprom_flag=1;
      IR_FLAG_REMOVE = value_eeprom ;
      value_eeprom=0;
      GPIO_WriteHigh(LED_PORT, LED_1);
      delay_ms(500);
      GPIO_WriteLow(LED_PORT, LED_1);
    }
    
    ADC_Value = ADC1_GetConversionValue();
    key_study();
    if(key_led_flag == 1)
    {
      LED_REVERSE();
    }    
    if(ADC_Value > 50000)  // 高
    {
      delay_ms(20);
      if(ADC_Value > 50000)
      {
        ADC_Value=0;
       
        IR_Send(TIM_IR_BUFFER);
      }
    }
    delay_ms(1);
    if(Write_Flag == 1)
    {
      WriteEEPROM(TIM_IR_BUFFER,IR_FLAG_REMOVE);
      Write_Flag=0;
    }
  }
}

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
    
  }
}
#endif






