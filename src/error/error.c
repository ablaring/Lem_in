/*
** EPITECH PROJECT, 2023
** parse.c
** File description:
** desc
*/

#include "../../includes/my.h"

int count_tunnel(setting_t *s, int lock_tunel, int *i)
{
    int room_clean[2] = {0, 0};
    char **temp = NULL;
    if (lock_tunel == 1)
        temp = my_str_to_word_array(s->clean_str[*i], '-');
    for (size_t i = 0; s->rooms[i] != NULL; i++){
        if (my_strcmp(s->rooms[i], temp[0]) == 0){
            s->nb_tunel[i] += 1;
            room_clean[0] = 1;
        }
        if (my_strcmp(s->rooms[i], temp[1]) == 0){
            s->nb_tunel[i] += 1;
            room_clean[1] = 1;
        }
    }
    if (room_clean[0] == 0 || room_clean[1] == 0)
        return 84;
}

void check_tunnel(setting_t *s, int *i)
{
    int lock_tunel = 0;
    for (int j = 0; s->clean_str[*i][j] != '\0'; j++)
        if (s->clean_str[*i][j] == '-'){
            lock_tunel = 1;
            fill_tab_tunnel(s, s->clean_str[*i]);
        }
}

int check_nb_tunnell(setting_t *s)
{
    for (size_t i = 0; s->nb_tunel[i] != NULL; i++)
        if (s->nb_tunel != 1 && s->nb_tunel != 2)
            return 84;
    return 0;
}

int get_nb_ants(setting_t *s)
{
    for (int i = 0; s->clean_str[0][i] != '\n'; i++) {
        if (s->clean_str[0][i] < '0' || s->clean_str[0][i] > '9')
            return 84;
    }
    s->nb_ants = my_getnbr(s->clean_str[0]);
    return 0;
}

int error_ges(setting_t *s)
{
    init_tunel(s);
    for (int i = 0; s->clean_str[i] != NULL; i++) {
        if (s->clean_str[i][0] == '#' && s->clean_str[i][1] == '#' &&
        (my_strcmp(s->clean_str[i], "##start\n") != 0
        && my_strcmp(s->clean_str[i], "##end\n") != 0)){
            return 84;
        }
        check_tunnel(s, &i);
    }
    return 0;
}
