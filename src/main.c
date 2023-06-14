/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** desc
*/

#include "../includes/my.h"

setting_t *create_setting(void)
{
    setting_t *s = malloc(sizeof(setting_t));
    s->nb_rooms = 0;
    return s;
}

int main(int argc)
{
    setting_t *s = create_setting();
    s->stock = malloc(sizeof(char *) * 100000);
    s->rooms = malloc(sizeof(char *) * 100000);
    s->check_end = 0;
    s->check_start = 0;
    s->check_room_before = 0;
    if (argc != 1 || fs_open_file(s, 0, 0) == 84 ||
    error_ges(s) == 84 || algo(s) == 84)
        return 84;
    free_function(s);
    free_memory(s);
    return 0;
}
