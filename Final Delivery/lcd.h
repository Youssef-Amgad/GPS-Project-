#ifndef LCD_H_
#define LCD_H_
#define lcd_Clear            0x01          
#define lcd_Home             0x02          
#define lcd_EntryMode        0x06         
#define lcd_DisplayOff       0x08          
#define lcd_DisplayOn        0x0F          
#define Set5x7FontSize    	 0x20					
#define four_bit_mode		     0x28					
#define lcd_FunctionReset    0x30       
#define first_row            0x80         
#define second_row           0xC0          
#define CURSOR_OFF           0x0C					 
#define CURSOR_ON            0x0E					 
#define EN									 0x04					 
#define RS									 0x01					 
void lcd_init(void);
void lcd_cmd(unsigned char cmd);
void lcd_write(unsigned char c, unsigned char ctrl);
void lcd_char(unsigned char data, unsigned char ctrl);
void lcd_str( char *str);
void delayMs(int n);
void delayUs(int n);
void reverse(char* str, int len);
int intToStr(int x, char str[], int d);
void lcd_str_2nd_row(char *str);




#endif
