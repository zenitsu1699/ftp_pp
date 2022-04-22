/*
** EPITECH PROJECT, 2021
** exec_command.c
** File description:
** exec_command
*/

#include "../inc/my_ftp.h"

// exec_command *_init_cmd_exec(void)
// {
//     exec_command *my_cmd = malloc(sizeof(exec_command) * 6);

//     if (my_cmd == NULL) handle_error("malloc");

//     return my_cmd;
// }

// void exec_cmd(int sd, the_data *c_user, char *input,
// 	      struct sockaddr_in address, int index)
// {
//     exec_command *my_cmd = _init_cmd_exec();
//     char *copy = clone_string(input);
//     char *token = NULL;

//     token = strtok(copy, " ");
//     for (int l = 0; l < 6; l++)
//         if (strcmp(token, my_cmd[l].cmd) == 0)
//             my_cmd[l].my_function(sd, c_user, input, address, index);
// }

