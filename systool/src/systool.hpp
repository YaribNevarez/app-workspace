/*
 * systool.hpp
 *
 *  Created on: Aug 30, 2017
 *      Author: root
 */

#ifndef SYSTOOL_HPP_
#define SYSTOOL_HPP_

#include "framework/application.hpp"
#include "framework/server.hpp"

class SystemTool: public Application
{
public:
	SystemTool();
	~SystemTool();

	virtual int run(void);

protected:

	class ServerFeature: public SystemFeature
	{
	public:
		ServerFeature(DeviceHandler *, uint16_t);
		virtual int run(void);
		virtual int command_handler(std::string, std::string &);
		virtual int command_handler(ByteVector, ByteVector &);

	protected:
		enum
		{
			EXECUTE = 0x80
		};
		Server server;
		uint8_t flags;
	};

	ServerFeature * serverFeature;
};

#endif /* SYSTOOL_HPP_ */
