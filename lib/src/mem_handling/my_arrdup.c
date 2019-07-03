/*
** EPITECH PROJECT, 2019
** my_arrdup
** File description:
** duplicate an array
*/

#include "my.h"

char **my_arrdup(char **arr)
{
    char **new = NULL;
    int i = 0;

    if (!arr)
        return (NULL);
    new = malloc(sizeof(char *) * (my_arrlen((void **)arr) + 1));
    for (; arr[i]; i++)
        new[i] = my_strdup(arr[i]);
    new[i] = NULL;
    return (new);
}