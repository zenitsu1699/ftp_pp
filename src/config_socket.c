/*
** EPITECH PROJECT, 2021
** config_socket.c
** File description:
** config_socket.c
*/

#include "../inc/my_ftp.h"

void config_socket(int fd_socket, int port, struct sockaddr_in *address)
{
    memset(address, 0, sizeof(struct sockaddr_in));
    (*address).sin_family = PF_INET;
    (*address).sin_port = htons(port);
    (*address).sin_addr.s_addr = INADDR_ANY;
    if (bind(fd_socket, (struct sockaddr *)address,
	     sizeof(struct sockaddr_in)) == -1)
        handle_error("bind");
}
