/*
** EPITECH PROJECT, 2021
** circle.c
** File description:
** manage tower range
*/

#include <SFML/Graphics.h>
#include <stddef.h>

sfCircleShape *create_circle(void)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setOutlineThickness(circle, 2);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, sfColor_fromRGB(0, 0, 0));
    return (circle);
}

sfRenderWindow *draw_circle(sfRenderWindow *game, sfCircleShape *circle,
                            sfVector2f pos, float range)
{
    sfCircleShape_setRadius(circle, range);
    pos.x -= range;
    pos.y -= range;
    sfCircleShape_setPosition(circle, pos);
    sfRenderWindow_drawCircleShape(game, circle, NULL);
    return (game);
}
