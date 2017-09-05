/*
 * systembox.cpp
 *
 *  Created on: Aug 29, 2017
 *      Author: root
 */
#include "systembox.hpp"
#include "deviceid.hpp"

SystemFeature::SystemFeature(DeviceHandler * device_handler):
	wasteTankSensor(device_handler, &id_WASTETLEVEL),
	chamberTopSensor(device_handler, &id_LEVELSENSOR_1),
	chamberBottomSensor(device_handler, &id_LEVELSENSOR_0),
	leakageSensor_0(device_handler, &id_LEAKSENSOR_0),
	leakageSensor_1(device_handler, &id_LEAKSENSOR_1),
	irSensor(device_handler, &id_IRSENSOR),
	flushValve(device_handler, &id_FLUSHVALVE),
	drainValve(device_handler, &id_DRAINVALVE),
	shutOffValve(device_handler, &id_SHUTOFFVALVE),
	drainLocalReq(device_handler, &id_DRAINLOCAL),
	emergencySwitch(device_handler, &id_EMERGENCY),
	appSelection(device_handler, &id_APPSELECTION),
	drainDelaySelection(device_handler, &id_DRAINDELAY),
	vacumGenerator(device_handler, &id_VACUMGEN),
	drainIndicator(device_handler, &id_DRAININDICATOR),
	leakageIndicator(device_handler, &id_LEAKINDICATOR),
	pwm_0(device_handler, &id_PWM_0),
	pwm_1(device_handler, &id_PWM_1),
	relay_0(device_handler, &id_RELAY_0),
	relay_1(device_handler, &id_RELAY_1)
{}

SystemFeature::~SystemFeature()
{}
