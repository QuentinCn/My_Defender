/*
** EPITECH PROJECT, 2021
** find_nb_line.c
** File description:
** find the number of line of a
char **
*/

int find_nb_line(char **buffer)
{
    int i = 0;

    for (; buffer[i]; i += 1);
    return (i);
}
