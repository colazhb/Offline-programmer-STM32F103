/**
  ******************************************************************************
  * 实验平台： XH-STM32F103C8最小核心板 
  * 开发团队： 基穆道山实验室
  * 编写软件： Keil V4.54
  * 编写日期： 2015-07                                           
  ******************************************************************************
  */ 
	
#include "led.h"   

/*****************************************************************************
* 函数名：LED_Init()
* 描  述：LED灯管脚配置初始化函数
*****************************************************************************/			
void LED_Init(void)
{
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);//开启GPIOC的外设时钟 

		GPIO_InitStructure.GPIO_Pin = LED;									 //选择要控制LED灯引脚	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		 //设置引脚模式为通用推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //设置引脚速率为50MHz 
		GPIO_Init(GPIOC, &GPIO_InitStructure);							 //调用库函数，初始化GPIOC端口
		
		GPIO_SetBits(GPIOC, LED);			//关闭所有LED灯
}

void LED_NUM_Init(void)
{
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE);//开启GPIOC的外设时钟 
		GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE); 
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 |GPIO_Pin_1 |GPIO_Pin_2 |GPIO_Pin_3 |GPIO_Pin_4 |GPIO_Pin_5 |GPIO_Pin_6 |GPIO_Pin_7;									 //选择要控制LED灯引脚	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		 //设置引脚模式为通用推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //设置引脚速率为50MHz 
		GPIO_Init(GPIOB, &GPIO_InitStructure);							 //调用库函数，初始化GPIOC端口
		
		//GPIO_SetBits(GPIOC, LED);			//关闭所有LED灯
}

/************************基*穆*道*山*实*验*室********************************/
