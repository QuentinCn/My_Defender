/*
** EPITECH PROJECT, 2021
** display_window.c
** File description:
** manage display of the window
*/

#include "my_defender.h"
#include "my.h"

static sfRenderWindow *draw_other_object(sfRenderWindow *game, element_list
                                         *tmp, sfRectangleShape *life,
                                         sfCircleShape *circle)
{
    if (tmp->type == TOWER)
        if (find_cursor(game, tmp))
            game = draw_circle(game, circle, (sfVector2f) {tmp->pos.x +
                    (sfTexture_getSize(tmp->texture).x * tmp->scale.x)  / 2,
                    tmp->pos.y + (sfTexture_getSize(tmp->texture).y *
                                  tmp->scale.y) / 1.5}, tmp->range);
    if (tmp->type == ENEMY)
        game = draw_rectangle(game, life, tmp->pos, tmp->life);
    return (game);
}

sfRenderWindow *manage_object(struct use_full *uses, element_list **object,
                              sfClock *clock, element_list **map)
{
    sfCircleShape *circle = create_circle();
    sfRectangleShape *life = create_rectangle();

    for (element_list *tmp = (*object); tmp; tmp = tmp->next) {
        uses->game = draw_other_object(uses->game, tmp, life, circle);
        anime_tower(&tmp, sfTime_asSeconds(sfClock_getElapsedTime(clock)),
                    object, uses);
        if (check_enemy(object, uses, map) == 1)
            sfRenderWindow_close(uses->game);
        anime_enemy(&tmp, sfTime_asSeconds(sfClock_getElapsedTime(clock)));
        move_enemy(&tmp, sfTime_asSeconds(sfClock_getElapsedTime(clock)));
        anime_portal(&tmp, sfTime_asSeconds(sfClock_getElapsedTime(clock)));
        anime_gold(&tmp, sfTime_asSeconds(sfClock_getElapsedTime(clock)));
        //damage_flame(object, sfTime_asSeconds(sfClock_getElapsedTime(clock)));
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 1)
            sfClock_restart(clock);
    }
    return (uses->game);
}

void display_window(struct use_full *uses, element_list *map, element_list
                    *object)
{
    sfEvent event;
    sfClock *time = sfClock_create();
    int pause = 0;
    int wave = 1;
    int a = 0;

    uses->text_money = create_money();
    while (sfRenderWindow_isOpen(uses->game)) {
        sfRenderWindow_clear(uses->game, sfTransparent);
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            pause = create_pause_menu(uses->game, (sfVideoMode) {1920, 1018, 32});
        while (sfRenderWindow_pollEvent(uses->game, &event))
            if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
                sfRenderWindow_close(uses->game);
        if (pause == -1)
            sfRenderWindow_close(uses->game);
        else if (pause == 1) {
            object = free_list(object);
            object = create_end(object, uses->buffer);
            display_window(uses, map, object);
            sfRenderWindow_close(uses->game);
        }
        if (a == 200) {
            wave = wave + 1;
            a = 0;
        } if (sfTime_asSeconds(sfClock_getElapsedTime(time)) >= 0.9)
              a++;
        object = add_enemy(object, uses->buffer, wave,
                           sfTime_asSeconds(sfClock_getElapsedTime(time)));
        uses->game = draw_in_win(uses->game, map);
        object = look_cursor(object, uses->game);
        object = check_for_clic(uses, map, object);
        uses->game = manage_object(uses, &object, time, &map);
        if (object)
            uses->game = draw_in_win(uses->game, object);
        sfRenderWindow_drawText(uses->game, uses->text_money, NULL);
        sfRenderWindow_display(uses->game);
    }
    sfRenderWindow_destroy(uses->game);
}
