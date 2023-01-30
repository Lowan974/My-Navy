/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** TODO: add description
*/

#include "navy.h"

char *my_itoa(int nb)
{
    char *str = malloc(sizeof(char) * 3);
    int i = 0;
    for (; nb > 0; i++) {
        str[i] = nb % 10 + 48;
        nb /= 10;
    }
    str[i] = '\0';
    return (my_revstr(str));
}
