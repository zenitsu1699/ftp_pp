/*
** EPITECH PROJECT, 2021
** server.c
** File description:
** server.c
*/

#include "../inc/my_ftp.h"

int server(int port, char *path)
{
    the_data *c_user = all_the_clients(path);
    struct sockaddr_in address;
    int master_socket = 0;
    fd_set readfds;

    master_socket = create_socket();
    config_socket(master_socket, port, &address);
    printf("Listener on port %d \n", port);
    initializing_the_queue(master_socket, BACKLOG);
    printf("Waiting for connections ...\n");
    while (TRUE) {
        create_multi_connection_client(&master_socket, c_user, address, &readfds);
	    com_multi_clients(&master_socket, c_user, address, &readfds);
    }
    return 0;
}
