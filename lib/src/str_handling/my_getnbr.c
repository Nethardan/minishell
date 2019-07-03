/*
** EPITECH PROJECT, 2018
** my getnbr
** File description:
** return a number sent to the function as a string
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int result = 0;
    int sign = 1;
    int len = my_strlen(str);

    for (uint_t i = 0; i < len; i += 1) {
        if (str[i] == '-')
            sign *= -1;
        if (ISNUM(str[i]) == TRUE){
            result *= 10;
            result += str[i] - 48;
        }
        if (ISNUM(str[i]) == TRUE && ISNUM(str[i + 1]) == FALSE)
            i = len;
    }
    return (result * sign);
}
