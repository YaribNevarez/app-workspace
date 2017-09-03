/*
 * server.cpp
 *
 *  Created on: Sep 3, 2017
 *      Author: root
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "server.hpp"

Server::Server(uint16_t host_port):
host_port(host_port),
server_socket(-1),
client_socket(-1)
{
	memset(&server_address, 0, sizeof(server_address));
	memset(&client_address, 0, sizeof(client_address));
}

int Server::connect_server(void)
{
	int addr_len;
	int result = EXIT_FAILURE;

	if (server_socket != -1)
	{
		listen(server_socket , 1);

		printf("Waiting for connection ...");
		addr_len = sizeof(struct sockaddr_in);

		client_socket = accept(server_socket,
							  (struct sockaddr *) &client_address,
							  (socklen_t*)&addr_len);

		if (client_socket != -1)
		{
			printf("Connection established.\n");
			result = EXIT_SUCCESS;
		}
		else
		{
			perror("connection - Error");
		}
	}

	return result;
}

int Server::prepare_server(void)
{
	int result = EXIT_FAILURE;

    server_socket = socket(AF_INET , SOCK_STREAM , 0);

    if (server_socket != -1)
    {
		printf("Socket created\n");

		server_address.sin_family = AF_INET;
		server_address.sin_addr.s_addr = INADDR_ANY;
		server_address.sin_port = htons(host_port);

		if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == 0)
		{
			result = EXIT_SUCCESS;
		}
		else
		{
			perror("bind - Error");
		}
    }
    else
    {
    	perror("socket - Error");
    }

    return result;
}

void Server::close_connection(void)
{
	if (server_socket != -1)
		close(server_socket);

	if (client_socket != -1)
		close(client_socket);
}

int Server::open_connection(void)
{
	int result;

	result = prepare_server();

	if (result == EXIT_SUCCESS)
	{
		result = connect_server();
	}

	return result;
}

int Server::receive_data(void * buffer, unsigned int length)
{
	return recv(client_socket, buffer, length, 0);
}

int Server::send_data(void * buffer, unsigned int length)
{
	return send(client_socket, buffer, length, 0);
}

Server::~Server()
{
	close_connection();
}
