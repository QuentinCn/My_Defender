/*
** EPITECH PROJECT, 2021
** manage_buffer.c
** File description:
** manage the buffer
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

static char *redo_line(char *str, int len_max)
{
    char *new = malloc(37);
    int i = 0;
    int mid_len = (36 - len_max) / 2;

    for (; i < mid_len; i += 1)
        new[i] = '#';
    for (int j = 0; str[j] != '\0'; i += 1, j += 1)
        new[i] = str[j];
    for (; i < len_max + mid_len * 2; i += 1)
        new[i] = '#';
    new[i] = '\0';
    free(str);
    return (new);
}

static char **add_lines(char **buffer)
{
    char **new = malloc(sizeof(char *) * 20);
    int i = 0;
    int len_max = find_nb_line(buffer);
    int mid_len = (19 - len_max) / 2;

    for (; i < mid_len; i += 1)
        new[i] = create_line('#', my_strlen(buffer[0]));
    for (int j = 0; buffer[j]; i += 1, j += 1)
        new[i] = buffer[j];
    for (; i < mid_len * 2 + len_max; i += 1)
        new[i] = create_line('#', my_strlen(buffer[0]));
    new[i] = NULL;
    return (new);
}

static char **adapt_buffer(char **buffer)
{
    int len_max = find_len_max(buffer);

    for (int i = 0; buffer[i]; i += 1)
        for (int j = 0; buffer[i][j] != '\0'; j += 1)
            if (buffer[i][j] == ' ')
                buffer[i][j] = '#';
    buffer = add_lines(buffer);
    for (int i = 0; buffer[i]; i += 1)
        buffer[i] = redo_line(buffer[i], len_max);
    return (buffer);
}

static char check_char(char **buffer, int lines, int col)
{
    if ((buffer[lines - 1][col] == '#' || buffer[lines - 1][col] == 'T') &&
    (buffer[lines + 1][col] == '#' || buffer[lines + 1][col] == 'T'))
        return ('0');
    if ((buffer[lines][col - 1] == '#' || buffer[lines][col - 1] == 'T') &&
    (buffer[lines][col + 1] == '#' || buffer[lines][col + 1] == 'T'))
        return ('1');
    if ((buffer[lines][col + 1] == '#' || buffer[lines][col + 1] == 'T') &&
    (buffer[lines - 1][col] == '#' || buffer[lines - 1][col] == 'T'))
        return ('2');
    if ((buffer[lines][col - 1] == '#' || buffer[lines][col - 1] == 'T') &&
    (buffer[lines + 1][col] == '#' || buffer[lines + 1][col] == 'T'))
        return ('4');
    if ((buffer[lines][col + 1] == '#' || buffer[lines][col + 1] == 'T') &&
    (buffer[lines + 1][col] == '#' || buffer[lines + 1][col] == 'T'))
        return ('5');
    if ((buffer[lines][col - 1] == '#' || buffer[lines][col - 1] == 'T') &&
    (buffer[lines - 1][col] == '#' || buffer[lines - 1][col] == 'T'))
        return ('3');
    return (buffer[lines][col]);
}

char **modify_buffer(char **buffer)
{
    for (int n = 0; buffer[n] != NULL; n++)
        for (int m = 0; buffer[n][m] != '\0'; m++)
            if (buffer[n][m] == '.')
                buffer[n][m] = check_char(buffer, n, m);
    buffer = adapt_buffer(buffer);
    return (buffer);
}
