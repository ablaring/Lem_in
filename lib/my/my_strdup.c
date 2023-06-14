/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** task01
*/
#include <stdlib.h>
#include <stdio.h>

char * my_strdup ( char const * src )
{
    int i = 0;
    int j = 0;
    char *str;
    for (i;src[i] != '\0'; i++);
    str = malloc(sizeof(char) * (i + 1));
    for (j;src[j] != '\0'; j++){
        str[j] = src [j];
    }
    str[j] = '\0';
    return str;
}
