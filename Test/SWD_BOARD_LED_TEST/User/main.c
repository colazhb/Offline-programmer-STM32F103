/**
  ******************************************************************************
  * 实验平台： XH-STM32F103C8最小核心板 
  * 开发团队： 基穆道山实验室
  * 编写软件： Keil V4.54
  * 编写日期： 2015-07
	* 实验说明： 呼吸灯效果                                             
  ******************************************************************************
  */  
	
#include "stm32f10x.h"
#include "led.h"

void Delay(__IO uint32_t nCount)
{
  for (; nCount != 0; nCount--);
}

uint8_t num_pin[]={0x90,0xfa,0x8c,0xa8,0xe2,0xa1,0x81,0xf8,0x80,0xa0};
/********************************主函数*************************************/
int main(void)
{	
//	unsigned int Time=5000, PWM=0;//定义周期并赋值
int i=0;
	//LED_Init();			//LED灯初始化函数	
	LED_NUM_Init();
	//GPIO_ResetBits(GPIOC,LED);    //熄灭LED灯
	//Delay(1000000);	
	
	while(1)
	{	
 
				GPIOB->ODR=num_pin[i];     //点亮LED灯 
   												//延时长度，5000次循环中
				//GPIO_ResetBits(GPIOB,(~num_pin[i])<<8);    //熄灭LED灯

		Delay(900000);		
		i++;
		if(i>9) i=0;

	}	
}

/************************基*穆*道*山*实*验*室********************************/
