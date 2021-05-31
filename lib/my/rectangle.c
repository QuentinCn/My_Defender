/*
** EPITECH PROJECT, 2021
** rectangle.c
** File description:
** manage sfRectangleShape
*/

#include <SFML/Graphics.h>
#include <stddef.h>

sfRectangleShape *create_rectangle(void)
{
    sfRectangleShape *life = sfRectangleShape_create();

    return (life);
}

sfRenderWindow *draw_rectangle(sfRenderWindow *game, sfRectangleShape
                               *rectangle, sfVector2f pos, int life)

{
    sfRectangleShape_setSize(rectangle, (sfVector2f) {life * 0.8, 3});
    sfRectangleShape_setFillColor(rectangle, sfColor_fromRGB(200, 0, 0));
    sfRectangleShape_setOutlineColor(rectangle, sfColor_fromRGB(200, 0, 0));
    sfRectangleShape_setPosition(rectangle, (sfVector2f) {pos.x + 5, pos.y});
    sfRenderWindow_drawRectangleShape(game, rectangle, NULL);
    return (game);
}
