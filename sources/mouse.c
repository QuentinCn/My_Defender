/*
** EPITECH PROJECT, 2021
** mouse.c
** File description:
** manage mouse interaction
*/

#include "my_defender.h"
#include "my.h"
#include <time.h>
#include <math.h>

bool find_cursor(sfRenderWindow *game, element_list *element)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(game);
    sfVector2u size = sfTexture_getSize(element->texture);

    size.x *= element->scale.x;
    size.y *= element->scale.y;
    if (cursor.x > element->pos.x && cursor.y > element->pos.y)
        if (cursor.x < element->pos.x + size.x && cursor.y < element->pos.y +
            size.y) {
            return (true);
        }
    return (false);
}

element_list *look_cursor(element_list *object, sfRenderWindow *game)
{
    for (element_list *tmp = object; tmp; tmp = tmp->next) {
        if ((tmp->type == TOWER1_IN_MENU || tmp->type == TOWER2_IN_MENU ||
        tmp->type == DESTRUCT_IN_MENU) && find_cursor(game, tmp) && tmp->state
        == 0) {
            tmp->scale = (sfVector2f) {tmp->scale.x + 0.05, tmp->scale.y + 0.05};
            tmp->state = 1;
        } else if ((tmp->type == TOWER1_IN_MENU || tmp->type == TOWER2_IN_MENU
        || tmp->type == DESTRUCT_IN_MENU)
        && tmp->state == 1 && find_cursor(game, tmp) == false) {
            tmp->scale = (sfVector2f) {tmp->scale.x - 0.05, tmp->scale.y - 0.05};
            tmp->state = 0;
        }
    }
    return (object);
}

void add_object(element_list **object, struct use_full *uses)
{
    for (element_list *tmp = (*object); tmp; tmp = tmp->next) {
        add_tower(tmp, uses, object);
    }
}

void create_menu(element_list **object, sfRenderWindow *game,
                         element_list *map, char **buffer)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game);
    int x = pos.x / (1920 / my_strlen(buffer[0]));
    int y = pos.y / (1080 / find_nb_line(buffer)) - 1;

    (*object) = delete_menu((*object));
    if (buffer[y + 1][x] == 'T') {
        (*object) = add_inlist((*object), create_tower_menu_base(map->pos.x,
                                         map->pos.y), len_list((*object)));
        (*object) = add_inlist((*object), create_tower_menu_tower(map->pos.x,
                   map->pos.y, "content/tower1.png"), len_list((*object)));
        (*object) = add_inlist((*object), create_tower_menu_tower(map->pos.x,
                   map->pos.y, "content/tower2.png"), len_list((*object)));
        for (element_list *tmp = (*object); tmp; tmp = tmp->next)
            if (!tmp->next) {
                tmp->type = TOWER2_IN_MENU;
                tmp->pos.y += 90;
                break;
            }
        (*object) = add_inlist((*object), create_destruct_menu_tower(map->pos.x + 160,
                   map->pos.y + 80, "content/destruct.png"),
    len_list((*object)));
    }
}

element_list *check_for_clic(struct use_full *uses, element_list *map,
                             element_list *object)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(uses->game);
    int x = pos.x / (1920 / my_strlen(uses->buffer[0]));
    int y = pos.y / (1080 / find_nb_line(uses->buffer)) - 1;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        while ((map->pos.x / (1920 / my_strlen(uses->buffer[0])) < x || map->pos.y
                / (1080 / find_nb_line(uses->buffer)) < y ) && map->next)
            map = map->next;
        delete_tower(&object, uses->game, uses->buffer, &uses->text_money);
        add_object(&object, uses);
        create_menu(&object, uses->game, map, uses->buffer);
    }
    return (object);
}
