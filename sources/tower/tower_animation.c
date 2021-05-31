/*
** EPITECH PROJECT, 2021
** tower_animation.c
** File description:
** manage tower animation
*/

#include "my_defender.h"
#include <my.h>

bool is_in_circle(sfVector2f tower, sfVector2f enemy, float range)
{
    if ((tower.x - range < enemy.x && tower.x > enemy.x) || (tower.x + range >
        enemy.x && tower.x < enemy.x))
        if ((tower.y - range < enemy.y && tower.y > enemy.y) || (tower.y + range >
        enemy.y && tower.y < enemy.y))
            return (true);
    return (false);
}

sfVector2f find_closer_enemy(element_list **element, element_list *object, float
                             range)
{
    sfVector2f pos = {-1, -1};
    sfVector2f pos_element = (*element)->pos;

    if ((*element)->next)
        if ((*element)->next->type == TOWER) {
            pos_element.y -= sfTexture_getSize((*element)->texture).y *
                (*element)->scale.y / 10;
            pos_element.y += sfTexture_getSize((*element)->texture).y *
                (*element)->scale.y;
        }
    for (; object; object = object->next)
        if (object->type == ENEMY)
            if (is_in_circle(pos_element, object->pos, range))
                pos = object->pos;
    return (pos);
}

int find_direction(char **buffer, element_list *element)
{
    int y = element->pos.x / (1920 / my_strlen(buffer[0]));
    int x = element->pos.y / (1080 / find_nb_line(buffer)) + 1;

    if (buffer[x][y + 1] >= '0' && buffer[x][y + 1] <= '6')
        return (0);
    if (buffer[x][y - 1] >= '0' && buffer[x][y - 1] <= '6')
        return (2);
    if (buffer[x + 1][y] >= '0' && buffer[x + 1][y] <= '6')
        return (1);
    if (buffer[x - 1][y] >= '0' && buffer[x - 1][y] <= '6')
        return (3);
    return (-1);
}

void anime_tower(element_list **element, float time, element_list **object,
                 struct use_full *uses)
{
    sfVector2f enemy_pos;

    if ((*element)->speed <= 0)
        return;
    if (is_around_time(time, (*element)->speed) && (*element)->type ==
        TOWER_PART) {
        enemy_pos = find_closer_enemy(element, (*object), (*element)->range);
        if ((enemy_pos.x == -1 && enemy_pos.y == -1)) {
            if ((*element)->pos.y < (*element)->start_pos.y) {
                (*element)->pos.y += 0.5;
            }
            return;
        }
        if ((*element)->start_pos.y - (*element)->pos.y < 20 &&
            (*element)->state == 0)
            (*element)->pos.y -= 5.5;
        else if ((*element)->pos.y < (*element)->start_pos.y) {
            (*element)->pos.y += 0.5;
            (*element)->state = 1;
        }
        if ((*element)->pos.y == (*element)->start_pos.y)
            (*element)->state = 0;
    }
    if ((*element)->type == ROC)
        if ((*element)->next->pos.y == (*element)->next->start_pos.y ||
            (*element)->state != 0)
            move_roc(element, object, find_closer_enemy(&(*element)->next,
                       (*object), (*element)->next->range));
    if ((*element)->type == FLAME)
        if ((*element)->prev->pos.y == (*element)->prev->start_pos.y ||
            (*element)->state != 0)
            move_flame(element, find_closer_enemy(&(*element)->next,
                                 (*object), (*element)->next->range),
                       find_direction(uses->buffer, (*element)->next));
}
