/*
** EPITECH PROJECT, 2021
** tower_menu.c
** File description:
** manage the tower's menu
*/

#include "my_defender.h"
#include <stdlib.h>

element_list *create_tower_menu_base(float i, float j)
{
    element_list *element = malloc(sizeof(*element));
    sfVector2u size;
    sfColor color = sfColor_fromRGBA(125, 125, 125, 175);

    element->type = TOWER_MENU;
    element->texture = sfTexture_createFromFile("content/circle.png", NULL);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, 1);
    sfSprite_setColor(element->sprite, color);
    element->scale = (sfVector2f) {1, 1};
    size = sfTexture_getSize(element->texture);
    element->pos = (sfVector2f) {i - size.x * element->scale.x / 2.8, j - size.y *
        element->scale.y / 2.8};
    element->speed = 0;
    element->life = -1;
    element->next = NULL;
    return (element);
}

element_list *create_tower_menu_tower(float i, float j, char *filename)
{
    element_list *element = malloc(sizeof(*element));
    sfVector2u size;

    element->state = 0;
    element->type = TOWER1_IN_MENU;
    element->texture = sfTexture_createFromFile(filename, NULL);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, 1);
    element->scale = (sfVector2f) {0.4, 0.4};
    size = sfTexture_getSize(element->texture);
    element->pos = (sfVector2f) {i - size.x * element->scale.x / 1.2, j - size.y *
        element->scale.y / 1.2};
    element->speed = 0;
    element->life = -1;
    element->next = NULL;
    return (element);
}

element_list *create_destruct_menu_tower(float i, float j, char *filename)
{
    element_list *element = malloc(sizeof(*element));
    sfVector2u size;

    element->state = 0;
    element->type = DESTRUCT_IN_MENU;
    element->texture = sfTexture_createFromFile(filename, NULL);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, 1);
    element->scale = (sfVector2f) {0.15, 0.15};
    size = sfTexture_getSize(element->texture);
    element->pos = (sfVector2f) {i - size.x * element->scale.x * 1.8, j - size.y *
        element->scale.y * 2};
    element->speed = 0;
    element->life = -1;
    element->next = NULL;
    return (element);
}

element_list *delete_menu(element_list *object)
{
    element_list *tmp = object;

    for (int i = 0; tmp; i += 1, tmp = tmp->next) {
        if (tmp->type == TOWER_MENU || tmp->type == TOWER2_IN_MENU || tmp->type ==
        TOWER1_IN_MENU || tmp->type == DESTRUCT_IN_MENU) {
            object = free_inlist(object, i);
            i -= 1;
        }
    }
    return (object);
}
