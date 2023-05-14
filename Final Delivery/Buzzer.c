#include "microconfig.h"
void buzzer_init() {
   
	SYSCTL_RCGCGPIO_R |=0X04;   //0000 0100
	while ((SYSCTL_PRGPIO_R & 0X04)==0){};
	GPIO_PORTC_AMSEL_R =0; 
	GPIO_PORTC_AFSEL_R =0;
	//--------------------------
	GPIO_PORTC_LOCK_R = 0x4C4F434B;
	GPIO_PORTC_CR_R =0x1F;
	//GPIO_PORTF_PCTL_R = 0X0000FFF0;
	
	//---------------------------
	GPIO_PORTC_DIR_R = 0x10;  // sets which pins are inputs and which pins are outputs 0001 0000
	GPIO_PORTC_DEN_R = 0x1F;  // use pins as digital inputs or outputs  00011111
	//GPIO_PORTC_PUR_R = 0x11;
	//GPIO_PORTF_DATA_R &= ~0X0E;
}

void buzzer_on() {
    GPIO_PORTC_DATA_R = 0x10;  // Set the buzzer pin high
}

void buzzer_off() {
    GPIO_PORTC_DATA_R = 0x00; // Set the buzzer pin low
}

