/*
** EPITECH PROJECT, 2023
** formate_string
** File description:
** desc
*/

#include "../includes/my.h"

void remove_coment_ending(setting_t *s)
{
    for (int i = 0, j = 0; s->stock[i];) {
        if (s->stock[i][j] == '#' && s->stock[i][j + 1] != '#') {
            s->stock[i][j] = (s->stock[i][j - 1] != '#') ? '\n' :
            s->stock[i][j];
            s->stock[i][j + 1] = (s->stock[i][j - 1] != '#') ? '\0' :
            s->stock[i][j + 1];
        }
        j++;
        if (s->stock[i][j] == '\0') {
            i++;
            j = 1;
        }
    }
    return;
}

void remove_coment_start(setting_t *s)
{
    for (int i = 0, j = 0; s->stock[i];) {
        if (j == 0 && s->stock[i][j] == '#' && s->stock[i][j + 1] != '#')
            s->stock[i][0] = '\0';
        j++;
        if (s->stock[i][j] == '\0') {
            i++;
            j = 0;
        }
    }
}

void remove_space(setting_t *s)
{
    s->clean_str = malloc(sizeof(char*) * my_strtab(s->stock) + 1);
    int a = 0, i = 0;
    while (s->stock[i]) {
        if (s->stock[i][0] != '\0') {
            s->clean_str[a] = my_strdup(s->stock[i]);
            a++;
        }
        i++;
    }
    s->clean_str[a] = NULL;
    return;
}

void traittement_string(setting_t *s)
{
    remove_coment_ending(s);
    remove_coment_start(s);
    remove_space(s);
}
