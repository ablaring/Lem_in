/*
** EPITECH PROJECT, 2023
** free.c
** File description:
** desc
*/
#include "../includes/my.h"

void free_memory(setting_t *s)
{
    if (s->path){
        for (int i = 0; i < s->lenght_path; i++)
            free(s->path[i]);
        free(s->path);
    }

    if (s->ant_moov){
        free(s->ant_moov);
    }
    free(s->start);
    free(s->end);
}
