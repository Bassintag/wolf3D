/*
** wolf.h for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 12:30:17 2016 Antoine Stempfer
** Last update Fri Jan  6 15:12:42 2017 Antoine Stempfer
*/

#ifndef WOLF3D_H_
# define WOLF3D_H_

# include <SFML/Graphics.h>
# include <SFML/Audio.h>
# include "my_framebuffer.h"
# include "mylists.h"
# include "wolf_types.h"

# define STATUS_SUCCESS	0
# define STATUS_FAILURE	84

# define WINDOW_W	960
# define WINDOW_H	600
# define HUD_START	480
# define WINDOW_TITLE	"Wolfenstein 3D"

# define BUFFER_SIZE	8388608

# define MAX_AMMOS	99
# define MAX_HEALTH	100
# define TURN_SPEED	M_PI
# define HIT_CD		0.5f
# define SPEED		5
# define FOV		80
# define END_TILE_ID	54

# define TEXTURE_GUI_PLAY_PATH		"textures/gui/play.w3t"
# define TEXTURE_GUI_EXIT_PATH		"textures/gui/exit.w3t"
# define TEXTURE_GUI_CREDITS_PATH	"textures/gui/credits.w3t"
# define TEXTURE_GUI_PAUSED_PATH	"textures/gui/paused.w3t"
# define TEXTURE_GUI_BEDEL_PATH		"textures/gui/bedel.w3t"

# define TILESET_OBJECTS_PATH	"textures/objects.w3t"
# define TILESET_ENEMIES_1_PATH	"textures/dog.w3t"
# define TILESET_ENEMIES_2_PATH	"textures/guard.w3t"
# define TILESET_WALLS_PATH	"textures/tileset.w3t"
# define TILESET_WEAPONS_PATH	"textures/weapons.w3t"
# define TILESET_HEAD_PATH	"textures/player_head.w3t"
# define TILESET_NUM_PATH	"textures/numbers.w3t"
# define TILESET_W_ICONS_PATH	"textures/weapon_icons.w3t"
# define HUD_BG_PATH		"textures/HUD.w3t"
# define TEXTURE_RES		64
# define TEXTURE_HEAD_W		24
# define TEXTURE_HEAD_H		32
# define TEXTURE_NUM_W		8
# define TEXTURE_NUM_H		16
# define TEXTURE_W_ICONS_W     	48
# define TEXTURE_W_ICONS_H     	24
# define TILE_SIZE		10
# define MINIMAP_W		19
# define MINIMAP_H		19
# define MINIMAP_SCALE		3
# define MENU_SCALE		2
# define HUD_SCALE		3

# define FLAG_CAMPAIGN		1
# define FLAG_NO_MENU		2
# define FLAG_NO_TEXTURES      	4

# define XPOS(o) (o.position.x)
# define YPOS(o) (o.position.y)
# define TXPOS(o) ((int)(o.position.x))
# define TYPOS(o) ((int)(o.position.y))
# define P_ANGLE(o) (atan2(o.dir.y, o.dir.x))

typedef struct		s_texture

{
  char			*pixels;
  int			width;
  int			height;
}			t_texture;

typedef struct		s_weapon_def
{
  int			texture;
  int			icon;
  int			sound;
  int			damage;
  float			cooldown;
  char			close_range;
}			t_weapon_def;

typedef	struct		s_weapon
{
  t_weapon_def		*type;
  float			cooldown;
}			t_weapon;

typedef struct		s_player
{
  sfVector2f		position;
  sfVector2f		dir;
  sfVector2f		cam_plane;
  t_list		*weapons;
  float			hit_timer;
  int			health;
  int			ammos;
  int			score;
}			t_player;

typedef struct		s_entity
{
  int			texture;
  t_texture		*tileset;
  float			distance;
  sfVector2f		position;
  int			type;
  void			*data;
  void			(*on_update)();
}			t_entity;

typedef struct		s_object_render_data
{
  t_entity		*entity;
  sfVector2i		draw_start;
  sfVector2i		draw_end;
  sfVector2f		transform;
}			t_object_render_data;

typedef struct		s_object_def
{
  char			*name;
  int			texture;
  char			solid;
  void			(*on_update)();
}			t_object_def;

typedef struct		s_object
{
  t_entity		*entity;
  t_object_def		*type;
}			t_object;

typedef struct		s_enemy_def
{
  char			*name;
  int			tileset;
  int			health;
  int			damage;
  char			close_range;
  float			speed;
  float			attack_speed;
  void			(*on_update)();
  void			(*on_damage)();
}			t_enemy_def;

typedef struct		s_enemy
{
  t_entity		*entity;
  t_enemy_def		*type;
  int			health;
  int			state;
  float			angle;
  float			attack_timer;
  float			hit_timer;
}			t_enemy;

struct			s_wolf;

