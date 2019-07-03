/*
** EPITECH PROJECT, 2019
** is_filetype.c
** File description:
** return 1 if the file is the file is of the filetype, else return 0
*/

#include "my.h"
#include "minishell2.h"

int is_filetype(const char *filepath, mode_t ftype)
{
    struct stat st;
    if (stat(filepath, &st) == -1)
        return (0);
    if ((st.st_mode & __S_IFMT) == ftype)
        return (1);
    return (0);
}