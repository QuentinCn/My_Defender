/*
** EPITECH PROJECT, 2021
** portal.c
** File description:
** manage portal
*/

#include "my_defender.h"
#include "my.h"
#include <stdlib.h>

element_list *create_portal(char **buffer, int i, int j)
{
    element_list *element = malloc(sizeof(*element));
    float size[2] = {1920, 1080};
    float len[2] = {my_strlen(buffer[j]), find_nb_line(buffer) + 1};

    element->area = (sfIntRect) {0, 0, 155, 320};
    element->texture = sfTexture_createFromFile("content/portal.png",
                                                &element->area);
    element->type = PORTAL;
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, 1);
    element->scale = (sfVector2f) {size[0] / len[0] / 200, size[1] / len[1] / 200};
    element->pos = (sfVector2f) {i * (size[0] / len[0]), j * (size[1] / len[1])};
    element->pos.x -= sfTexture_getSize(element->texture).x * element->scale.x / 2;
    element->pos.y -= sfTexture_getSize(element->texture).y * element->scale.y /
    2.5;
    element->speed = 0.1;
    element->life = -1;
    element->next = NULL;
    element->prev = NULL;
    return (element);
}

sfIntRect move_portal_area(sfIntRect area)
{
    if (area.left < 465)
        area.left += 160;
    else
        area.left = 0;
    return (area);
}

void anime_portal(element_list **element, float time)
{
    if ((*element)->type == PORTAL)
        if (is_around_time(time, (*element)->speed)) {
            (*element)->area = move_portal_area((*element)->area);
            (*element)->texture = sfTexture_createFromFile("content/portal.png",
                                                           &(*element)->area);
            sfSprite_setTexture((*element)->sprite, (*element)->texture, 1);
        }
}
