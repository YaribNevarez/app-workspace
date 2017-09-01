/*
 * deviceid.hpp
 *
 *  Created on: Sep 1, 2017
 *      Author: root
 */

#ifndef DEVICEID_HPP_
#define DEVICEID_HPP_

#ifdef __cplusplus
extern "C" {
#endif

#include "iodef.hpp"

enum
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
};

DeviceIdentity deviceIdentities[] =
{
	{LEVELSENSOR_0,  "LEVELSENSOR_0" },
	{LEVELSENSOR_1,  "LEVELSENSOR_1" },
	{WASTETLEVEL,    "WASTETLEVEL"   },
	{LEAKSENSOR_0,   "LEAKSENSOR_0"  },
	{LEAKSENSOR_1,   "LEAKSENSOR_1"  },
	{IRSENSOR,       "IRSENSOR"      },
	{FLUSHVALVE,     "FLUSHVALVE"    },
	{DRAINVALVE,     "DRAINVALVE"    },
	{SHUTOFFVALVE,   "SHUTOFFVALVE"  },
	{DRAINLOCAL,     "DRAINLOCAL"    },
	{EMERGENCY,      "EMERGENCY"     },
	{APPSELECTION,   "APPSELECTION"  },
	{DRAINDELAY,     "DRAINDELAY"    },
	{VACUMGEN,       "VACUMGEN"      },
	{DRAININDICATOR, "DRAININDICATOR"},
	{LEAKINDICATOR,  "LEAKINDICATOR" },
	{PWM_0,          "PWM_0"         },
	{PWM_1,          "PWM_1"         },
	{RELAY_0,        "RELAY_0"       },
	{RELAY_1,        "RELAY_1"       }
};

#ifdef __cplusplus
}
#endif

#endif /* DEVICEID_HPP_ */
