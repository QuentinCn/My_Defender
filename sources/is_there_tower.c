/*
** EPITECH PROJECT, 2021
** is_there_tower.c
** File description:
** check if there is a tower at this place
*/

#include "my_defender.h"
#include "my.h"

bool is_there_tower(element_list *object, char **buffer, int i, int j)
{
    sfVector2f pos;

    for (; object; object = object->next) {
        pos = find_pos(buffer, j, i, object);
        if (object->type == TOWER && object->pos.x == pos.x && object->pos.y ==
            pos.y) {
            return (false);
        }
    }
    return (true);
}

void delete_tower_in_list(element_list **object, char **buffer, int i, int j)
{
    sfVector2f pos;
    int k = 0;

    for (element_list *tmp = (*object); tmp; tmp = tmp->next, k += 1) {
        pos = find_pos(buffer, j, i, tmp);
        if (tmp->type == TOWER && tmp->pos.x == pos.x && tmp->pos.y ==
            pos.y) {
            (*object) = free_inlist((*object), k - 1);
            (*object) = free_inlist((*object), k - 1);
            (*object) = free_inlist((*object), k - 1);
            (*object) = free_inlist((*object), k - 1);
            return;
        }
    }
}

void delete_tower(element_list **object, sfRenderWindow *game,
                  char **buffer, sfText **text_money)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game);
    int x = pos.x / (1920 / my_strlen(buffer[0]));
    int y = pos.y / (1080 / find_nb_line(buffer)) - 1;

    for (element_list *tmp = (*object); tmp; tmp = tmp->next) {
        if (find_cursor(game, tmp) && tmp->type == DESTRUCT_IN_MENU &&
            !is_there_tower((*object), buffer, y + 2, x - 1)) {
            delete_tower_in_list(object, buffer, y + 2, x - 1);
            *text_money = change_money(*text_money, 25);
            break;
        }
    }
}
