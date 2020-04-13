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
		src/fill_struct.c	\
		src/fill_rooms.c	\
		src/check_buff.c	\
		src/multi_cmp.c		\
		src/check_tunnel.c	\
		$(wildcard util/*.c)

OBJ	=	$(SRC:.c=.o)

CC	?=	gcc

CFLAGS	=	-W -Wextra -Wall

CPPFLAGS=	-I./include/

name	:	all

all	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

debug	:	CFLAGS += -g
debug	:	re

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	name all debug clean fclean re
