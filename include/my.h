/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** include lib
*/

#ifndef MY_H_
#define MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdarg.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/wait.h>

enum tf {
    FALSE,
    TRUE
};

#define ISNUM(x) (x >= '0' && x <= '9' ? TRUE : FALSE)
#define ISALPHA(x) ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') \
                    ? TRUE : FALSE)
#define WLOWER(x, y) ((x) < (y) ? x : y)
#define WUPPER(x, y) ((x) > (y) ? x : y)
#define uint_t unsigned int
static char builtin[4][3] = { "ls\n", "ls " , "cd\n" , "cd "};

enum redir {
    LEFT, LEFT2, RIGHT, RIGHT2, PIPE, ELSE
};


void print_prompt(char **env);

// BUILTIN
char **my_exit(char const *str);
int exec_main(char *str, char **env);
int exec(char *str, char **env);
char **find_path(char **env);
int have_redirection(char *brut_command);
int make_redirection(char *brut_command, char **env);

int exec_cd(char *str, char ***env);

//ENVIROMENT
char *get_env_value(char *var, char *def, char **env);
int exec_setenv(char *str, char ***env);
int exec_unsetenv(char *str, char ***env);
char **setenv_val_and_var(char *var, char *val, char **env);

// ERROR
int p_error(char const *function_name);

// MEM HANDLING
void free_tab(void **tab);
char **my_arrdup(char **arr);

//String handling
int my_strlen(char const *str);
int my_strdelim(char const *str, char delim);

int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char **my_str_to_word_array(char const *str, char const *separ);
int is_number(char const *str);
int my_getnbr(char const *str);
char *my_str_cut(char *str, char *cut);
char *my_str_concat(char *s1, char c, char *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(const char *s);
char *my_strndup(const char *s, size_t n);
char *my_strsep(char *str, const char *delim);
char *str_moove(char *str, int start, int offset);


char **my_arr_cpy(char **dest, char **src);
int my_arrlen(void **arr);

//Print
void my_putstr(char const *str);
void my_puterr(char const *str);
void my_putchar(char c);
int my_putnbr(int nb);
void my_putdouble(double lf);
int my_printf(char const *format, ...);
void print_arr(char **arr, char *delim);

#endif
