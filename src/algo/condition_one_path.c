/*
** EPITECH PROJECT, 2023
** condition_one_path.c
** File description:
** desc
*/

#include "../../includes/my.h"

void condition_one_path(setting_t *s, int i)
{
    if (s->nb_ants == 0)
        return;
    else{
        my_printf("P%d-%s\n", i + 1, s->path[0]);
        s->nb_ants--;
        condition_one_path(s, i + 1);
    }
}
