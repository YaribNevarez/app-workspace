/*
 * server.cpp
 *
 *  Created on: Sep 3, 2017
 *      Author: root
 */

#include "server.hpp"

Server::Server(uint16_t host_port, size_t buffer_length):
buffer_length(buffer_length),
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

		printf("Waiting for connection\n");
		addr_len = sizeof(struct sockaddr_in);

		client_socket = accept(server_socket,
							  (struct sockaddr *) &client_address,
							  (socklen_t*)&addr_len);

		if (client_socket != -1)
		{
			printf("Connection established\n");
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
		printf("Server created\n");

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
	if (client_socket != -1)
		close(client_socket);

	if (server_socket != -1)
		close(server_socket);
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

int Server::receive_buffer(void * buffer, size_t length)
{
	return recv(client_socket, buffer, length, 0);
}

int Server::receive_buffer(std::string & string)
{
	int result;

	std::string i_string(buffer_length, (char) 0);

	result = receive_buffer((void *)i_string.data(), i_string.size());

	if (result != -1)
	{
		string = i_string;
		string.resize(result);
	}

	return result;
}

int Server::receive_buffer(ByteVector & vector)
{
	int result;

	ByteVector i_vector(buffer_length);

	result = receive_buffer(i_vector.data(), i_vector.size());

	if (result != -1)
	{
		vector = i_vector;
		vector.resize(result);
	}

	return result;
}

int Server::send_buffer(void * buffer, size_t length)
{
	return send(client_socket, buffer, length, 0);
}

int Server::send_buffer(const char * array)
{
	return send_buffer((void *) array, strlen(array));
}

int Server::send_buffer(std::string & string)
{
	return send_buffer((void *)string.data(), string.size());
}

int Server::send_buffer(ByteVector & vector)
{
	return send_buffer((void *)vector.data(), vector.size());
}

void Server::set_buffer_length(size_t length)
{
	buffer_length = length;
}

size_t Server::get_buffer_length()
{
	return buffer_length;
}

Server::~Server()
{
	close_connection();
}
