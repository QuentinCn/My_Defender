/*
** EPITECH PROJECT, 2021
** check_clic.c
** File description:
** manage button hit box
*/

#include <SFML/Graphics.h>

int check_clic(sfRenderWindow *menu, sfText *button)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(menu);
    sfVector2f button_pos = sfText_getPosition(button);
    unsigned int button_size = sfText_getCharacterSize(button);

    while (sfMouse_isButtonPressed(sfMouseLeft) == 0)
        return (0);
    while (mouse_pos.x < button_pos.x || mouse_pos.y < button_pos.y ||
    mouse_pos.x > button_pos.x + button_size * 2 || mouse_pos.y > button_pos.y
    + button_size)
        return (0);
    return (1);
}
