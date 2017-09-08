/*
 * systool.cpp
 *
 *  Created on: Aug 30, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <typeinfo>
#include "systool.hpp"
#include "framework/zybo.hpp"
#include "framework/commander.hpp"

SystemTool::SystemTool()
{
	tcpServerFeature = new TcpServerFeature(&ZYNQ_PMOD_HANDLER, 23);
}

SystemTool::TcpServerFeature::TcpServerFeature(DeviceHandler * device_handler, uint16_t host_port):
		SystemFeature(device_handler),
		server(host_port),
		flags(0x00)
{
}

int SystemTool::TcpServerFeature::run(void)
{
	TcpSocket * client;
	std::string message;
	std::string answer;
	bool exit_flag;

	if (server.prepare() != -1)
	for (;;)
	{
		puts("\nWaiting for connection ...");
		client = server.accept_connection();

		if (client != NULL)
		{
			do
			{
				if (client->receive_buffer(message) > 0)
				{
					printf("\nClient: %s", message.c_str());
					exit_flag = Commander::execute(message, answer);
					printf("\nServer: %s", answer.c_str());
					client->send_buffer(answer);
				}
				else
				{
					exit_flag = true;
				}
			} while(!exit_flag);

			delete client;
		}
	}

	perror("\nError");

	return EXIT_SUCCESS;
}

int SystemTool::run(void)
{
	char op;
	puts("\n***** Welcome to the local SysTool *****");
	puts("\n\nOptions:");
	puts("\n 1   - Start command server");
	puts("\n 2   - Start command local");
	puts("\n ESC - Exit");
	puts("\n\nSelect: ");

	op = std::cin.get();

	switch(op)
	{
	case '1': tcpServerFeature->start(); for (;tcpServerFeature->isRunning();); break;
	case '2': break;
	default:;
	}

	printf("Bye\n");
    return 0;
}

SystemTool::~SystemTool()
{
}
