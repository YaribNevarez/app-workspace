/*
 * systool.hpp
 *
 *  Created on: Aug 30, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
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

		bool is_executing(void);
		bool is_connected(void);

	protected:
		enum
		{
			EXECUTING = 0x80,
			CONNECTED = 0x40
		};

		inline void set_flag(uint8_t);
		inline void clear_flag(uint8_t);
		inline bool get_flag(uint8_t);

		Server server;
		uint8_t flags;
	};

	ServerFeature * serverFeature;
};

#endif /* SYSTOOL_HPP_ */
