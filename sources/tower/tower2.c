/*
** EPITECH PROJECT, 2021
** tower.c
** File description:
** manage tower
*/

#include "my_defender.h"
#include "my.h"
#include <stdlib.h>

element_list *create_flame(char **buffer, int i, int j, char *filename)
{
    element_list *element = malloc(sizeof(*element));

    element->type = FLAME;
    element->area = (sfIntRect) {0, 0, 106, 104};
    element->texture = sfTexture_createFromFile(filename, &element->area);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, 1);
    element->scale = (sfVector2f) {0.4, 0.4};
    element->pos = find_pos(buffer, i, j, element);
    element->pos.x += 30;
    element->pos.y += 50;
    element->start_pos = element->pos;
    element->state = 0;
    element->speed = 0.2;
    element->life = -1;
    element->next = NULL;
    element->prev = NULL;
    sfSprite_setRotation(element->sprite, 180);
    return (element);
}

element_list *create_tower2_object_mid(char **buffer, int i, int j, char
*filename)
{
    element_list *element = malloc(sizeof(*element));

    element->type = TOWER;
    element->texture = sfTexture_createFromFile(filename, NULL);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, 1);
    element->scale = (sfVector2f) {0.3, 0.3};
    element->pos = find_pos(buffer, i, j, element);
    element->start_pos = element->pos;
    element->state = 0;
    element->speed = 0;
    element->life = -1;
    element->range = 125;
    element->next = NULL;
    element->prev = NULL;
    return (element);
}


element_list *create_tower2_object_front(char **buffer, int i, int j, char *
                                               filename)
{
    element_list *element = malloc(sizeof(*element));

    element->type = TOWER_PART;
    element->texture = sfTexture_createFromFile(filename, NULL);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, 1);
    element->scale = (sfVector2f) {0.3, 0.3};
    element->pos = find_pos(buffer, i, j, element);
    element->pos.y += sfTexture_getSize(element->texture).y * element->scale.y /
    1.5;
    element->start_pos = element->pos;
    element->state = 0;
    element->speed = 0.01;
    element->life = -1;
    element->range = 125;
    element->next = NULL;
    element->prev = NULL;
    return (element);
}

element_list *create_tower2_object_back(char **buffer, int i, int j, char *
                                              filename)
{
    element_list *element = malloc(sizeof(*element));

    element->type = TOWER_PART;
    element->texture = sfTexture_createFromFile(filename, NULL);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, 1);
    element->scale = (sfVector2f) {0.3, 0.3};
    element->pos = find_pos(buffer, i, j, element);
    element->pos.x += 2;
    element->pos.y += sfTexture_getSize(element->texture).y * element->scale.y /
    1.5;
    element->start_pos = element->pos;
    element->state = 0;
    element->speed = 0.01;
    element->life = -1;
    element->range = 125;
    element->next = NULL;
    element->prev = NULL;
    return (element);
}
