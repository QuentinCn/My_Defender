/*
** EPITECH PROJECT, 2021
** create_texture.c
** File description:
** manage with texture creation
*/

#include <SFML/Graphics.h>

sfTexture *create_grass_texture(int left, int top, int width, int height)
{
    sfIntRect area = {left, top, width, height};
    sfTexture *text = sfTexture_createFromFile("content/grass_theme.jpg",
                                               &area);

    return (text);
}
