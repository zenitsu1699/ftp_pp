/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "../inc/my_ftp.h"

int main(int ac, char **av)
{
    if (arg_error(ac, av)) return 84;
    server(atoi(av[1]), av[2]);

    return 0;
}
