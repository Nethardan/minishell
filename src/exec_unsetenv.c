/*
** EPITECH PROJECT, 2019
** exec_unsetenv.c
** File description:
** execute unsetenv
*/

#include "my.h"

static char **change_env(char *var, char **env)
{
    char **buffer;
    int nb_var = my_arrlen((void **)env);
    int j = 0;

    buffer = malloc(sizeof(char *) * (nb_var));
    for (int i = 0; env[i]; i++) {
        j += !my_strcmp(var, env[i + j]) ? 1 : 0;
        buffer[i] = my_strdup(env[i + j]);
    }
    buffer[nb_var - 1] = NULL;
    return (buffer);
}

char **unsetenv_loop(char **arr, char **env, int word)
{
    for (int i = 0; env[i] != NULL; i += 1) {
        if (my_strncmp(arr[word], env[i], my_strlen(arr[word])) == 0 &&
            env[i][my_strlen(arr[word])] == '=') {
            env = change_env(env[i], env);
            word += 1;
            i = 0;
        }
    }
    return (env);
}

int exec_unsetenv(char *str, char ***env)
{
    char **arr = my_str_to_word_array(str, " \n\t");
    int word = 1;

    if (!arr)
        return (0);
    if (arr[1] == NULL) {
        my_puterr("unsetenv: Too few arguments.\n");
        return (1);
    }
    *env = unsetenv_loop(arr, *env, word);
    return (0);
}
