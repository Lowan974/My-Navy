/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** TODO: add description
*/

#include "navy.h"

int player_one_loop(games_infos *request, char *line)
{
    while (1) {
        display_content(request->p1, request->p2);
        attack(request, line);
        defense(request, line);
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
    }
}

int player_two_loop(games_infos *request, char *line)
{
    while (1) {
        display_content(request->p1, request->p2);
        defense(request, line);
        attack(request, line);
        if (win_condition(&request->p1, &request->p2) == 1)
            return 0;
        if (win_condition(&request->p1, &request->p2) == 2)
            return 1;
    }
}
