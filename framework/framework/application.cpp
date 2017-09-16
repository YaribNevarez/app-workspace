/*
 * application.cpp
 *
 *  Created on: Aug 31, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
 */

#include "application.hpp"

Application::Application(int argc, char * argv[]):
argc(argc),
argv(argv)
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

bool Application::passed_arg(std::string argument)
{
	bool flag = false;

	if ((0 < argc) && (argv != NULL))
		for (signed i = 0; !flag && (i < argc) && (argv[i] != NULL); i ++)
			flag = argument.compare(argv[i]) == 0;

	return flag;
}

std::string Application::passed_arg(int i)
{
	std::string argument = "";
	if ((0 < argc) && (argv != NULL) && (argv[i] != NULL))
		argument = argv[i];
	return argument;
}

int Application::passed_arg(void)
{
	return argc;
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
