/*
 * server.hpp
 *
 *  Created on: Sep 3, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
 */

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <arpa/inet.h>

typedef std::vector<uint8_t> ByteVector;

class Server
{
public:
	Server(uint16_t, size_t = DEFAULT_BUFFER_LENGTH);

	virtual int  open_connection(void);
	virtual void close_connection(void);

	virtual int  receive_buffer(void *, size_t);
	virtual int  receive_buffer(std::string &);
	virtual int  receive_buffer(ByteVector &);

	virtual int  send_buffer(void *, size_t);
	virtual int  send_buffer(const char *);
	virtual int  send_buffer(std::string &);
	virtual int  send_buffer(ByteVector &);

	void         set_buffer_length(size_t);
	size_t       get_buffer_length();

	virtual ~Server(void);
private:
	int prepare_server(void);
	int connect_server(void);

	enum
	{
		DEFAULT_BUFFER_LENGTH = 255
	};

	size_t   buffer_length;
	uint16_t host_port;
	int      server_socket;
	int      client_socket;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
};


#endif /* SERVER_HPP_ */
