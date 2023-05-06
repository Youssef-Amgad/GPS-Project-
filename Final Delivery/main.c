#include "microconfig.h"
#include "tm4c123gh6pm.h"
#include "TM4C123.h"    // Device header
void SystemInit(){};

int switch1,switch2,h=0;
float distance =0,total_distance =0;
float current[4]= {0};
float final[4]={0};
char* str;
	
int main()
	{
	   // initialization ports
    init_PORT_F();
		init_PORT_B();
		init_PORT_E();
		UART5_Init(16000000,9600,16000000);
		lcd_init();
		SysTick_Init();
		
	 while(1){  
		 switch2 = SW2_input();
		 switch1 = SW1_input();
		 if( switch2 != 0x10 ){
		   GPS_read(final);
			 h = 1; //flag
		 }
		 if ( h == 1 ){
		   str = "press switch 1";
			 lcd_cmd(lcd_Clear);
			 delayMs(500);
       lcd_str(str);
       delayMs(500);
			 str = "to start";
			 lcd_str_distance(str);
			 delayMs(500);
		 }else if ( h == 0 ){
		   str = "press switch 2";
       lcd_cmd(lcd_Clear);
			 delayMs(500);
       lcd_str(str);
       delayMs(500);
			 str ="to save final pt";
			 lcd_str_distance(str);
			 delayMs(500);
		 }
		 if( switch1 != 0x01){
		   str = "Total distance ="; //print "total distance"
			 lcd_cmd(lcd_Clear);
			 delayMs(500);
       lcd_str(str);
       delayMs(500);
			 while(1){
				 GPS_read(current);
				 if ( (current[2]==0)&&(current[3]==0) ){
				   current[2]=current[0];
					 current[3]=current[1];
					 GPS_read(current);
				 }
				 total_distance = total_distance + GPS_getDistance(current[2],current[3],current[0],current[1]); //calculating total distance
				 current[2]=current[0];
				 current[3]=current[1];
				 distance = GPS_getDistance(current[0],current[1],final[0],final[1]); //displacement from current point to final point
				 if( distance > 5 ){
				   RGB_Output(0x02);//led red
				 }else if( distance > 0.2){
				   RGB_Output(0x0A);//led yellow
				 }else{
				   RGB_Output(0x08);//led green
					 str= "thank u";  //print thank u and exit
					 lcd_cmd(lcd_Clear);
			     delayMs(500);
           lcd_str(str);
           delayMs(500);
					 break;
				 }
				 ftoa(total_distance,str,2); //print value of total distance
				// lcd_cmd(second_row);
			   delayMs(500);
         lcd_str_distance(str);
         delayMs(500);
			 }
		 }
	 }
}
