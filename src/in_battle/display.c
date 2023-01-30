/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** display.c
*/
#include "navy.h"

void display_content(player p1, player p2)
{
    write(1, "my positions:\n", 14);
    for (int i = 0; i < 10; i++) {
        write(1, p1.map[i], 18);
        write(1, "\n", 1);
    }
    write(1, "\nenemy's positions:\n", 21);
    for (int i = 0; i < 10; i++) {
        write(1, p2.map[i], 18);
        write(1, "\n", 1);
    }
    write(1, "\n", 1);
}

void display_hit_status(int hit_status, char *hit_pos)
{
    hit_pos[2] = '\0';
    if (hit_status) {
        mini_printf("%s: hit\n\n", hit_pos);
    } else {
        mini_printf("%s: missed\n\n", hit_pos);
    }
}

int is_connected(char *argv[])
{
    if (my_strcmp(argv[1], current_message) == 0) {
        mini_printf("successfully connected\n\n");
        return 0;
    } else {
        mini_printf("wrong PID");
        return 84;
    }
}
