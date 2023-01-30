/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** TODO: add description
*/

#include "navy.h"

int my_strcmp(char *s1, char *s2)
{
    unsigned int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i = i + 1;
    return (s1[i] - s2[i]);
}
