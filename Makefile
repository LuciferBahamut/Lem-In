##
## EPITECH PROJECT, 2020
## lem-in
## File description:
## makefile
##

NAME	=	lem_in

SRC	=	src/main.c		\
		src/read_file.c		\
		src/first_display.c	\
		$(wildcard util/*.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wextra -Wall

CPPFLAGS=	-I./include/

all	:	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(OBJ) $(CPPFLAGS)

debug	:	CFLAGS += -g
debug	:	re

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all debug clean fclean re
