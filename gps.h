#ifndef gps_H_
#define gps_H_
#include "microconfig.h"

void GPS_read (float points[4]);
float ToRad(float angle );
float GPS_getDistance (float lat1 ,float long1, float lat2, float long2);
//float GPS_getDisplacment_from_final_point (double lat_final ,double long_final);
//void  GET_GPS_Final_Point (void) ;
#endif
