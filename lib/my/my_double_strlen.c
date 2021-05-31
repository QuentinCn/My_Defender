/*
** EPITECH PROJECT, 2021
** my_double_strlen
** File description:
** my_strlen for char **
*/

int my_double_strlen(char **str)
{
    int i = 0;

    for (; str[i]; i += 1);
    return (i);
}
