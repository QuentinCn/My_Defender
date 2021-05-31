/*
** EPITECH PROJECT, 2021
** damage_flame.c
** File description:
** manage flame that do damage
*/

#include "my_defender.h"
#include <stdlib.h>
#include "my.h"

bool is_burn(sfVector2f pos, sfVector2f enemy_pos)
{
    if (pos.x > enemy_pos.y && pos.x < enemy_pos.x + 10)
        if (pos.y > enemy_pos.y && pos.y < enemy_pos.y + 75)
            return (true);
    return (false);
}

void create_damage_flame(element_list **object)
{
    element_list *element = malloc(sizeof(*element));

    element->type = DAMAGE_FLAME;
    element->texture = sfTexture_createFromFile("content/damage_flame.png", NULL);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, 1);
    element->scale = (sfVector2f) {0.1, 0.1};
    element->pos = (*object)->pos;
    element->start_pos = (*object)->pos;
    element->state = 0;
    element->speed = 0.2;
    element->life = -1;
    element->next = (*object)->next;
    element->prev = (*object);
    (*object)->next = element;
}

void add_damage(element_list **object)
{
    for (element_list *tmp = (*object); tmp; tmp = tmp->next) {
        if (tmp->type == FLAME)
            for (element_list *tmp2 = (*object); tmp2; tmp2 = tmp2->next) {
                if (tmp2->next) {
                    if (tmp2->next->type == DAMAGE_FLAME)
                        continue;
                    else if (is_burn(tmp->pos, tmp2->pos) && tmp2->type == ENEMY)
                        create_damage_flame(&tmp2);
                }
            }
    }
}

void damage_flame(element_list **object, float time)
{
    int i = 0;

    add_damage(object);
    for (element_list *tmp = (*object); tmp; tmp = tmp->next, i += 1) {
        if (tmp->type == DAMAGE_FLAME) {
            if (tmp->type == DAMAGE_FLAME && tmp->prev->type == ENEMY) {
                if (is_around_time(time, tmp->prev->speed * 10))
                    tmp->prev->life -= 1;
                tmp->pos = tmp->prev->pos;
            }
            if (tmp->state >= 10)
                *object = free_inlist(*object, i);
            tmp->state += 1;
        }
    }
}
