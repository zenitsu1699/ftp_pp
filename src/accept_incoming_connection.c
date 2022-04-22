/*
** EPITECH PROJECT, 2021
** accept_incoming_connection.c
** File description:
** accept_incoming_connection.c
*/

#include "../inc/my_ftp.h"

int accept_incoming_connection(int fd_socket, struct sockaddr_in *address)
{
    int fd = 0;
    socklen_t addr_size = sizeof(struct sockaddr_in);
    int addrlen = sizeof(address);

    fd = accept(fd_socket, (struct sockaddr *)address, (socklen_t *)&addrlen);
    if (fd == -1) handle_error("accept");
    return fd;
}