#include"stm32f10x.h"
#include"usart.h"
#include"iic.h"
#include"ee.h"
#include"adc.h"

extern __IO uint16_t ADC_ConvertedValue[CHANNEL_NUMBER];

// �ֲ����������ڱ���ת�������ĵ�ѹֵ 	 
float ADC_ConvertedValueLocal[6];        

// �����ʱ
void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{	
  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  Usart_config();
	printf("��ӭʹ�ñ���STM32���ǵķ����󷢰�\n\n\n\n");
	
	ADCx_Init();
	
  while(1)
	{	
		ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3;
		ADC_ConvertedValueLocal[1] =(float) ADC_ConvertedValue[1]/4096*3.3; 
		ADC_ConvertedValueLocal[2] =(float) ADC_ConvertedValue[2]/4096*3.3; 
		ADC_ConvertedValueLocal[3]=(float) ADC_ConvertedValue[3]/4096*3.3; 
		ADC_ConvertedValueLocal[4] =(float) ADC_ConvertedValue[4]/4096*3.3; 
		ADC_ConvertedValueLocal[5] =(float) ADC_ConvertedValue[5]/4096*3.3; 		
	
	//	printf("\r\n The current AD value0 = 0x%04X \r\n",ADC_ConvertedValue[0]); 
		printf("\r\n The current AD value0 = %f V \r\n",ADC_ConvertedValueLocal[0]); 
	//	printf("\r\n The current AD value1 = 0x%04X \r\n",ADC_ConvertedValue[1]); 
		printf("\r\n The current AD value1 = %f V \r\n",ADC_ConvertedValueLocal[1]); 
	//	printf("\r\n The current AD value2 = 0x%04X \r\n",ADC_ConvertedValue[2]); 
		printf("\r\n The current AD value2 = %f V \r\n",ADC_ConvertedValueLocal[2]);
//		printf("\r\n The current AD value3 = 0x%04X \r\n",ADC_ConvertedValue[3]); 
		printf("\r\n The current AD value3 = %f V \r\n",ADC_ConvertedValueLocal[3]);
//		printf("\r\n The current AD value4 = 0x%04X \r\n",ADC_ConvertedValue[4]); 
		printf("\r\n The current AD value4 = %f V \r\n",ADC_ConvertedValueLocal[4]);
//		printf("\r\n The current AD value5 = 0x%04X \r\n",ADC_ConvertedValue[5]); 
		printf("\r\n The current AD value5= %f V \r\n",ADC_ConvertedValueLocal[5]);
		printf("\r\n\r\n");

		Delay(0xffffee); 
	}	
}

/*********************************************END OF FILE**********************/
