/*
** EPITECH PROJECT, 2022
** Lemin
** File description:
** error_handling.c
*/

#include "../../includes/my.h"

int check_info(setting_t *s, int j)
{
    if (my_strcmp(s->clean_str[j], "##start\n") == 0){
        if (s->clean_str[j + 1] == NULL || s->clean_str[j + 1][0] == '#')
            return 84;
        s->check_start++;
    }
    if (my_strcmp(s->clean_str[j], "##end\n") == 0){
        if (s->clean_str[j + 1] == NULL || s->clean_str[j + 1][0] == '#')
            return 84;
        s->check_end++;
    }
    return 0;
}

int check_start_end(setting_t *s)
{
    s->check_start = 0;
    s->check_end = 0;
    for (int i = 0; s->rooms[i] != NULL; i++)
        if (my_strcmp(s->rooms[i], s->start) == 0)
            s->check_start++;
    for (int i = 0; s->rooms[i] != NULL; i++)
        if (my_strcmp(s->rooms[i], s->end) == 0)
            s->check_end++;
    if (s->check_start != 1 || s->check_end != 1)
        return 84;
    return 0;
}

int check_tunnel_end(setting_t *s, int i)
{
    int nb = 0;
    for (size_t j = 0; s->clean_str[i][j] != NULL; j++){
        if (s->clean_str[i][j] == '-'){
            nb = 1;
        }
    }
    if (nb == 0)
        return 84;
    return 0;
}

int print_end_res(setting_t *s, int nb_room, int i)
{
    if (i == 0)
        if (get_nb_ants(s) == 84)
            return 84;
    if (nb_room == 1){
        my_putstr("#rooms\n");
        s->check_room_before = 1;
    }
    my_printf("%s", s->clean_str[i]);
    return 0;
}
