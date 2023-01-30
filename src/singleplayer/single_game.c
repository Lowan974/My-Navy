/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-navy-sebastien.lucas
** File description:
** single_game.c
*/
#include "navy.h"
int fetch_level(games_infos *request);
void start_level(void);

int single_process(games_infos *request)
{
    srand(time(NULL));
    fill_ia_map(&request->p2);
    mini_printf("Choose your level:\nEasy: 1\nMedium: 2\nHard: 3\n:");
    return (fetch_level(request));
}

int fetch_level(games_infos *request)
{
    char *line;
    size_t len = 0;
    ssize_t lineSize = 0;
    lineSize = getline(&line, &len, stdin);
    while (1) {
        switch (line[0]) {
        case '1':
            mini_printf("You choose Easy level !\n\n");
            start_level();
            return easy_level(request);
        case '2':
            mini_printf("You choose Medium level !\n\n");
            start_level();
            return medium_level(request);
        case '3':
            mini_printf("You choose Hard level !\n\n");
            mini_printf("This mode is not fishined yet :(\n");
            start_level();
            return 3;
        default:
            mini_printf("Wrong level\n---\n");
            mini_printf("Choose your level:\nEasy: 1\nMedium: 2\nHard: 3\n");
            lineSize = getline(&line, &len, stdin);
        }
    }
    return 0;
}

void start_level(void)
{
    mini_printf("The game will start in : ");
    usleep(800000);
    mini_printf("3 ");
    usleep(800000);
    mini_printf("2 ");
    usleep(800000);
    mini_printf("1 ");
    usleep(800000);
    system("@cls||clear");
}
