/*
** EPITECH PROJECT, 2021
** ar_error.c
** File description:
** arg_error
*/

#include "../inc/my_ftp.h"

int bad_argument(char **av)
{
    if (check_port(av[1])) {
        printf("Port invalid\n");
        return 84; }
    if (check_path(av[2])) {
        printf("Path invalid\n");
        return 84; }
    return 0;
}

int nbr_of_argument(int ac, char **av)
{
    if (ac == 1) {
        printf("Not enough arg\n");
        return 84; }
    else if (ac == 2) {
        if (!strcmp("-help", av[1])) {
            usage();
            return 0; }
        else return 84; }
    if (ac > 3) {
        printf("Too many args\n");
        return 84; }
    return 0;
}

int arg_error(int ac, char **av)
{
    if (nbr_of_argument(ac, av))
        return 84;
    else if (ac == 3)
        if (bad_argument(av)) return 84;
    return 0;
}