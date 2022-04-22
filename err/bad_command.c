/*
** EPITECH PROJECT, 2021
** bad_command.c
** File description:
** bad_command.c
*/

#include "../inc/my_ftp.h"

void first_part_init(the_commands *my_cmd)
{
    my_cmd[0].cmd = clone_string("LIST");
    my_cmd[1].cmd = clone_string("HELP");
    my_cmd[2].cmd = clone_string("CWD");
    my_cmd[3].cmd = clone_string("CDUP");
    my_cmd[4].cmd = clone_string("DELE");
    my_cmd[5].cmd = clone_string("QUIT");
    my_cmd[6].cmd = clone_string("PWD");
    my_cmd[7].cmd = clone_string("NOOP");
    my_cmd[8].cmd = clone_string("RETR");
    my_cmd[9].cmd = clone_string("STOR");
    my_cmd[10].cmd = clone_string("USER");
    my_cmd[11].cmd = clone_string("PASS");
    my_cmd[12].cmd = clone_string("PORT");
    my_cmd[13].cmd = clone_string("PASV");
}

void second_part_init(the_commands *my_cmd)
{
    my_cmd[0].my_function = &list_err;
    my_cmd[1].my_function = &help_err;
    my_cmd[2].my_function = &cwd_err;
    my_cmd[3].my_function = &cdup_err;
    my_cmd[4].my_function = &dele_err;
    my_cmd[5].my_function = &quit_err;
    my_cmd[6].my_function = &pwd_err;
    my_cmd[7].my_function = &noop_err;
    my_cmd[8].my_function = &retr_err;
    my_cmd[9].my_function = &stor_err;
    my_cmd[10].my_function = &user_err;
    my_cmd[11].my_function = &pass_err;
    my_cmd[12].my_function = &port_err;
    my_cmd[13].my_function = &pasv_err;
}

the_commands *_init_command(void)
{
    the_commands *my_cmd = malloc(sizeof(the_commands) * 14);

    if (my_cmd == NULL) handle_error("malloc");
    first_part_init(my_cmd);
    second_part_init(my_cmd);
    return my_cmd;
}

char *bad_command(char *input)
{
    the_commands *my_cmd = _init_command();

    for (int l = 0; l < 14; l++)
        if (strcmp(input, my_cmd[l].cmd) == 0)
            return input;
    return NULL;
}