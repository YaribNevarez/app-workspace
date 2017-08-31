/*
 * devicehandler.cpp
 *
 *  Created on: Aug 7, 2017
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "devicehandler.hpp"


DeviceHandler::DeviceHandler (const char * const file_name):
file_name(NULL),
file_handler(NULL),
auto_open(true)
{
	if (file_name != NULL)
	{
		int length = strlen(file_name);
		if (0 < length)
		{
			DeviceHandler::file_name = (char *) malloc(length + 1);
			memcpy(DeviceHandler::file_name, file_name, length + 1);
		}
	}
	pthread_mutex_init(&ioMutex, NULL);
	pthread_mutex_init(&fileMutex, NULL);
}

size_t  DeviceHandler::IORequest(void * buffer,
								 size_t size,
								 IORequestType irq,
								 char query_ID)
{
	size_t result = 0;
	pthread_mutex_lock(&ioMutex);

	if (auto_open)
	{
		open();
	}

	if ((0 < size) & is_open())
	{
		switch (irq)
		{
		case WRITE:
			//pthread_mutex_lock(&ioMutex);
			result = fwrite(buffer, size, 1, file_handler);
			fflush(file_handler);
			//pthread_mutex_unlock(&ioMutex);
			break;

		case READ:
			//pthread_mutex_lock(&ioMutex);
			result = fread(buffer, size, 1, file_handler);
			fflush(file_handler);
			//pthread_mutex_unlock(&ioMutex);
			break;

		case QUERY:
			//pthread_mutex_lock(&ioMutex);
			result = fwrite(&query_ID, sizeof(query_ID), 1, file_handler);
			fflush(file_handler);

			if (result == sizeof(query_ID))
			{
				result = fread(buffer, size, 1, file_handler);
			}
			//pthread_mutex_unlock(&ioMutex);
			break;

		default:;
		}
	}

	if (auto_open)
	{
		close();
	}

	pthread_mutex_unlock(&ioMutex);
	return result;
}

void DeviceHandler::set_auto_open(bool flag)
{
	auto_open = flag;
}

size_t DeviceHandler::write(void * buffer, size_t size)
{
	return IORequest(buffer, size, WRITE);
}

size_t DeviceHandler::read (void * buffer, size_t size)
{
	return IORequest(buffer, size, READ);
}

bool DeviceHandler::open(void)
{
	pthread_mutex_lock(&fileMutex);
	if (!is_open() && (file_name != NULL) && (0 < strlen(file_name)))
	{
		file_handler = fopen(file_name, "r+");
	}
	pthread_mutex_unlock(&fileMutex);
	return is_open();
}

bool DeviceHandler::is_open(void)
{
	return file_handler != NULL;
}

bool DeviceHandler::close(void)
{
	pthread_mutex_lock(&fileMutex);
	if (is_open() && 0 == fclose(file_handler))
	{
		file_handler = NULL;
	}
	pthread_mutex_unlock(&fileMutex);
	return !is_open();
}

DeviceHandler::~DeviceHandler()
{
	close();
	if (file_name != NULL)
	{
		free(file_name);
	}
	pthread_mutex_destroy(&ioMutex);
	pthread_mutex_destroy(&fileMutex);
}

Device::Device(DeviceID ID, DeviceHandler * device_handler):
device_ID(ID),
device_handler(device_handler)
{
	pthread_mutex_init(&mutex, NULL);
}

int Device::get_ID(void)
{
	return device_ID;
}

bool Device::write(int data)
{
	bool result = false;
	pthread_mutex_lock(&mutex);
	//while (pthread_mutex_trylock(&mutex) != 0) usleep(1000);
	if (device_handler != NULL)
	{
		IOPacket packet;
		packet.device_ID = device_ID;
		packet.data = data;

		result = device_handler->write(&packet, sizeof(packet)) == sizeof(packet);
	}
	pthread_mutex_unlock(&mutex);
	return result;
}

bool Device::read(int * data)
{
	bool result = false;
	pthread_mutex_lock(&mutex);
	//while (pthread_mutex_trylock(&mutex) != 0) usleep(1000);
	if (device_handler != NULL)
	{
		IOPacket packet;

		device_handler->IORequest(&packet, sizeof(packet), DeviceHandler::QUERY, device_ID);

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
	pthread_mutex_destroy(&mutex);
}
