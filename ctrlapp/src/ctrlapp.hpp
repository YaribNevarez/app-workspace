/*
 * cccapp.hpp
 *
 *  Created on: Aug 7, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
 */

#ifndef CCCAPP_HPP_
#define CCCAPP_HPP_

#include <vector>

#include "framework/application.hpp"

// Multiple inheritance of two different concepts
class ControlApp: public Application
{
public:
	ControlApp(int argc = 0, char * argv[] = NULL);
	~ControlApp();

	virtual int run(void);

protected:

	void server(void);

	class DrainFeature: public Thread
	{
	public:
		DrainFeature()
		{}
		virtual int run(void);
	};

	class FlushFeature: public Thread
	{
	public:
		FlushFeature()
		{}
		virtual int run(void);
	};

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

	class RelayFeature: public Thread
	{
	public:
		RelayFeature()
		{}
		virtual int run(void);
	};
};


#endif /* CCCAPP_HPP_ */