typedef struct		s_game_state
{
  void			(*on_load)();
  void			(*on_update)();
  void			(*on_exit)();
}			t_game_state;

typedef struct		s_map
{
  sfVector2i		size;
  t_texture		*textures_enemies[enemy_def_count];
  t_texture		*textures_walls;
  t_texture		*textures_objects;
  t_texture		*textures_weapons;
  t_texture		*textures_head;
  t_texture		*textures_num;
  t_texture		*textures_weapon_icons;
  t_texture		*texture_hud_bg;
  t_weapon_def		weapon_defs[weapon_def_count];
  sfSoundBuffer       	*sounds[sound_count];
  int			**tiles;
  float			*z_buffer;
  t_list		*entities;
  t_player		player;
  struct s_wolf		*app;
  int			flash;
}			t_map;

typedef struct		s_wolf
{
  sfRenderWindow	*window;
  int			flags;
  t_texture		*textures_gui[gui_texture_count];
  t_map			map;
  int			current_state;
  char			mouse_states[sfMouseButtonCount];
  char			prev_mouse_states[sfMouseButtonCount];
  char			key_states[sfKeyCount];
  char			prev_states[sfKeyCount];
  char			**quests;
  int			quest_count;
  int			quest;
  sfVector2f		mouse;
  float			delta;
  float			time;
}			t_wolf;

typedef struct		s_raycast_hit
{
  int			side;
  int			id;
  float			texture_x;
  float			dist;
}			t_raycast_hit;

int			init_app(t_wolf *, char *);

int			init_map(t_map *, t_wolf *);

int			init_weapon_defs(t_map *);

int			init_walls_textures(t_map *);

int			init_objects_textures(t_map *);

int			init_enemies_textures(t_map *);

int			init_weapons_textures(t_map *);

int			init_hud_textures(t_map *);

int			init_player(t_player *, t_map *);

int			init_entities(t_map *, char *);

int			init_objects(t_map *, char *);

int			init_enemies(t_map *, char *);

int			init_sounds(t_map *);

int			load_map(t_map *, char *);

int			load_quests_file(t_wolf *, char *);

int			load_next_quest(t_wolf *);

int			load_quest(t_wolf *, int);

void			update_objects(t_map *, t_object *);

void			render_map(t_my_framebuffer *, t_map *);

void			render_walls(t_my_framebuffer *, t_map *);

void			render_objects(t_my_framebuffer *, t_map *);

void			render_hud(t_my_framebuffer *, t_map *);

void			update_object(t_object *, t_map *);

void			update_player(t_player *, t_map *);

void			update_enemy(t_enemy *, t_map *);

int			start_game(t_wolf *);

void			main_loop(t_my_framebuffer *, t_wolf *);

void			handle_events(t_wolf *);

t_object_def		*get_object_def(char *);

t_entity		*object_create(t_object_def *, sfVector2f, t_map *);

void			object_delete(t_object *, t_map *);

t_enemy_def		*get_enemy_def(char *);

t_entity		*enemy_create(t_enemy_def *, sfVector2f, t_map *);

void			enemy_delete(t_enemy *, t_map *);

int			player_update_health(t_player *, int);

int			player_has_weapon(t_player *, t_weapon_def *);

void			play_sound(int, t_map *);

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

void			my_draw_vertical_strip_cam(t_my_framebuffer *,
						   sfVector2i,
						   sfVector2i, t_texture *);

void			my_draw_texture(t_my_framebuffer *, t_texture *,
					int, int);

void			my_draw_texture_scaled(t_my_framebuffer *, t_texture *,
					       sfVector2i, int);

void			my_draw_texture_downscaled(t_my_framebuffer *,
						   t_texture *,
						   sfVector2i, int);

void			my_draw_rect(t_my_framebuffer *, sfVector2i,
				     sfVector2i, sfColor);

void			my_draw_num_left_hud(t_my_framebuffer *, int,
					     t_texture *, sfVector2i);

void			my_draw_num_right_hud(t_my_framebuffer *, int,
					      t_texture *, sfVector2i);

void			gui_draw_image_centered(t_my_framebuffer *,
						t_texture *, int);

void			draw_menu_item(t_wolf *, t_my_framebuffer *,
				       t_texture *, int);

int			gui_in_bounds(sfVector2i, sfVector2i, sfVector2f);

char			is_hovered(t_texture *, int, int);

char			can_move(t_map *, float, float);

float			can_see(sfVector2f, sfVector2f, t_map *);

t_object		*get_object_at(t_map *, int, int);

t_weapon		*weapon_create(t_weapon_def *);

sfVector2i		my_vector2i_create(int, int);

sfVector2i		my_vector2i_add(sfVector2i, int, int);

sfVector2f		my_vector2f_create(float, float);

int			compare_entities(void *, void *);

#endif /* WOLF_H_ */
