/*
 * systool.cpp
 *
 *  Created on: Aug 30, 2017
 *      Author: root
 */

#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <string.h>


#include "systool.hpp"


SystemTool::SystemTool()
{
}

int SystemTool::Server::run(void)
{
	int addr_len, read_size;
    char client_message[2000];

    //Create socket
    server_socket = socket(AF_INET , SOCK_STREAM , 0);
    if (server_socket == -1)
    {
    	puts("Could not create socket");
    }
    puts("Socket created");

    //Prepare the sockaddr_in structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons( 8888 );

    //Bind
    if( bind(server_socket, (struct sockaddr *)&server_address , sizeof(server_address)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");

    //Listen
    listen(server_socket , 1);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    addr_len = sizeof(struct sockaddr_in);

    //accept connection from an incoming client
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&addr_len);
    if (client_socket < 0)
    {
        perror("accept failed");
        return 1;
    }
    puts("Connection accepted");

    //Receive a message from client
    while( (read_size = recv(client_socket , client_message , sizeof(client_message) , 0)) > 0 )
    {
    	if (1)
    	{
    		//relay_0.get_ID();
    	}
    	else if (1)
    	{}

    	puts(client_message);
        write(client_socket , client_message , strlen(client_message));
    }

    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }

    return 0;
}

int SystemTool::run(void)
{


    return 0;
}

SystemTool::~SystemTool()
{
}