/*
** EPITECH PROJECT, 2022
** my_swap.c
** File description:
** task01
*/
#include "my.h"

void my_swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
