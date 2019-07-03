/*
** EPITECH PROJECT, 2019
** exec_cd.c
** File description:
** exec_cd
*/

#include "my.h"
#include "minishell2.h"

int print_f_err(char *file, const char *cmd)
{
    my_puterr(file);
    my_puterr(cmd);
    return (1);
}

int cd_errors(char **cmd, char **env, char *last_directory)
{
    if (my_arrlen((void **)cmd) > 2) {
        my_puterr(ERR_CD_ARGS);
        return (1);
    }
    if (!my_strcmp(cmd[1], "-")) {
        if (!last_directory)
            return (print_f_err(NULL, ERR_CD_F_D));
        return (0);
    } else if (cmd[1]) {
        if (access(cmd[1], F_OK) == -1)
            return (print_f_err(cmd[1], ERR_CD_F_D));
        if (!is_filetype(cmd[1], __S_IFDIR))
            return (print_f_err(cmd[1], ERR_N_DIR));
    }
    return (0);
}

int exec_cd(char *str, char ***env)
{
    char **cmd = my_str_to_word_array(str, " \n\t");
    static char *last_d = NULL;
    char *buffer = NULL;

    if (cd_errors(cmd, *env, last_d))
        return (1);
    last_d = !last_d ? get_env_value("PWD", "/", *env) : last_d;
    if (!cmd[1]) {
        buffer = get_env_value("HOME", "/", *env);
    } else if (!my_strcmp(cmd[1], "-")) {
        buffer = my_strdup(last_d);
    } else {
        chdir(cmd[1]);
        buffer = getcwd(buffer, FILENAME_MAX);
    }
    last_d = !my_strcmp(buffer, get_env_value("PWD", "/", *env)) ?
                    last_d : get_env_value("PWD", "/", *env);
    *env = setenv_val_and_var("PWD", buffer, *env);
    chdir(buffer);
    free_tab((void **)cmd);
    return (0);
}