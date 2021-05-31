/*
** EPITECH PROJECT, 2021
** money.c
** File description:
** manage the money
*/

#include "my_defender.h"
#include "my.h"
#include <stdlib.h>

sfText *create_money(void)
{
    sfText *money_text = sfText_create();

    money_text = create_button(money_text, my_itoc(120), (sfVector2f) {0, 0});
    sfText_setCharacterSize(money_text, 50);
    sfText_setPosition(money_text, (sfVector2f) {80, 0});
    return (money_text);
}

element_list *create_gold(void)
{
    element_list *element = malloc(sizeof(*element));

    element->area = (sfIntRect) {10, 86, 65, 65};
    element->texture = sfTexture_createFromFile("content/money.png",
                                                &element->area);
    element->type = GOLD;
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, 1);
    element->scale = (sfVector2f) {0.9, 0.9};
    element->pos = (sfVector2f) {5, 5};
    element->speed = 0.09;
    element->life = -1;
    element->state = 0;
    element->next = NULL;
    element->prev = NULL;
    return (element);
}

static void other_case(element_list **element)
{
    switch ((*element)->state) {
    case (4):
        (*element)->area = (sfIntRect) {260, 86, 40, 65};
        (*element)->state = 5;
        return;
    case (5):
        (*element)->area = (sfIntRect) {300, 86, 60, 65};
        (*element)->state = 6;
        return;
    case (6):
        (*element)->area = (sfIntRect) {415, 86, 65, 65};
        (*element)->state = 7;
        return;
    case (7):
        (*element)->area = (sfIntRect) {485, 86, 65, 65};
        (*element)->state = 0;
        return;
    }
}

static void first_case(element_list **element)
{
    switch ((*element)->state) {
    case (0):
        (*element)->area = (sfIntRect) {10, 86, 65, 65};
        (*element)->state = 1;
        return;
    case (1):
        (*element)->area = (sfIntRect) {80, 86, 65, 65};
        (*element)->state = 2;
        return;
    case (2):
        (*element)->area = (sfIntRect) {150, 86, 65, 65};
        (*element)->state = 3;
        return;
    case (3):
        (*element)->area = (sfIntRect) {210, 86, 60, 65};
        (*element)->state = 4;
        return;
    default:
        other_case(element);
        return;
    }
}

void anime_gold(element_list **element, float time)
{
    if ((*element)->type != GOLD)
        return;
    if (!is_around_time(time, (*element)->speed))
        return;
    first_case(element);
    (*element)->texture = sfTexture_createFromFile("content/money.png",
                                                &(*element)->area);
    sfSprite_setTexture((*element)->sprite, (*element)->texture, 1);
}
