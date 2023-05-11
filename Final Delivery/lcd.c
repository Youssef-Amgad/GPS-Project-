#include "microconfig.h"

void lcd_init(void){
	SYSCTL_RCGCGPIO_R |= 0x02;
	while((SYSCTL_PRGPIO_R & 0x02)==0)
	{
	}
	GPIO_PORTB_LOCK_R = 0x4C4F434B;
	GPIO_PORTB_CR_R |= 0xFF;
	GPIO_PORTB_AMSEL_R = 0;
	GPIO_PORTB_AFSEL_R = 0;
	GPIO_PORTB_PCTL_R = 0;
	GPIO_PORTB_DEN_R = 0xFF;
	GPIO_PORTB_DIR_R = 0xFF;

	lcd_cmd(Set5x7FontSize);
	lcd_cmd(four_bit_mode);
	lcd_cmd(lcd_EntryMode);
	lcd_cmd(lcd_Clear);
	lcd_cmd(lcd_DisplayOn);
	lcd_cmd(first_row);
}

void lcd_cmd(unsigned char cmd){
	lcd_write(cmd & 0xF0, 0);
	lcd_write(cmd<<4, 0);
	if(cmd < 4){
		delay_ms (20);
	}
	else{
		delay_us (400);
	}
}

void lcd_write(unsigned char c, unsigned char ctrl){
	c &= 0XF0;
	ctrl &= 0x0F;
	GPIO_PORTB_DATA_R = c | ctrl;
	GPIO_PORTB_DATA_R = c | ctrl | EN;
	delay_ms(50);                 //delay is 1 sec.
	GPIO_PORTB_DATA_R = c;
	GPIO_PORTB_DATA_R = 0;
}

void lcd_char(unsigned char data, unsigned char ctrl){
	lcd_write(data&0xF0, RS);
	lcd_write(data<<4, RS);
	delay_us(40);
}

void lcd_str( char *str){
	int i;	
	for( i = 0; *str!=0; i++){
		lcd_char(*(str++),RS);
	}
}
void lcd_str_2nd_row( char *str){
	int i;
	lcd_cmd(second_row);
	for( i = 0; *str!=0; i++){
		lcd_char(*(str++),RS);
	}
}
void reverse(char* str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
 
int intToStr(int x, char str[], int d)
{
    int i = 0;
    while (x) {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }
 
    while (i < d)
        str[i++] = '0';
 
    reverse(str, i);
    str[i] = '\0';
    return i;
}

