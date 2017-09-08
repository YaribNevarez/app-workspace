/*
 * TCPServer.hpp
 *
 *  Created on: Sep 3, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
 */

#ifndef TCPTCPServer_HPP_
#define TCPTCPServer_HPP_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "tcpsocket.hpp"

class TcpServer
{
public:
	TcpServer(uint16_t);

	int 		 prepare(void);
	TcpSocket *  accept_connection(void);
	virtual void close_connection(void);

	virtual ~TcpServer(void);

private:
	uint16_t           host_port;
	int                server_socket;
	struct sockaddr_in server_address;
	bool               bound;
};


#endif /* TCPServer_HPP_ */
