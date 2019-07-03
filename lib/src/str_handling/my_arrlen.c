/*
** EPITECH PROJECT, 2019
** my_arrlen.c
** File description:
** count the number of string in an array
*/

#include "my.h"

int my_arrlen(void **arr)
{
    int i = 0;

    if (!arr)
        return (0);
    for (; arr[i]; i++);
    return (i);
}