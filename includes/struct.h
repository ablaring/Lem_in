/*
** EPITECH PROJECT, 2022
** STRUCT_H
** File description:
** desc
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct all {
        char **stock;
        char **clean_str;
        int *nb_tunel;
        char **rooms;
        char **path;
        char **second_path;
        char **new_path;
        char ***tunnel;
        char *start;
        char *end;
        int *ant_moov;
        int nb_rooms;
        int nb_ants;
        int previous_ant;
        int lenght_path;
        int j;
        int check_start;
        int check_end;
        int check_room_before;
    } setting_t;

#endif
