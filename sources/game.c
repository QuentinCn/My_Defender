/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** manage the game
*/

#include "my_defender.h"
#include <stdlib.h>
#include <SFML/Audio.h>

element_list *create_end(element_list *object, char **buffer)
{
    for (int i = 0; buffer[i]; i += 1)
        for (int j = 0; buffer[i][j] != '\0'; j += 1) {
            if (buffer[i][j] == 'B')
                object = add_inlist(object, create_portal(buffer, j, i),
                                    len_list(object));
            if (buffer[i][j] == 'E') {
                object = add_inlist(object, create_end_tower(buffer, j, i),
                                    len_list(object));
                object = add_inlist(object, create_end_life(buffer, j, i),
                                    len_list(object));
            }
        }
    return (object);
}

void play(char **buffer)
{
    t_sound sound_play = play_sound("content/play.ogg");;
    sfMusic *sound = play_music("content/Hell.ogg");
    element_list *map = NULL;
    element_list *object = NULL;
    struct use_full uses = {NULL};
    int n = 0;

    uses.sound = play_sound("content/death.ogg");
    uses.video = (sfVideoMode) {1920, 1018, 32};
    uses.game = sfRenderWindow_create(uses.video, 
    "Sau6 Studio", sfClose | sfResize, NULL);
    uses.buffer = buffer;
    sfRenderWindow_setFramerateLimit(uses.game, 60);
    n = create_main_menu(uses.game, uses.video);
    if (n <= 2) {
        sfSound_play(sound_play.sound);
        if (n == 2)
            map = create_map(map, buffer, "content/grass_theme.jpg");
        if (n == 1)
            map = create_map(map, buffer, "content/winter_theme.jpg");
        if (n == 0)
            map = create_map(map, buffer, "content/roc_theme.jpg");
        object = create_end(object, buffer);
        object = add_inlist(object, create_gold(), len_list(object));
        display_window(&uses, map, object);
    }
    destroy_sound(&sound_play);
    destroy_sound(&uses.sound);
    sfMusic_destroy(sound);
}
