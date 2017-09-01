/*
 * devices.hpp
 *
 *  Created on: Aug 7, 2017
 *      Author: root
 */

#ifndef DEVICES_HPP_
#define DEVICES_HPP_

#include "devicehandler.hpp"

///////////////////////////////////////////////////////////////////////////////

class LevelSensor : public Device
{
public:
	LevelSensor(DeviceHandler *, DeviceIdentity *);

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
	LeakageSensor(DeviceHandler *, DeviceIdentity *);

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
	IRSensor(DeviceHandler *, DeviceIdentity *);

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
	Valve(DeviceHandler *, DeviceIdentity *);

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
	OutputPin(DeviceHandler *, DeviceIdentity *);

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
	InputPin(DeviceHandler *, DeviceIdentity *);

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
	OutputVector(DeviceHandler *, DeviceIdentity *);

	bool set_value(int value);
};

///////////////////////////////////////////////////////////////////////////////

class InputVector : public Device
{
public:
	InputVector(DeviceHandler *, DeviceIdentity *);

	int get_value(void);
};

///////////////////////////////////////////////////////////////////////////////

#endif /* DEVICES_HPP_ */
