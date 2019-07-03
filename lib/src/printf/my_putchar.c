/*
** EPITECH PROJECT, 2018
** my putchar
** File description:
** display one character
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
