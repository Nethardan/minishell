/*
** EPITECH PROJECT, 2019
** minishell2.h
** File description:
** minishell2
*/

#ifndef MINISHELL2_H_
#define MINISHELL2_H_

int is_filetype(const char *filepath, mode_t ftype);
void print_signal(int signal);
int print_f_err(char *file, const char *cmd);

static const char *ERR_CD_F_D = ": No such file or directory.\n";
static const char *ERR_CD_ARGS = "cd: Too many arguments.\n";
static const char *ERR_N_DIR = ": Not a directory.\n";

#endif /* !MINISHELL2_H_ */
