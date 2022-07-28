#include"stm32f10x.h"
#include"usart.h"
#include"iic.h"
#include"ee.h"
#include"adc.h"

extern __IO uint16_t ADC_ConvertedValue[CHANNEL_NUMBER];

// 局部变量，用于保存转换计算后的电压值 	 
float ADC_ConvertedValueLocal[6];        

// 软件延时
void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  Usart_config();
	printf("欢迎使用秉火STM32开是的风光过后发板\n\n\n\n");
	
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
