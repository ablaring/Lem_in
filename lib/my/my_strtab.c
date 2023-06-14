/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-lemin-arthur.blaringhem
** File description:
** my_strtab.c
*/

#include "my.h"

int my_strtab(char **tab)
{
    int i = 0;

    for (; *tab; tab++, i++);

    return i;
}
