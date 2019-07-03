/*
** EPITECH PROJECT, 2018
** my_puterr.c
** File description:
** print error message
*/

#include "my.h"

void my_puterr(char const *str)
{
    int len = my_strlen(str);

    if (str == NULL)
        return;
    write(2, str, len);
}
