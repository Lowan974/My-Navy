/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** medium_level.c
*/

#include "navy.h"

int medium_level(games_infos *request)
{
    int nb_round = 1;
    char *line;
    char *last_shoot = malloc(sizeof(char) * 2);
    int hit = 0;
    while (1) {
        mini_printf("\n==========\n-Round %d-\n==========\n\n", nb_round);
        mini_printf("Your Turn:\n\n");
        display_content(request->p1, request->p2);
        line = fetch_input();
        hit = shoot_status(&request->p2, line);
        modify_player_map(&request->p2, line, hit);
        display_hit_status(hit, line);
        mini_printf("Waiting for enemy's attack...\n");
        usleep(2000000);
        medium_attack(request, last_shoot, nb_round);
        if (end_game(request, last_shoot)) {
            return 1;
        }
        system("@cls||clear");
        nb_round++;
    }
}

int end_game(games_infos *request, char *last_shoot)
{
    if (win_condition(&request->p1, &request->p2) == 1) {
        free_players(&request->p1);
        free_players(&request->p2);
        free(last_shoot);
        free(request);
        return 1;
    }
    if (win_condition(&request->p1, &request->p2) == 2) {
        free_players(&request->p1);
        free_players(&request->p2);
        free(last_shoot);
        free(request);
        return 1;
    }
    return 0;
}

void medium_attack(games_infos *request, char *last_shoot, int nb_round)
{
    int hit;
    static int power = 0;
    char *hit_pos = malloc(sizeof(char) * 2);
    if (power == 5) {
        power = 0;
        get_not_destroyed_pos(&request->p1, hit_pos);
    } else if (nb_round > 1 && request->p1.map[1 + ((int)last_shoot[1] - 48)][2 + ((int)(last_shoot[0] - 65) * 2)] == 'x') {
        if (shoot_rand(&request->p1, (rand() % 4), 0, last_shoot) == 1) {
            power += 1;
            hit_pos[0] = last_shoot[0];
            hit_pos[1] = last_shoot[1];
        } else {
            power += 1;
            get_hit_pos(hit_pos, &request->p1);
        }
    } else {
        get_hit_pos(hit_pos, &request->p1);
    }
    hit = shoot_status(&request->p1, hit_pos);
    if (hit == 0)
        power += 1;
    modify_player_map(&request->p1, hit_pos, hit);
    display_hit_status(hit, hit_pos);
    last_shoot[0] = hit_pos[0];
    last_shoot[1] = hit_pos[1];
    usleep(1000000);
    free(hit_pos);
}

char *get_not_destroyed_pos(player *p, char *hit_pos)
{
    for (int i = 2; i < 10; i++) {
        for (int j = 2; j < 16; j += 2) {
            if (p->map[i][j] >= '2' && p->map[i][j] <= '5') {
                hit_pos[0] = p->map[0][j];
                hit_pos[1] = p->map[i][0];
                return hit_pos;
            }
        }
    }
    return hit_pos;
}