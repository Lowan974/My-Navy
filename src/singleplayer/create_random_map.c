/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** create_random_map.c
*/

#include "navy.h"
void create_random_pos(char **pos);
char **get_line_pos(char **pos, int i);
int check_pos_err(char **line_pos, int direct, int i);

void fill_ia_map(player *p)
{
    int boat_size = 0;
    create_random_pos(p->boat_pos);
}

void create_random_pos(char **pos)
{
    for (int i = 0; i < 4; i++) {
        get_line_pos(pos, i);
    }
}

char **get_line_pos(char **pos, int i)
{
    pos[i][0] = ((rand() % 8)) + 65;
    pos[i][1] = ((rand() % 8) + 1) + 48;
    while (check_pos_err(pos, (rand() % 4), i + 1) == 1) {
        pos[i][0] = ((rand() % 8)) + 65;
        pos[i][1] = ((rand() % 8) + 1) + 48;
    }
    return pos;
}

int check_pos_err(char **line_pos, int direct, int i)
{
    switch (direct) {
    case 0:
        if ((line_pos[i - 1][0] + i) > 'H') {
            return 1;
        }
        line_pos[i - 1][2] = line_pos[i - 1][0] + i;
        line_pos[i - 1][3] = line_pos[i - 1][1];
        return 0;
    case 1:
        if ((line_pos[i - 1][1] + i) > '8') {
            return 1;
        }
        line_pos[i - 1][2] = line_pos[i - 1][0];
        line_pos[i - 1][3] = line_pos[i - 1][1] + i;
        return 0;
    case 2:
        if ((line_pos[i - 1][0] - i) < 'A') {
            return 1;
        }
        line_pos[i - 1][2] = line_pos[i - 1][0] - i;
        line_pos[i - 1][3] = line_pos[i - 1][1];
        return 0;
    case 3:
        if ((line_pos[i - 1][1] - i) < '1') {
            return 1;
        }
        line_pos[i - 1][2] = line_pos[i - 1][0];
        line_pos[i - 1][3] = line_pos[i - 1][1] - i;
        return 0;
    default:
        return 0;
    }
}
