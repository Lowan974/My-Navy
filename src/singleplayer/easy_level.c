/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** easy_level.c
*/

#include "navy.h"
void easy_attack(games_infos *request);

int easy_level(games_infos *request)
{
    int nb_round = 1;
    char *line;
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
        easy_attack(request);
        if (win_condition(&request->p1, &request->p2) == 1) {
            free_players(&request->p1);
            free_players(&request->p2);
            free(request);
            return 0;
        }
        if (win_condition(&request->p1, &request->p2) == 2) {
            free_players(&request->p1);
            free_players(&request->p2);
            free(request);
            return 1;
        }
        system("@cls||clear");
        nb_round++;
    }
}

void easy_attack(games_infos *request)
{
    int hit;
    char *hit_pos = malloc(sizeof(char) * 2);
    get_hit_pos(hit_pos, &request->p1);
    hit = shoot_status(&request->p1, hit_pos);
    modify_player_map(&request->p1, hit_pos, hit);
    display_hit_status(hit, hit_pos);
    usleep(1000000);
    free(hit_pos);
}

char *get_hit_pos(char *hit_pos, player *p)
{
    hit_pos[0] = ((rand() % 8)) + 65;
    hit_pos[1] = ((rand() % 8) + 1) + 48;
    if (p->map[1 + ((int)hit_pos[1] - 48)][2 + ((int)(hit_pos[0] - 65) * 2)] == 'o' ||
        p->map[1 + ((int)hit_pos[1] - 48)][2 + ((int)(hit_pos[0] - 65) * 2)] == 'x') {
            get_hit_pos(hit_pos, p);
    }
    return hit_pos;
}
