  
/*****************************DETAILS FOR SEVEN SEGMENT PROJECT***********************************/
/*

pins: 0,1,2,3,4,5,6,7
port: C

Common cathode : ON - 0 , OFF - 1
Common anode : ON - 1 , OFF - 0

Common Anode: 						
0	01000000	C0  
1	01111001	F9
2	00100100	A4
3	00110000	B0
4	00011001	99
5	00010010	92
6	00000010	82
7	01111000	F8
8	00000000	80
9	00010000	90

Common Cathode:
0	0111111	3F
1	0000110	06
2	1011011	5B
3	1001111	4F
4	1100110	66
5	1101101	6D
6	1111101	7D
7	0000111	07
8	1111111	7F
9	1001111	4F

I am using common anode configuration here. 

*/

/***********Initialisations*************/
#include "stm32f10x.h"

GPIO_InitTypeDef GPIOInitStructure;
TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
NVIC_InitTypeDef NVIC_InitStructure;

void gpio_define(void);
void TIM2_define(void);

uint16_t flag=0;
	
	
int main(void)
{
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);

	
   gpio_define();
	 TIM2_define();
	 TIM_Cmd(TIM2,ENABLE);
	
	/***********SEVEN SEGMENT CODE START******************/
	  GPIOC->ODR=0xff;
	
		uint8_t lables[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
		uint8_t i=0;
		while(1){
				
			 if(flag==1)
					{
					flag=0;		 
					GPIOC->ODR=lables[i];				
					i++;
				}		

				if(i==10)
				{
				i=0;
				}
        
  /***********SEVEN SEGMENT CODE END******************/
				
}
	
	
 
 return 0;
}


void gpio_define(void)
{

 GPIOInitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
 GPIOInitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIOInitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOC,&GPIOInitStructure);

}

void TIM2_define()
{
	TIM_TimeBaseStructure.TIM_Prescaler =  (SystemCoreClock/10000) - 1;
	TIM_TimeBaseStructure.TIM_Period = 9;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel =TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStructure);
	
}

void TIM2_IRQHandler(void)
{
	static uint16_t mscounter=0;
	if(TIM_GetITStatus(TIM2,TIM_IT_Update) == SET){
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
		mscounter++;
		if(mscounter%1000 == 0){
				flag=1;
		}

	
	}
}



