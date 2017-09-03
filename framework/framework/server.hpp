/*
 * server.hpp
 *
 *  Created on: Sep 3, 2017
 *      Author: root
 */

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <sys/socket.h>
#include <arpa/inet.h>

class Server
{
public:
	Server(uint16_t);

	virtual int  open_connection(void);
	virtual void close_connection(void);
	virtual int  receive_data(void *, unsigned int);
	virtual int  send_data(void *, unsigned int);

	virtual ~Server(void);
private:
	int prepare_server(void);
	int connect_server(void);
	uint16_t host_port;
	int server_socket;
	int client_socket;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
};


#endif /* SERVER_HPP_ */