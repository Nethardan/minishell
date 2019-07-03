/*
** EPITECH PROJECT, 2018
** fs_open_file
** File description:
** open a r-only file
*/

#include "my.h"
#include "minishell2.h"

void print_pwd(char *env)
{
    if (my_strncmp(env, "PWD", 3) == 0) {
        for (int i = 4; env[i] != '\0'; i += 1)
            my_putchar(env[i]);
        my_putchar('\n');
    }
}

int print(char *str, char **env)
{
    if (my_strcmp(str, "env\n") == 0)
        for (uint_t i = 0; env[i] != NULL; i += 1)
            my_printf("%s\n", env[i]);
    if (my_strcmp(str, "pwd\n") == 0)
        for (uint_t i = 0; env[i] != NULL; i += 1)
            print_pwd(env[i]);
    return (0);
}

int loop(char *str, char ***env)
{
    if (my_strcmp(str, "env\n") == 0 || my_strcmp(str, "pwd\n") == 0) {
        print(str, *env);
        return (0);
    }
    if (my_strncmp(str, "setenv\n", 7) == 0 ||
        my_strncmp(str, "setenv ", 7) == 0)
            return (exec_setenv(str, env));
    if (my_strncmp(str, "unsetenv\n", 9) == 0 ||
        my_strncmp(str, "unsetenv ", 9) == 0)
        return (exec_unsetenv(str, env));
    if (my_strncmp(str, "cd\n", 9) == 0 ||
        my_strncmp(str, "cd ", 9) == 0)
        return (exec_cd(str, env));
    return (exec_main(str, *env));
}

int main_loop(int ac, char **av, char **env, size_t n)
{
    char *str = NULL;
    int func_ret = 0;
    char **exit_ret = NULL;
    int cmd_ret = 0;

    do {
        if (my_strncmp(str, "exit\n", 5) == 0
            || my_strncmp(str, "exit ", 5) == 0)
            exit_ret = my_exit(str);
        else
            if (my_strlen(str) > 1)
                cmd_ret = loop(str, &env);
        if (exit_ret != NULL)
            return (exit_ret[1] == NULL ? 0 : my_getnbr(exit_ret[1]));
        if (isatty(0))
            print_prompt(env);
    } while ((func_ret = getline(&str, &n, stdin)) != -1);
    if (func_ret == -1 && isatty(0))
        my_putstr("exit\n");
    free(str);
    return (cmd_ret);
}

int main(int ac, char **av, char **env)
{
    char **new_env = my_arrdup(env);
    int return_val = 0;
    size_t n = 0;

    if (!new_env)
        return (84);
    return_val = main_loop(ac, av, new_env, n);
    free_tab((void **)new_env);
    return (return_val);
}
