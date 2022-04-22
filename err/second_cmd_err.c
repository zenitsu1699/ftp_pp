/*
** EPITECH PROJECT, 2021
** second_cmd_err.c
** File description:
** second_cmd_err
*/

#include "../inc/my_ftp.h"

char *user_err(char *input)
{
    char *copy = clone_string(input);
    char **mystr = my_str_to_word_tab(input, " ");

    if (mystr[2] != NULL) return NULL;
    return input;
}

char *pass_err(char *input)
{
    char *copy = clone_string(input);
    char **mystr = my_str_to_word_tab(input, " ");

    if (mystr[2] != NULL) return NULL;
    return input;
}

char *port_err(char *input)
{
    char *copy = clone_string(input);
    char **mystr = my_str_to_word_tab(input, " ");

    if (mystr[2] != NULL) return NULL;
    return input;
}