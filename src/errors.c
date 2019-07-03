/*
** EPITECH PROJECT, 2019
** errors.c
** File description:
** print errors
*/

#include "my.h"

int p_error(char const *function_name)
{
    perror(function_name);
    return (84);
}
