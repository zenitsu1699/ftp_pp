/*
** EPITECH PROJECT, 2021
** check_path.c
** File description:
** check_path
*/

#include "../inc/my_ftp.h"

int check_path(char *dir)
{
    DIR *dir_name = opendir(dir);

    if (!dir_name)
        return 84;
    return 0;
}

int check_file(char *file)
{
    int fd = open(file, O_RDONLY);
    if (fd == -1)
        return 84;
    close(fd);
    return 0;
}