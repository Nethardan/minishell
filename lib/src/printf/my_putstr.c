/*
** EPITECH PROJECT, 2018
** my putchar
** File description:
** display one character
*/

#include "my.h"

void my_putstr(char const *str)
{
    int len = my_strlen(str);

    if (str == NULL)
        return;
    write(1, str, len);
}
