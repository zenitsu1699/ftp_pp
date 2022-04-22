/*
** EPITECH PROJECT, 2021
** get_the_command.c
** File description:
** get_the_command.c
*/

#include "../inc/my_ftp.h"

void get_the_command(int sd, the_data *c_user,
		     struct sockaddr_in address, int index)
{
    char *input = NULL;
    char **mystr = NULL;
    int addrlen = sizeof(address);

    input = get_input(sd);
    mystr = my_str_to_word_tab(input, " ");
    // while (bad_command(input) == NULL) {
    //     dprintf(sd, "%s", ERR_COMMAND);
    //     input = get_input(sd); }
    exec_cmd(sd, c_user, mystr, address, index);
}

void user_cmd(int sd, the_data *c_user, char **mystr,
	      struct sockaddr_in address, int index)
{
    if (strcmp(mystr[0], "USER") == 0) {
        if (c_user[index].client_info->user_pass == NULL) {
            if (mystr[1] == NULL) {
                dprintf(sd, "331 Permission denied.\n");
                return ; }
            else if (strcmp(mystr[1], "Anonymous") == 0) {
                c_user[index].client_info->user_name = clone_string("Anonymous");
                dprintf(sd, "331 Please specify the password.\n");
                return ; }
            else {
                c_user[index].client_info->user_name = clone_string(mystr[1]);
                dprintf(sd, "331 Please specify the password.\n");
                return ; } }
        else {
            dprintf(sd, "331 Can't change from guest user.\n");
            return ; }
    }
    else return ;
}

void pass_cmd(int sd, the_data *c_user, char **mystr,
	      struct sockaddr_in address, int index)
{
    if (strcmp(mystr[0], "PASS") == 0) {
        if (c_user[index].client_info->user_name == NULL &&
            c_user[index].client_info->user_pass == NULL) {
            dprintf(sd, "503 Login with USER first.\n");
            return ; }
        else if (strcmp(c_user[index].client_info->user_name, "Anonymous") == 0 &&
                 c_user[index].client_info->user_pass == NULL) {
            c_user[index].client_info->user_pass = clone_string("ok");
            dprintf(sd, "230 Login successful.\n");
            return ; }
        else if (c_user[index].client_info->user_pass != NULL) {
            dprintf(sd, "230 Already logged in.\n");
            return ; }
        else if (strcmp(c_user[index].client_info->user_name, "Anonymous") != 0 &&
                 c_user[index].client_info->user_pass == NULL) {
            c_user[index].client_info->user_pass = NULL;
            dprintf(sd, "530 Login incorrect.\n");
            return ; }
    }
    else return ;
}

void other_cmd(int sd, the_data *c_user, char **mystr,
	      struct sockaddr_in address, int index)
{
    if (bad_command(mystr[0]) == NULL) {
        if (c_user[index].client_info->user_pass == NULL) {
            dprintf(sd, "530 Please login with USER and PASS.\n");
            return ; }
        else {
            dprintf(sd, "500 Unknown command.\n");
            return ; } }
    else {
        if ((strcmp(mystr[0], "USER") == 0) || (strcmp(mystr[0], "PASS") == 0) ||
            (strcmp(mystr[0], "QUIT") == 0))
            return ;
        else if (c_user[index].client_info->user_pass == NULL) {
                dprintf(sd, "530 Please login with USER and PASS.\n");
                return ; } }
}

void quit_cmd(int sd, the_data *c_user, char **mystr,
	      struct sockaddr_in address, int index)
{
    if (strcmp(mystr[0], "QUIT") == 0) {
        dprintf(sd, "221 Goodbye.\n");
        close(sd);
        c_user[index].client_socket = 0;
        c_user[index].client_ip = NULL;
        c_user[index].client_port = 0;
        c_user[index].client_info = NULL;
        printf("Log Out of client n°%d\n", index); }
}

void help_cmd(int sd, the_data *c_user, char **mystr,
	      struct sockaddr_in address, int index)
{
    if (strcmp(mystr[0], "HELP") == 0 &&
        c_user[index].client_info->user_pass != NULL) {
        dprintf(sd, "214-The following commands are recognized.\n");
        dprintf(sd, " ABOR ACCT ALLO APPE CDUP CWD  DELE EPRT EPSV FEAT HELP LIST MDTM MKD\n");
        dprintf(sd, " MODE NLST NOOP OPTS PASS PASV PORT PWD  QUIT REIN REST RETR RMD  RNFR\n");
        dprintf(sd, " MODE NLST NOOP OPTS PASS PASV PORT PWD  QUIT REIN REST RETR RMD  RNFR\n");
        dprintf(sd, " RNTO SITE SIZE SMNT STAT STOR STOU STRU SYST TYPE USER XCUP XCWD XMKD\n");
        dprintf(sd, " XPWD XRMD\n");
        dprintf(sd, "214 Help OK.\n"); }
    else return ;
}

void pwd_cmd(int sd, the_data *c_user, char **mystr,
	      struct sockaddr_in address, int index)
{
    char *get_pwd = NULL;

    if (strcmp(mystr[0], "PWD") == 0 &&
        c_user[index].client_info->user_pass != NULL) {
            dprintf(sd, "257 %c%s%c\n", '"', c_user[index].path, '"');
            return ; }
    else return ;
}

void noop_cmd(int sd, the_data *c_user, char **mystr,
	      struct sockaddr_in address, int index)
{
    char *get_pwd = NULL;

    if (strcmp(mystr[0], "NOOP") == 0 &&
        c_user[index].client_info->user_pass != NULL) {
            dprintf(sd, "200 NOOP ok.\n");
            return ; }
    else return ;
}

void cdup_cmd(int sd, the_data *c_user, char **mystr,
	      struct sockaddr_in address, int index)
{
    char *get_pwd = NULL;

    if (strcmp(mystr[0], "CDUP") == 0 &&
        c_user[index].client_info->user_pass != NULL) {
            dprintf(sd, "250 Directory successfully changed.\n");
            return ; }
    else return ;
}

void exec_cmd(int sd, the_data *c_user, char **mystr,
	      struct sockaddr_in address, int index)
{
    user_cmd(sd, c_user, mystr, address, index);
    pass_cmd(sd, c_user, mystr, address, index);
    help_cmd(sd, c_user, mystr, address, index);
    pwd_cmd(sd, c_user, mystr, address, index);
    cdup_cmd(sd, c_user, mystr, address, index);
    noop_cmd(sd, c_user, mystr, address, index);
    other_cmd(sd, c_user, mystr, address, index);
    quit_cmd(sd, c_user, mystr, address, index);
}