/*
 * commander.hpp
 *
 *  Created on: Sep 8, 2017
 *      Author: root
 */

#ifndef COMMANDER_HPP_
#define COMMANDER_HPP_

#include <stdlib.h>

class Commander
{
public:
static bool execute(std::string command, std::string & answer);
};

#endif /* COMMANDER_HPP_ */
