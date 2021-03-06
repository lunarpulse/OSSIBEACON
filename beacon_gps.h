/*
 * gps.h
 *
 *  Created on: 2012. 12. 21.
 *      Author: OSSI
 */

#ifndef BEACON_GPS_H_
#define BEACON_GPS_H_

#include "ossi_beacon.h"

#define MAXCOMMAS 14   //Max commas to store positions of (14 for GGA sentence)
#define MAXGPS 82              //Max NMEA string size
#define MAXLAT 9               //Max latitude size in bytes
#define MAXLONG 10             //Max longitude size in bytes
#define MAXTIME 10             //Max time size in bytes
#define MAXSATS 2              //Max sats size in bytes
#define MAXALTI 8              //Max altitude size in bytes

typedef struct
{
	uint8_t lat[MAXLAT];
	uint8_t lng[MAXLONG];
	uint8_t time[MAXTIME];
	uint8_t sats[MAXSATS];
	uint8_t alti[MAXALTI];
	uint8_t ns;
	uint8_t ew;
	uint8_t valid;
} Gps;

void gps_setReadyFlag(void);
void gps_clearReadyFlag(void);
uint8_t gps_isReady(void);

uint8_t gps_updateData(uint8_t data);
void gps_makePacket(void);
uint8_t* gps_getStream(void);

#endif /* BEACON_GPS_H_ */
