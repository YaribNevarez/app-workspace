/*
 * cccapp.hpp
 *
 *  Created on: Aug 7, 2017
 *      Author: root
 */

#ifndef CCCAPP_HPP_
#define CCCAPP_HPP_

#include <vector>

#include "framework/application.hpp"

// Multiple inheritance of two different concepts
class ControlApp: public Application
{
public:
	ControlApp();
	~ControlApp();

	virtual int run(void);

protected:

	class DrainFeature: public SystemFeature
	{
	public:
		DrainFeature(DeviceHandler * device_handler):
			SystemFeature(device_handler)
		{}
		virtual int run(void);
	};

	class FlushFeature: public SystemFeature
	{
	public:
		FlushFeature(DeviceHandler * device_handler):
			SystemFeature(device_handler)
		{}
		virtual int run(void);
	};

	class IRFeature: public SystemFeature
	{
	public:
		IRFeature(DeviceHandler * device_handler):
			SystemFeature(device_handler)
		{}
		virtual int run(void);
	};

	class LeakageFeature: public SystemFeature
	{
	public:
		LeakageFeature(DeviceHandler * device_handler):
			SystemFeature(device_handler)
		{}
		virtual int run(void);
	};

	class RelayFeature: public SystemFeature
	{
	public:
		RelayFeature(DeviceHandler * device_handler):
			SystemFeature(device_handler)
		{}
		virtual int run(void);
	};
};


#endif /* CCCAPP_HPP_ */
