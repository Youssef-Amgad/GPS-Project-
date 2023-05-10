#include "microconfig.h"
#include "tm4c123gh6pm.h"
#include "TM4C123.h"    // Device header

char switches,h,k;
double distance,total_distance;
char* str;
char* klam;
char c;



void float_to_char_array(float value, char* char_array, int array_size) {
    // Format the float value as a string and store it in char_array
    sprintf(char_array, "%f", value);
}

int main()
	 {	  
		
		float current_lat=0,current_long=0;
    float previous_lat=0,previous_long=0;
		float test_lat=0,test_long=0;
		float final_lat=0,final_long=0;
		char result[16]; 
		c = 0x0;
		distance=0;
		total_distance=0;
		k=0;
		h=0; 
		// initialization ports
    init_PORT_F();
		init_PORT_B();
		SysTick_Init();
		UART5_init();
		lcd_init();
		RGB_Output(0x02);
		
	 while(1){ 
		 if(k==0)
		 {
			 str = "LOADING...";
			 lcd_cmd(lcd_Clear);
			 delay_ms(500);
			 lcd_str(str);
			 delay_ms(500);
		 }
		 while (c != 0x01)   //to stop program until gps read valid readings
		 {
			 test_lat = GPS_read_lat();
		   test_long = GPS_read_long();
			 k=1;
		 }
		 delay_ms(1000);			 		 
		 switches = SW_input();
		 if( switches == 0x10 ){
		   c=0x0;
			 while (c != 0x01)
		 {
		   final_long = GPS_read_long();
		 }
		 c=0x0;
		 	 while (c != 0x01)
		 {
			 final_lat = GPS_read_lat();
		 }
			 h = 1; //flag
		 }
		 if (h == 1){
			 str = "press switch 1";
			 delay_ms(500);
			 lcd_cmd(lcd_Clear);
			 lcd_str(str);
			 str = "to start";
			 lcd_str_2nd_row(str);
			 
		  }else if ( h == 0 ){
		   str = "press switch 2";
			 lcd_cmd(lcd_Clear);
			 delay_ms(500);
       lcd_str(str);
		   str ="to save final pt";
			 lcd_str_2nd_row(str);
		   delay_ms(500);
			}

		 if(switches == 0x01){
			 
			 total_distance = 0;
		   str = "Total distance ="; //print "total distance"
			 lcd_cmd(lcd_Clear);
			 delay_ms(500);
       lcd_str(str);
			 

			 while(1){
				 
				 c=0x0;
			   while (c != 0x01)
		     {
						current_long = GPS_read_long();
		     }
		     c=0x0;
		 	   while (c != 0x01)
				 {
			      current_lat = GPS_read_lat();
		     }
				 
				 if ( (previous_lat==0)&&(previous_long==0) ){
				   previous_lat=current_lat;
					 previous_long=current_long;
					 continue;
				 }
				 total_distance = total_distance + GPS_getDistance(current_lat,current_long,previous_lat,previous_long); //calculating total distance
				 previous_lat=current_lat;
				 previous_long=current_long;
				 distance = GPS_getDistance(current_lat,current_long,final_lat,final_long); //displacement from current point to final point
				 if( distance > 5 ){
				   RGB_Output(0x02);//led red
				 }else if( distance > 2.5
				 ){
				   RGB_Output(0x0A);//led yellow
				 }else{
				   RGB_Output(0x08);//led green
					 float_to_char_array(total_distance,result,8); //print value of total distance
           lcd_str_2nd_row(result);
				   delay_ms(2000);
					 str= "7mdala 3la slama";  //print thank u and exit
					 lcd_cmd(lcd_Clear);
					 delay_ms(200);
           lcd_str(str);
					 lcd_cmd(lcd_Clear);
					 str= "Thank U :D";  //print thank u and exit
           lcd_str_2nd_row(str);
           delay_ms(500);
					 h=0;
					break;
				 }
				 float_to_char_array(total_distance,result,8); //print value of total distance
         lcd_str_2nd_row(result);
				 delay_ms(1000);

		 }
		 }
	 }}
