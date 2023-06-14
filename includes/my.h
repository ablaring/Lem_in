/*
** EPITECH PROJECT, 2022
** MY_H
** File description:
** desc
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <string.h>
    #include <dirent.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <stddef.h>
    #include <sys/types.h>
    #include <signal.h>
    #include <stdbool.h>
    #include "../lib/my/my.h"
    #include "./struct.h"

void free_function(setting_t *s);
void remove_coment_ending(setting_t *s);
void remove_coment_start(setting_t *s);
void remove_space(setting_t *s);
void traittement_string(setting_t *s);
int error_ges(setting_t *s);
void check_tunnel(setting_t *s, int *i);
int check_nb_tunnell(setting_t *s);
int stock_rooms(setting_t *s, int j);
void init_tunel(setting_t *s);
int algo(setting_t *s);
int find_path(setting_t *s, int i, int j, int k);
int print_res(setting_t *s);
void moov_ant(setting_t *s, int i, int k, int lock);
void end_moovant(setting_t *s, int k, int lock);
void fill_tab_tunnel(setting_t *s, char *tunel);
void free_memory(setting_t *s);
bool algo_suite(setting_t *s, int i, int j, int k);
bool find_tunel_cut(setting_t *s, int i, int j, int k);
void fill_previous_tab(setting_t *s, int *k);
int check_info(setting_t *s, int j);
void condition_one_path(setting_t *s, int i);
int fs_open_file (setting_t *s, int j, int k);

#endif
