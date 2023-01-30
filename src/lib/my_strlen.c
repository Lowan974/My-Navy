/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** TODO: add description
*/

int my_strlen(char *src)
{
    int i = 0;
    while (src[i] != '\0')
        i++;
    return i;
}
