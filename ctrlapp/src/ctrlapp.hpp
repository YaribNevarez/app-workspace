/*
 * cccapp.hpp
 *
 *  Created on: Aug 7, 2017
 *      Author: root
 */

#ifndef CCCAPP_HPP_
#define CCCAPP_HPP_

#include <vector>

#include "systembox.hpp"

// Multiple inheritance of two different concepts
class ControlApp: public Runnable
{
public:
	ControlApp();
	~ControlApp();

	virtual int run(void);

protected:

	class DrainProcess: public SystemBox
	{
	public:
		DrainProcess(DeviceHandler * device_handler):
		SystemBox(device_handler)
		{}
		virtual int run(void);
	};

	class FlushProcess: public SystemBox
	{
	public:
		FlushProcess(DeviceHandler * device_handler):
		SystemBox(device_handler)
		{}
		virtual int run(void);
	};

	class IRProcess: public SystemBox
	{
	public:
		IRProcess(DeviceHandler * device_handler):
		SystemBox(device_handler)
		{}
		virtual int run(void);
	};

	class LeakageProcess: public SystemBox
	{
	public:
		LeakageProcess(DeviceHandler * device_handler):
		SystemBox(device_handler)
		{}
		virtual int run(void);
	};

	class RelayProcess: public SystemBox
	{
	public:
		RelayProcess(DeviceHandler * device_handler):
		SystemBox(device_handler)
		{}
		virtual int run(void);
	};

	std::vector<SystemBox *> processes;
	std::vector<Thread *> 	 threads;
};


#endif /* CCCAPP_HPP_ */
