/*
** EPITECH PROJECT, 2021
** manage_money.c
** File description:
** manage the player's money
*/

#include "my.h"

sfText *change_money(sfText *text_money, int to_add)
{
    int amount = my_getnbr(sfText_getString(text_money));

    amount += to_add;
    sfText_setString(text_money, my_itoc(amount));
    return (text_money);
}

bool is_there_enough_money(sfText *text_money)
{
    int amount = my_getnbr(sfText_getString(text_money));

    if (amount >= 50)
        return (true);
    else
        return (false);
}
