/*
 * daemon.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
 */

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "daemon.hpp"

int Daemon::become(int flags)
{
	int maxfd, fd;

	/* Returns 0 on success, -1 on error */
	switch (fork())
	{
	case -1:
		return -1;
	case 0:
		break;
	default:
		_exit(EXIT_SUCCESS);
	}

	/* Become background process */
	if (setsid() == -1)
		return -1; /* Become leader of new session */
	switch (fork()) {
	case -1:
		return -1;
	case 0:
		break;
	default:
		_exit(EXIT_SUCCESS);
	}

	/* Ensure we are not session leader */
	/* Child falls through... */
	/* while parent terminates */

	if (!(flags & BD_NO_UMASK0))
		umask(0); /* Clear file mode creation mask */
	if (!(flags & BD_NO_CHDIR))
		chdir("/"); /* Change to root directory */
	if (!(flags & BD_NO_CLOSE_FILES))
	{ /* Close all open files */
		maxfd = sysconf(_SC_OPEN_MAX);
		if (maxfd == -1)
			/* Limit is indeterminate... */
			maxfd = BD_MAX_CLOSE;
		/* so take a guess */
		for (fd = 0; fd < maxfd; fd++)
			close(fd);
	}

	if (!(flags & BD_NO_REOPEN_STD_FDS))
	{
		close (STDIN_FILENO);
		/* Reopen standard fd's to /dev/null */
		fd = open("/dev/null", O_RDWR);
		if (fd != STDIN_FILENO)
			/* 'fd' should be 0 */
			return -1;
		if (dup2(STDIN_FILENO, STDOUT_FILENO) != STDOUT_FILENO)
			return -1;
		if (dup2(STDIN_FILENO, STDERR_FILENO) != STDERR_FILENO)
			return -1;
	}
	return 0;
}

