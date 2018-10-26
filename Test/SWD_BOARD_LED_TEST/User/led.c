/**
  ******************************************************************************
  * ʵ��ƽ̨�� XH-STM32F103C8��С���İ� 
  * �����Ŷӣ� ���µ�ɽʵ����
  * ��д����� Keil V4.54
  * ��д���ڣ� 2015-07                                           
  ******************************************************************************
  */ 
	
#include "led.h"   

/*****************************************************************************
* ��������LED_Init()
* ��  ����LED�ƹܽ����ó�ʼ������
*****************************************************************************/			
void LED_Init(void)
{
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);//����GPIOC������ʱ�� 

		GPIO_InitStructure.GPIO_Pin = LED;									 //ѡ��Ҫ����LED������	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		 //��������ģʽΪͨ���������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //������������Ϊ50MHz 
		GPIO_Init(GPIOC, &GPIO_InitStructure);							 //���ÿ⺯������ʼ��GPIOC�˿�
		
		GPIO_SetBits(GPIOC, LED);			//�ر�����LED��
}

void LED_NUM_Init(void)
{
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE);//����GPIOC������ʱ�� 
		GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE); 
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 |GPIO_Pin_1 |GPIO_Pin_2 |GPIO_Pin_3 |GPIO_Pin_4 |GPIO_Pin_5 |GPIO_Pin_6 |GPIO_Pin_7;									 //ѡ��Ҫ����LED������	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		 //��������ģʽΪͨ���������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //������������Ϊ50MHz 
		GPIO_Init(GPIOB, &GPIO_InitStructure);							 //���ÿ⺯������ʼ��GPIOC�˿�
		
		//GPIO_SetBits(GPIOC, LED);			//�ر�����LED��
}

/************************��*��*��*ɽ*ʵ*��*��********************************/
