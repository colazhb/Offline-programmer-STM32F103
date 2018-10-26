GPIO�Ĵ������� ��STM32�ο��ֲ�����-p75��

1���˿����õͼĴ���(GPIOx_CRL)(x = A...E)
2���˿����ø߼Ĵ���(GPIOx_CRH)(x = A...E)

3���˿��������ݼĴ���(GPIOx_IDR)(x = A...E)
   ��ЩλΪֻ����ֻ������(16λ)����ʽ������������ֵΪ��ӦI/O�ڵ�״̬��
   
4���˿�������ݼĴ���(GPIOx_ODR)(x = A...E)
   ֻ������(16bit)����ʽ��������λֵȫ��0��д0�����0��д1�����1��
   
5���˿�λ����/����Ĵ���(GPIOx_BSRR)(x = A...E)
   ��16bitд1������0����16bitд1������λ��ͬʱд1�Ļ���16bi��Ч��
   
6���˿�λ����Ĵ���(GPIOx_BRR)(x = A...E)
   ��16λд1������λ��
   
7���˿����������Ĵ���(GPIOx_LCKR)(x = A...E)

GPIO����ģʽ
typedef enum
{ GPIO_Mode_AIN = 0x0,            /* ģ������ */   
  GPIO_Mode_IN_FLOATING = 0x04,   /* �������룬��λ���״̬ */
  GPIO_Mode_IPD = 0x28,           /* �������� */
  GPIO_Mode_IPU = 0x48,           /* �������� */
  GPIO_Mode_Out_OD = 0x14,        /* ��©��� */
  GPIO_Mode_Out_PP = 0x10,        /* ������� */
  GPIO_Mode_AF_OD = 0x1C,         /* ���ÿ�©��� */
  GPIO_Mode_AF_PP = 0x18          /* ����������� */
}GPIOMode_TypeDef;
=====================================================================================
/* ����LED1�� */
GPIO_SetBits(GPIOC, LED1);

/* Ϩ��LED1�� */
GPIO_ResetBits(GPIOC, LED1);


/**
  * @brief  Sets the selected data port bits.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bits to be written.
  *   This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */
void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_Pin));
  
  GPIOx->BSRR = GPIO_Pin;
}

/**
  * @brief  Clears the selected data port bits.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bits to be written.
  *   This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_Pin));
  
  GPIOx->BRR = GPIO_Pin;
}
