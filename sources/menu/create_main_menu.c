/*
** EPITECH PROJECT, 2021
** main
** File description:
** menu
*/

#include "my_defender.h"
#include "my.h"

sfSprite *screen_fund(char *str, double a, double b)
{
    sfTexture *background_img;
    sfSprite *sprite_background;
    sfVector2f offset_background = {a, b};

    background_img = sfTexture_createFromFile(str, NULL);
    sprite_background = sfSprite_create();
    sfSprite_setTexture(sprite_background, background_img, 1);
    sfSprite_setScale(sprite_background, offset_background);
    return (sprite_background);
}

int seasons_menu(sfRenderWindow *game, sfVideoMode video)
{
    struct text seasons = take_seasons_struct(seasons, video);
    sfSprite *fund = screen_fund("content/seasons.jpg", 1.01, 1.1);

    while (sfRenderWindow_isOpen(game)) {
        sfRenderWindow_display(game);
        while (sfRenderWindow_pollEvent(game, &seasons.event)) {
            if (seasons.event.type == sfEvtClosed)
                sfRenderWindow_close(game);
        }
        sfRenderWindow_clear(game, sfBlack);
        sfRenderWindow_drawSprite(game, fund, NULL);
        sfRenderWindow_drawText(game, seasons.b, NULL);
        sfRenderWindow_drawText(game, seasons.c, NULL);
        sfRenderWindow_drawText(game, seasons.a, NULL);
        check_curs_on_button(seasons.a, &game, sfColor_fromRGB(0, 0, 0));
        check_curs_on_button(seasons.b, &game, sfColor_fromRGB(0, 0, 0));
        check_curs_on_button(seasons.c, &game, sfColor_fromRGB(0, 0, 0));
        if (check_clic(game, seasons.a)) {
            return (2);
        } if (check_clic(game, seasons.b)) {
            return (1);
        } if (check_clic(game, seasons.c)) {
            return (0);
        }
    }
    return (0);
}

void check_curs_on_button(sfText *text, sfRenderWindow **game, sfColor color)
{
    if (check_curs(*game, text) == sfTrue) {
        sfText_setColor(text, sfColor_fromRGB(255, 255, 255));
        sfText_setCharacterSize(text, 120);
    } else {
        sfText_setColor(text, sfColor_fromRGB(color.r, color.g, color.b));
        sfText_setCharacterSize(text, 100);
    }
}

int create_main_menu(sfRenderWindow *game, sfVideoMode video)
{
    struct text main = take_main_struct(main, video);
    sfSprite *fund = screen_fund("content/main_menu_fund.jpg", 1, 1);
    int n = 0;

    while (sfRenderWindow_isOpen(game)) {
        while (sfRenderWindow_pollEvent(game, &main.event)) {
            if (main.event.type == sfEvtClosed)
                sfRenderWindow_close(game);
        } sfRenderWindow_display(game);
        if (check_clic(game, main.a)) {
            return (2);
        } else if (check_clic(game, main.c)) {
            sfRenderWindow_clear(game, sfBlack);
            return (seasons_menu(game, video));
        } else if (check_clic(game, main.d)) {
            return (3);
        } else if (check_clic(game, main.b)) {
            n = rules_menu(game, video);
            if (n == 1)
                sfRenderWindow_close(game);
            create_main_menu(game, video);
        }
        sfRenderWindow_clear(game, sfBlack);
        check_curs_on_button(main.a, &game, sfColor_fromRGB(0, 0, 0));
        check_curs_on_button(main.b, &game, sfColor_fromRGB(0, 0, 0));
        check_curs_on_button(main.c, &game, sfColor_fromRGB(0, 0, 0));
        check_curs_on_button(main.d, &game, sfColor_fromRGB(0, 0, 0));
        sfRenderWindow_drawSprite(game, fund, NULL);
        sfRenderWindow_drawText(game, main.a, NULL);
        sfRenderWindow_drawText(game, main.b, NULL);
        sfRenderWindow_drawText(game, main.c, NULL);
        sfRenderWindow_drawText(game, main.d, NULL);
    }
    return (0);
}
