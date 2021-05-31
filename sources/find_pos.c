/*
** EPITECH PROJECT, 2021
** find_pos.c
** File description:
** find the position for the tower
*/

#include "my_defender.h"
#include "my.h"

sfVector2f find_pos(char **buffer, int i, int j, element_list *element)
{
    float size[2] = {1920, 1080};
    float len[2] = {my_strlen(buffer[j]), find_nb_line(buffer) + 1};
    sfVector2f pos = {0, 0};

    pos.x = i * (size[0] / len[0]);
    pos.y = j * (size[1] / len[1]) - sfTexture_getSize(element->texture).y *
                 element->scale.y / 4;
    return (pos);
}
