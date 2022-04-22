/*
** EPITECH PROJECT, 2021
** get_input_client.c
** File description:
** get_input_client.c
*/

#include "../inc/my_ftp.h"

char *get_input(int sd)
{
    FILE *sd_file = NULL;
    size_t len;
    char *line = NULL;
    int i = 0;

    sd_file = fdopen(sd, "r");
    if (getline(&line, &len, sd_file) == -1)
        handle_error("getline");
    i = strlen(line);
    line[i - 2] = '\0';
    for (int k = 0; line[k] != '\0'; k++)
        if (line[k] == '\t') line[k] = ' ';
    return line;
}