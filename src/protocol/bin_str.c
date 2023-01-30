/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** TODO: add description
*/

#include "navy.h"

char *int_to_bin(int num)
{
    int c;
    int d;
    int count;
    char *result;
    count = 0;
    result = malloc(sizeof(char) * 33);
    for (c = 31; c >= 0; c--) {
        d = num >> c;
        if (d & 1)
            *(result + count) = 1 + '0';
        else
            *(result + count) = 0 + '0';
        count++;
    }
    *(result + count) = '\0';
    return result;
}

int binary_str_to_int(char *binary_str)
{
    int result = 0;
    int len = my_strlen(binary_str);
    for (int i = 0; i < len; i++) {
        result = result << 1;
        if (binary_str[i] == '1')
            result = result | 1;
    }
    return result;
}
