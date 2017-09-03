/*
 * systool.cpp
 *
 *  Created on: Aug 30, 2017
 *      Author: root
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "systool.hpp"
#include "framework/zybo.hpp"

SystemTool::SystemTool()
{
	server = new Server(7777);
	register_feature((SystemFeature *) server);
}

int SystemTool::run(void)
{
	start();

	for (;;);
    return 0;
}

SystemTool::~SystemTool()
{
}
