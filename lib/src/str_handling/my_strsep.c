/*
** EPITECH PROJECT, 2019
** my_strsep
** File description:
** reproduce the strsep function
*/

#include "my.h"

static int is_delim(char c, const char *delim)
{
    for (int i = 0; delim[i]; i++)
        if (c == delim[i])
            return (1);
    return (0);
}

char *my_strsep(char *str, const char *delim)
{
    if (!str)
        return (NULL);
    if (!delim)
        return (str);

    for (int i = 0; str[i]; i++)
        if (is_delim(str[i], delim)) {
            str[i] = '\0';
            return (str);
        }
    return (str);
}