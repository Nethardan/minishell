/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** return the number of characters in the srting
*/

#include "my.h"

int my_strlen(char const *str)
{
    int str_len = 0;

    if (str == NULL)
        return (0);
    else
        for (int i = 0; str[i] != '\0'; i++)
            str_len += 1;
    return (str_len);
}

int my_strdelim(char const *str, char delim)
{
    int str_len = 0;

    if (str == NULL)
        return (0);
    else
        for (int i = 0; str[i] != delim; i++)
            str_len += 1;
    return (str_len);
}