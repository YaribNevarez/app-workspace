/*
 * device.cpp
 *
 *  Created on: Oct 6, 2017
 *      Author: root
 */
#include "device.hpp"

Device::Device(DeviceHandler * device_handler, DeviceIdentity * identity):
device_handler(device_handler),
device_ID(0),
device_name("")
{
	pthread_mutex_init(&mutex, NULL);
	if (identity != NULL)
	{
		device_ID   = identity->ID;
		device_name = identity->name;
	}
	get_instanceVector().push_back(this);
}

DeviceID Device::get_ID(void)
{
	return device_ID;
}

std::string Device::get_name(void)
{
	return device_name;
}

Device * Device::get_instanceByID(DeviceID id)
{
	Device * instance = NULL;
	InstanceVector instances = get_instanceVector();
	for (unsigned i = 0; (i < instances.size()) && (instance == NULL); i ++)
	{
		if ((DeviceID)instances[i]->get_ID() == id)
		{
			instance = instances[i];
		}
	}

	return instance;
}

Device::InstanceVector & Device::get_instanceVector(void)
{
	static InstanceVector instances(0);
	return instances;
}

bool Device::write(uint32_t data)
{
	bool result = false;
	pthread_mutex_lock(&mutex);
	if (device_handler != NULL)
	{
		IOPacket packet;
		packet.device_ID = device_ID;
		packet.data = data;

		result = device_handler->write(&packet, sizeof(packet)) > 0;
	}
	pthread_mutex_unlock(&mutex);
	return result;
}

bool Device::read(uint32_t * data)
{
	bool result = false;
	pthread_mutex_lock(&mutex);
	if (device_handler != NULL)
	{
		IOPacket packet;

		result = device_handler->IORequest(&packet,
										   sizeof(packet),
										   DeviceHandler::QUERY,
										   device_ID) > 0;

		if (packet.device_ID == device_ID)
		{
			*data = packet.data;
		}
	}
	pthread_mutex_unlock(&mutex);
	return result;
}

Device::~Device()
{
	unsigned i;
	InstanceVector instances = get_instanceVector();
	for (i = 0; (i < instances.size()) && (this != instances[i]); i ++);
	instances.erase(instances.begin() + i);
	pthread_mutex_destroy(&mutex);
}


