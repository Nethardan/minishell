/*
** EPITECH PROJECT, 2019
** get_env_value.c
** File description:
** get env value of the variable var
*/

/*
    If you want to get the value of the PWD you cant do :
        get_env_var("PWD", env);
*/
#include "my.h"

char *get_this_value(char *var, char *value)
{
    int varlen = my_strlen(var) + 1;
    int valuelen = my_strlen(value);
    char *buffer = malloc(sizeof(char) * (valuelen - varlen + 1));
    int i = 0;

    for (; value[varlen + i]; i++)
        buffer[i] = value[varlen + i];
    buffer[i] = '\0';
    return (buffer);
}

char *get_env_value(char *var, char *def, char **env)
{
    if (!var || !env)
        return (my_strdup(def));
    for (int i = 0; env[i]; i++)
        if (my_strncmp(var, env[i], my_strlen(var) - 1) == 0 &&
            env[i][my_strlen(var)] == '=')
            return (get_this_value(var, env[i]));
    return (my_strdup(def));
}