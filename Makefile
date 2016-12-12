##
## Makefile for wolf3d in /home/antoine.stempfer/delivery/MUL_2016/wolf3d
##
## Made by Bassintag
## Login   <bassintag@epitech.eu>
##
## Started on  Mon Dec 12 13:36:51 2016 Bassintag
## Last update Mon Dec 12 20:16:59 2016 Antoine Stempfer
##

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-Wextra -Wall -I $(INC) -g

LDFLAGS	=	-L$(LIBDIR) -lc_graph_prog -lmy -lmyio -lm

INC	=	include

LIBDIR	=	lib

NAME	=	wolf3d

OBJS	=	$(SRCS:.c=.o)

SRCS	=	src/init_app.c \
		src/init_map.c \
		src/init_player.c \
		src/init_entities.c \
		src/start_game.c \
		src/render_map.c \
		src/handle_events.c \
		src/raycast.c \
		src/main.c \
		src/my_framebuffer.c \
		src/my_put_pixel.c \
		src/my_clean.c \
		src/my_draw_vertical_line.c \
		src/can_move.c \
		src/keybinds/key_close.c \
		src/keybinds/key_left.c \
		src/keybinds/key_right.c \
		src/keybinds/key_forward.c \
		src/keybinds/key_back.c

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
