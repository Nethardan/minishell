/*
** EPITECH PROJECT, 2019
** is_number.c
** File description:
** return 1 if he string in param is a positiv number, else 0
*/

#include "my.h"

int is_number(char const *str)
{
    if (ISNUM(str[0]) == FALSE && str[0] != '-')
        return (FALSE);
    if (str[0] == '-' && (str[1] == '\n' || str[1] == '\0'))
        return (FALSE);
    for (uint_t i = 1; str[i] != '\n' && str[i]; i++)
        if (ISNUM(str[i]) == FALSE)
            return (FALSE);
    return (TRUE);
}
