/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** hit_condition.c
*/

#include "navy.h"

int modify_player_map(player *p, char *hit_pos, int hit_status)
{
    if (hit_status == 0 &&
    p->map[1 + ((int)hit_pos[1] - 48)][2 + ((int)(hit_pos[0] - 65) * 2)]
    != 'x') {
        p->map[1 + ((int)hit_pos[1] - 48)][2 + ((int)(hit_pos[0] - 65) * 2)] =
        'o';
        return 0;
    } else {
        p->hit_remaining -= 1;
        p->map[1 + ((int)hit_pos[1] - 48)][2 + ((int)(hit_pos[0] - 65) * 2)] =
        'x';
        return 1;
    }
}

int shoot_status(player *p, char *hit_pos)
{
    if (p->map[1 + ((int)hit_pos[1] - 48)][2 + ((int)(hit_pos[0] - 65) * 2)] ==
    'x') {
        return 0;
    }
    for (int i = 0; i < 4; i++) {
        if (p->boat_pos[i][0] == p->boat_pos[i][2]) {
            if (p->boat_pos[i][1] > p->boat_pos[i][3]) {
                if (hit_pos[1] <= p->boat_pos[i][1] && hit_pos[1] >= p->boat_pos[i][3] && hit_pos[0] == p->boat_pos[i][0]) {
                    return 1;
                }
            } else {
                if (hit_pos[1] >= p->boat_pos[i][1] && hit_pos[1] <= p->boat_pos[i][3] && hit_pos[0] == p->boat_pos[i][0]) {
                    return 1;
                }
            }
        }
        if (p->boat_pos[i][1] == p->boat_pos[i][3]) {
            if (p->boat_pos[i][0] > p->boat_pos[i][2]) {
                if (hit_pos[0] <= p->boat_pos[i][0] && hit_pos[0] >= p->boat_pos[i][2] && hit_pos[1] == p->boat_pos[i][1]) {
                    return 1;
                }
            } else {
                if (hit_pos[0] >= p->boat_pos[i][0] && hit_pos[0] <= p->boat_pos[i][2] && hit_pos[1] == p->boat_pos[i][1]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int win_condition (player *p1, player *p2)
{
    if (p1->hit_remaining == 0) {
        display_content(*p1, *p2);
        write(1, "Enemy won\n\n", 11);
        return 1;
    }
    if (p2->hit_remaining == 0) {
        display_content(*p1, *p2);
        write(1, "I won\n\n", 7);
        return 2;
    }
    return 0;
}
