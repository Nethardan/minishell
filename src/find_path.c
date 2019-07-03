/*
** EPITECH PROJECT, 2019
** find_path.c
** File description:
** find the deferents pathes
*/

#include "my.h"

static int is_path(char *str)
{
    if (my_strncmp(str, "PATH=", 5) == 0)
        return (TRUE);
    return (FALSE);
}

char **find_path(char **env)
{
    int path_local;

    for (int i = 0; env[i] != NULL; i += 1)
        if (is_path(env[i]) == TRUE) {
            path_local = i;
            break;
        }
    return (my_str_to_word_array(env[path_local], "PATH=:"));
}
