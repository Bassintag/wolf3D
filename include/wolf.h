/*
** wolf.h for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 12:30:17 2016 Antoine Stempfer
** Last update Mon Dec 12 20:19:47 2016 Antoine Stempfer
*/

#ifndef WOLF3D_H_
# define WOLF3D_H_

# include <SFML/Graphics.h>
# include "my_framebuffer.h"

# define STATUS_SUCCESS	0
# define STATUS_FAILURE	84

# define WINDOW_W	920
# define WINDOW_H	540
# define WINDOW_TITLE	"Wolfenstein 3D"

# define BUFFER_SIZE	1048576

# define TURN_SPEED	4
# define SPEED		0.1f
# define FOV		80

# define TILE_SIZE	10

typedef struct		s_player
{
  sfVector2f		position;
  float			rotation;
}			t_player;

typedef struct		s_map
{
  sfVector2i		size;
  int			**tiles;
  t_player		player;
}			t_map;

typedef struct		s_wolf
{
  sfRenderWindow	*window;
  t_map			map;
}			t_wolf;

typedef struct		s_raycast_hit
{
  int			side;
  float			dist;
}			t_raycast_hit;

int			init_app(t_wolf *, char *);

int			init_map(t_map *, char *);

int			init_player(t_player *);

int			init_entities(t_map *, char *);

void			render_map(t_my_framebuffer *, t_map *);

int			start_game(t_wolf *);

void			handle_events(t_wolf *);

t_raycast_hit	       	raycast(sfVector2f, float, int **, sfVector2i);

void			my_clean(t_my_framebuffer *, sfColor);

void			my_draw_vertical_line(t_my_framebuffer *, int,
					      sfVector2i, sfColor);

void			my_draw_rect(t_my_framebuffer *, sfVector2i,
				     sfVector2i, sfColor);

char			can_move(t_map *, float, float);

#endif /* WOLF_H_ */
