#include "microconfig.h"
//for LEDS in TIVA-C
void init_PORT_F(void)
	{
	//uint32_t delay;
	SYSCTL_RCGCGPIO_R |=0X20;   //0010 0000
	while ((SYSCTL_PRGPIO_R & 0X20)==0){};
	GPIO_PORTF_AMSEL_R =0; 
	GPIO_PORTF_AFSEL_R =0;
	//--------------------------
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R =0x1F;
	//GPIO_PORTF_PCTL_R = 0X0000FFF0;
	
	//---------------------------
	GPIO_PORTF_DIR_R = 0x0E;  // sets which pins are inputs and which pins are outputs 00001110
	GPIO_PORTF_DEN_R = 0x1F;  // use pins as digital inputs or outputs  00011111
	GPIO_PORTF_PUR_R = 0x11;
	//GPIO_PORTF_DATA_R &= ~0X0E;
}
	
//for LCD
void init_PORT_B(void)
	{
	
	SYSCTL_RCGCGPIO_R |=0X02;  //0000 0010
	while ((SYSCTL_PRGPIO_R & 0X02)==0);
 /*
GPIO_PORTB_AMSEL_R &= ~0XFF; 
GPIO_PORTB_AFSEL_R &= ~0XFF;

GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;
GPIO_PORTB_CR_R |= 0xFF;
GPIO_PORTF_PCTL_R = 0X0000FFF0;
	*/
	GPIO_PORTB_DIR_R |= 0xFF;  // sets which pins are inputs and which pins are outputs 00001110
	GPIO_PORTB_DEN_R |= 0xFF;  // use pins as digital inputs or outputs  00011111
}
	

//functions for portf input and output
	uint32_t SW_input(void){
return (GPIO_PORTF_DATA_R&0x11); // read PF4,PF0 0001 0000
}

	
void RGB_Output(uint32_t data){ // write PF3-PF1 outputs 
	GPIO_PORTF_DATA_R = data;
}
