/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** TODO: add description
*/

#include "navy.h"

char *my_strcat(char *dest, char const *src)
{
    unsigned int i = 0;
    unsigned int j = 0;

    while (dest[i])
        i++;
    while (src[j]) {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}
