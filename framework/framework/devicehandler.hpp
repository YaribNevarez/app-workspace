/*
 * portdriver.hpp
 *
 *  Created on: Aug 6, 2017
 *      Author: root
 */

#ifndef PORTDRIVER_HPP_
#define PORTDRIVER_HPP_
#include <string>
#include <vector>
#include <pthread.h>
#include "iodef.hpp"

using namespace std;

class DeviceHandler
{
	public:
	typedef enum
	{
		READ,
		WRITE,
		QUERY
	}IORequestType;
	DeviceHandler (const char * const);
	size_t  IORequest(void *, size_t, IORequestType, char = 0);
	size_t  write(void *, size_t);
	size_t  read (void *, size_t);
	void    set_auto_open(bool);
	bool    open(void);
	bool    is_open(void);
	bool    close(void);
	~DeviceHandler();
private:
	char * file_name;
	FILE * file_handler;
	bool   auto_open;
	pthread_mutex_t ioMutex;
	pthread_mutex_t fileMutex;
};

class Device
{
public:
	Device(DeviceHandler *, DeviceIdentity *);

	typedef std::vector<Device *> InstanceVector;

	static Device *       get_instanceByID(DeviceID);
	static InstanceVector get_instanceVector(void);

	int 			get_ID(void);
	std::string     get_name(void);

	virtual 		~Device();

protected:
	bool			write(int);
	bool			read(int *);
	pthread_mutex_t mutex;
	DeviceHandler *	device_handler;
	DeviceID		device_ID;
	std::string     device_name;
private:
	static InstanceVector instances;
};

#endif /* PORTDRIVER_HPP_ */
