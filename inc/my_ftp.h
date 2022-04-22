/*
** EPITECH PROJECT, 2021
** myu_ftp.h
** File description:
** my_ftp
*/

#ifndef MYFTP_H
#define MYFTP_H

#include "my_lib.h"


char *clone_string(char *s);
int check_port(char *str);
char *get_input(int sd);
char **my_str_to_word_tab(char *input, char *c);
void usage(void);
int check_path(char *dir);
int check_file(char *file);


int bad_argument(char **av);
int nbr_of_argument(int ac, char **av);
int arg_error(int ac, char **av);
the_commands *_init_command(void);
void first_part_init(the_commands *my_cmd);
void second_part_init(the_commands *my_cmd);
char *bad_command(char *input);

char *pasv_err(char *input);
char *list_err(char *input);
char *help_err(char *input);
char *pwd_err(char *input);
char *quit_err(char *input);
char *noop_err(char *input);
char *cdup_err(char *input);
char *port_err(char *input);
char *pass_err(char *input);
char *user_err(char *input);
char *stor_err(char *input);
char *retr_err(char *input);
char *dele_err(char *input);
char *cwd_err(char *input);


int server(int port, char *path);
int accept_incoming_connection(int fd_socket, struct sockaddr_in *address);
void com_multi_clients(int *master_socket, the_data *c_user,
		       struct sockaddr_in address, fd_set *readfds);
void config_socket(int fd_socket, int port, struct sockaddr_in *address);
void get_max_sd(int *master_socket, the_data *c_user,
	        fd_set *readfds, int *max_sd);
void create_multi_connection_client(int *master_socket, the_data *c_user,
				    struct sockaddr_in address, fd_set *readfds);
int create_socket(void);
void initializing_the_queue(int fd_socket, int backlog);
the_data *all_the_clients(char *path);
void add_new_connection(the_data *c_user, int new_socket,
			struct sockaddr_in address, fd_set *readfds);


void get_the_command(int sd, the_data *c_user,
		     struct sockaddr_in address, int index);
exec_command *_init_cmd_exec(void);
void exec_cmd(int sd, the_data *c_user, char **mystr,
	      struct sockaddr_in address, int index);

#endif
