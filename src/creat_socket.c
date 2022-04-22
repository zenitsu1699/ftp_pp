/*
** EPITECH PROJECT, 2021
** creat_socket.c
** File description:
** creat_socket.c
*/

#include "../inc/my_ftp.h"

int create_socket(void)
{
    int fd_socket = 0;
    struct protoent *my_protocol = getprotobyname("tcp");
    int papa = my_protocol->p_proto;
    int opt = TRUE;

    fd_socket = socket(PF_INET, SOCK_STREAM, papa);
    if (fd_socket == -1) handle_error("socket");
    if (setsockopt(fd_socket, SOL_SOCKET, SO_REUSEADDR,
		   (char *)&opt, sizeof(opt)) < 0) handle_error("setsockopt");
    return fd_socket;
}
