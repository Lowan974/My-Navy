/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** memory.c
*/
#include "../../includes/navy.h"

void malloc_players(player *p)
{
    p->boat_pos = malloc(sizeof(char *) * 4);
    for (int i = 0; i < 4; i++) {
        p->boat_pos[i] = malloc(sizeof(char) * 4);
    }
    p->map = malloc(sizeof(char *) * 10);
    for (int i = 0; i < 10; i++) {
        p->map[i] = malloc(sizeof(char) * 18);
    }
}

void free_players(player *p)
{
    for (int i = 0; i < 4; i++) {
        free(p->boat_pos[i]);
    }
    free(p->boat_pos);
    free(p->map);
}
