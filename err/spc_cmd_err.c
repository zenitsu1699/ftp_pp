/*
** EPITECH PROJECT, 2021
** spc_cmd_err.c
** File description:
** spc_cmd_err
*/

#include "../inc/my_ftp.h"

char *help_err(char *input)
{
    char *copy = clone_string(input);
    char **mystr = my_str_to_word_tab(input, " ");

    if (mystr[1] == NULL) return input;
    else if (mystr[2] != NULL) return NULL;
    return input;
}

char *list_err(char *input)
{
    char *copy = clone_string(input);
    char **mystr = my_str_to_word_tab(input, " ");

    if (mystr[1] == NULL) return input;
    else if (mystr[2] != NULL) return NULL;
    else if (check_path(mystr[1])) return NULL;
    return input;
}