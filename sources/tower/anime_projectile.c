/*
** EPITECH PROJECT, 2021
** anime_projectile.c
** File description:
** manage the projectile
*/

#include "my_defender.h"
#include "my.h"

void move_rock_area(element_list **element)
{
    (*element)->area.left = 104 * -1 * (*element)->state;
    if ((*element)->area.left == 728)
        (*element)->area.left = 0;
    (*element)->texture = sfTexture_createFromFile("content/roc.png",
                                                   &(*element)->area);
    sfSprite_setTexture((*element)->sprite, (*element)->texture, 1);
}

void move_roc(element_list **element, element_list **object, sfVector2f enemy_pos)
{
    int i = 0;

    if ((*element)->state <= -1) {
        move_rock_area(element);
        if ((*element)->state == -7) {
            (*element)->pos = (*element)->start_pos;
            (*element)->state = 0;
            return;
        }
        (*element)->state -= 1;
        return;
    }
    if (enemy_pos.x == -1 || enemy_pos.y == -1) {
        (*element)->pos = (*element)->start_pos;
        return;
    }
    if ((*element)->state == 0)
        (*element)->state = 1;
    if ((*element)->state >= 1) {
        (*element)->pos = (*element)->start_pos;
        for (i = 0; i < (*element)->state; i += 1)
            (*element)->pos.x += (enemy_pos.x - (*element)->start_pos.x) / 25;
        for (i = 0; i < (*element)->state && ((*element)->pos.y + 30 >
                                          enemy_pos.y || (*element)->pos.y +
                                          30 > (*element)->start_pos.y); i += 1)
            (*element)->pos.y -= 5;
        for (; i < (*element)->state && (*element)->pos.y < enemy_pos.y; i += 1)
            (*element)->pos.y += 5;
        (*element)->state += 1;
    }
    if (is_around((*element)->pos.x, enemy_pos.x) && ((*element)->pos.y + 5 >=
                         enemy_pos.y || (*element)->pos.y - 5 <= enemy_pos.y)) {
        hit_enemy(object, enemy_pos, 10);
        (*element)->state = -1;
    }
}

void move_flame(element_list **element, sfVector2f
                enemy_pos, int direction)
{
    int i = 0;
    int rot = (direction == 2)? -1: 1;

    if ((*element)->state <= -1) {
        if ((*element)->state == -1) {
            (*element)->texture = sfTexture_createFromFile("content/51.png", NULL);
            sfSprite_setTexture((*element)->sprite, (*element)->texture, 1);
            (*element)->scale = (sfVector2f) {0.3, 0.3};
            (*element)->pos.x += 20;
            (*element)->pos.y += 20;
        }
        else if ((*element)->state == -200) {
            (*element)->texture = sfTexture_createFromFile("content/flame.png", NULL);
            sfSprite_setTexture((*element)->sprite, (*element)->texture, 1);
            (*element)->scale = (sfVector2f) {0.4, 0.4};
            (*element)->state = 1;
            (*element)->pos = (*element)->start_pos;
        }
        (*element)->state -= 1;
        return;
    }
    if (enemy_pos.x == -1 || enemy_pos.y == -1) {
        (*element)->pos = (*element)->start_pos;
        return;
    }
    if ((*element)->state == 0)
        (*element)->state = 1;
    if ((*element)->state >= 1) {
        (*element)->pos = (*element)->start_pos;
        for (i = 0; i < (*element)->state && i < 10; i += 1) {
            (*element)->pos.x += (direction != 2)? 4: -4;
            (*element)->pos.y -= (direction != 3)? 4: 8;
            sfSprite_setRotation((*element)->sprite,
                                 sfSprite_getRotation((*element)->sprite) + rot);
        }
        for (; i < (*element)->state; i += 1)
        {
            (*element)->pos.x += (direction != 2)? 2: -2;
            (*element)->pos.y += (direction == 1)? 8: 0;
            (*element)->pos.y += (direction == 3)? 2: 0;
            (*element)->pos.y += (direction != 1 && direction != 3)? 4: 0;
            sfSprite_setRotation((*element)->sprite,
                                 sfSprite_getRotation((*element)->sprite) + rot);
        }
        (*element)->state += 1;
    }
    if ((*element)->state >= 20) {
        (*element)->state = -1;
        sfSprite_setRotation((*element)->sprite, 180);
    }
}
