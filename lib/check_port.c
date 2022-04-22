/*
** EPITECH PROJECT, 2021
** check_number.c
** File description:
** Check the string ....
*/

#include "../inc/my_ftp.h"

int check_port(char *str)
{
    if (str[0] < '1' || str[0] > '9') return 84;
    for (int i = 1; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9') return 84;
        else if (i > 5) return 84;
    return 0;
}