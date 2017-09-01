/*
 * systembox.cpp
 *
 *  Created on: Aug 29, 2017
 *      Author: root
 */
#include "systembox.hpp"
#include "deviceid.hpp"

SystemFeature::SystemFeature(DeviceHandler * device_handler):
	wasteTankSensor(device_handler, WASTETLEVEL),
	chamberTopSensor(device_handler, LEVELSENSOR_1),
	chamberBottomSensor(device_handler, LEVELSENSOR_0),
	leakageSensor_0(device_handler, LEAKSENSOR_0),
	leakageSensor_1(device_handler, LEAKSENSOR_1),
	irSensor(device_handler, IRSENSOR),
	flushValve(device_handler, FLUSHVALVE),
	drainValve(device_handler, DRAINVALVE),
	shutOffValve(device_handler, SHUTOFFVALVE),
	drainLocalReq(device_handler, DRAINLOCAL),
	emergencySwitch(device_handler, EMERGENCY),
	appSelection(device_handler, APPSELECTION),
	drainDelaySelection(device_handler, DRAINDELAY),
	vacumGenerator(device_handler, VACUMGEN),
	drainIndicator(device_handler, DRAININDICATOR),
	leakageIndicator(device_handler, LEAKINDICATOR),
	pwm_0(device_handler, PWM_0),
	pwm_1(device_handler, PWM_1),
	relay_0(device_handler, RELAY_0),
	relay_1(device_handler, RELAY_1)
{}

SystemFeature::~SystemFeature()
{}
