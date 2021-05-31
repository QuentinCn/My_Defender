
##
## EPITECH PROJECT, 2020
## makefile
## File description:
## Makefile
##

SRC	=	sources/main.c				\
		sources/map.c				\
		sources/add_get_len_free_list.c		\
		sources/create_print_free_list.c	\
		sources/game.c				\
		sources/display_window.c		\
		sources/manage_buffer.c			\
		sources/mouse.c				\
		sources/portal.c			\
		sources/end_tower.c			\
		sources/find_pos.c			\
		sources/is_there_tower.c		\
		sources/tower/tower1.c			\
		sources/tower/tower2.c			\
		sources/tower/damage_flame.c		\
		sources/tower/tower_animation.c		\
		sources/tower/anime_projectile.c	\
		sources/tower/add_tower.c		\
		sources/tower/tower_menu.c		\
		sources/enemy/enemy.c			\
		sources/menu/create_main_menu.c		\
		sources/menu/create_button.c		\
		sources/menu/pause.c			\
		sources/menu/rules_menu.c		\
		sources/menu/take_button_struct.c	\
		sources/money/money.c			\
		sources/money/manage_money.c	\
		sources/menu/create_lose_menu.c	\
		sources/sound.c

NAME	=	my_defender

CSFML	=	-lcsfml-graphics -lcsfml-system -l csfml-window -lcsfml-audio

LIB	=	-L./lib -lmy -I./include

ERROR	=	-Wall -Wextra

all:	 $(NAME)

libmy:
	make -sC lib/my

$(NAME):	libmy
	gcc -o $(NAME) $(ERROR) $(SRC) $(LIB) $(CSFML) -g3
	echo -e "\033[00m\033[32mCompilation done => ${NAME}\033[00m"

clean:
	$(shell find -name "*.gcda" -delete)
	$(shell find -name "*.gcno" -delete)
	$(shell find -name "#*#" -delete -o -name "*~" -delete)
	make -sC lib/my clean

fclean:	clean
	rm -f $(NAME)
	make -sC lib/my fclean
	clear

re:	fclean all

