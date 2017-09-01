/*
 * devices.cpp
 *
 *  Created on: Aug 7, 2017
 *      Author: root
 */
#include "devices.hpp"

///////////////////////////////////////////////////////////////////////////////

LevelSensor::LevelSensor(DeviceHandler * device_handler, DeviceID ID, std::string name):
Device(device_handler, ID, name)
{}

LevelSensor::Status LevelSensor::get_level(void)
{
	Status status;
	read((int *) & status);
	return status;
}

///////////////////////////////////////////////////////////////////////////////

LeakageSensor::LeakageSensor(DeviceHandler * device_handler, DeviceID ID, std::string name):
Device(device_handler, ID, name)
{}

LeakageSensor::Status LeakageSensor::get_status(void)
{
	Status status;
	read((int *) & status);
	return status;
}

///////////////////////////////////////////////////////////////////////////////

IRSensor::IRSensor(DeviceHandler * device_handler, DeviceID ID, std::string name):
Device(device_handler, ID, name)
{}

IRSensor::Status IRSensor::get_status(void)
{
	Status status;
	read((int *) & status);
	return status;
}

///////////////////////////////////////////////////////////////////////////////

Valve::Valve(DeviceHandler * device_handler, DeviceID ID, std::string name):
Device(device_handler, ID, name)
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

OutputPin::OutputPin(DeviceHandler * device_handler, DeviceID ID, std::string name):
Device(device_handler, ID, name)
{}

bool OutputPin::set_status(Status status)
{
	return write((int) status);
}

///////////////////////////////////////////////////////////////////////////////

InputPin::InputPin(DeviceHandler * device_handler, DeviceID ID, std::string name):
Device(device_handler, ID, name)
{}

InputPin::Status InputPin::get_status(void)
{
	Status status;
	read((int *) & status);
	return status;
}

///////////////////////////////////////////////////////////////////////////////

OutputVector::OutputVector(DeviceHandler * device_handler, DeviceID ID, std::string name):
Device(device_handler, ID, name)
{}

bool OutputVector::set_value(int value)
{
	return write(value);
}

///////////////////////////////////////////////////////////////////////////////

InputVector::InputVector(DeviceHandler * device_handler, DeviceID ID, std::string name):
Device(device_handler, ID, name)
{}

int InputVector::get_value(void)
{
	int status;
	read(& status);
	return status;
}

///////////////////////////////////////////////////////////////////////////////
