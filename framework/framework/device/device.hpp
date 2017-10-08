/*
 * device.hpp
 *
 *  Created on: Oct 6, 2017
 *      Author: root
 */

#ifndef DEVICE_HPP_
#define DEVICE_HPP_
#include <string>
#include <vector>
#include <pthread.h>
#include "stdint.h"
#include "iodef.hpp"
#include "devicehandler.hpp"

class Device
{
public:
	Device(DeviceHandler * device_handler, DeviceIdentity * identity);

	typedef std::vector<Device *> InstanceVector;

	static Device *         get_instanceByID(DeviceID id);
	static InstanceVector & get_instanceVector(void);

	DeviceID		get_ID(void);
	std::string     get_name(void);

	bool			write(uint32_t data);
	bool			read(uint32_t * data);

	virtual 		~Device();
protected:
	pthread_mutex_t mutex;
	DeviceHandler *	device_handler;
	DeviceID		device_ID;
	std::string     device_name;
};


#endif /* DEVICE_HPP_ */