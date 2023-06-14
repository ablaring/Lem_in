/*
** EPITECH PROJECT, 2023
** parse.c
** File description:
** desc
*/

#include "../../includes/my.h"

void init_tunel(setting_t *s)
{
    size_t i = 0;
    s->tunnel = malloc(sizeof(char **) * count_double_arr(s->rooms) * 5);
    for (; s->rooms[i] != NULL; i++){
        s->tunnel[i] = malloc(sizeof(char *) * 10000);
        s->tunnel[i][0] = my_strdup(s->rooms[i]);
        s->tunnel[i][1] = NULL;
    }
}

void recursive_tunnel_suite(setting_t *s, char *tunel, size_t i, char **temp)
{
    if (my_strcmp(s->rooms[i], temp[1]) == 0 &&
    s->tunnel[i][s->j] == NULL){
        s->tunnel[i][s->j] = my_strdup(temp[0]);
        s->tunnel[i][s->j + 1] = NULL;
        return;
    }else if (my_strcmp(s->rooms[i], temp[1]) == 0 &&
    s->tunnel[i][s->j] != NULL){
        s->j += 1;
        recursive_tunnel(s, tunel, i, temp);
    }
}

void recursive_tunnel(setting_t *s, char *tunel, size_t i, char **temp)
{
    if (my_strcmp(s->rooms[i], temp[0]) == 0 &&
    s->tunnel[i][s->j] == NULL){
        s->tunnel[i][s->j] = my_strdup(temp[1]);
        s->tunnel[i][s->j + 1] = NULL;
        return;
    }else if (my_strcmp(s->rooms[i], temp[0]) == 0 &&
    s->tunnel[i][s->j] != NULL){
        s->j += 1;
        recursive_tunnel(s, tunel, i, temp);
    }
    recursive_tunnel_suite(s, tunel, i, temp);
}

void fill_tab_tunnel(setting_t *s, char *tunel)
{
    int i = 0;
    int j = 0;
    int  nb = 0;
    char **temp = my_str_to_word_array(tunel, '-');
    temp[1][my_strlen(temp[1]) - 1] = '\0';
    for (i = 0; s->rooms[i] != NULL; i++){
        s->j = 1;
        recursive_tunnel(s, tunel, i, temp);
    }
}
