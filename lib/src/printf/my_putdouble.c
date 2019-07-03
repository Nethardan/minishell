/*
** EPITECH PROJECT, 2018
** my_putfloat.c
** File description:
** print a float variable
*/

#include "my.h"

void my_putdouble(double lf)
{
    double i = 100000;
    int buff = lf;

    my_putnbr(buff);
    my_putchar('.');
    buff = (lf - buff) * i;
    if (buff == 0)
        my_putstr("000000");
    else
        my_putnbr(buff);
}
