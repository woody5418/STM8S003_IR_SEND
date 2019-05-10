#include "adc.h"
#include "delay.h"


void ADC_Init(void)
{
  
    GPIO_Init( GPIOD,AD_channel3,GPIO_MODE_IN_PU_NO_IT );//GPIO的3管脚对应ADC采集的4通道
  
    /**< 连续转换模式 */
    /**< 使能通道 */
    /**< ADC时钟：fADC2 = fcpu/18 */
    /**< 这里设置了从TIM TRGO 启动转换，但实际是没有用到的*/
    /**  不使能 ADC2_ExtTriggerState**/
    /**< 转换数据左对齐 */
    /**< 不使能通道10的斯密特触发器 */
    /**  不使能通道10的斯密特触发器状态 */
    ADC1_DeInit();
    ADC1_Cmd(ENABLE);
    //ADC1_ConversionConfig(ADC1_CONVERSIONMODE_CONTINUOUS, ADC1_CHANNEL_3, ADC1_ALIGN_LEFT);
    ADC1_Init(ADC1_CONVERSIONMODE_CONTINUOUS, ADC1_CHANNEL_3, ADC1_PRESSEL_FCPU_D2, \
    ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_LEFT, ADC1_SCHMITTTRIG_CHANNEL3, DISABLE);

    ADC1_Cmd(ENABLE);
    ADC1_StartConversion(); 
}

