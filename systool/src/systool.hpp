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

	Server * server;
};

#endif /* SYSTOOL_HPP_ */
