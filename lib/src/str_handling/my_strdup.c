/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** duplicate a string
*/

#include "my.h"

char *my_strdup(const char *s)
{
    int i = 0;
    char *new = NULL;

    if (!s)
        return (NULL);
    new = malloc(sizeof(char) * (my_strlen(s) + 1));
    if (new) {
        for (; s[i]; i++)
            new[i] = s[i];
        new[i] = '\0';
    }
    return (new);
}

char *my_strndup(const char *s, size_t n)
{
    int i = 0;
    char *new = NULL;

    if (!s)
        return (NULL);
    new = malloc(sizeof(char) * (n + 1));
    if (new) {
        for (int i = 0; s[i] && i < n; i++)
            new[i] = s[i];
        new[i] = '\0';
    }
    return (new);
}