/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-pushswap-lowan.ferraro
** File description:
** main.c
*/

#include "navy.h"
int game_mode(char **av, int ac, games_infos *request);
char current_message[33];

int main (int ac, char **av)
{
    if (usage(av, ac))
        return 0;
    games_infos *request = malloc(sizeof(games_infos));
    malloc_players(&request->p1);
    malloc_players(&request->p2);
    if (parsing(ac, av, request) == 84) {
        free_players(&request->p1);
        free_players(&request->p2);
        free(request);
        return 84;
    }
    return (game_mode(av, ac, request));
}

int usage(char **av, int ac)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        mini_printf("USAGE\n\t./navy [first_player_pid] navy_positions\n");
        mini_printf("DESCRIPTION\n\tfirst_player_pid: only for the 2nd player");
        mini_printf(". pid of the first player.\n");
        mini_printf("\tnavy_positions:");
        mini_printf("file representing the positions of the ships.\n");
        mini_printf("SINGLEPLAYER\n\tto play in singleplayer with a bot, ");
        mini_printf("use the following command:\n\t");
        mini_printf("./navy -singleplayer navy_positions\n");
        return 1;
    }
    return 0;
}

int game_mode(char **av, int ac, games_infos *request)
{
    if (my_strcmp(av[1], "-singleplayer") == 0 && ac == 3) {
        return (single_process(request));
    }
    if (ac == 2) {
        return (process1(request));
    } else if (ac == 3) {
        return (process2(request, av));
    }
    return 0;
}
