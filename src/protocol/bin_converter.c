/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** TODO: add description
*/

#include "navy.h"
int binary_to_nb(char *signal);
int str_to_nb(char *str);

char *signal_to_str(char *signal)
{
    char *str = malloc(sizeof(char) * 3);
    int nbr = binary_to_nb(signal);
    int count = 0;
    while ((nbr - 8) > 0) {
        nbr -= 8;
        count++;
    }
    str[0] = 65 + count;
    str[1] = nbr + 48;
    str[2] = '\0';
    return (str);
}

char *str_to_signal(char *str)
{
    char *signal = malloc(sizeof(char) * 7);
    int nbr = str_to_nb(str);
    int multiple = 64;
    int i = 0;
    for (i; i < 7; i++) {
        if (nbr >= multiple) {
            nbr -= multiple;
            signal[i] = '1';
        } else {
            signal[i] = '0';
        }
        multiple /= 2;
    }
    return signal;
}

int binary_to_nb(char *signal)
{
    int nb = 0;
    int multiple = 64;
    for (int i = 0; i < 8; i++) {
        nb += (int)(signal[i] - 48) * multiple;
        multiple /= 2;
    }
    return nb;
}

int str_to_nb(char *str)
{
    return (int)(((str[0] - 65)) * 8) + (str[1] - 48);
}
