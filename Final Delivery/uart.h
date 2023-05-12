#include "microconfig.h"

void init_PORT_E(void);
//void UART5_Init(unsigned clk, unsigned baudrate,unsigned clkdiv);
char UART_recieveByte(int num);
void UART5_init(void);


//void UART7_Init(unsigned clk, unsigned baudrate,unsigned clkdiv);
void UART5_transmit(char data);
void UART5_OutString(char *pt);
//void UART6_Init(unsigned clk, unsigned baudrate,unsigned clkdiv);
void UART_OutChar(char data);
void UART_OutString(char *pt);
void UART_Init(unsigned clk, unsigned baudrate);
//void UART6_transmit(char data);
//void UART6_OutString(char *pt);
//void getCommand(char * Command, int len);
