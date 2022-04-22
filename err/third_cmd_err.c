/*
** EPITECH PROJECT, 2021
** third_cmd_err.c
** File description:
** third_cmd_err
*/

#include "../inc/my_ftp.h"

char *cwd_err(char *input)
{
    char *copy = clone_string(input);
    char **mystr = my_str_to_word_tab(input, " ");

    if (mystr[2] != NULL) return NULL;
    else if (check_path(mystr[1])) return NULL;
    return input;
}

char *dele_err(char *input)
{
    char *copy = clone_string(input);
    char **mystr = my_str_to_word_tab(input, " ");

    if (mystr[2] != NULL) return NULL;
    else if (check_file(mystr[1])) return NULL;
    return input;
}

char *retr_err(char *input)
{
    char *copy = clone_string(input);
    char **mystr = my_str_to_word_tab(input, " ");

    if (mystr[2] != NULL) return NULL;
    else if (check_file(mystr[1])) return NULL;
    return input;
}

char *stor_err(char *input)
{
    char *copy = clone_string(input);
    char **mystr = my_str_to_word_tab(input, " ");

    if (mystr[2] != NULL) return NULL;
    else if (check_file(mystr[1])) return NULL;
    return input;
}