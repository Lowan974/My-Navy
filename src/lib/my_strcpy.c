/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** TODO: add description
*/

#include "navy.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    for (; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
