/*
 * cccapp.cpp
 *
 *  Created on: Aug 7, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
 */
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include "ctrlapp.hpp"
#include "framework/systembox.hpp"
#include "framework/daemon.hpp"
#include "framework/commander.hpp"
#include "framework/tcpserver.hpp"

using namespace SYSTEMBOX;

ControlApp::ControlApp(int argc, char * argv[]):
Application(argc, argv)
{
	if (0 < passed_arg("-drain"))
		register_thread(new DrainFeature());

	if (0 < passed_arg("-flush"))
		register_thread(new FlushFeature());

	if (0 < passed_arg("-ir"))
		register_thread(new IRFeature());

	if (0 < passed_arg("-leakage"))
		register_thread(new LeakageFeature());

	if (0 < passed_arg("-relay"))
		register_thread(new RelayFeature());
}

int ControlApp::DrainFeature::run(void)
{
	typedef enum
	{
		START_SEQUENCE,
		ACTIVATE_VG,
		OPEN_FLUSH_VALVE,
		CLOSE_FLUSH_VALVE,
		DEACTIVATE_VG,
		STOP_SEQUENCE,
		END_SEQUENCE
	} DrainSequenceState;

	DrainSequenceState sequence_state;

	for (;;)
	{
		if (drainLocalReq.get_status() && (LevelSensor::FULL != wasteTankSensor.get_level()))
		{
			int time_delay = drainDelaySelection.get_value();

			sequence_state = START_SEQUENCE;

			while (sequence_state != END_SEQUENCE)
			{
				switch (sequence_state)
				{
				case START_SEQUENCE:
				case ACTIVATE_VG:
					vacumGenerator.set_status(OutputPin::ON);
					sleep(time_delay); // TODO: Implement interruption
					if (sequence_state != STOP_SEQUENCE) // TODO: Only UART command
					{
						sequence_state = OPEN_FLUSH_VALVE;
					}
					break;

				case OPEN_FLUSH_VALVE:
					flushValve.set_position(Valve::OPEN);
					sleep(20);
					if (sequence_state != STOP_SEQUENCE)
					{
						sequence_state = CLOSE_FLUSH_VALVE;
					}
					break;

				case CLOSE_FLUSH_VALVE:
					flushValve.set_position(Valve::CLOSE);
					sleep(10);
					if (sequence_state != STOP_SEQUENCE)
					{
						sequence_state = DEACTIVATE_VG;
					}
					break;

				case DEACTIVATE_VG:
					vacumGenerator.set_status(OutputPin::OFF);
					sequence_state = END_SEQUENCE;
					break;
				case STOP_SEQUENCE:
					flushValve.set_position(Valve::CLOSE);
					sleep(20);
					vacumGenerator.set_status(OutputPin::OFF);
					sequence_state = END_SEQUENCE;
				case END_SEQUENCE:
					break;
				}
			}
		}
	}
	return 0;
}

int ControlApp::FlushFeature::run(void)
{
	LevelSensor::Status topSensor;
	LevelSensor::Status bottomSensor;
	bool flushFlag;

	for (;;)
	{
		topSensor    = chamberTopSensor.get_level();
		bottomSensor = chamberBottomSensor.get_level();

		if ((topSensor == LevelSensor::FULL) && (bottomSensor == LevelSensor::FULL)
			 && (LevelSensor::FULL != wasteTankSensor.get_level()))
		{	// Chamber is FULL !!!!!
//			if (LevelSensor::FULL != wasteTankSensor.get_level())
			{
				vacumGenerator.set_status(OutputPin::ON);
				flushValve.set_position(Valve::OPEN);
				flushFlag = true;
			}
		}
//		else if ((topSensor == LevelSensor::FULL) && (bottomSensor == LevelSensor::LOW))
//		{
//
//		}
//		else if ((topSensor == LevelSensor::LOW) && (bottomSensor == LevelSensor::FULL))
//		{
//
//		}
		else // if ((topSensor == LevelSensor::LOW) && (bottomSensor == LevelSensor::LOW))
		{
			if (flushFlag)
			{
				sleep(1);
				flushValve.set_position(Valve::CLOSE);

				sleep(5);
				vacumGenerator.set_status(OutputPin::OFF);

				flushFlag = false;
			}
		}
	}
	return 0;
}

int ControlApp::IRFeature::run(void)
{
	typedef enum
	{
		IR_MODE = 0,
		EMERGENCY,
		SOV_OPEN
	} ESwitchState;

	ESwitchState status;
	const unsigned int ABSENCE_TIMEOUT = 60;
	unsigned int timer = 0;

	for (;;)
	{
		status = (ESwitchState) emergencySwitch.get_value();
		switch(status)
		{
		case IR_MODE:
			switch (irSensor.get_status())
			{
			case IRSensor::PRESENCE:
				shutOffValve.set_position(Valve::OPEN);
				timer = ABSENCE_TIMEOUT;
				break;
			case IRSensor::ABSENCE:
				if (timer == 0)
				{
					shutOffValve.set_position(Valve::CLOSE);
				}
				else
				{
					shutOffValve.set_position(Valve::OPEN);
					sleep(1);
					timer --;
				}
				break;
			default:;
			}
			break;
		case EMERGENCY:
			shutOffValve.set_position(Valve::CLOSE);
			timer = 0;
			break;
		case SOV_OPEN:
			shutOffValve.set_position(Valve::OPEN);
			timer = 0;
			break;
		default:;
			timer = 0;
		}
	}
	return 0;
}

int ControlApp::LeakageFeature::run(void)
{
	for (;;)
	{
		if (LeakageSensor::LEAKING == leakageSensor_0.get_status()
		 || LeakageSensor::LEAKING == leakageSensor_1.get_status())
		{
			leakageIndicator.set_status(OutputPin::ON);
		}
		else
		{
			leakageIndicator.set_status(OutputPin::OFF);
		}
	}
	return 0;
}

int ControlApp::RelayFeature::run(void)
{
	for (;;);
	return 0;
}

void ControlApp::server(void)
{
	TcpServer * server;
	TcpSocket * client;
	std::string message;
	std::string answer;
	bool exit_flag;

	server = new TcpServer(23);
	if (server != NULL)
	{
		if (server->prepare() != -1)
		{
			for (;;)
			{
				client = server->accept_connection(); // Waiting for connection

				if (client != NULL)
				{
					do
					{
						if (client->receive_buffer(message) > 0)
						{
							exit_flag = Commander::execute(message, answer);
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
		}
		delete server;
	}

	perror("\nExit");
}

int ControlApp::run(void)
{
	if (0 < passed_arg("-daemon"))
	{
		Daemon::become(0);
	}

	start(); // start all registered worker threads

	if (0 < passed_arg("-server"))
	{
		server();
	}

	for (;;);

	return 0;
}

ControlApp::~ControlApp()
{}
