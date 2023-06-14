/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** desc
*/

#include "../includes/my.h"

void condition_findstart(setting_t *s, int i)
{
    if (my_strcmp(s->stock[i], "##start\n") == 0)
        s->start = my_strdup(s->stock[i + 1]);
    if (my_strcmp(s->stock[i], "##end\n") == 0)
        s->end = my_strdup(s->stock[i + 1]);
}

void find_start_end(setting_t *s, int i)
{
    for (i = 0; s->stock[i] != NULL; i++)
        if (s->stock[i][0] == '#' && s->stock[i][1] == '#')
            condition_findstart(s, i);
    for (size_t i = 0; s->start[i] != '\0'; i++)
        if (s->start[i] == ' ')
            s->start[i] = '\0';
    for (size_t i = 0; s->end[i] != '\0'; i++)
        if (s->end[i] == ' ')
            s->end[i] = '\0';
}

void free_function(setting_t *s)
{
    for (; *s->stock; s->stock++)
        free(*s->stock);
    for (; *s->clean_str; s->clean_str++)
        free(*s->clean_str);
}

int fs_open_file(setting_t *s, int j, int k)
{
    int fd = NULL;
    int read = 0;
    char *str = malloc(sizeof(char) * 100);
    for (j = 0; (read = getline(&str, &fd, stdin)) != -1; j++){
        s->stock[j] = my_strdup(str);
        stock_rooms(s, j);
    }
    traittement_string(s);
    if (j == 0 || print_res(s) == 84)
        return 84;
    find_start_end(s, j);
    if (s->stock[j - 1][my_strlen(s->stock[j - 1]) - 1] != '\n')
        s->stock[j - 1] = my_strcat(s->stock[j - 1], "\n");
    s->stock[j] = NULL;
    free(str);
    return 0;
}
