/*
** EPITECH PROJECT, 2022
** my_strlowcase.c
** File description:
** task09
*/


char * my_strlowcase ( char * str )
{
    int i = 0;
    for (i; str[i] != '\0'; i++){
        if (str[i] >= 65 && str[i] <= 90){
            str[i] = str[i] + 32;
        }
    }
    return str;
}
