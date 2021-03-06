/**
  ******************************************************************************
  * 实验平台： XH-STM32F103C8最小核心板 
  * 开发团队： 基穆道山实验室
  * 编写软件： Keil V4.54
  * 编写日期： 2015-07                                           
  ******************************************************************************
  */  
	
#include "delay.h"   
	
/******************************************************
* 函数名：delay()
* 描  述：简单delay初始化函数
* 输  入：0--0xFFFFFFFF
* 输  出：无
* 备  注: 软件延时，通过执行代码达到延时效果。
********************************************************/			
void delay(__IO uint32_t nCount)
{
  for (; nCount != 0; nCount--);
}

/************************基*穆*道*山*实*验*室********************************/
