/*
** EPITECH PROJECT, 2021
** connection_multi_clients.c
** File description:
** connection_multi_clients.c
*/

#include "../inc/my_ftp.h"

void get_max_sd(int *master_socket, the_data *c_user,
	        fd_set *readfds, int *max_sd)
{
    int sd = 0;

    *max_sd = *master_socket;
    for (int i = 0; i < MAX_CLIENTS; i++) {
      sd = c_user[i].client_socket;
      if (sd > 0)
        FD_SET(sd, readfds);
      if (sd > *max_sd)
        *max_sd = sd;
    }
}

void create_multi_connection_client(int *master_socket, the_data *c_user,
				    struct sockaddr_in address, fd_set *readfds)
{
    int max_sd = 0;
    int activity = 0;
    int new_socket = 0;
    char *message = "220 \r\n";

    FD_ZERO(readfds);
    FD_SET(*master_socket, readfds);
    get_max_sd(master_socket, c_user, readfds, &max_sd);
    activity = select(max_sd + 1, readfds, NULL, NULL, NULL);
    if ((activity < 0) && (errno!=EINTR)) printf("select error");
    if (FD_ISSET(*master_socket, readfds)) {
        new_socket = accept_incoming_connection(*master_socket, &address);
        printf("New connection , socket fd is %d , ip is : %s , port : %d \n" , new_socket ,
            inet_ntoa(address.sin_addr) , ntohs(address.sin_port));
        dprintf(new_socket, "%s", message);
        printf("Welcome message sent successfully\n");
        add_new_connection(c_user, new_socket, address, readfds); }
}
