/*
 * systool.hpp
 *
 *  Created on: Aug 30, 2017
 *      Author: root
 */

#ifndef SYSTOOL_HPP_
#define SYSTOOL_HPP_

#include <sys/socket.h>
#include <arpa/inet.h>
#include "framework/application.hpp"

class SystemTool: public Application
{
public:
	SystemTool();
	~SystemTool();

	virtual int run(void);

protected:
	class ServerFeature: protected SystemFeature
	{
	public:
		ServerFeature(DeviceHandler * device_handler):
			SystemFeature(device_handler)
		{}
		virtual int run(void);

	private:
		int server_socket;
		int client_socket;
		struct sockaddr_in server_address;
		struct sockaddr_in client_address;
	};

	ServerFeature * server;
};

#endif /* SYSTOOL_HPP_ */
