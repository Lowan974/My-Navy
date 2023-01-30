/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** TODO: add description
*/

#include "navy.h"

void get_pid(int sig, siginfo_t *info, void *context)
{
    my_strcat(current_message, my_itoa(info->si_pid));
}

void send_pid(void)
{
    int current_pid = getpid();
}

void connection_handler(int sig, siginfo_t *info, void *context)
{
    if (sig == SIGUSR1) {
        my_strcat(current_message, "0");
    } else {
        my_strcat(current_message, "1");
    }
}

void send_sig(int sig, int pid)
{
    int return_value = kill(pid, sig);
    while (return_value != 0)
        return_value = kill(pid, sig);
}

void send_position(char *current_message, int pid)
{
    struct timespec tim;
    struct timespec tim2;
    tim.tv_sec = 0;
    tim.tv_nsec = 10000L;
    for (int i = 0; i < 7; i++) {
        if (current_message[i] == '0') {
            send_sig(SIGUSR1, pid);
            nanosleep(&tim, &tim2);
        }
        if (current_message[i] == '1') {
            send_sig(SIGUSR2, pid);
            nanosleep(&tim, &tim2);
        }
    }
}
