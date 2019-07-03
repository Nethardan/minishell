/*
** EPITECH PROJECT, 2019
** print_arr.c
** File description:
** print_arr
*/

#include "my.h"

void print_arr(char **arr, char *delim)
{
    if (!arr)
        return;
    for (int i = 0; arr[i] != NULL; i++) {
        my_putstr(arr[i]);
        if (delim)
            my_putstr(delim);
    }
}