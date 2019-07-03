/*
** EPITECH PROJECT, 2019
** my_str_to_word_array.c
** File description:
** str to a word array
*/

#include "my.h"

static int is_separ(char const c, char const *separ)
{
    int is_separ;

    for (uint_t i = 0; separ[i] != '\0'; i += 1) {
        is_separ = c == separ[i] ? 1 : 0;
        if (is_separ)
            return (1);
    }
    return (0);
}

static uint_t count_words(char const *str, char const *separ)
{
    uint_t nb_words = 0;

    if (!str || !separ)
        return (0);
    for (uint_t i = 0; str[i] != '\0'; i += 1)
        nb_words += (!is_separ(str[i], separ))
            && (is_separ(str[i + 1], separ) || str[i + 1] == '\0') ? 1 : 0;
    return (nb_words);
}

static int *get_allocsize(char const *str, char const *separ, uint_t nb_words)
{
    uint_t *alloc_size = NULL;
    uint_t size = 0;
    uint_t count = 0;
    uint_t prev = 0;

    if (!str || !separ)
        return (NULL);
    alloc_size = malloc(sizeof(uint_t) * (nb_words));
    for (uint_t i = 0; alloc_size && str[i] && count < nb_words; i += 1) {
        size += !is_separ(str[i], separ) ? 1 : 0;
        count += (!is_separ(str[i], separ)) && (is_separ(str[i + 1], separ)
                || str[i + 1] == '\0') ? 1 : 0;
        if (count != prev) {
            alloc_size[count - 1] = size;
            prev += 1;
            size = 0;
        }
    }
    return (alloc_size);
}

static char **alloc_array(char const *str, char const *separ, uint_t nb_words)
{
    char **array = NULL;
    uint_t *alloc_size = get_allocsize(str, separ, nb_words);

    if (!str || !separ || !alloc_size)
        return (NULL);
    array = malloc(sizeof(char *) * (nb_words + 1));
    for (uint_t i = 0; i < nb_words; i += 1) {
        array[i] = malloc(sizeof(char) * (alloc_size[i] + 1));
    }
    free(alloc_size);
    array[nb_words] = NULL;
    return (array);
}

char **my_str_to_word_array(char const *str, char const *separ)
{
    uint_t x = 0;
    uint_t y = 0;
    uint_t prev = 0;
    uint_t nb_words = count_words(str, separ);
    char **array = alloc_array(str, separ, nb_words);

    if (!str || !separ || !array)
        return (NULL);
    for (uint_t i = 0; str[i] && (y < nb_words); i += 1) {
        array[y][x] = !is_separ(str[i], separ) ? str[i] : array[y][x];
        x += !is_separ(str[i], separ) ? 1 : 0;
        y += (!is_separ(str[i], separ)) &&
            (is_separ(str[i + 1], separ) || str[i + 1] == '\0') ? 1 : 0;
        if (y != prev) {
            array[y - 1][x] = '\0';
            x = 0;
            prev += 1;
        }
    }
    return (array);
}
