#include "microconfig.h"
//port E initialization
void init_PORT_E(void)
	{
	SYSCTL_RCGCGPIO_R |=0X10; //activate port E 
	while ((SYSCTL_PRGPIO_R&0X10)==0){};
	GPIO_PORTE_AMSEL_R &=~0X30;	 //lw el ba2e analogue yfdlo zy mahoma
	GPIO_PORTE_AFSEL_R |=0X30;
	GPIO_PORTE_PCTL_R |= 0x00110000; // set PE4 and PE5 to use UART2
//GPIO_PORTE_PCTL_R = (GPIO_PORTA_PCTL_R&0XFFFFFF00)|0X00000011; //configure UART0 RX/TX for PA0,PA1
	GPIO_PORTE_DEN_R |=0X30;
	}
	
//UART5_Initialization
void UART5_init(void){
	//unsigned BRD;
	init_PORT_E();
	SYSCTL_RCGCUART_R |= 0x20;
	SYSCTL_RCGCGPIO_R |= 0x10;   

	UART5_CTL_R &= ~0x1;
	//SET BRD
	//BR = 9600 BITS/SEC
	//16*10^6/(16*9600) = 104.16667
	UART5_IBRD_R = 104;
	UART5_FBRD_R = 11;
	UART5_LCRH_R = 0x70;
	UART5_CTL_R = 0x301;
	
	GPIO_PORTE_AFSEL_R |= 0X30;
	GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R & 0xFF00FFFF) + 0x00110000;
	GPIO_PORTE_DEN_R |= 0X30;	
	GPIO_PORTE_AMSEL_R = 0x0;
}
char UART_recieveByte(int num)
{
    if(num == 6)
    {
        while((UART6_FR_R&UART_FR_RXFE) != 0);      // wait until RXFE is 0
        return((char)(UART6_DR_R&0xFF));//8 bits one byte character
    }
    else if(num == 5)
    {
        while((UART5_FR_R&UART_FR_RXFE) != 0);      // wait until RXFE is 0
        return((char)(UART5_DR_R&0xFF));
    }
   
    else if(num==7)
    {
        while((UART7_FR_R&UART_FR_RXFE) != 0);      // wait until RXFE is 0
        return((char)(UART7_DR_R& 0xFF));
    }
		else{
			return 0;
		}
}
