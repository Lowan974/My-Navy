/*
** EPITECH PROJECT, 2022
** mini_pritnf
** File description:
** mini_printf.h
*/

#pragma once
    #include <stdarg.h>
    #include <unistd.h>
    int my_strlen(char const *str);
    char *my_revstr(char *str);
    int my_putstr(char const *str);
    int my_putnbr(long int nb);
    int my_putnbr_lli(long long int nb);
    void my_putchar(char c);
