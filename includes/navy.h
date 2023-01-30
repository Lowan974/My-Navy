/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-pushswap-lowan.ferraro
** File description:
** navy.h
*/

#pragma once
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdio.h>
    #include <signal.h>
    #include <unistd.h>
    #include <time.h>

extern char current_message[33];

typedef struct {
    char **boat_pos;
    char **map;
    int hit_remaining;
} player;

typedef struct navy{
    player p1;
    player p2;
    int enemy_pid;
} games_infos;

int mini_printf (const char * format, ...);
int parsing(int ac, char **av, games_infos *request);
int usage(char **av, int ac);

//Singleplayer//
void fill_ia_map(player *p);
char *get_hit_pos(char *hit_pos, player *p);
int single_process(games_infos *request);
int easy_level(games_infos *request);

//Medium_LVL//
int medium_level(games_infos *request);
void medium_attack(games_infos *request, char *last_shoot, int nb_round);
int try_to_shoot(player *p, int direction, char *last_shoot);
int shoot_rand(player *p, int direction, int max_loop, char *last_shoot);
char *get_not_destroyed_pos(player *p, char *hit_pos);
int end_game(games_infos *request, char *last_shoot);

//Memory_handling//
void malloc_players(player *p);
void free_players(player *p);
//Init_players//
void create_maps(player *p, int arg);
void add_to_struct(char **boat, char *buf, int i);
void fill_map(player *p);
//In_battle//
int modify_player_map(player *p, char *hit_pos, int hit_status);
int shoot_status(player *p, char *hit_pos);
void display_hit_status(int hit_status, char *hit_pos);
void display_content(player p1, player p2);
int win_condition (player *p1, player *p2);
int player_one_loop(games_infos *request, char *line);
int player_two_loop(games_infos *request, char *line);
void attack(games_infos *request, char *line);
void defense(games_infos *request, char *line);
//Communication//
void connection_handler(int sig, siginfo_t *info, void *context);
char *str_to_signal(char *str);
char *signal_to_str(char *signal);
void send_sig(int sig, int pid);
void get_pid(int sig, siginfo_t *info, void *context);
void send_position(char *current_message, int pid);
void send_sig(int sig, int pid);
int is_connected(char *argv[]);
//Processus functions//
int process1(games_infos *request);
int process2(games_infos *request, char *argv[]);
//lib functions//
int my_strcmp(char *s1, char *s2);
int my_strlen(char *src);
int my_get_nbr(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_itoa(int nb);
int my_strisnum(char const *str);
char *my_strcpy(char *dest, char const *src);
//bin converter functions//
char *signal_to_str(char *signal);
char *str_to_signal(char *str);
char *int_to_bin(int num);
int binary_str_to_int(char* binary_str);
//Input//
char *fetch_input(void);
//ADDBOAT//
void add_vertical_boat(player *p, int i, int *count);
void add_horizontal_boat(player *p, int i, int *count);
void add_left_boat(player *p, int i, int *count);
void add_up_boat(player *p, int i, int *count);
