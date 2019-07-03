/*
** EPITECH PROJECT, 2019
** my_arr_cpy.c
** File description:
** copy an array
*/

#include "my.h"

char **my_arr_cpy(char **dest, char **src)
{
    int i = 0;

    for (; src[i]; i += 1)
        dest[i] = my_strdup(src[i]);
    dest[i] = NULL;
    return (dest);
}
