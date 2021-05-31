/*
** EPITECH PROJECT, 2021
** find_len_max.c
** File description:
** find the biggest len in a char **
*/

int my_strlen(char const *str);

int find_len_max(char **buffer)
{
    int len_max = 0;

    for (int i = 0; buffer[i]; i += 1)
        if (my_strlen(buffer[i]) > len_max)
            len_max = my_strlen(buffer[i]);
    return (len_max);
}
