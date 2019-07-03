/*
** EPITECH PROJECT, 2019
** exec_setenv.v
** File description:
** execute setenv
*/

#include "my.h"

char **setenv_val_and_var(char *var, char *val, char **env)
{
    char *setenv = NULL;
    char *command = my_str_concat(var, ' ', val);

    if (!val || !var || !env)
        return (NULL);
    setenv = my_strdup("setenv ");
    if (!setenv)
        return (NULL);
    exec_setenv(my_str_concat(setenv, '\0', command), &env);
    return (env);
}

static int setenv_error(char **arr, char **env, int count)
{
    if (count > 3) {
        my_puterr("setenv: Too many arguments.\n");
        return (84);
    }
    if (arr[1] == NULL)
        return (0);
    if (ISALPHA(arr[1][0]) == FALSE) {
        my_puterr("setenv: Variable name must begin with a letter.\n");
        return (84);
    }
    for (int i = 1; arr[1][i] != '\0'; i += 1)
        if (ISNUM(arr[1][i]) == FALSE && ISALPHA(arr[1][i]) == FALSE) {
            my_puterr("setenv: Variable name must contain alphanumeric");
            my_puterr(" characters.\n");
            return (84);
        }
    return (0);
}

static char **create_variable(char **array, char **env)
{
    char **buffer = NULL;
    int nb_var = my_arrlen((void **)env);
    int variable_len = my_strlen(array[1]) + my_strlen(array[2]) + 1;
    int i = 0;

    buffer = malloc(sizeof(char *) * (nb_var + 2));
    my_arr_cpy(buffer, env);
    buffer[nb_var] = malloc(sizeof(char) * (variable_len + 1));
    buffer[nb_var + 1] = NULL;
    for (; i < variable_len; i += 1)
        if (i < my_strlen(array[1]))
            buffer[nb_var][i] = array[1][i];
        else if (i == my_strlen(array[1]))
            buffer[nb_var][i] = '=';
        else
            buffer[nb_var][i] = array[2] == NULL ? '\0' :
                array[2][i - 1 - my_strlen(array[1])];
    buffer[nb_var][i] = '\0';
    free_tab((void **)env);
    return (buffer);
}

char **find_variable(char **env, char **array, char *str)
{
    for (int i = 0; env[i]; i += 1)
        if (my_strncmp(array[1], env[i], my_strlen(array[1]) - 1) == 0 &&
            env[i][my_strlen(array[1])] == '=') {
            exec_unsetenv(str, &env);
            env = create_variable(array, env);
            return (env);
        }
    env = create_variable(array, env);
    return (env);
}

int exec_setenv(char *str, char ***env)
{
    char **array =  my_str_to_word_array(str, " \n\t");
    int count = my_arrlen((void **)array);

    if (setenv_error(array, *env, count) == 84) {
        free_tab((void **)array);
        return (1);
    }
    if (count == 1) {
        print_arr(*env, "\n");
        free_tab((void **)array);
        return (0);
    }
    *env = find_variable(*env, array, str);
    free_tab((void **)array);
    return (0);
}
