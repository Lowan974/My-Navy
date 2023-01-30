/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** TODO: add description
*/

#include "navy.h"

void defense(games_infos *request, char *line)
{
    int hit;
    mini_printf("waiting for enemy's attack...\n");
    current_message[0] = '\0';
    while (my_strlen(current_message) != 7);
    line = signal_to_str(current_message);
    hit = shoot_status(&request->p1, line);
    modify_player_map(&request->p1, line, hit);
    usleep(1000);
    if (hit == 1) {
        send_sig(SIGUSR2, request->enemy_pid);
    } else {
        send_sig(SIGUSR1, request->enemy_pid);
    }
    display_hit_status(hit, line);
    free(line);
}

void attack(games_infos *request, char *line)
{
    int hit;
    line = fetch_input();
    current_message[0] = '\0';
    my_strcat(current_message, str_to_signal(line));
    send_position(current_message, request->enemy_pid);
    current_message[0] = '\0';
    pause();
    hit = (int) (current_message[0] - 48);
    modify_player_map(&request->p2, line, hit);
    display_hit_status(hit, line);
}

int process1(games_infos *request)
{
    char *line;
    struct sigaction sa;
    current_message[0] = '\0';
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &get_pid;
    current_message[0] = '\0';
    sigaction(SIGUSR1, &sa, NULL);
    mini_printf("my_pid: %d\n", getpid());
    mini_printf("waiting for enemy connection...\n\n");
    pause();
    request->enemy_pid = my_get_nbr(current_message);
    mini_printf("enemy connected\n\n");
    kill(request->enemy_pid, SIGUSR1);
    sa.sa_flags = SA_RESTART;
    sa.sa_sigaction = &connection_handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    return player_one_loop(request, line);
}

void battle_mode(struct sigaction *sa)
{
    current_message[0] = '\0';
    sa->sa_flags = SA_RESTART;
    sa->sa_sigaction = &connection_handler;
    sigaction(SIGUSR1, sa, NULL);
    sigaction(SIGUSR2, sa, NULL);
}

int process2(games_infos *request, char *argv[])
{
    char *line;
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &get_pid;
    sigaction(SIGUSR1, &sa, NULL);
    mini_printf("my pid = %d\n", getpid());
    int ennemy_pid = my_get_nbr(argv[1]);
    request->enemy_pid = ennemy_pid;
    current_message[0] = '\0';
    kill(ennemy_pid, SIGUSR1);
    usleep(1000);
    if (is_connected(argv) == 84)
        return 84;
    battle_mode(&sa);
    return player_two_loop(request, line);
}
