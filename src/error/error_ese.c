/*
** EPITECH PROJECT, 2023
** desc
** File description:
** desc
*/

#include "../../includes/my.h"

int error_salop(setting_t *s, int i)
{
    if (s->clean_str[i][0] == '#' && s->clean_str[i][1] == '#' &&
    (my_strcmp(s->clean_str[i], "##start\n") != 0
    && my_strcmp(s->clean_str[i], "##end\n") != 0)){
        return 84;
    }
    return 0;
}
