##
## Makefile for wolf3d in /home/antoine.stempfer/delivery/MUL_2016/wolf3d
##
## Made by Bassintag
## Login   <bassintag@epitech.eu>
##
## Started on  Mon Dec 12 13:36:51 2016 Bassintag
## Last update Thu Dec 15 17:01:40 2016 Antoine Stempfer
##

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-Wextra -Wall -Werror -I $(INC) -O3

LDFLAGS	=	-L$(LIBDIR) -lc_graph_prog -lmy -lmyio -lmylists -lm

INC	=	include

LIBDIR	=	lib

NAME	=	wolf3d

OBJS	=	$(SRCS:.c=.o)

SRCS	=	src/init_app.c \
		src/init_map.c \
		src/init_player.c \
		src/init_entities.c \
		src/start_game.c \
		src/main_loop.c \
		src/render_map.c \
		src/render_objects.c \
		src/handle_events.c \
		src/raycast.c \
		src/main.c \
		src/object_utils.c \
		src/my_framebuffer.c \
		src/my_put_pixel.c \
		src/my_load_texture.c \
		src/my_slice_texture.c \
		src/my_destroy_texture.c \
		src/my_texture_get_at.c \
		src/my_clean.c \
		src/my_draw_vertical_line.c \
		src/my_draw_vertical_strip.c \
		src/my_draw_rect.c \
		src/my_draw_texture.c \
		src/can_move.c \
		src/can_see.c \
		src/my_vectors2.c \
		src/move_forward.c \
		src/keybinds/key_close.c \
		src/keybinds/key_left.c \
		src/keybinds/key_right.c \
		src/keybinds/key_strafe_left.c \
		src/keybinds/key_strafe_right.c \
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
