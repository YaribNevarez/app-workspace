/*
 * tcpsocket.hpp
 *
 *  Created on: Sep 7, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
 */

#ifndef TCPSOCKET_HPP_
#define TCPSOCKET_HPP_

#include <string.h>
#include <stdint.h>
#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <arpa/inet.h>

typedef std::vector<uint8_t> ByteVector;

class TcpSocket
{
public:
	TcpSocket(void);
	TcpSocket(int client_socket, struct sockaddr_in client_address);
	virtual ~TcpSocket(void);

	virtual int  open_connection(char * host_address, uint16_t port);
	virtual void close_connection(void);

	virtual int  receive_buffer(void * buffer, size_t length);
	virtual int  receive_buffer(std::string & string);
	virtual int  receive_buffer(ByteVector & vector);

	virtual int  send_buffer(void * buffer, size_t length);
	virtual int  send_buffer(const char * array);
	virtual int  send_buffer(std::string & string);
	virtual int  send_buffer(ByteVector &vector);

	void         set_buffer_length(size_t length);
	size_t       get_buffer_length(void);

protected:
	enum
	{
		DEFAULT_BUFFER_LENGTH = 255
	};

	int    client_socket;
	size_t buffer_length;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
};



#endif /* TCPSOCKET_HPP_ */
