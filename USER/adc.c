#include "adc.h"
#include "delay.h"


void ADC_Init(void)
{
  
    GPIO_Init( GPIOD,AD_channel3,GPIO_MODE_IN_PU_NO_IT );//GPIO��3�ܽŶ�ӦADC�ɼ���4ͨ��
  
    /**< ����ת��ģʽ */
    /**< ʹ��ͨ�� */
    /**< ADCʱ�ӣ�fADC2 = fcpu/18 */
    /**< ���������˴�TIM TRGO ����ת������ʵ����û���õ���*/
    /**  ��ʹ�� ADC2_ExtTriggerState**/
    /**< ת����������� */
    /**< ��ʹ��ͨ��10��˹���ش����� */
    /**  ��ʹ��ͨ��10��˹���ش�����״̬ */
    ADC1_DeInit();
    ADC1_Cmd(ENABLE);
    //ADC1_ConversionConfig(ADC1_CONVERSIONMODE_CONTINUOUS, ADC1_CHANNEL_3, ADC1_ALIGN_LEFT);
    ADC1_Init(ADC1_CONVERSIONMODE_CONTINUOUS, ADC1_CHANNEL_3, ADC1_PRESSEL_FCPU_D2, \
    ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_LEFT, ADC1_SCHMITTTRIG_CHANNEL3, DISABLE);

    ADC1_Cmd(ENABLE);
    ADC1_StartConversion(); 
}

