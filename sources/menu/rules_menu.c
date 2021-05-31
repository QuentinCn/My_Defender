/*
** EPITECH PROJECT, 2021
** rules
** File description:
** menu
*/

#include <stdlib.h>
#include "my.h"
#include "my_defender.h"

sfBool check_curs(sfRenderWindow *menu, sfText *button)
{
    sfFloatRect text = sfText_getGlobalBounds(button);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(menu);
    int x = 0;
    int y = 0;
    
    x = mouse.x;
    y = mouse.y;
    return (sfFloatRect_contains(&text, x, y)); 
}

static int my_strlen_text(char **text_rules)
{
    int a = 0;
    int b = 0;
    int c = 0;

    while (text_rules[a] != NULL) {
        while (text_rules[a][b] != '\0') {
            b++;
            c++;
        }
        b = 0;
        a++;
    }
    return (c);
}

static char *take_text(char *rules, char **text_rules)
{
    int a = 0;
    int b = 0;
    int c = 0;

    while (text_rules[a] != NULL) {
        while (text_rules[a][b] != '\0') {
            rules[c] = text_rules[a][b];
            c++;
            b++;
        }
        rules[c] = '\n';
        c++;
        b = 0;
        a++;
    }
    rules[c] = '\0';
    return (rules);
}

static sfText *create_rules_text(sfText *rules, char *str)
{
    sfFont *font = sfFont_createFromFile("content/Medieval.ttf");
    int size = 40;
    sfVector2f exit_pos = {10, 10};

    rules = sfText_create();
    sfText_setString(rules, str);
    sfText_setFont(rules, font);
    sfText_setCharacterSize(rules, size);
    sfText_setPosition(rules, exit_pos);
    sfText_setColor(rules, sfColor_fromRGB(0, 0, 0));
    return (rules);
}

static char *modify_rules_text(char **text_rules)
{
    int all = my_strlen_text(text_rules);
    char *rules = malloc(sizeof(char) * all);

    rules = take_text(rules, text_rules);
    return (rules);
}

int rules_menu(sfRenderWindow *game, sfVideoMode video)
{
    char **text_rules = NULL;
    char *rules;
    int size = video.width / 20;
    sfText *quit = NULL;
    sfSprite *fund = screen_fund("content/rules_menu.png", 1.6, 1.5);
    sfEvent event;
    sfText *rules_text = NULL;

    text_rules = fopen_getline(text_rules, "content/rules.txt");
    rules = modify_rules_text(text_rules);
    rules_text = create_rules_text(rules_text, rules);
    quit = create_button(quit, "Quit", (sfVector2f) {video.width - size * 4,
    video.height - size * 2.8});
    while (!check_clic(game, quit)) {
        while (sfRenderWindow_pollEvent(game, &event)) {
            if (event.type == sfEvtClosed)
                return(1);
        }
        sfRenderWindow_clear(game, sfBlack);
        sfRenderWindow_drawSprite(game, fund, NULL);
        sfRenderWindow_drawText(game, quit, NULL);
        sfRenderWindow_drawText(game, rules_text, NULL);
        sfRenderWindow_display(game);
        check_curs_on_button(quit, &game, sfColor_fromRGB(0, 0, 0));
    }
    sfRenderWindow_clear(game, sfBlack);
    return (0);
}
