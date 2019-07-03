/*
** EPITECH PROJECT, 2019
** my_str_concat.c
** File description:
** cont two strings
*/

#include "my.h"

char *my_str_concat(char *s1, char c, char *s2)
{
    int s1_len = my_strlen(s1);
    int offset = c == '\0' ? 0 : 1;
    int size = s1_len + my_strlen(s2) + 1 + offset;
    char *str = NULL;

    if (!s1 && !s2)
        return (NULL);
    if (!s1 || !s2)
        return (s1 == NULL ? s2 : s1);
    str = malloc(sizeof(char) * (size + 1));
    for (int i = 0; str && i < size; i++)
        if (i < s1_len)
            str[i] = s1[i];
        else if ((i == s1_len) && (c != '\0'))
            str[i] = c;
        else
            str[i] = s2[i - s1_len - offset];
    if (str)
        str[size] = '\0';
    return (str);
}
