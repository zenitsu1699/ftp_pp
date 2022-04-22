/*
** EPITECH PROJECT, 2021
** initializing_the_queue.c
** File description:
** initializing_the_queue.c
*/

#include "../inc/my_ftp.h"

void initializing_the_queue(int fd_socket, int backlog)
{
    if (listen(fd_socket, backlog) == -1)
        handle_error("listen");
}
