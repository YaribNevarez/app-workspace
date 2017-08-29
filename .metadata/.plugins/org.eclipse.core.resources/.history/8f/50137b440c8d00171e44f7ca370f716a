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

typedef enum
{
	DEVICE_ID_BEGIN = 0,
	LEVELSENSOR_0,
	LEVELSENSOR_1,
	WASTETLEVEL,
	LEAKSENSOR_0,
	LEAKSENSOR_1,
	IRSENSOR,
	FLUSHVALVE,
	DRAINVALVE,
	SHUTOFFVALVE,
	DRAINLOCAL,
	EMERGENCY,
	APPSELECTION,
	DRAINDELAY,
	VACUMGEN,
	DRAININDICATOR,
	LEAKINDICATOR,
	PWM_0,
	PWM_1,
	RELAY_0,
	RELAY_1,
	DEVICE_ID_END
} DeviceID;

typedef struct
{
	const DeviceID     device_ID;
	const char * const driver_name;
} DeviceDef;

typedef struct
{
	unsigned char device_ID;
	unsigned int  data;
} IOPacket;

const char * const ZYNQ_BTN_FILE  = "/proc/zynq_btn";
const char * const ZYNQ_LED_FILE  = "/proc/zynq_led";
const char * const ZYNQ_SW_FILE   = "/proc/zynq_sw";
const char * const ZYNQ_PMOD_FILE = "/proc/zynq_pmod";

#ifdef __cplusplus
}
#endif

#endif /* IOCMD_HPP_ */
