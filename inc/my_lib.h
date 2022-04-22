/*
** EPITECH PROJECT, 2021
** my_lib.h
** File description:
** my_lib
*/

#ifndef MYLIB_H
#define MYLIB_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/un.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/time.h>

#include <dlfcn.h>
#include <gnu/lib-names.h>
#include <dirent.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TRUE   1
#define FALSE  0
#define MAX_CLIENTS 45

#define BACKLOG 25


#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

#define ERR_COMMAND "[410 Error] : Bad command  : Please tape '/help'.\n"

typedef struct info_server
{
    char *uuid_user;
    char *name_user;
} info_server;

typedef struct info_of_client
{
    char *user_name;
    char *user_pass;
}the_info, *infos;

typedef struct the_data_client
{
    int client_socket;
    char *client_ip;
    int client_port;
    char *path;
    the_info *client_info;
} the_data, *data_client;

typedef struct the_commands
{
    char *cmd;
    char *(*my_function)(char *input);
} the_commands;

typedef struct exec_command
{
    char *cmd;
    void (*my_function)(int sd, the_data *c_user, char *input,
            		struct sockaddr_in address, int index);
} exec_command;

#endif
