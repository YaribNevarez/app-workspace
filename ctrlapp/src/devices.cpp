/*
 * devices.cpp
 *
 *  Created on: Aug 7, 2017
 *      Author: root
 */
#include "devices.hpp"

///////////////////////////////////////////////////////////////////////////////

LevelSensor::LevelSensor(DeviceID ID, DeviceHandler * device_handler):
Device(ID, device_handler)
{}

LevelSensor::Status LevelSensor::get_level(void)
{
	Status status;
	read((int *) & status);
	return status;
}

///////////////////////////////////////////////////////////////////////////////

LeakageSensor::LeakageSensor(DeviceID ID, DeviceHandler * device_handler):
Device(ID, device_handler)
{}

LeakageSensor::Status LeakageSensor::get_status(void)
{
	Status status;
	read((int *) & status);
	return status;
}

///////////////////////////////////////////////////////////////////////////////

IRSensor::IRSensor(DeviceID ID, DeviceHandler * device_handler):
Device(ID, device_handler)
{}

IRSensor::Status IRSensor::get_status(void)
{
	Status status;
	read((int *) & status);
	return status;
}

///////////////////////////////////////////////////////////////////////////////

Valve::Valve(DeviceID ID, DeviceHandler * device_handler):
Device(ID, device_handler)
{}

bool     Valve::set_position(Position position)
{
	return write((int) position);
}

Valve::Position Valve::get_position(void)
{
	Position position;
	read((int *) & position);
	return position;
}

///////////////////////////////////////////////////////////////////////////////

OutputPin::OutputPin(DeviceID ID, DeviceHandler * device_handler):
Device(ID, device_handler)
{}

bool OutputPin::set_status(Status status)
{
	return write((int) status);
}

///////////////////////////////////////////////////////////////////////////////

InputPin::InputPin(DeviceID ID, DeviceHandler * device_handler):
Device(ID, device_handler)
{}

InputPin::Status InputPin::get_status(void)
{
	Status status;
	read((int *) & status);
	return status;
}

///////////////////////////////////////////////////////////////////////////////

OutputVector::OutputVector(DeviceID ID, DeviceHandler * device_handler):
Device(ID, device_handler)
{}

bool OutputVector::set_value(int value)
{
	return write(value);
}

///////////////////////////////////////////////////////////////////////////////

InputVector::InputVector(DeviceID ID, DeviceHandler * device_handler):
Device(ID, device_handler)
{}

int InputVector::get_value(void)
{
	int status;
	read(& status);
	return status;
}

///////////////////////////////////////////////////////////////////////////////
