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

	void drainFlushProcess(void);

	class IRProcess: public Thread
	{
	public:
		IRProcess()
		{}
		virtual int run(void);
	};

	class LeakageProcess: public Thread
	{
	public:
		LeakageProcess()
		{}
		virtual int run(void);
	};

	class ServerProcess: public Thread
	{
	public:
		ServerProcess()
		{}
		virtual int run(void);
	};
};


#endif /* CTRLAPP_HPP_ */
