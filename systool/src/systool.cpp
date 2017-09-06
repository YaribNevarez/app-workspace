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

SystemTool::SystemTool()
{
	serverFeature = new ServerFeature(&ZYNQ_PMOD_HANDLER, 3333);
	register_feature((SystemFeature *) serverFeature);
}

SystemTool::ServerFeature::ServerFeature(DeviceHandler * device_handler, uint16_t host_port):
		SystemFeature(device_handler),
		server(host_port),
		flags(0x00)
{
}

int SystemTool::ServerFeature::command_handler(std::string command, std::string & answer)
{
	Device::InstanceVector devices = Device::get_instanceVector();
	answer.clear();

	if (command.compare(0, 4, "EXIT") == 0)
	{
		answer = "Exit server...\n";
		clear_flag(EXECUTING);
	}
	if (command.compare(0, 7, "DEVICES") == 0)
	{
		char c_answer[128];
		sprintf(c_answer, "%d\n", devices.size());
		answer = c_answer;
	}
	if (command.compare(0, 7, "DEVICE ") == 0)
	{
		uint32_t i = strtoul(command.substr(6).c_str(), NULL, 0);
		if (i < devices.size())
		{
			answer = devices[i]->get_name() + "\n";
		}
		else
		{
			answer = "NO DEVICE\n";
		}
	}
	else
	{
		Device * device = NULL;

		for (unsigned i = 0; i < devices.size(); i ++)
		{
			if (command.compare(0,
								devices[i]->get_name().size(),
								devices[i]->get_name()) == 0)
			{
				device = devices[i];
			}
		}

		if (device != NULL)
		{
			uint32_t data;
			bool device_access;
			std::string::size_type token_equal;

			token_equal = command.find("=", device->get_name().size());

			if (token_equal == string::npos)
			{
				device_access = device->read(& data);
				answer = "[READ] ";
			}
			else
			{
				data = strtoul(command.substr(token_equal + 1).c_str(), NULL, 0);
				device_access = device->write(data);
				answer = "[WRITE] ";
			}

			if (device_access)
			{
				char c_answer[128];
				sprintf(c_answer, "%s = 0x%X\n", device->get_name().c_str(), data);
				answer += c_answer;
			}
			else
			{
				answer += "Couldn't access device: " + device->get_name() + "\n";
			}
		}
	}

	if (answer.empty())
	{
		answer = "_________________ HELP _________________\n";
		answer += "List of devices:\n\n";
		for (unsigned i = 0; i < devices.size(); i ++)
		{
			answer += devices[i]->get_name() + "\n";
		}
		answer += "\n * Example reading:\n" + devices[0]->get_name() + "     (hit ENTER key)\n";
		answer += "\n * Example writing:\n" + devices[0]->get_name() + " = 1 (hit ENTER key)\n";
		answer += "\n * Get number of registered devices:\nDEVICES (hit ENTER key)\n";
		answer += "\n * Get name of a registered device:\nDEVICE 1 (hit ENTER key)\n";
		answer += "\n * Exit commander:\nEXIT (hit ENTER key)\n";
	}

	answer += "________________________________________\n";

	return SUCCESS;
}

bool SystemTool::ServerFeature::is_executing(void)
{
	return get_flag(EXECUTING);
}

bool SystemTool::ServerFeature::is_connected(void)
{
	return get_flag(CONNECTED);
}

void SystemTool::ServerFeature::set_flag(uint8_t flag)
{
	flags |= flag;
}

void SystemTool::ServerFeature::clear_flag(uint8_t flag)
{
	flags &= ~flag;
}

bool SystemTool::ServerFeature::get_flag(uint8_t flag)
{
	return flags & flag;
}

int SystemTool::ServerFeature::run(void)
{
	int result = server.open_connection();
	set_flag(EXECUTING);

	if (result == SUCCESS)
	{
		std::string message;
		std::string answer;
		set_flag(CONNECTED);

		do
		{
			if (server.receive_buffer(message) > 0)
			{
				command_handler(message, answer);
				server.send_buffer(answer);
			}
		} while(get_flag(EXECUTING));

		server.close_connection();
		clear_flag(CONNECTED);
	}

	return result;
}

int SystemTool::run(void)
{
	printf("Welcome to the local DevTool\n");

	start();
	for (;serverFeature->isRunning(););

	printf("Bye\n");
    return 0;
}

SystemTool::~SystemTool()
{
}
