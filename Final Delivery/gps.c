#include "microconfig.h"
const double EARTH_RADIUS = 6371000 ;
//in meters
char string[10];   

char GPS [100];     //34an GPS i will pass a lot of values in it as mentioned in serial monitor

char GPS_GPGGA_VALUES[12][20];
char *token;       //bn2t3 beh el strings el kter 3aiz mno $gpgga then ba5od el longitude we lattiude
extern char c;


float GPS_read_lat (void) {
float currentLat,min=0.0, sec=0.0,deg=0.0,result=0.0;
int i=0;
char c0=UART_recieveByte(5) ;
if (c0 == '$'){
char c1 = UART_recieveByte(5);
if(c1 == 'G'){
char c2 = UART_recieveByte(5);
if(c2 == 'P'){
char c3 = UART_recieveByte(5);
if(c3 == 'G'){
char c4 = UART_recieveByte(5);
if(c4 == 'G'){
char c5 = UART_recieveByte(5);
if(c5 == 'A'){
char c6 = UART_recieveByte(5);
if(c6 == ','){
char c7 = UART_recieveByte(5);
while (c7 !='*'){
GPS[i]=c7;
c7 = UART_recieveByte(5);
i++;
}
i=0;
token=strtok(GPS,",");//by2t3 el function


do {
strcpy(GPS_GPGGA_VALUES[i],token);//kol ama y3de 3ala element y5do ysayvo 3ala array gded
token=strtok(NULL,",");
i++;}
while(token!=NULL);

if( strcmp(GPS_GPGGA_VALUES[5], "1") == 0){
currentLat=atof(GPS_GPGGA_VALUES[1]); 
//currentLong=atof(GPS_GPGGA_VALUES[3]);

	RGB_Output(0x0E); //to indicate
  c = 0x1;//flag
//lat calculation
deg=currentLat/100;
min=currentLat-(deg*100);
sec=min/60.0;
result= deg+sec;					
return result;
        }
				}
				}
       }
      }
     }
    }
	}
}

float GPS_read_long (void) {
float currentLong ,min=0.0, sec=0.0,deg=0.0,result=0.0;
int i=0;
char c0=UART_recieveByte(5) ;
if (c0 == '$'){
char c1 = UART_recieveByte(5);
if(c1 == 'G'){
char c2 = UART_recieveByte(5);
if(c2 == 'P'){
char c3 = UART_recieveByte(5);
if(c3 == 'G'){
char c4 = UART_recieveByte(5);
if(c4 == 'G'){
char c5 = UART_recieveByte(5);
if(c5 == 'A'){
char c6 = UART_recieveByte(5);
if(c6 == ','){
char c7 = UART_recieveByte(5);
while (c7 !='*'){
GPS[i]=c7;
c7 = UART_recieveByte(5);
i++;
}
i=0;
token=strtok(GPS,",");//by2t3 el function


do {
strcpy(GPS_GPGGA_VALUES[i],token);//kol ama y3de 3ala element y5do ysayvo 3ala array gded
token=strtok(NULL,",");
i++;}
while(token!=NULL);

if( strcmp(GPS_GPGGA_VALUES[5], "1") == 0){
//currentLat=atof(GPS_GPGGA_VALUES[1]); 
currentLong=atof(GPS_GPGGA_VALUES[3]);

	RGB_Output(0x0E); //to indicate
  c = 0x1; //flag

// calculate long
deg = currentLong/100;
min = currentLong -(deg*100);
sec = min/60.0;
result = deg + sec;
return result;
        }
				}
				}
       }
      }
     }
    }
	}
  }
float ToRad(float angle )
	{
return angle * PI/180 ;
	}


float GPS_getDistance (float lat1 ,float long1, float lat2, float long2)  //function takes coordinates of two points and calculates distance 
{
double currentLatRad1 = ToRad(lat1);
double currentLatRad2 = ToRad(lat2);
double currentLong1 = ToRad(long1);
double currentLong2 = ToRad(long2);
double lat=currentLatRad2 - currentLatRad1;
double lon =currentLong2 - currentLong1;
//haversine accumulate distance
double a= pow(sin(lat/2),2) + cos(currentLatRad1)* cos(currentLatRad2)*pow(sin(lon/2),2);
double c=2 * atan2(sqrt(a), sqrt(1-a));
double d=EARTH_RADIUS * c;

return d;   //returns the distance between the 2 points only	
}
