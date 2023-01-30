/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** TODO: add description
*/

#include "navy.h"

char *my_revstr(char *str)
{
    int i = 0;
    int str_len = 0;
    char tmp = ' ';

    str_len = my_strlen(str);
    while (i < (str_len / 2)) {
        tmp = str[i];
        str[i] = str[(str_len - i - 1)];
        str[(str_len - i - 1)] = tmp;
        i = i + 1;
    }
    return (str);
}
