/*
 * cccapp.hpp
 *
 *  Created on: Aug 7, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
 */

#ifndef CCCAPP_HPP_
#define CCCAPP_HPP_

#include <vector>

#include "m_application.hpp"

// Multiple inheritance of two different concepts
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


#endif /* CCCAPP_HPP_ */
