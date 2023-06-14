/*
** EPITECH PROJECT, 2023
** desc
** File description:
** algo.c
*/

#include "../../includes/my.h"

void fill_previous_tab(setting_t *s, int *k)
{
    s->path[*k] = my_strdup(s->start);
    s->path[*k + 1] = NULL;
}

void end_moovant(setting_t *s, int k, int lock)
{
    if (s->nb_ants != 0){
        if (lock == 1)
            my_putstr("\n");
        moov_ant(s, s->previous_ant - s->nb_ants, k + 1, 0);
    }
}

void moov_ant(setting_t *s, int i, int k, int lock)
{
    if (k < s->lenght_path && s->ant_moov[k] == 0){
        my_printf("P%d-%s", i + 1, s->path[k]);
        if (s->path[k + 1] != NULL)
            s->ant_moov[k] = 1;
        if (k - 1 >= 0)
            s->ant_moov[k - 1] = 0;
        if (my_strcmp(s->path[k], s->end) == 0)
            s->nb_ants--;
        lock = 1;
    }
    if (i + 1 != s->previous_ant &&
    k - 1 < s->lenght_path && k - 1 >= 0 && s->ant_moov[k - 1] == 0){
        my_putstr(" ");
        moov_ant(s, i + 1, k - 1, 1);
    }
    end_moovant(s, k, lock);
}

int find_path(setting_t *s, int i, int j, int k)
{
    if (my_strcmp(s->start, s->end) == 0)
        return 0;
    if (s->tunnel[i + 1] == NULL && s->tunnel[i][j + 1] == NULL)
        return 84;
    if (i == 0)
        i++;
    if (s->tunnel[i][j + 1] != NULL &&
    my_strcmp(s->start, s->tunnel[i][j + 1]) == 0){
        if (find_tunel_cut(s, 0, 0, k) == true)
            return;
        s->tunnel[i][j + 1] = "encule";
        free(s->start);
        s->start = my_strdup(s->tunnel[i][0]);
        fill_previous_tab(s, &k);
        find_path(s, 0, j, k + 1);
    }
    if (s->tunnel[i][j + 1] != NULL)
        find_path(s, i, j + 1, k);
    else if (s->tunnel[i + 1] != NULL)
        find_path(s, i + 1, 0, k);
}

int algo(setting_t *s)
{
    s->previous_ant = s->nb_ants;
    s->path = malloc(sizeof(char *) * 100000);
    s->path[0] = "encule";
    if (find_path(s, 0, 1, 0) == 84)
        return 84;
    s->lenght_path = count_double_arr(s->path);
    if (s->lenght_path == 0)
        return 84;
    s->ant_moov = malloc(sizeof(int) * s->lenght_path);
    for (int i = 0; i < s->lenght_path; i++)
        s->ant_moov[i] = 0;
    if (s->lenght_path == 1){
        s->path[0] = my_strdup(s->end);
        condition_one_path(s, 0);
        return 0;
    }
    moov_ant(s, 0, 0, 0);
    my_putstr("\n");
}
