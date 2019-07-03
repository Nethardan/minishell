/*
** EPITECH PROJECT, 2019
** my_exit.c
** File description:
** my_exit
*/

#include "my.h"

char **my_exit(char const *str)
{
    char **arr = my_str_to_word_array(str, " \n\t");
    int nb_args = my_arrlen((void **)arr);

    if (nb_args > 2 || (arr[1] != NULL && is_number(arr[1]) == FALSE)) {
        free_tab((void **)arr);
        my_puterr("exit: Expression syntax.\n");
        return (NULL);
    }
    if (isatty(0))
        my_putstr("exit\n");
    return (arr);
}
