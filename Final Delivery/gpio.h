#ifndef GPIO_H_
#define GPIO_H_
#include "microconfig.h"
#define RED_LED     0x02           
#define BLUE_LED    0x04           
#define GREEN_LED   0x08
#define YELLOW_LED  0x0A
#define SWITCH_1    0x10  
void SW1_Int_Interrupt(void);             
void GPIOF_Handler(void);                 
void init_PORT_F(void);
void init_PORT_B(void);
uint32_t SW_input(void);
void RGB_Output(uint32_t data);
void switch_press(void);


#endif 
