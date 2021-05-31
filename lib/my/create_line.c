/*
** EPITECH PROJECT, 2021
** create_line.c
** File description:
** create a line with a char given
*/

#include <stdlib.h>

char *create_line(char c, int len)
{
    char *str = malloc(len + 1);

    for (int i = 0; i < len - 1; i += 1) {
        str[i] = c;
        str[i + 1] = '\0';
    }
    return (str);
}
