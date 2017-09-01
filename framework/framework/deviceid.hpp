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


DeviceIdentity id_LEVELSENSOR_0  = {LEVELSENSOR_0,  "LEVELSENSOR_0" };
DeviceIdentity id_LEVELSENSOR_1  = {LEVELSENSOR_1,  "LEVELSENSOR_1" };
DeviceIdentity id_WASTETLEVEL    = {WASTETLEVEL,    "WASTETLEVEL"   };
DeviceIdentity id_LEAKSENSOR_0   = {LEAKSENSOR_0,   "LEAKSENSOR_0"  };
DeviceIdentity id_LEAKSENSOR_1   = {LEAKSENSOR_1,   "LEAKSENSOR_1"  };
DeviceIdentity id_IRSENSOR       = {IRSENSOR,       "IRSENSOR"      };
DeviceIdentity id_FLUSHVALVE     = {FLUSHVALVE,     "FLUSHVALVE"    };
DeviceIdentity id_DRAINVALVE     = {DRAINVALVE,     "DRAINVALVE"    };
DeviceIdentity id_SHUTOFFVALVE   = {SHUTOFFVALVE,   "SHUTOFFVALVE"  };
DeviceIdentity id_DRAINLOCAL     = {DRAINLOCAL,     "DRAINLOCAL"    };
DeviceIdentity id_EMERGENCY      = {EMERGENCY,      "EMERGENCY"     };
DeviceIdentity id_APPSELECTION   = {APPSELECTION,   "APPSELECTION"  };
DeviceIdentity id_DRAINDELAY     = {DRAINDELAY,     "DRAINDELAY"    };
DeviceIdentity id_VACUMGEN       = {VACUMGEN,       "VACUMGEN"      };
DeviceIdentity id_DRAININDICATOR = {DRAININDICATOR, "DRAININDICATOR"};
DeviceIdentity id_LEAKINDICATOR  = {LEAKINDICATOR,  "LEAKINDICATOR" };
DeviceIdentity id_PWM_0          = {PWM_0,          "PWM_0"         };
DeviceIdentity id_PWM_1          = {PWM_1,          "PWM_1"         };
DeviceIdentity id_RELAY_0        = {RELAY_0,        "RELAY_0"       };
DeviceIdentity id_RELAY_1        = {RELAY_1,        "RELAY_1"       };

#ifdef __cplusplus
}
#endif

#endif /* DEVICEID_HPP_ */