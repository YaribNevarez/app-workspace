/*
 * iocmd.hpp
 *
 *  Created on: Aug 7, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
 */

#ifndef IOCMD_HPP_
#define IOCMD_HPP_

#ifdef __cplusplus
extern "C" {
#endif

#define SUCCESS 0

typedef unsigned int  DeviceID;
typedef unsigned int  Data;

typedef struct
{
	DeviceID device_ID;
	Data     data;
} IOPacket;

typedef struct
{
	const DeviceID	ID;
	const char * 	name;
} DeviceIdentity;

#ifdef __cplusplus
}
#endif

#endif /* IOCMD_HPP_ */
