/*
** wolf.h for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 12:30:17 2016 Antoine Stempfer
** Last update Sat Dec 17 23:18:50 2016 Antoine Stempfer
*/

#ifndef WOLF3D_H_
# define WOLF3D_H_

# include <SFML/Graphics.h>
# include "my_framebuffer.h"
# include "mylists.h"

# define STATUS_SUCCESS	0
# define STATUS_FAILURE	84

# define WINDOW_W	960
# define WINDOW_H	540
# define WINDOW_TITLE	"Wolfenstein 3D"

# define BUFFER_SIZE	8388608

# define TURN_SPEED	M_PI
# define SPEED		5
# define FOV		80

# define TILESET_OBJECTS_PATH	"textures/objects.w3t"
# define TILESET_WALLS_PATH	"textures/tileset.w3t"
# define TILESET_WEAPONS_PATH	"textures/weapons.w3t"
# define TEXTURE_RES		64
# define TILE_SIZE		10
# define HUD_SCALE		4

# define XPOS(o) (o.position.x)
# define YPOS(o) (o.position.y)

typedef struct		s_texture
{
  char			*pixels;
  int			width;
  int			height;
}			t_texture;

typedef struct		s_weapon_def
{
  int			texture;
  float			damage;
  float			cooldown;
  char			close_range;
}			t_weapon_def;

typedef	struct		s_weapon
{
  t_weapon_def		*type;
  int			ammos;
  float			cooldown;
}			t_weapon;

typedef struct		s_player
{
  sfVector2f		position;
  sfVector2f		dir;
  sfVector2f		cam_plane;
  t_list		*weapons;
}			t_player;

typedef struct		s_object_def
{
  char			*name;
  int			texture;
  char			solid;
  void			(*on_collision)();
}			t_object_def;

typedef struct		s_object
{
  t_object_def		*type;
  sfVector2f		position;
  float			distance;
}			t_object;

typedef struct		s_object_render_data
{
  t_object		*object;
  sfVector2i		draw_start;
  sfVector2i		draw_end;
  sfVector2f		transform;
}			t_object_render_data;

typedef struct		s_map
{
  sfVector2i		size;
  t_texture		*textures_walls;
  t_texture		*textures_objects;
  t_texture		*textures_weapons;
  int			**tiles;
  float			*z_buffer;
  t_list		*objects;
  t_player		player;
}			t_map;

typedef struct		s_wolf
{
  sfRenderWindow	*window;
  t_map			map;
  char			key_states[sfKeyCount];
  char			prev_states[sfKeyCount];
  float			delta;
}			t_wolf;

typedef struct		s_raycast_hit
{
  int			side;
  int			id;
  float			texture_x;
  float			dist;
}			t_raycast_hit;

int			init_app(t_wolf *, char *);

int			init_map(t_map *, char *);

int			init_walls_textures(t_map *);

int			init_objects_textures(t_map *);

int			init_weapons_textures(t_map *);

int			init_player(t_player *);

int			init_entities(t_map *, char *);

void			render_map(t_my_framebuffer *, t_map *);

void			render_objects(t_my_framebuffer *, t_map *);

void			render_hud(t_my_framebuffer *, t_map *);

int			start_game(t_wolf *);

void			main_loop(t_my_framebuffer *, t_wolf *);

void			handle_events(t_wolf *);

t_object_def		*get_object_def(char *);

t_object		*object_create(t_object_def *, sfVector2f);

t_raycast_hit	       	raycast(sfVector2f, float, int **, sfVector2i);

t_texture		*my_load_texture(char *);

t_texture		*my_slice_texture(t_texture *, int, int);

void			my_destroy_texture(t_texture *);

sfColor			my_texture_get_at(t_texture *, int, int);

void			my_clean(t_my_framebuffer *, sfColor);

void			my_draw_vertical_line(t_my_framebuffer *, int,
					      sfVector2i, sfColor);

void			my_draw_vertical_strip(t_my_framebuffer *, sfVector2i,
					      sfVector2i, t_texture *);

void			my_draw_texture(t_my_framebuffer *, t_texture *,
					int, int);

void			my_draw_texture_scaled(t_my_framebuffer *, t_texture *,
					       sfVector2i, int);

void			my_draw_rect(t_my_framebuffer *, sfVector2i,
				     sfVector2i, sfColor);

char			can_move(t_map *, float, float);

float			can_see(sfVector2f, sfVector2f, t_map *);

t_object		*get_object_at(t_map *, int, int);

t_weapon		*create_weapon(t_weapon_def *, int);

sfVector2i		my_vector2i_create(int, int);

sfVector2f		my_vector2f_create(float, float);

int			compare_objects(void *, void *);

#endif /* WOLF_H_ */
