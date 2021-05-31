/*
** EPITECH PROJECT, 2021
** my_defender.h
** File description:
** .h
*/

#ifndef MY_DEFENDER
#define MY_DEFENDER

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>

#define MAP (0)
#define TOWER (1)
#define TOWER_PART (2)
#define ROC (3)
#define TOWER_MENU (4)
#define TOWER1_IN_MENU (5)
#define PORTAL (6)
#define ENEMY (7)
#define END (8)
#define END_LIFE (9)
#define DESTRUCT_IN_MENU (10)
#define GOLD (11)
#define TOWER2_IN_MENU (12)
#define FLAME (13)
#define DAMAGE_FLAME (14)

typedef struct list_element
{
    int type;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f start_pos;
    int state;
    sfVector2f scale;
    sfIntRect area;
    int life;
    float speed;
    float range;
    char *path;
    struct list_element *next;
    struct list_element *prev;
} element_list;

struct text
{
    sfEvent event;
    sfText *a;
    sfText *b;
    sfText *c;
    sfText *d;
};

typedef struct info_sound
{
    sfSoundBuffer *buffer;
    sfSound *sound;
}t_sound;

struct use_full
{
    char **buffer;
    sfRenderWindow *game;
    sfVideoMode video;
    sfText *text_money;
    t_sound sound;
};

element_list *add_inlist(element_list *list, element_list *element, int pos);
element_list *get_inlist(element_list *list, int pos);
int len_list(element_list *list);
element_list *free_inlist(element_list *list, int pos);
element_list *free_list(element_list *list);
void play(char **buffer);
sfRenderWindow *draw_in_win(sfRenderWindow *win, element_list *list);
element_list *create_map(element_list *list, char **buffer, char *map);
element_list *create_tower(element_list *list, char **buffer, int i, int j);
void play(char **buffer);
void display_window(struct use_full *uses, element_list *map, element_list
*object);
char **modify_buffer(char **buffer);
element_list *check_for_clic(struct use_full *uses, element_list *map,
                             element_list *object);
element_list *create_tower_menu_base(float i, float j);
element_list *create_tower_menu_tower(float i, float j, char *filename);
element_list *delete_menu(element_list *object);
element_list *create_portal(char **buffer, int i, int j);
sfIntRect move_portal_area(sfIntRect area);
element_list *look_cursor(element_list *object, sfRenderWindow *game);
void anime_tower(element_list **element, float time, element_list **object,
struct use_full *uses);
sfVector2f find_pos(char **buffer, int i, int j, element_list *element);
int create_main_menu(sfRenderWindow *game, sfVideoMode video);
sfText *create_button(sfText *play, char *str, sfVector2f vect);
element_list *create_end(element_list *object, char **buffer);
bool is_there_tower(element_list *object, char **buffer, int i, int j);
element_list *add_enemy(element_list *object, char **buffer, int wave, float time);
void anime_enemy(element_list **element, float time);
void move_enemy(element_list **element, float time);
void anime_portal(element_list **element, float time);
int rules_menu(sfRenderWindow *game, sfVideoMode video);
sfBool check_curs(sfRenderWindow *menu, sfText *button);
struct text take_seasons_struct(struct text seasons, sfVideoMode video);
struct text take_main_struct(struct text main, sfVideoMode video);
struct text take_lose_struct(struct text pause, sfVideoMode video);
bool find_cursor(sfRenderWindow *game, element_list *element);
sfSprite *screen_fund(char *str, double a, double b);
void check_curs_on_button(sfText *text, sfRenderWindow **game, sfColor color);
void hit_enemy(element_list **element, sfVector2f enemy_pos, int damage);
int check_enemy(element_list **object, struct use_full *uses, element_list **map);
int create_pause_menu(sfRenderWindow *game, sfVideoMode video);
element_list *create_end_tower(char **buffer, int i, int j);
element_list *create_end_life(char **buffer, int i, int j);
element_list *create_destruct_menu_tower(float i, float j, char *filename);
int change_life(element_list **element);
sfText *create_money(void);
element_list *create_gold(void);
void anime_gold(element_list **element, float time);
sfText *change_money(sfText *text_money, int to_add);
bool is_there_enough_money(sfText *text_money);
void is_there_tower_delete(element_list **object, char **buffer);
int lose_menu(struct use_full *uses, element_list **object, element_list **map);
struct text take_lose_struct(struct text pause, sfVideoMode video);
int create_lose_menu(sfRenderWindow *game, sfVideoMode video);
sfText *create_text_go(sfText *play, char *str, sfVector2f play_pos);
void delete_tower(element_list **object, sfRenderWindow *game,
                         char **buffer, sfText **text_money);
sfMusic *play_music(char *filename);
t_sound play_sound(char *filename);
void destroy_sound(t_sound *st_sound);
void add_tower(element_list *element, struct use_full *uses, element_list
                **object);
 element_list *create_tower1_object_mid(char **buffer, int i, int j, char *
                                       filename);
 element_list *create_tower1_object_front(char **buffer, int i, int j, char *
                                        filename);
 element_list *create_tower1_object_back(char **buffer, int i, int j, char *
                                        filename);
 element_list *create_roc(char **buffer, int i, int j, char *filename);
 element_list *create_flame(char **buffer, int i, int j, char *filename);
 element_list *create_tower2_object_mid(char **buffer, int i, int j, char *
                                       filename);
 element_list *create_tower2_object_front(char **buffer, int i, int j, char *
                                         filename);
 element_list *create_tower2_object_back(char **buffer, int i, int j, char *
                                        filename);
 void move_flame(element_list **element, sfVector2f enemy_pos, int direction);
 void move_roc(element_list **element, element_list **object, sfVector2f
 enemy_pos);
void damage_flame(element_list **object, float time);

#endif /* !MY_DEFENDER */
