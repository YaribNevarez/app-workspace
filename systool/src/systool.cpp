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
#include "framework/commander.hpp"
#include "framework/systembox.hpp"
#include <signal.h>

using namespace SYSTEMBOX;

SystemTool::SystemTool(int argc, char * argv[]):
Application(argc, argv)
{
}

void SystemTool::remote_commander(uint16_t server_port)
{
	TcpServer * server;
	TcpSocket * client;
	std::string message;
	std::string answer;
	bool exit_flag;

	server = new TcpServer(server_port);
	if (server != NULL)
	{
		if (server->prepare() != -1)
		for (;;)
		{
			std::cout << "\nWaiting for connection on server port: " << server_port << std::endl;
			client = server->accept_connection();

			if (client != NULL)
			{
				do
				{
					if (client->receive_buffer(message) > 0)
					{
						std::cout << "\nClient: " << message.c_str();
						exit_flag = Commander::execute(message, answer);
						std::cout << "\nServer: " << answer.c_str();
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
		delete server;
	}

	perror("\nExit");
}

void SystemTool::local_commander(void)
{
	std::string cmd;
	std::string answer;
	bool exit_flag;

	std::cout << "\nWaiting for command ...\n";

	do
	{
		std::getline(std::cin, cmd);
		exit_flag = Commander::execute(cmd, answer);
		std::cout << answer;
	} while(!exit_flag);
}

int SystemTool::run(void)
{
	int tcp_port = 0;
	char op;

	if (argc >= 2)
	{
		op = argv[1][0];

		if (argc > 2)
		{
			tcp_port = strtoul(argv[2], NULL, 0);
		}
	}
	else
	{
		std::cout << "\n***** Welcome to the local SysTool *****";
		std::cout << "\n\nOptions:";
		std::cout << "\n 1   - Server commander";
		std::cout << "\n 2   - Local commander";
		std::cout << "\n XXX - Exit";
		std::cout << "\n\nSelect: ";

		op = std::cin.get();
	}

	switch(op)
	{
	case '1':
		if (tcp_port == 0)
		{
			std::cout << "\nTCP/IP port number: ";
			std::cin >> tcp_port;
		}
		remote_commander(tcp_port);
		break;
	case '2':
		local_commander();
		break;
	default:;
	}

	std::cout << "\nBYE\n";
    return EXIT_SUCCESS;
}

SystemTool::~SystemTool()
{
}
