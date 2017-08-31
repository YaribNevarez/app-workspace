/*
 * systembox.cpp
 *
 *  Created on: Aug 29, 2017
 *      Author: root
 */
#include "systembox.hpp"

SystemFeature::SystemFeature(DeviceHandler * device_handler):
	wasteTankSensor(WASTETLEVEL, device_handler),
	chamberTopSensor(LEVELSENSOR_1, device_handler),
	chamberBottomSensor(LEVELSENSOR_0, device_handler),
	leakageSensor_0(LEAKSENSOR_0, device_handler),
	leakageSensor_1(LEAKSENSOR_1, device_handler),
	irSensor(IRSENSOR, device_handler),
	flushValve(FLUSHVALVE, device_handler),
	drainValve(DRAINVALVE, device_handler),
	shutOffValve(SHUTOFFVALVE, device_handler),
	drainLocalReq(DRAINLOCAL, device_handler),
	emergencySwitch(EMERGENCY, device_handler),
	appSelection(APPSELECTION, device_handler),
	drainDelaySelection(DRAINDELAY, device_handler),
	vacumGenerator(VACUMGEN, device_handler),
	drainIndicator(DRAININDICATOR, device_handler),
	leakageIndicator(LEAKINDICATOR, device_handler),
	pwm_0(PWM_0, device_handler),
	pwm_1(PWM_1, device_handler),
	relay_0(RELAY_0, device_handler),
	relay_1(RELAY_1, device_handler)
{}

SystemFeature::~SystemFeature()
{}
