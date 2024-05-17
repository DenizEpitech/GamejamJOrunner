##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	create_sprite_texture.c			\
		int_to_str.c 					\
		click_sprite.c 					\
		creatd_circle_rectangle.c 		\
		sprite_set_new_texture.c 		\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

LCSFML	=	-lcsfml-system -lcsfml-window -lcsfml-network -lcsfml-graphics -lm

CFLAG	=	-W -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		$(RM) *.o

fclean: 	clean
		$(RM) $(NAME)

re:		fclean all

tests_run:	$(CC) $(SRC) --coverage -lcriterion -o $(TNAME)

.PHONY:		all clean fclean re tests_run
