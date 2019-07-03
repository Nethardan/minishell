/*
** EPITECH PROJECT, 2018
** disp_stdarg.c
** File description:
** dist arguments
*/

#include "my.h"

int error(va_list list, char const *format)
{
    int i = 0;

    if (format == NULL) {
        my_puterr("s IS A NULL STRING\n");
        i = -1;
    }
    return (i == -1 ? -1 : 0);
}

int disp_flags2(va_list list, char const *format, int i)
{
    double f;

    switch (format[i]) {
    case 'f':
        f = va_arg(list, double);
        my_putdouble(f);
        break;
    case 'l':
        if (format[i + 1] == 'f') {
            f = va_arg(list, double);
            my_putdouble(f);
            i++;
        }
        break;
    case '%':
        my_putchar('%');
        break;
    }
    return (i);
}

int disp_flags(va_list list, char const *format, int i)
{
    char c, *str;
    int d;
    double f;

    switch (format[i]) {
    case 'c':
        c = (char) va_arg(list, int);
        my_putchar(c);
        break;
    case 's':
        str = va_arg(list, char *);
        my_putstr(str == NULL ? "(null)" : str);
        break;
    case 'd':
        d = va_arg(list, int);
        my_putnbr(d);
        break;
    }
    return (disp_flags2(list, format, i));
}

int my_printf(char const *format, ...)
{
    va_list list;
    int i;

    va_start(list, format);
    i = error(list, format);
    va_end(list);
    if (i == -1)
        return (84);
    va_start(list, format);
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            i = disp_flags(list, format, i);
        } else
            my_putchar(format[i]);
    }
    va_end(list);
    return (0);
}
