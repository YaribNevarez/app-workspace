/*
 * iocmd.hpp
 *
 *  Created on: Aug 7, 2017
 *      Author: root
 */

#ifndef IOCMD_HPP_
#define IOCMD_HPP_

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char DeviceID;
typedef unsigned int  Data;

typedef struct
{
	DeviceID device_ID;
	Data     data;
} IOPacket;

typedef struct
{
	DeviceID 	 ID;
	const char * name;
} DeviceIdentity;

#ifdef __cplusplus
}
#endif

#endif /* IOCMD_HPP_ */
