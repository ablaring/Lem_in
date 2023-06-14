/*
** EPITECH PROJECT, 2023
** Lemin
** File description:
** rooms.c
*/

#include "../../includes/my.h"

int stock_rooms(setting_t *s, int j)
{
    int i = 0;
    size_t t = 0;
    int lock = 0;
    for (i = 0; s->stock[j][i] != '\0'; i++)
        if (s->stock[j][i] == ' ' && s->stock[j][i + 1] != '\n')
            lock = 1;
    if (lock == 1 && s->stock[j][0] != '#' && s->stock[j][i + 1] != '\n') {
        s->rooms[s->nb_rooms] = malloc(sizeof(char) * my_strlen(s->stock[j]));
        for (; s->stock[j][t] != ' '; t++)
            s->rooms[s->nb_rooms][t] = s->stock[j][t];
        s->nb_rooms += 1;
    }
    s->rooms[s->nb_rooms] = NULL;
    return 0;
}
