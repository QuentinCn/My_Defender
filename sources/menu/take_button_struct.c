/*
** EPITECH PROJECT, 2021
** take
** File description:
** button
*/

#include "my_defender.h"

struct text take_seasons_struct(struct text seasons, sfVideoMode video)
{
    int size = video.width / 20;

    seasons.a = create_button(seasons.a, "Summer",
    (sfVector2f) {video.width /  10, video.height / 2 - size * 2});
    seasons.b = create_button(seasons.b, "Winter", 
    (sfVector2f) {video.width / 2.3, video.height / 3 - size / 5});
    seasons.c = create_button(seasons.c, "Inferno", 
    (sfVector2f) {video.width - size * 5, video.height / 2 - size * 2});
    return(seasons);
}

struct text take_main_struct(struct text main, sfVideoMode video)
{
    int size = video.width / 20;

    main.a = create_button(main.a,"Play",
    (sfVector2f) {video.width / 2 - size * 3.5 / 2, video.height / 3});
    main.b = create_button(main.b, "Rules",
    (sfVector2f) {video.width / 2 + 4.37 * size, 800});
    main.c = create_button(main.c, "Seasons", 
    (sfVector2f) {video.width / 2 - size * 2.5, 800});
    main.d = create_button(main.d, "Exit", 
    (sfVector2f) {video.width / 2 - 9 * size, 800});
    return(main);
}

struct text take_lose_struct(struct text main, sfVideoMode video)
{
    int size = video.width / 20;

    main.a = create_text_go(main.a,"Game Over",
    (sfVector2f) {400, 200});
    main.b = create_button(main.b, "Back to the menu",
    (sfVector2f) {30, 800});
    main.c = create_button(main.c, "Restart", 
    (sfVector2f) {video.width / 4 + 4.2 * size * 2.5, 800});
    return(main);
}