/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-pushswap-lowan.ferraro
** File description:
** main.c
*/
#include "../../includes/navy.h"
int get_file_size(char *file_path);
int check_error(char *buf, int index);
int get_files_infos(char *file_path, player p);
int parcours_file(char *file_path, char *buf, int *i, player p);

int parsing(int ac, char **av, games_infos *request)
{
    int check_err = 0;
    int current_av = 2;
    if (ac == 2)
        current_av = 1;
    if (ac == 2 || ac == 3) {
        check_err = 1;
        if (get_files_infos(av[current_av], request->p1) == 84)
            return 84;
        create_maps(&request->p1, 1);
    }
    create_maps(&request->p2, 0);
    if (check_err == 0) {
        return 84;
    }
    return 0;
}

int parcours_file(char *file_path, char *buf, int *i, player p)
{
    FILE *file;
    size_t lines;
    file = fopen(file_path, "r");
    lines = 8;
    if (file == NULL)
        return 84;
    for (*i = 2; getline(&buf, &lines, file) != -1; *i += 1) {
        if (check_error(buf, *i) == 84) {
            fclose(file);
            return 84;
        }
        add_to_struct(p.boat_pos, buf, *i - 2);
    }
    fclose(file);
    return 0;
}

int get_files_infos(char *file_path, player p)
{
    int len;
    int i;
    char *buf;
    len = get_file_size(file_path);
    if (len == -1)
        return 84;
    buf = malloc(sizeof(char) * len);
    if (parcours_file(file_path, buf, &i, p) == 84) {
        free(buf);
        return 84;
    }
    if (i != 6) {
        free(buf);
        return 84;
    }
    free(buf);
    return 0;
}

int check_error(char *buf, int index)
{
    if ((int)(buf[0] - 48) != index) {
        return 84;
    }
    if (((int)buf[5] - (int)buf[2]) != index - 1) {
        if ((int)(buf[6] - 48) - (int)(buf[3] - 48) != index - 1) {
            return 84;
        }
    }
    if ((buf[2] < 65 || buf[2] > 72) || (buf[5] < 65 || buf[5] > 72)) {
        return 84;
    }
    if ((buf[3] < 49 || buf[3] > 57) || (buf[6] < 49 || buf[6] > 57)) {
        return 84;
    }
    return 0;
}

int get_file_size(char *file_path)
{
    int lenght = 0;
    int fd;
    char carac;
    fd = open(file_path, O_RDONLY);
    if (fd == -1)
        return -1;
    while (read(fd, &carac, 1)) {
        lenght++;
    }
    close(fd);
    return lenght;
}
