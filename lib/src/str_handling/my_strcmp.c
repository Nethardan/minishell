/*
** EPITECH PROJECT, 2019
** my_strcmp.h
** File description:
** reproduce the behavior of str cmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    if (!s1 && !s2)
        return (0);
    if (!s1)
        return (-1);
    if (!s2)
        return (1);
    for (uint_t i = 0; s1[i] != '\0' || s2[i] != '\0'; i += 1) {
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (-1);
    }
    return (0);
}
