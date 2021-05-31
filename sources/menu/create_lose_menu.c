/*
** EPITECH PROJECT, 2021
** season
** File description:
** choice
*/

#include "my.h"
#include "my_defender.h"

int lose_menu(struct use_full *uses, element_list **object, element_list **map)
{
    int n = create_lose_menu(uses->game, uses->video);

    if (n == -1) {
        sfRenderWindow_close(uses->game);
        return (-1);
    } if (n == 0) {
        (*object) = free_list(*object);
        sfRenderWindow_clear(uses->game, sfBlack);
        display_window(uses, *map, *object);
    } if (n == 1) {
        (*object) = free_list(*object);
        (*map) = free_list(*map);
        sfRenderWindow_clear(uses->game, sfBlack);
        play(uses->buffer);
    }
    return (0);
}

int create_lose_menu(sfRenderWindow *game, sfVideoMode video)
{
    struct text pause = take_lose_struct(pause, video);
    sfSprite *fund = screen_fund("content/menu_pause.png", 1, 1);

    while (sfRenderWindow_isOpen(game)) {
        sfRenderWindow_clear(game, sfBlack);
        sfRenderWindow_drawSprite(game, fund, NULL);
        sfRenderWindow_drawText(game, pause.a, NULL);
        sfRenderWindow_drawText(game, pause.b, NULL);
        sfRenderWindow_drawText(game, pause.c, NULL);
        while (sfRenderWindow_pollEvent(game, &pause.event)) {
            if (pause.event.type == sfEvtClosed ||
                sfKeyboard_isKeyPressed(sfKeyEscape))
                return (-1);
        }
        sfRenderWindow_display(game);
        check_curs_on_button(pause.b, &game, sfColor_fromRGB(255, 255, 255));
        check_curs_on_button(pause.c, &game, sfColor_fromRGB(255, 255, 255));
        if (check_clic(game, pause.a)) {
            return (0);
        } else if (check_clic(game, pause.b)) {
            return (1);
        } else if (check_clic(game, pause.c)) {
            return (-1);
        }
    }
    return (-1);
}