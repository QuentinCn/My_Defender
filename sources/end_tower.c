/*
** EPITECH PROJECT, 2021
** end.c
** File description:
** manage end of map
*/

#include "my_defender.h"
#include "my.h"
#include <stdlib.h>

element_list *create_end_tower(char **buffer, int i, int j)
{
    element_list *element = malloc(sizeof(*element));
    float size[2] = {1920, 1080};
    float len[2] = {my_strlen(buffer[j]), find_nb_line(buffer) + 1};

    element->texture = sfTexture_createFromFile("content/end.png", NULL);
    element->type = END;
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, 1);
    element->scale = (sfVector2f) {0.5, 0.5};
    element->pos = (sfVector2f) {i * (size[0] / len[0]) + 32, j * (size[1] /
    len[1]) - 8};
    element->pos.x -= sfTexture_getSize(element->texture).x * element->scale.x / 2;
    element->pos.y -= sfTexture_getSize(element->texture).y * element->scale.y /
    2.5;
    element->speed = -1;
    element->life = 5;
    element->next = NULL;
    element->prev = NULL;
    return (element);
}

element_list *create_end_life(char **buffer, int i, int j)
{
    element_list *element = malloc(sizeof(*element));
    float size[2] = {1920, 1080};
    float len[2] = {my_strlen(buffer[j]), find_nb_line(buffer) + 1};

    element->area = (sfIntRect) {25, 25, 200, 26};
    element->texture = sfTexture_createFromFile("content/life.png", &element->area);
    element->type = END_LIFE;
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, 1);
    element->scale = (sfVector2f) {0.5, 0.5};
    element->pos = (sfVector2f) {i * (size[0] / len[0]) + 32, j * (size[1] /
    len[1]) - 50};
    element->pos.x -= sfTexture_getSize(element->texture).x * element->scale.x / 2;
    element->pos.y -= sfTexture_getSize(element->texture).y * element->scale.y /
    2.5;
    element->speed = -1;
    element->life = -1;
    element->next = NULL;
    element->prev = NULL;
    return (element);
}

int change_life(element_list **element)
{
    for (element_list *tmp = (*element); tmp; tmp = tmp->next) {
        if (tmp->type == END_LIFE) {
            tmp->area.top += 30 + tmp->prev->life * 1.5;
            tmp->texture = sfTexture_createFromFile("content/life.png",
                                                        &tmp->area);
            sfSprite_setTexture(tmp->sprite, tmp->texture, 1);
            return(tmp->area.top);
        }
    }
    return (0);
}
