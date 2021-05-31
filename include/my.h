/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** lib's .h
*/

#ifndef MY
#define MY

#include <SFML/Graphics.h>
#include <stdbool.h>

char **fopen_getline(char **buffer, char *filename);
sfTexture *create_grass_texture(int left, int top, int width, int height);
int my_strlen(char *str);
int find_len_max(char **buffer);
int find_nb_line(char **buffer);
char *create_line(char c, int len);
int check_clic(sfRenderWindow *menu, sfText *button);
sfCircleShape *create_circle(void);
sfRenderWindow *draw_circle(sfRenderWindow *game, sfCircleShape *circle,
                            sfVector2f pos, float range);
char *find_path(char **buffer);
bool is_around(float x, float y);
bool is_around_time(float time, float speed);
sfRenderWindow *draw_rectangle(sfRenderWindow *game, sfRectangleShape
                               *rectangle, sfVector2f pos, int life);
sfRectangleShape *create_rectangle(void);
char *my_itoc(int nb);
int my_getnbr(char const *nb);

#endif /* !MY */
