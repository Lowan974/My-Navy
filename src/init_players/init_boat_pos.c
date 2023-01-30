/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** init_boat_pos.c
*/

#include "navy.h"

void add_to_struct(char **boat, char *buf, int i)
{
    boat[i][0] = buf[2];
    boat[i][1] = buf[3];
    boat[i][2] = buf[5];
    boat[i][3] = buf[6];
}
