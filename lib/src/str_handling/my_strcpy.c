/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** copy a string into an other
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    uint_t i = 0;

    if (!src)
        return (NULL);
    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
