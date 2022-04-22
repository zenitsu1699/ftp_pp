/*
** EPITECH PROJECT, 2021
** first_cmd_err.c
** File description:
** first_cmd_err
*/

#include "../inc/my_ftp.h"

char *cdup_err(char *input)
{
    char *copy = clone_string(input);
    char **mystr = my_str_to_word_tab(input, " ");

    if (mystr[1] != NULL) return NULL;
    return input;
}

char *noop_err(char *input)
{
    char *copy = clone_string(input);
    char **mystr = my_str_to_word_tab(input, " ");

    if (mystr[1] != NULL) return NULL;
    return input;
}

char *quit_err(char *input)
{
    char *copy = clone_string(input);
    char **mystr = my_str_to_word_tab(input, " ");

    if (mystr[1] != NULL) return NULL;
    return input;
}

char *pwd_err(char *input)
{
    char *copy = clone_string(input);
    char **mystr = my_str_to_word_tab(input, " ");

    if (mystr[1] != NULL) return NULL;
    return input;
}

char *pasv_err(char *input)
{
    char *copy = clone_string(input);
    char **mystr = my_str_to_word_tab(input, " ");

    if (mystr[1] != NULL) return NULL;
    return input;
}