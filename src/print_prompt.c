/*
** EPITECH PROJECT, 2019
** print_prompt.c
** File description:
** print_prompt
*/

#include "my.h"

void print_prompt(char **env)
{
    char *current_user = get_env_value("USER", "usr", env);
    char *pwd = get_env_value("PWD", "/", env);
    char **sep_pwd = my_str_to_word_array(pwd, "/");

    my_printf(".-[%s ~/%s]\n`--> ", current_user,
            sep_pwd[my_arrlen((void **)sep_pwd) - 1]);
    free(current_user);
    free(pwd);
    free_tab((void **)sep_pwd);
}