/*
** EPITECH PROJECT, 2021
** create_enemy.c
** File description:
** manage enemy
*/

#include "my_defender.h"
#include "my.h"
#include <stdlib.h>

static element_list *create_enemy(char **buffer, int i, int j, char *
                                             filename)
{
    element_list *element = malloc(sizeof(*element));

    element->type = ENEMY;
    element->area = (sfIntRect) {411, 125, 45, 43};
    element->texture = sfTexture_createFromFile(filename, &element->area);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, 1);
    element->scale = (sfVector2f) {1.2, 1.2};
    element->pos = find_pos(buffer, i, j, element);
    element->start_pos = element->pos;
    element->speed = 0.08;
    element->state = 0;
    element->life = 50;
    element->path = find_path(buffer);
    element->next = NULL;
    element->prev = NULL;
    return (element);
}


element_list *add_enemy(element_list *object, char **buffer, int wave, float time)
{
    int nb_enemy = 0;

    for (element_list *tmp = object; tmp; tmp = tmp->next) {
        if (tmp->type == ENEMY)
            nb_enemy += 1;
    }
    if (!(is_around_time(time, 0.5) && nb_enemy < wave * 5))
        return (object);
    for (int i = 0; buffer[i]; i += 1)
        for (int j = 0; buffer[i][j] != '\0'; j += 1)
            if (buffer[i][j] == 'B')
                object = add_inlist(object, create_enemy(buffer, j, i,
                                       "content/knight.png"), len_list(object));
    return (object);
}

void anime_enemy(element_list **element, float time)
{
    if ((*element)->type != ENEMY)
        return;
    if (!is_around_time(time, (*element)->speed))
        return;
    if ((*element)->area.left < 552)
        (*element)->area.left += 47;
    else
        (*element)->area.left = 411;
    (*element)->texture = sfTexture_createFromFile("content/knight.png",
                                                   &(*element)->area);
    sfSprite_setTexture((*element)->sprite, (*element)->texture, 1);
}

void move_enemy(element_list **element, float time)
{
    if ((*element)->type != ENEMY)
        return;
    if (!is_around_time(time, (*element)->speed / 3))
        return;
    switch ((*element)->path[0]) {
    case 'r':
        (*element)->pos.x += 2.7;
        break;
    case 'l':
        (*element)->pos.x -= 2.7;
        break;
    case 'd':
        (*element)->pos.y += 2.7;
        break;
    case 'u':
        (*element)->pos.y -= 2.7;
        break;
    }
    (*element)->state = ((*element)->state == 19)? 0: (*element)->state + 1;
    if ((*element)->state == 19)
        (*element)->path = &(*element)->path[1];
}

void hit_enemy(element_list **object, sfVector2f enemy_pos, int damage)
{
    for (element_list *tmp = (*object); tmp; tmp = tmp->next) {
        if (tmp->pos.x == enemy_pos.x && tmp->pos.y == enemy_pos.y
        && tmp->type == ENEMY) {
            tmp->life -= damage;
        }
    }
}

int check_enemy(element_list **object, struct use_full *uses,  element_list **map)
{
    int i = 0;
    int n = 0;

    for (element_list *tmp = (*object); tmp; tmp = tmp->next, i += 1) {
        if (tmp->type == ENEMY && tmp->life <= 0) {
            if (tmp->next->type == DAMAGE_FLAME)
                (*object) = free_inlist((*object), i + 1);
            (*object) = free_inlist((*object), i);
            uses->text_money = change_money(uses->text_money, 20);
            sfSound_play(uses->sound.sound);
        }
        if (tmp->type == ENEMY)
            if (tmp->path[0] == '\0') {
                (*object) = free_inlist((*object), i);
                n = change_life(object);
                if (n == 196) {
                    lose_menu(uses, object, map);
                }
                for (element_list *tmp = (*object); tmp; tmp = tmp->next)
                    if (tmp->type == END)
                        tmp->life -= 1;
            }
    }
    return (0);
}
