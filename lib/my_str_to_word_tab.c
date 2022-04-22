/*
** EPITECH PROJECT, 2021
** my_str_to_word_tab.c
** File description:
** my_str_to_word_tab.c
*/

#include "../inc/my_ftp.h"

char *_init_second_param(void)
{
    char *cc = NULL;

    cc = malloc(sizeof(char) * 2);
    if (cc == NULL) handle_error("malloc");
    cc[0] = '"';
    cc[1] = '\0';
    return cc;
}

char **my_str_to_word_tab(char *input, char *c)
{
    char **mystr = NULL;
    char *token = NULL;
    char *str = NULL;
    char *ss = NULL;
    char *my_clone = clone_string(input);
    int j = 0;

    for (j = 0, str = input; ; j++, str = NULL) {
        token = strtok(str, c);
        if (token == NULL) break; }
    mystr = malloc(sizeof(char *) * (j + 1));
    if (mystr == NULL) handle_error("malloc");
    for (int i = 0; ; i++, my_clone = NULL) {
        token = strtok(my_clone, c);
        if (token == NULL) break;
        mystr[i] = clone_string(token); }
    mystr[j] = NULL;
    return mystr;
}