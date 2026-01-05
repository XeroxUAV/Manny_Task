#include "functions.h"
#include "main.h"
#include "adc.h"

unsigned char s1_switch,s1_active_cnt,s1_inactive_cnt,D_cnt=1,AD_Value;
void Bits_Counter(void)
{
	HAL_GPIO_TogglePin(D1_GPIO_Port,D1_Pin);
	if((D_cnt%2)==0)
		HAL_GPIO_TogglePin(D2_GPIO_Port,D2_Pin);
	if(((D_cnt%4)==0) || ((D_cnt%8)==0) || ((D_cnt%12)==0))
	{
		HAL_GPIO_TogglePin(D3_GPIO_Port,D3_Pin);
	}
	if((D_cnt%8)==0)
	{
		HAL_GPIO_TogglePin(D4_GPIO_Port,D4_Pin);
	}
	if(D_cnt>=16)
		D_cnt = 0;
	D_cnt++;
	HAL_Delay(1000);
}
void Blink_LED(void)
{
	HAL_GPIO_TogglePin(D1_GPIO_Port,D1_Pin);
	HAL_Delay(500);
}
void Switch_Test(void)
{
	if(HAL_GPIO_ReadPin(S1_GPIO_Port,S1_Pin)==0)
	{
		s1_active_cnt++;
		s1_inactive_cnt=0;
		if(s1_active_cnt>=5)
		{
			s1_switch = 1;
		}
	}
	else
	{
		s1_active_cnt=0;
		s1_inactive_cnt++;
		if(s1_inactive_cnt>=5)
		{
				s1_switch=0;
		}
	}
	if(s1_switch)
	{
		HAL_GPIO_WritePin(D1_GPIO_Port,D1_Pin,GPIO_PIN_SET);
	}
	else
		HAL_GPIO_WritePin(D1_GPIO_Port,D1_Pin,GPIO_PIN_RESET);
	
}
void My_Delay(unsigned int ms)
{
    volatile unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1000; j++);
}
void Potentio_LED(void)
{
	HAL_ADCEx_Calibration_Start(&hadc1);
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 1); 
	AD_Value = HAL_ADC_GetValue(&hadc1);
	TIM1->CCR4 = (AD_Value<<4);
	HAL_Delay(1);
}
