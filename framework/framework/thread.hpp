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

class Thread: public Runnable
{
public:
	Thread(void):
	thread(0)
	{}

	virtual ~Thread(void)
	{
		quit();
	}

	virtual int start(void)
	{
		int result = -1;
		if (!isRunning())
		{
			result = pthread_create(&thread, NULL, process_trigger, this);
		}
		return result;
	}

	virtual int quit(void)
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

	static void * process_trigger(void * runnable)
	{
		if (runnable != NULL)
		{
			pthread_exit((void *)((Runnable *) runnable)->run());
		}
		return EXIT_SUCCESS;
	}
	pthread_t	thread;
};

#endif /* TREAD_HPP_ */
