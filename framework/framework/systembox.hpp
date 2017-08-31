/*
 * systembox.hpp
 *
 *  Created on: Aug 29, 2017
 *      Author: root
 */

#ifndef SYSTEMBOX_HPP_
#define SYSTEMBOX_HPP_

#include "thread.hpp"
#include "devices.hpp"

class SystemFeature: public Thread
{
public:
	SystemFeature(DeviceHandler *);
	virtual ~SystemFeature();

protected:
	LevelSensor     wasteTankSensor;
	LevelSensor     chamberTopSensor;
	LevelSensor     chamberBottomSensor;
	LeakageSensor	leakageSensor_0;
	LeakageSensor   leakageSensor_1;
	IRSensor        irSensor;
	Valve           flushValve;
	Valve           drainValve;
	Valve           shutOffValve;
	InputPin        drainLocalReq;
	InputVector     emergencySwitch;
	InputVector     appSelection;
	InputVector     drainDelaySelection;
	OutputPin       vacumGenerator;
	OutputPin       drainIndicator;
	OutputPin       leakageIndicator;
	OutputVector    pwm_0;
	OutputVector    pwm_1;
	OutputPin       relay_0;
	OutputPin       relay_1;
};

#endif /* SYSTEMBOX_HPP_ */
