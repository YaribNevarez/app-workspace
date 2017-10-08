/*
 * devices.hpp
 *
 *  Created on: Aug 7, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
 */

#ifndef DEVICES_HPP_
#define DEVICES_HPP_

#include "m_device.hpp"

///////////////////////////////////////////////////////////////////////////////

class LevelSensor : public Device
{
public:
	LevelSensor(DeviceHandler * device_handler, DeviceIdentity * identity);

	typedef enum
	{
		LOW = 0,
		FULL = 1
	} Status;

	Status get_level(void);
};

///////////////////////////////////////////////////////////////////////////////

class LeakageSensor : public Device
{
public:
	LeakageSensor(DeviceHandler * device_handler, DeviceIdentity * identity);

	typedef enum
	{
		NO_LEAKING = 0,
		LEAKING    = 1
	} Status;

	Status get_status(void);
};

///////////////////////////////////////////////////////////////////////////////

class IRSensor : public Device
{
public:
	IRSensor(DeviceHandler * device_handler, DeviceIdentity * identity);

	typedef enum
	{
		ABSENCE  = 0,
		PRESENCE = 1
	} Status;

	Status get_status(void);
};

///////////////////////////////////////////////////////////////////////////////

class Valve : public Device
{
public:
	Valve(DeviceHandler * device_handler, DeviceIdentity * identity);

	typedef enum
	{
		CLOSE = 0,
		OPEN  = 1
	} Position;

	bool     set_position(Position position);
	Position get_position(void);
};

///////////////////////////////////////////////////////////////////////////////

class OutputPin: public Device
{
public:
	OutputPin(DeviceHandler * device_handler, DeviceIdentity * identity);

	typedef enum
	{
		OFF = 0,
		ON  = 1
	} Status;

	bool set_status(Status status);
};

///////////////////////////////////////////////////////////////////////////////

class InputPin : public Device
{
public:
	InputPin(DeviceHandler * device_handler, DeviceIdentity * identity);

	typedef enum
	{
		OFF = 0,
		ON  = 1
	} Status;

	Status get_status(void);
};

///////////////////////////////////////////////////////////////////////////////

class OutputVector : public Device
{
public:
	OutputVector(DeviceHandler * device_handler, DeviceIdentity * identity);

	bool set_value(int value);
};

///////////////////////////////////////////////////////////////////////////////

class InputVector : public Device
{
public:
	InputVector(DeviceHandler * device_handler, DeviceIdentity * identity);

	int get_value(void);
};

///////////////////////////////////////////////////////////////////////////////

#endif /* DEVICES_HPP_ */
