/*
** EPITECH PROJECT, 2019
** my_str_cut.c
** File description:
** cut the end of a string
*/

#include "my.h"

static int is_cut(char c, char *cut)
{
    for (int i = 0; cut[i] != '\0'; i += 1)
        if (cut[i] == c)
            return (TRUE);
    return (FALSE);
}

char *my_str_cut(char *str, char *cut)
{
    if (str == NULL || cut == NULL)
        return (str);
    for (uint_t i = 0; str[i] != '\0'; i += 1)
        str[i] = is_cut(str[i], cut) == TRUE ? '\0' : str[i] ;
    return (str);
}
