/*
** EPITECH PROJECT, 2019
** str_moove.c
** File description:
** str_moove
*/

#include "my.h"

char *str_moove(char *str, int start, int offset)
{
    int len = my_strlen(str);

    if (start < 0 || start > len || offset >= 0) {
        str = NULL;
        my_puterr("str_moove: Error, check your arguments.\n");
        return (NULL);
    }
    for (int i = start; i < len + offset + 1; i++) {
        str[i] = str[i - offset];
    }
    return (str);
}