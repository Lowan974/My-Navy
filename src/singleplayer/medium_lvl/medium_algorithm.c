/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** medium_algorithm.c
*/

#include "navy.h"

int shoot_rand(player *p, int direction, int max_loop, char *last_shoot)
{
    if (max_loop == 4)
        return 0;
    switch (direction)
    {
    case 0:
        if (try_to_shoot(p, direction, last_shoot) == 0) {
            shoot_rand(p, 1, max_loop + 1, last_shoot);
        } else {
            last_shoot[0] += 1;
            return 1;
        }
        break;
    case 1:
        if (try_to_shoot(p, direction, last_shoot) == 0) {
            shoot_rand(p, 2, max_loop + 1, last_shoot);
        } else {
            last_shoot[1] += 1;
            return 1;
        }
        break;
    case 2:
        if (try_to_shoot(p, direction, last_shoot) == 0) {
            shoot_rand(p, 3, max_loop + 1, last_shoot);
        } else {
            last_shoot[0] -= 1;
            return 1;
        }
        break;
    case 3:
        if (try_to_shoot(p, direction, last_shoot) == 0) {
            shoot_rand(p, 0, max_loop + 1, last_shoot);
        } else {
            last_shoot[1] -= 1;
            return 1;
        }
        break;
    default:
        break;
    }
}

int try_to_shoot(player *p, int direction, char *last_shoot)
{
    if (direction == 0) {
        if (p->map[0][2 + ((int)(last_shoot[0] - 65) * 2)] == 'H' ||
            p->map[1 + ((int)last_shoot[1] - 48)][4 + ((int)(last_shoot[0] - 65) * 2)] == 'x' ||
            p->map[1 + ((int)last_shoot[1] - 48)][4 + ((int)(last_shoot[0] - 65) * 2)] == 'o') {
            return 0;
        }
    }
    if (direction == 1) {
        if (p->map[1 + ((int)last_shoot[1] - 48)][0] == '8' ||
        p->map[2 + ((int)last_shoot[1] - 48)][2 + ((int)(last_shoot[0] - 65) * 2)] == 'x' ||
        p->map[2 + ((int)last_shoot[1] - 48)][2 + ((int)(last_shoot[0] - 65) * 2)] == 'o') {
            return 0;
        }
    }
    if (direction == 2) {
        if (p->map[1 + ((int)last_shoot[1] - 48)][((int)(last_shoot[0] - 65) * 2)] == '|' ||
        p->map[1 + ((int)last_shoot[1] - 48)][((int)(last_shoot[0] - 65) * 2)] == 'x' ||
        p->map[1 + ((int)last_shoot[1] - 48)][((int)(last_shoot[0] - 65) * 2)] == 'o') {
            return 0;
        }
    }
    if (direction == 3) {
        if (p->map[((int)last_shoot[1] - 48)][2 + ((int)(last_shoot[0] - 65) * 2)] == '-' ||
        p->map[((int)last_shoot[1] - 48)][2 + ((int)(last_shoot[0] - 65) * 2)] == 'x' ||
        p->map[((int)last_shoot[1] - 48)][2 + ((int)(last_shoot[0] - 65) * 2)] == 'o') {
            return 0;
        }
    }
}
