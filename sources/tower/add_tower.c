/*
** EPITECH PROJECT, 2021
** add_tower.c
** File description:
** add the good tower
*/

#include "my_defender.h"
#include "my.h"

element_list *create_tower1(element_list *object, char **buffer, int i, int j)
{
    object = add_inlist(object, create_tower1_object_back(buffer, j, i,
                                      "content/1.png"), len_list(object));
    object = add_inlist(object, create_tower1_object_mid(buffer, j, i,
                                      "content/3.png"), len_list(object));
    object = add_inlist(object, create_roc(buffer, j, i,
                                      "content/roc.png"), len_list(object));
    object = add_inlist(object, create_tower1_object_front(buffer, j, i,
                                      "content/2.png"), len_list(object));
    return (object);
}

element_list *create_tower2(element_list *object, char **buffer, int i, int j)
{
    object = add_inlist(object, create_tower2_object_back(buffer, j, i,
                                      "content/4.png"), len_list(object));
    object = add_inlist(object, create_flame(buffer, j, i,
                                      "content/flame.png"), len_list(object));
    object = add_inlist(object, create_tower2_object_mid(buffer, j, i,
                                      "content/6.png"), len_list(object));
    object = add_inlist(object, create_tower2_object_front(buffer, j, i,
                                      "content/5.png"), len_list(object));
    return (object);
}

void add_tower(element_list *element, struct use_full *uses, element_list
**object)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(uses->game);
    int x = pos.x / (1920 / my_strlen(uses->buffer[0]));
    int y = pos.y / (1080 / find_nb_line(uses->buffer)) - 1;

    switch(element->type) {
    case (TOWER1_IN_MENU):
        if (find_cursor(uses->game, element) && element->type == TOWER1_IN_MENU &&
            is_there_tower((*object), uses->buffer, y + 2, x + 1) &&
            is_there_enough_money(uses->text_money)) {
            (*object) = create_tower1((*object), uses->buffer, y + 2, x + 1);
            uses->text_money = change_money(uses->text_money, -50);
        }
        break;
    case (TOWER2_IN_MENU):
        if (find_cursor(uses->game, element) && element->type == TOWER2_IN_MENU &&
            is_there_tower((*object), uses->buffer, y + 2, x) &&
            is_there_enough_money(uses->text_money)) {
            (*object) = create_tower2((*object), uses->buffer, y + 1, x + 1);
            uses->text_money = change_money(uses->text_money, -50);
        }
        break;
    default:
        break;
    }
}
