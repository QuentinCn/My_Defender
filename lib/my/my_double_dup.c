/*
** EPITECH PROJECT, 2021
** my_double_dup.c
** File description:
** duplicate a char **
*/

#include <stdlib.h>

int my_double_strlen(char **buffer);

int my_strlen(char *str);

char **my_double_dup(char **dest, char **src)
{
    int i = 0;
    int j = 0;

    dest = malloc(sizeof(char *) * (my_double_strlen(src) + 1));
    for (; src[i]; i += 1) {
        dest[i] = malloc(my_strlen(src[i]) + 1);
        for (j = 0; src[i][j] != '\0'; j += 1)
            dest[i][j] = src[i][j];
        dest[i][j] = '\0';
    }
    dest[i] = NULL;
    return (dest);
}
