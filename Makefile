##
## EPITECH PROJECT, 2023
## make file
## File description:
## makes stuff
##

SRC	=			src/main.c		\
				src/menu/menu.c	\

CC	?=	gcc

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

LCSFML	=	-lcsfml-system -lcsfml-window -lcsfml-network -lcsfml-graphics

CPPFLAGS	=	-iquote./include/

CFLAGS	=	-L./libCSFML -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./libCSFML -I libCSFML
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS) $(LCSFML)

clean:
		$(RM) $(OBJ)
		make fclean -C ./libCSFML -I libCSFML

fclean: 	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
