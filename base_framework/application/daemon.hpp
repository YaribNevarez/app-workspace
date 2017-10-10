/*
 * daemon.hpp
 *
 *  Created on: Sep 10, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
 */

#ifndef DAEMON_HPP_
#define DAEMON_HPP_


class Daemon
{
public:
	enum
	{   // Bit-mask values for 'flags' argument of becomeDaemon()
		BD_NO_CHDIR = 01,          // Don't chdir("/")
		BD_NO_CLOSE_FILES = 02,    // Don't close all open files
		BD_NO_REOPEN_STD_FDS = 04, // Don't reopen stdin, stdout, and stderr to /dev/null
		BD_NO_UMASK0 = 010,        // Don't do a umask(0)
		BD_MAX_CLOSE = 8192        // Maximum file descriptors to close if sysconf(_SC_OPEN_MAX) is indeterminate
	};
	static int become(int flags);
};


#endif /* DAEMON_HPP_ */