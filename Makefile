##
## Makefile for matchstick in /home/benoit.pingris/delivery/CPE_2016_matchstick
## 
## Made by benoit pingris
## Login   <benoit.pingris@epitech.net>
## 
## Started on  Tue Feb 14 10:08:03 2017 benoit pingris
## Last update Fri Feb 17 20:14:34 2017 benoit pingris
##

CC	=	gcc -lc_graph_prog

NAME	=	matchstick

SRC	=	./main/main.c \
		./main/map.c \
		./main/draw.c \
		./main/musics.c \
		./main/free.c \
		./main/game.c \
		./main/game_2.c \
		./get_next_line/get_next_line.c \
		./useful/str.c \
		./useful/str_2.c \
		./my_printf/flag.c \
		./my_printf/hexa.c \
		./my_printf/octal_bin.c \
		./my_printf/my_printf.c \
		./my_printf/my_putstr_printf.c \
		./my_printf/my_strlen_printf.c \
		./my_printf/my_put_nbr_printf.c \
		./my_printf/my_putchar_printf.c \
		./my_printf/my_put_nbr_unsigned.c \

CFLAGS +=	-I./includes

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lncurses

clean	:
		$(RM) $(OBJ)

fclean	:	clean

		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re

