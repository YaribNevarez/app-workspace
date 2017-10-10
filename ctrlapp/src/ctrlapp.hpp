/*
 * ctrlapp.hpp
 *
 *  Created on: Aug 7, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
 */

#ifndef CTRLAPP_HPP_
#define CTRLAPP_HPP_

#include <vector>

#include "m_application.hpp"

class ControlApp: public Application
{
public:
	ControlApp(int argc = 0, char * argv[] = NULL);
	~ControlApp();

	virtual int run(void);

protected:

	void drain_flush(void);

	class IRFeature: public Thread
	{
	public:
		IRFeature()
		{}
		virtual int run(void);
	};

	class LeakageFeature: public Thread
	{
	public:
		LeakageFeature()
		{}
		virtual int run(void);
	};

	class ServerFeature: public Thread
	{
	public:
		ServerFeature()
		{}
		virtual int run(void);
	};
};


#endif /* CTRLAPP_HPP_ */
