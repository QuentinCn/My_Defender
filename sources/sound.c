/*
** EPITECH PROJECT, 2021
** sound
** File description:
** sound
*/

#include "my_defender.h"

t_sound play_sound(char *filename)
{
    t_sound st_sound;

    st_sound.buffer = sfSoundBuffer_createFromFile(filename);
    st_sound.sound = sfSound_create();
    sfSound_setBuffer(st_sound.sound, st_sound.buffer);
    sfSound_setVolume(st_sound.sound, 100);
    return (st_sound);
}

void destroy_sound(t_sound *st_sound)
{
    sfSoundBuffer_destroy(st_sound->buffer);
    sfSound_destroy(st_sound->sound);
}

sfMusic *play_music(char *filename)
{
    sfMusic *music = sfMusic_createFromFile(filename);

    sfMusic_setVolume(music, 5);
    sfMusic_setLoop(music, 1);
    sfMusic_play(music);
    return (music);
}