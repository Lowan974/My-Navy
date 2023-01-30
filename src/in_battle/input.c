/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** input
*/

#include "navy.h"

char *fetch_input(void)
{
    char *line;
    mini_printf("attack: ");
    size_t len = 0;
    ssize_t lineSize = 0;
    lineSize = getline(&line, &len, stdin);
    while (!(line[0] >= 'A' && line[0] <= 'H') || !(line[1] >= '1' &&
    line[1] <= '8') || (lineSize - 1) != 2) {
        mini_printf("wrong position\n");
        mini_printf("attack: ");
        lineSize = getline(&line, &len, stdin);
    }
    return line;
}
