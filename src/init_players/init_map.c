/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** init_map.c
*/

#include "navy.h"

void create_maps(player *p, int arg)
{
    p->map[0] = " |A B C D E F G H";
    p->map[1] = "-+---------------";
    for (int i = 1; i < 9; i++) {
        p->map[i + 1][0] = (char)(i + 48);
        p->map[i + 1][1] = '|';
        for (int j = 0; j < 15; j++) {
            p->map[i + 1][j + 2] = (j % 2 == 0 ? '.' : ' ');
        }
    }
    if (arg == 1) {
        fill_map(p);
    }
    p->hit_remaining = 14;
}

void fill_map(player *p)
{
    int count = 0;
    for (int i = 0; i < 4; i++) {
        count = 0;
        if (p->boat_pos[i][0] == p->boat_pos[i][2]) {
            if (p->boat_pos[i][3] > p->boat_pos[i][1]) {
                add_vertical_boat(p, i, &count);
            } else {
                add_up_boat(p, i, &count);
            }
        }
        if (p->boat_pos[i][1] == p->boat_pos[i][3]) {
            if (p->boat_pos[i][2] > p->boat_pos[i][0]) {
                add_horizontal_boat(p, i, &count);
            } else {
                add_left_boat(p, i, &count);
            }
        }
    }
}

void add_vertical_boat(player *p, int i, int *count)
{
    for (int j = 0; j <= ((int)(p->boat_pos[i][3]) -
                            (int)(p->boat_pos[i][1])); j++) {
        p->map[((int)p->boat_pos[i][1] + 1 - 48) + *count]
        [2 + (((int)p->boat_pos[i][0] - 65) * 2)] =
            (char)((i + 2) + 48);
        *count += 1;
    }
}

void add_horizontal_boat(player *p, int i, int *count)
{
    for (int x = 0; x <= ((int)(p->boat_pos[i][2]) -
                            (int)(p->boat_pos[i][0])); x++) {
        p->map[((int)p->boat_pos[i][1] + 1 - 48)]
        [2 + (((int)p->boat_pos[i][0] - 65) * 2) + *count] =
            (char)((i + 2) + 48);
        *count += 2;
    }
}

void add_left_boat(player *p, int i, int *count)
{
    for (int x = 0; x >= ((int)(p->boat_pos[i][2]) -
                            (int)(p->boat_pos[i][0])); x--) {
        p->map[((int)p->boat_pos[i][1] + 1 - 48)]
        [2 + (((int)p->boat_pos[i][0] - 65) * 2) + *count] =
            (char)((i + 2) + 48);
        *count -= 2;
    }
}

void add_up_boat(player *p, int i, int *count)
{
    for (int j = 0; j >= ((int)(p->boat_pos[i][3]) -
                            (int)(p->boat_pos[i][1])); j--) {
        p->map[((int)p->boat_pos[i][1] + 1 - 48) + *count]
        [2 + (((int)p->boat_pos[i][0] - 65) * 2)] =
            (char)((i + 2) + 48);
        *count -= 1;
    }
}
