/*
** EPITECH PROJECT, 2019
** print_signal.c
** File description:
** print_signal
*/

#include "my.h"
#include "minishell2.h"

static const char *signal_mess[65] = {
    [0 ... 64] = NULL,
    [0] = "",
    [SIGHUP] = "Hangup",
    [SIGINT] = "\n",
    [SIGQUIT] = "Quit",
    [SIGILL] = "Illegal instruction",
    [SIGTRAP] = "Trace/BPT trap",
    [SIGABRT] = "Abort",
    [SIGBUS] = "Buss error",
    [SIGFPE] = "Floating exception",
    [SIGKILL] = "Killed",
    [SIGUSR1] = "User signal 1",
    [SIGSEGV] = "Segmentation fault",
    [SIGUSR2] = "User signal 2",
    [SIGPIPE] = "Broken pipe",
    [SIGALRM] = "Alarm clock",
    [SIGTERM] = "Terminated",
    [16] = "Stack limit exceeded",
    [SIGSTOP] = "",
    [SIGTSTP] = "",
    [SIGCONT] = "\nSuspended (signal)",
    [SIGCHLD] = "\nSuspended",
    [SIGTTIN] = "\nSuspended (tty input)",
    [SIGTTOU] = "\nSuspended (tty output",
    [SIGPOLL] = "",
    [SIGXCPU] = "Cputime limit exceeded",
    [SIGXFSZ] = "Filesize limit exceeded",
    [SIGVTALRM] = "Virtual time alarm",
    [SIGPROF] = "Profiling time alarm",
    [SIGWINCH] = "",
    [29] = "Pollable event occured",
    [SIGSYS] = "Bad system call",
    [61] = "Fourth Last Realtime Signal",
    [62] = "Third Last Realtime Signal",
    [63] = "Second Last Realtime Signal",
    [64] = "Last Realtime Signal",
};

void print_signal(int sig)
{
    const char *str = (sig > 64) ? NULL : signal_mess[sig];

    if (str)
        my_puterr(str);
    else if (sig >= 32 && sig <= 60)
        my_printf("Signal %d", sig);
}