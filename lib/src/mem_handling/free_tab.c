/*
** EPITECH PROJECT, 2019
** free_tab
** File description:
** free a void **
*/

#include "my.h"

void free_tab(void **tab)
{
    if (!tab)
        return;
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}