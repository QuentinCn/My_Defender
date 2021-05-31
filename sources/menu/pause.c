/*
** EPITECH PROJECT, 2021
** pause.c
** File description:
** manage the pause menu
*/

#include "my_defender.h"
#include "my.h"

struct text take_pause_struct(struct text pause, sfVideoMode video)
{
    int size = video.width / 20;

    pause.a = create_button(pause.a, "Play",
    (sfVector2f) {video.width / 2 - size * 3.5 / 2, video.height / 3});
    pause.b = create_button(pause.b, "Restart", 
    (sfVector2f) {video.width / 1.5 - 0.1 * size, 800});
    pause.c = create_button(pause.c, "Exit",
    (sfVector2f) {video.width / 2 - 9 * size, 800});
    return(pause);
}

int create_pause_menu(sfRenderWindow *game, sfVideoMode video)
{
    struct text pause = take_pause_struct(pause, video);
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
        check_curs_on_button(pause.a, &game, sfColor_fromRGB(255, 255, 255));
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
