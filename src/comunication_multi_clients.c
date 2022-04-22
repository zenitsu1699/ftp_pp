/*
** EPITECH PROJECT, 2021
** communication_multi_clients.c
** File description:
** communication_multi_clients.c
*/

#include "../inc/my_ftp.h"

void com_multi_clients(int *master_socket, the_data *c_user,
		       struct sockaddr_in address, fd_set *readfds)
{
    int sd = 0;
    int addrlen = sizeof(address);

    for (int i = 0; i < MAX_CLIENTS; i++) {
        sd = c_user[i].client_socket;
        if (FD_ISSET(sd, readfds)) {
            if (getpeername(sd, (struct sockaddr*)&address, (socklen_t*)&addrlen) == -1) {
                printf("Host disconnected , ip %s , port %d \n" ,
                       inet_ntoa(address.sin_addr) , ntohs(address.sin_port));
                dprintf(sd, "Good bye!!!\n");
                close(sd);
            c_user[i].client_socket = 0;
            c_user[i].client_ip = NULL;
            c_user[i].client_port = 0;
            c_user[i].client_info = NULL; }
            else get_the_command(sd, c_user, address, i);
	    } }
}
