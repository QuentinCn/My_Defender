/*
** EPITECH PROJECT, 2021
** map.c
** File description:
** handle map
*/

#include "my_defender.h"
#include "my.h"
#include <stdlib.h>

element_list *create_map_element(char **buffer, int i, int j, char *map)
{
    element_list *element = malloc(sizeof(*element));
    float size[2] = {1920, 1080};
    float len[2] = {my_strlen(buffer[j]), find_nb_line(buffer) + 1};

    switch (buffer[j][i]) {
    case ('#'):
        element->area = (sfIntRect) {57, 0, 53, 53};
        element->texture = sfTexture_createFromFile(map, &element->area);
        break;
    case ('0'):
        element->area = (sfIntRect) {169, 113, 53, 53};
        element->texture = sfTexture_createFromFile(map, &element->area);
        break;
    case ('1'):
        element->area = (sfIntRect) {113, 0, 53, 53};
        element->texture = sfTexture_createFromFile(map, &element->area);
        break;
    case ('2'):
        element->area = (sfIntRect) {1, 169, 53, 53};
        element->texture = sfTexture_createFromFile(map, &element->area);
        break;
    case ('3'):
        element->area = (sfIntRect) {1, 113, 53, 53};
        element->texture = sfTexture_createFromFile(map, &element->area);
        break;
    case ('4'):
        element->area = (sfIntRect) {113, 57, 53, 53};
        element->texture = sfTexture_createFromFile(map, &element->area);
        break;
    case ('5'):
        element->area = (sfIntRect) {57, 57, 53, 53};
        element->texture = sfTexture_createFromFile(map, &element->area);
        break;
    case ('T'):
        element->area = (sfIntRect) {1, 0, 53, 53};
        element->texture = sfTexture_createFromFile(map, &element->area);
        break;
    case ('B'):
        element->area = (sfIntRect) {169, 113, 53, 53};
        element->texture = sfTexture_createFromFile(map, &element->area);
        break;
    case ('E'):
        element->area = (sfIntRect) {169, 113, 53, 53};
        element->texture = sfTexture_createFromFile(map, &element->area);
        break;
    default:
        element->area = (sfIntRect) {0, 0, 0, 0};
        element->texture = sfTexture_createFromFile(map, &element->area);
        break;
    }
    element->type = MAP;
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, 1);
    element->pos = (sfVector2f) {i * (size[0] / len[0]), j * (size[1] / len[1])};
    element->scale = (sfVector2f) {size[0] / len[0] / 50, size[1] / len[1] / 50};
    element->speed = 0;
    element->life = -1;
    element->next = NULL;
    element->prev = NULL;
    return (element);
}

element_list *create_map(element_list *map, char **buffer, char *texture)
{
    for (int i = 0; buffer[i]; i += 1) {
        for (int j = 0; buffer[i][j] != '\0'; j += 1) {
            map = add_inlist(map, create_map_element(buffer, j, i, texture),
                             len_list(map));
        }
    }
    return (map);
}

sfRenderWindow *draw_in_win(sfRenderWindow *win, element_list *map)
{
    while (map) {
        sfSprite_setScale(map->sprite, map->scale);
        sfSprite_setPosition(map->sprite, map->pos);
        sfRenderWindow_drawSprite(win, map->sprite, NULL);
        map = map->next;
    }
    return (win);
}
