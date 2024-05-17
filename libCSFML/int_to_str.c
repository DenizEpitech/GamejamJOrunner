/*
** EPITECH PROJECT, 2023
** ilann
** File description:
** bvbhjo
*/

#include <stdlib.h>
#include <stdio.h>

char *int_to_str(int nbr)
{
    char *str = malloc(sizeof(char) * 4);
    int j = 0;

    str[3] = '\0';
    for (int i = 100; i > 1; i /= 10){
        str[j] = (nbr / i) + '0';
        nbr = nbr - ((str[j] - '0')* i);
        j++;
    }
    str[2] = nbr + '0';
    return str;
}
