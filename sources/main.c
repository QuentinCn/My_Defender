/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stddef.h>
#include "my.h"
#include "my_defender.h"

int main(int ac, char **av, char **env)
{
    char **buffer = NULL;

    if (env[0] == NULL)
        return (84);
    if (ac > 2)
        return (84);
    if (ac == 1)
        buffer = fopen_getline(buffer, "test.txt");
    else
        buffer = fopen_getline(buffer, av[1]);
    if (buffer == NULL)
        return (84);
    play(modify_buffer(buffer));
    return (0);
}
