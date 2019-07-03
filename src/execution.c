/*
** EPITECH PROJECT, 2019
** execution.c
** File description:
** execute builtins and binaries
*/

#include "my.h"
#include "minishell2.h"

static int exec_error(char *str)
{
    if (str == NULL || my_strcmp(str, "\n") == 0)
        return (84);
    if (access(my_str_cut(str, " \n\t"), F_OK) == -1) {
        my_printf("%s: Command not found.\n", my_str_cut(str, " \n\t"));
        return (84);
    }
    if (access(my_str_cut(str, " \n\t"), X_OK) == -1) {
        my_printf("%s: Permission denied.\n", my_str_cut(str, " \n\t"));
        return (84);
    }
    return (0);
}

static int fork_execution(char **command, char **env, char *exec)
{
    pid_t cpid;
    int wstatus = 0;

    cpid = fork();
    if (cpid == -1)
        return (p_error("fork"));
    if (cpid == 0) {
        execve(command[0], command, env);
    } else
        if (wait(&wstatus) == -1)
            return (p_error("wait"));
        if (WIFEXITED(wstatus)) {
            return (WEXITSTATUS(wstatus));
    } else if (WIFSIGNALED(wstatus)) {
        print_signal(WTERMSIG(wstatus));
        my_puterr(__WCOREDUMP(wstatus) ? " (core dumpt)\n" : "\n");
        return (wstatus);
    }
    return (0);
}

static int exec_str(char **command, char **env, char *exec)
{
    int ret;
    struct stat st;

    if (stat(command[0], &st) == -1) {
        my_puterr("Error: stat failed.\n");
        return (1);
    }
    if (access(command[0], X_OK) == -1 || S_ISDIR(st.st_mode)) {
        free_tab((void **)command);
        print_f_err(exec, ": Permission denied.\n");
        free(exec);
        return (1);
    }
    ret = fork_execution(command, env, exec);
    free_tab((void **)command);
    free(exec);
    return (ret);
}

int exec(char *str, char **env)
{
    char *p = get_env_value("PATH", "/usr/bin:/bin", env);
    char **path = my_str_to_word_array(p, ":");
    char **command = my_str_to_word_array(str, "\n\t ");
    char *exec = my_strdup(command[0]);

    if (access(command[0], F_OK) == 0) {
        free_tab((void **)path);
        free(p);
        return (exec_str(command, env, exec));
    }
    for (int i = 0; path[i]; i++) {
        free(command[0]);
        command[0] = my_str_concat(path[i], '/', exec);
        if (access(command[0], F_OK) == 0) {
            free_tab((void **)path);
            free(p);
            return (exec_str(command, env, exec));
        }
    }
    my_printf("%s: Command not found.\n", exec);
    free_tab((void **)path);
    free(p);
    return (1);
}

int exec_main(char *str, char **env)
{
    char **multiple_exec = my_str_to_word_array(str, ";");
    int exec_ret = 0;

    for (int i = 0; str && multiple_exec[i]; i++)
        exec_ret = exec(multiple_exec[i], env);
    free_tab((void **)multiple_exec);
    return (exec_ret);
}