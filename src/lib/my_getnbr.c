/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** my_getnbr.c
*/

int my_get_nbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;
    while (str[i] == '-') {
        neg *= -1;
        i++;
    }
    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        if (nb > 214748364 || (nb == 214748364 && str[i] > '7'))
            return 0;
        nb = nb * 10 + str[i] - 48;
    }
    return nb * neg;
}
