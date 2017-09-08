/*
 * systool.hpp
 *
 *  Created on: Aug 30, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
 */

#ifndef SYSTOOL_HPP_
#define SYSTOOL_HPP_

#include "framework/application.hpp"
#include "framework/tcpserver.hpp"

class SystemTool: public Application
{
public:
	SystemTool();
	~SystemTool();

	virtual int run(void);

protected:

	class TcpServerFeature: public SystemFeature
	{
	public:
		TcpServerFeature(DeviceHandler *, uint16_t);
		virtual int run(void);

	protected:
		TcpServer server;
		uint8_t   flags;
	};

	TcpServerFeature * tcpServerFeature;
};

#endif /* SYSTOOL_HPP_ */
