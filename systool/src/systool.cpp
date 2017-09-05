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
	serverFeature = new ServerFeature(&ZYNQ_PMOD_HANDLER, 1111);
	register_feature((SystemFeature *) serverFeature);
}

SystemTool::ServerFeature::ServerFeature(DeviceHandler * device_handler, uint16_t host_port):
		SystemFeature(device_handler),
		server(host_port),
		flags(EXECUTE)
{
}

int SystemTool::ServerFeature::command_handler(std::string command, std::string & answer)
{
	Device::InstanceVector devices = Device::get_instanceVector();
	answer.clear();

	if (devices.empty())
	{
		answer = "________________________________________\n";
		answer += "NO REGISTERED DEVICES\n";
		answer += "________________________________________\n";
	}
	else if (command.compare(0, 4, "EXIT") == 0)
	{
		answer = "Exit server...\n";
		flags &= ~ EXECUTE;
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
				sprintf(c_answer, "%s : 0x%X\n", device->get_name().c_str(), data);
				answer += c_answer;
			}
			else
			{
				answer += "Couldn't access device: " + device->get_name() + "\n";
			}
			answer += "________________________________________\n";
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
		answer += "\n * Exit commander:\nEXIT (hit ENTER key)\n";
		answer += "________________________________________\n";
	}

	return SUCCESS;
}

int SystemTool::ServerFeature::command_handler(ByteVector command, ByteVector & answer)
{
	return SUCCESS;
}

int SystemTool::ServerFeature::run(void)
{
	int result = server.open_connection();

	if (result == SUCCESS)
	{
		ByteVector  buffer;
		std::string answer;

		do
		{
			if (server.receive_buffer(buffer) > 0)
			{
				if (std::isalpha(buffer[0]))
				{
					command_handler(std::string((const char *)buffer.data()), answer);
					server.send_buffer(answer);
				}
			}
		} while(flags & EXECUTE);

		server.close_connection();
	}

	return result;
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
