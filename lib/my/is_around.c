/*
** EPITECH PROJECT, 2021
** is_around_time.c
** File description:
** check if a float is around time
*/

#include <stdbool.h>

bool is_around_time(float time, float speed)
{
    for (int i = 1; speed * i < 1; i += 1)
        if (time >= speed * i - 0.01 && time <= speed * i + 0.01)
            return (true);
    return (false);
}

bool is_around(float x, float y)
{
    if (x >= y - 0.1 && x <= y + 0.1)
        return (true);
    return (false);
}
