/*
 * tread.hpp
 *
 *  Created on: Aug 29, 2017
 *      Author: root
 */

#ifndef TREAD_HPP_
#define TREAD_HPP_

#include <pthread.h>
#include <errno.h>
#include <stdlib.h>

class Runnable
{
public:
	virtual int run() = 0;
};

class Thread
{
public:
	Thread(Runnable * obj = NULL):
	thread(0),
	obj(obj)
	{}

	virtual ~Thread()
	{}

	virtual int start(Runnable * obj = NULL)
	{
		int result = -1;
		if (!isRunning())
		{
			if (obj != NULL)
				Thread::obj = obj;

			if (Thread::obj != NULL)
				result = pthread_create(&thread,
										NULL,
										process_trigger,
										Thread::obj);
		}
		return result;
	}

	virtual int quit()
	{
		int result = EXIT_SUCCESS;
		if (isRunning())
		{
			pthread_cancel(thread);
			pthread_join(thread, (void **)&result);

			if (result == (int)PTHREAD_CANCELED)
			{
				result = EXIT_SUCCESS;
			}
		}
		return result;
	}

	virtual bool isRunning(void)
	{
		int result = -1;
		if (thread != 0)
		{
			pthread_tryjoin_np(thread, (void **)&result);
		}
		return result == EBUSY;
	}

private:

	static void * process_trigger(void * obj)
	{
		if (obj != NULL)
		{
			pthread_exit((void *)((Runnable *) obj)->run());
		}
		return EXIT_SUCCESS;
	}
	pthread_t	thread;
	Runnable *	obj;
};

#endif /* TREAD_HPP_ */
