#ifndef gps_H_
#define gps_H_
#include "microconfig.h"

float GPS_read_long (void);
float GPS_read_lat (void);
float ToRad(float angle );
float GPS_getDistance (float lat1 ,float long1, float lat2, float long2);
#endif
