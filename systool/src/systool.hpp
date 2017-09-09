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
	SystemTool(int argc = 0, char * argv[] = NULL);
	~SystemTool();

	virtual int run(void);

protected:

	void remote_commander(uint16_t server_port = 2323);
	void local_commander(void);
};

#endif /* SYSTOOL_HPP_ */
