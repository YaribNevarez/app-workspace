/*
 * application.cpp
 *
 *  Created on: Aug 31, 2017
 *      Author: root
 */

#include "application.hpp"

Application::Application()
{}

Application::~Application()
{
	while (!features.empty())
	{
		if (features.back() != NULL)
			delete features.back();

		features.pop_back();
	}
}

void Application::register_feature(SystemFeature * feature)
{
	features.push_back(feature);
}

int Application::start(void)
{
	int result = EXIT_SUCCESS;

	for (unsigned int i = 0;
		(i < features.size()) && (result == EXIT_SUCCESS);
		i ++)
	{
		result = features[i]->start();
	}

	return result;
}
