/*
** EPITECH PROJECT, 2021
** my_itoc
** File description:
** recup an int from a char *
*/

#include <stdlib.h>

char *my_revstr(char *str);

char *my_itoc(int nb)
{
    char *nbr;
    int nb2 = nb;
    int i = 1;

    if (nb == 0)
        return ("0");
    for (; nb2 > 0; i += 1)
        nb2 /= 10;
    nbr = malloc(sizeof(char) * i);
    for (int j = 1; nb > 0; j += 1) {
        nbr[j - 1] = nb % 10 + '0';
        nb /= 10;
        nbr[j] = '\0';
    }
    return (my_revstr(nbr));
}
