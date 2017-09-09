/*
 * application.hpp
 *
 *  Created on: Aug 31, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
 */

#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include <errno.h>
#include <stdlib.h>
#include <vector>
#include "thread.hpp"

class Application: public Runnable
{
public:
	Application(int argc = 0, char * argv[] = NULL);
	virtual ~Application();

protected:
	void register_thread(Thread *);
	int  start(void);

	int     argc;
	char ** argv;

private:
	std::vector<Thread *> threads;
};


#endif /* APPLICATION_HPP_ */
