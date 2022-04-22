/*
** EPITECH PROJECT, 2021
** clone_string.c
** File description:
** clone_string.c
*/

#include "../inc/my_ftp.h"

char *clone_string(char *s)
{
    char *str = NULL;
    int s_s = 0;

    for (; s[s_s] != '\0'; s_s++);
    str = malloc(sizeof(char) * (s_s + 1));
    if (str == NULL) return NULL;
    for (int k = 0; s[k] != '\0'; k++)
        str[k] = s[k];
    str[s_s] = '\0';
    return str;
}