/*
** EPITECH PROJECT, 2021
** main
** File description:
** menu
*/

#include "my_defender.h"

sfText *create_button(sfText *play, char *str, sfVector2f play_pos)
{
    sfFont *font = sfFont_createFromFile("content/Medieval.ttf");

    play = sfText_create();
    sfText_setString(play, str);
    sfText_setFont(play, font);
    sfText_setPosition(play, play_pos);
    return (play);
}

sfText *create_text_go(sfText *play, char *str, sfVector2f play_pos)
{
    sfFont *font = sfFont_createFromFile("content/Medieval.ttf");

    play = sfText_create();
    sfText_setString(play, str);
    sfText_setCharacterSize(play, 200);
    sfText_setFont(play, font);
    sfText_setPosition(play, play_pos);
    return (play);
}