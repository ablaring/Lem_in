/*
** EPITECH PROJECT, 2023
** desc
** File description:
** algo.c
*/

#include "../../includes/my.h"

bool algo_suite(setting_t *s, int i, int j, int k)
{
    for (size_t j = 0; s->tunnel[i][j] != NULL; j++){
        if (my_strcmp(s->end, s->tunnel[i][j]) == 0){
            s->tunnel[i][j] = "encule";
            free(s->start);
            s->start = my_strdup(s->tunnel[i][j]);
            fill_previous_tab(s, &k);
            return true;
        }
    }
    return false;
}

bool find_tunel_cut(setting_t *s, int i, int j, int k)
{
    if (s->tunnel[i] == NULL)
        return false;
    if (s->tunnel[i][0] != NULL &&
    my_strcmp(s->start, s->tunnel[i][0]) == 0)
        return algo_suite(s, i, j, k);
    else
        find_tunel_cut(s, i + 1, 0, k);
    return false;
}

void tunnel_check(setting_t *s,int *lock, int i)
{
    for (size_t j = 0; s->clean_str[i][j] != NULL; j++){
        if (s->clean_str[i][j] == '-'){
            *lock = 1;
        }
    }
    if (*lock == 1 && s->check_room_before == 1)
        my_putstr("#tunnels\n");
}

void end_print_res(setting_t *s, int i, int lock)
{
    if (s->clean_str[i - 1][my_strlen(s->clean_str[i - 1]) - 1] != '\n'){
        my_putchar('\n');
        s->clean_str[i - 1] = my_strcat(s->clean_str[i - 1], "\n");
    }
    if (s->check_room_before == 1 && lock == 1)
        my_putstr("#moves\n");
}

int print_res(setting_t *s)
{
    int lock = 0;
    int i = 0;
    int nb_room = 0;
    my_putstr("#number_of_ants\n");
    for (; s->clean_str[i] != NULL; i++, nb_room++){
        if (s->clean_str[i][0] == '\n' && s->clean_str[i][1] == '\0')
            i++;
        if (check_info(s, i) == 84
        || s->check_end > 1 || s->check_start > 1 || error_salop(s, i) == 84)
            return 84;
        if (lock == 0)
            tunnel_check(s, &lock, i);
        if ((lock == 1 && check_tunnel_end(s, i) == 84) || (lock == 1 &&
        s->check_room_before == 0) || print_end_res(s, nb_room, i) == 84)
            return 84;
    }
    if (s->check_end != 1 || s->check_start != 1)
        return 84;
    end_print_res(s, i, lock);
    return 0;
}
