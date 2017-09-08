/*
 * application.cpp
 *
 *  Created on: Aug 31, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
 */

#include "application.hpp"

Application::Application()
{}

Application::~Application()
{
	while (!threads.empty())
	{
		if (threads.back() != NULL)
			delete threads.back();

		threads.pop_back();
	}
}

void Application::register_thread(Thread * thread)
{
	threads.push_back(thread);
}

int Application::start(void)
{
	int result = EXIT_SUCCESS;

	for (unsigned int i = 0;
		(i < threads.size()) && (result == EXIT_SUCCESS);
		i ++)
	{
		result = threads[i]->start();
	}

	return result;
}
