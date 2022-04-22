/*
** EPITECH PROJECT, 2021
** the_client.c
** File description:
** the_client.c
*/

#include "../inc/my_ftp.h"

the_data *all_the_clients(char *path)
{
    the_data *c_user = NULL;

    c_user = malloc(sizeof(the_data) * MAX_CLIENTS);
    if (c_user == NULL) handle_error("malloc");
    for (int i = 0; i < MAX_CLIENTS; i++) {
        c_user[i].client_socket = 0;
        c_user[i].client_ip = NULL;
        c_user[i].client_port = 0;
        c_user[i].path = clone_string(path);
        c_user[i].client_info = NULL; }
    return c_user;
}

void add_new_connection(the_data *c_user, int new_socket,
			struct sockaddr_in address, fd_set *readfds)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (c_user[i].client_socket == 0) {
	    c_user[i].client_socket = new_socket;
	    c_user[i].client_ip = clone_string(inet_ntoa(address.sin_addr));
	    c_user[i].client_port = ntohs(address.sin_port);
        c_user[i].client_info = malloc(sizeof(the_data));
        if (c_user[i].client_info == NULL) handle_error("malloc");
        c_user[i].client_info->user_name = NULL;
        c_user[i].client_info->user_pass = NULL;
	    printf("Adding to list of sockets as %d\n" , i);
	    break; }
    }
}
