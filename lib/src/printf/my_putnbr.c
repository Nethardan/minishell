/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** display the number given as a parameter
*/

#include "my.h"

int my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb *(-1);
    }
    if (nb > 9) {
        my_putnbr(nb / 10);
        my_putchar((nb % 10) + '0');
    } else {
        my_putchar(nb + '0');
        return (0);
    }
}
