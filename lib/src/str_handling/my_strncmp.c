/*
** EPITECH PROJECT, 2019
** my_strncmp.c
** File description:
** my str ncmp
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (s1 == NULL && s2 == NULL)
        return (0);
    if (s1 == NULL)
        return (-1);
    if (s2 == NULL)
        return (1);
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0' && i < n; i += 1) {
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (-1);
    }
    return (0);
}
