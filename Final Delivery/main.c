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
