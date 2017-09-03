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

int SystemTool::ServerFeature::command_handler(std::string command)
{
	std::string answer;

	printf("Command: %s\n", command.c_str());

	if (command.compare(0, 4, "EXIT") == 0)
	{
		printf("Exit server...\n");
		flags &= ~ EXECUTE;
	}
	else
	{
		Device::InstanceVector devices = Device::get_instanceVector();
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
			if (dynamic_cast<LevelSensor *>(device))
			{
				printf("%s\n", device->get_name().c_str());
			}
			else if(dynamic_cast<LeakageSensor *>(device))
			{
				printf("%s\n", device->get_name().c_str());
			}
			else if(dynamic_cast<IRSensor *>(device))
			{
				printf("%s\n", device->get_name().c_str());
			}
			else if(dynamic_cast<Valve *>(device))
			{
				printf("%s\n", device->get_name().c_str());
				if (command.compare(device->get_name().size(), 3, " = ") == 0)
				{
					unsigned i = command.find(";", device->get_name().size() + 3);
					printf("End (;): %d\n", i);
					if (i != string::npos)
					{
						int data;
						data = strtoul(command.substr(device->get_name().size() + 3, i).c_str(), NULL, 0);
						printf("Data: %d\n", data);
						((Valve *)device)->set_position((Valve::Position) data);
					}
				}
			}
			else if(dynamic_cast<OutputPin *>(device))
			{
				printf("%s\n", device->get_name().c_str());
			}
			else if(dynamic_cast<InputPin *>(device))
			{
				printf("%s\n", device->get_name().c_str());
			}
			else if(dynamic_cast<OutputVector *>(device))
			{
				printf("%s\n", device->get_name().c_str());
			}
			else if(dynamic_cast<InputVector *>(device))
			{
				printf("%s\n", device->get_name().c_str());
			}
			else
			{
				printf("%s\n", device->get_name().c_str());
			}
		}
		else
		{
			server.send_buffer("Command not found\n");
		}
	}
	return SUCCESS;
}

int SystemTool::ServerFeature::command_handler(ByteVector command)
{
	return SUCCESS;
}

int SystemTool::ServerFeature::run(void)
{
	int result = server.open_connection();

	if (result == SUCCESS)
	{
		ByteVector buffer;
		do
		{
			if (server.receive_buffer(buffer) > 0)
			{
				if (std::isalpha(buffer[0]))
				{
					command_handler(std::string((const char *)buffer.data()));
				}
				else
				{
					command_handler(buffer);
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
