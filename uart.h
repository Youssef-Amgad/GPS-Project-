#include "microconfig.h"


void UART7_Init(unsigned clk, unsigned baudrate,unsigned clkdiv);
void init_PORT_E(void);

void UART7_transmit(char data);
void UART7_OutString(char *pt);
void UART6_Init(unsigned clk, unsigned baudrate,unsigned clkdiv);

void UART6_transmit(char data);
void UART6_OutString(char *pt);
void getCommand(char * Command, int len);
void UART5_Init(unsigned clk, unsigned baudrate,unsigned clkdiv);
char UART_recieveByte(int num);
