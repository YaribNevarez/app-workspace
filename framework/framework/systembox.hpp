/*
 * systembox.hpp
 *
 *  Created on: Aug 29, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
 */

#ifndef SYSTEMBOX_HPP_
#define SYSTEMBOX_HPP_

#include "devices.hpp"
#include "deviceid.hpp"
#include "zybo.hpp"

using namespace ZYBO::HANDLER;
//using namespace ZEDBOARD::HANDLER;
//using namespace FLORIDA::HANDLER;

namespace SYSTEMBOX
{
	LevelSensor wasteTankSensor(&PMOD, &id_WASTETLEVEL);
	LevelSensor chamberTopSensor(&PMOD, &id_LEVELSENSOR_1);
	LevelSensor chamberBottomSensor(&PMOD, &id_LEVELSENSOR_0);
	LeakageSensor leakageSensor_0(&PMOD, &id_LEAKSENSOR_0);
	LeakageSensor leakageSensor_1(&PMOD, &id_LEAKSENSOR_1);
	IRSensor irSensor(&PMOD, &id_IRSENSOR);
	Valve flushValve(&PMOD, &id_FLUSHVALVE);
	Valve drainValve(&PMOD, &id_DRAINVALVE);
	Valve shutOffValve(&PMOD, &id_SHUTOFFVALVE);
	InputPin drainLocalReq(&PMOD, &id_DRAINLOCAL);
	InputVector emergencySwitch(&PMOD, &id_EMERGENCY);
	InputVector appSelection(&PMOD, &id_APPSELECTION);
	InputVector drainDelaySelection(&PMOD, &id_DRAINDELAY);
	OutputPin vacumGenerator(&PMOD, &id_VACUMGEN);
	OutputPin drainIndicator(&PMOD, &id_DRAININDICATOR);
	OutputPin leakageIndicator(&PMOD, &id_LEAKINDICATOR);
	OutputVector pwm_0(&PMOD, &id_PWM_0);
	OutputVector pwm_1(&PMOD, &id_PWM_1);
	OutputPin relay_0(&PMOD, &id_RELAY_0);
	OutputPin relay_1(&PMOD, &id_RELAY_1);
};

#endif /* SYSTEMBOX_HPP_ */
