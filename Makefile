##
## EPITECH PROJECT, 2024
## Compile mylib
## File description:
## Makefile that compiles the lib
##

NAME	=	my_navy

SRCS	=	my_navy.c \
			usages.c \
			my_strcmp.c \
			load_file_in_mem.c \
			check_file.c \
			microlib.c \
			my_strlen.c	\
			player1.c	\
			player2.c	\
			input.c	\
			signal.c	\
			win.c	\
			game.c	\
			load_map.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra

LDFLAGS	=	-lncurses -lcurses

all:	$(NAME)

$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(OBJS)
	rm -f *~

fclean:	clean
	rm -f $(NAME_TEST)
	rm -f $(NAME)

re:	fclean all
