/*
** EPITECH PROJECT, 2021
** find_path
** File description:
** find the path to follow
*/

#include <stdlib.h>

int my_strlen(char *str);
char **my_double_dup(char **dest, char **src);

static int find_nb_step(char **buffer)
{
    int nb_step = 0;

    for (int i = 0; buffer[i]; i += 1)
        for (int j = 0; buffer[i][j] != '\0'; j += 1)
            if (buffer[i][j] <= '5' && buffer[i][j] >= '0')
                nb_step += 1;
    return (nb_step);
}

static char *add_at_end(char *path, char c)
{
    int pos = my_strlen(path);

    path[pos] = c;
    path[pos + 1] = '\0';
    return (path);
}

static char *do_different_case(char **buffer, int *i, int *j, char *path)
{
    if (buffer[*i][*j + 1] >= '0' && buffer[*i][*j + 1] <= '5') {
        path = add_at_end(path, 'r');
        buffer[*i][*j] = ' ';
        *j += 1;
    } else if (buffer[*i][*j - 1] >= '0' && buffer[*i][*j - 1] <= '5') {
        path = add_at_end(path, 'l');
        buffer[*i][*j] = ' ';
        *j -= 1;
    } else if (buffer[*i + 1][*j] >= '0' && buffer[*i + 1][*j] <= '5') {
        path = add_at_end(path, 'd');
        buffer[*i][*j] = ' ';
        *i += 1;
    } else if (buffer[*i - 1][*j] >= '0' && buffer[*i - 1][*j] <= '5') {
        path = add_at_end(path, 'u');
        buffer[*i][*j] = ' ';
        *i -= 1;
    }
    return (path);
}

char *find_path(char **buffer)
{
    int i = 0;
    int j = 0;
    char **tmp = my_double_dup(tmp, buffer);
    char *path = malloc(find_nb_step(buffer) + 1);

    path[0] = '\0';
    for (i = 0; tmp[i]; i += 1) {
        for (j = 0; tmp[i][j] != '\0'; j += 1)
            if (tmp[i][j] == 'B')
                break;
        if (tmp[i][j] == 'B')
            break;
    }
    for (int k = 0; k < find_nb_step(buffer); k += 1)
        path = do_different_case(tmp, &i, &j, path);
    return (path);
}
