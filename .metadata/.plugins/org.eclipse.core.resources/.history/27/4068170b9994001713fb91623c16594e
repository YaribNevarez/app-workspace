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
#include "systembox.hpp"

class Application: public Runnable
{
public:
	Application();
	virtual ~Application();

protected:
	void register_thread(Thread *);
	int start(void);

private:
	std::vector<Thread *> threads;
};


#endif /* APPLICATION_HPP_ */
