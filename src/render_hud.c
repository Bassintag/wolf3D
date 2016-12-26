/*
** render_hud.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Fri Dec 16 14:57:01 2016 Antoine Stempfer
** Last update Mon Dec 19 15:29:20 2016 Antoine Stempfer
*/

#include "wolf.h"

static void	render_flash(t_my_framebuffer *buffer, t_map *map)
{
  if (map->flash > 0)
    {
      my_clean(buffer, sfWhite);
      map->flash -= 1;
    }
}

static void	render_head(t_my_framebuffer *buffer, t_map *map)
{
  int		texture_id;
  sfVector2i	draw_pos;
  t_texture	*texture;

  texture_id = (int)(7 - ((float)map->player.health / MAX_HEALTH) * 7) * 3
    + (int)(map->app->time) % 3;
  texture = &map->textures_head[texture_id];
  draw_pos = my_vector2i_create(WINDOW_W / 2 - TEXTURE_HEAD_W * HUD_SCALE,
				HUD_START + 4 * HUD_SCALE);
  my_draw_texture_scaled(buffer, texture, draw_pos, HUD_SCALE);
}

static void	render_numbers(t_my_framebuffer *buffer, t_map *map)
{
  my_draw_num_right_hud(buffer, 1, map->textures_num,
			my_vector2i_create(40 * HUD_SCALE,
					   HUD_START + 16 * HUD_SCALE));
  my_draw_num_right_hud(buffer, map->player.score, map->textures_num,
			my_vector2i_create(96 * HUD_SCALE,
					   HUD_START + 16 * HUD_SCALE));
  my_draw_num_right_hud(buffer, map->player.health, map->textures_num,
			my_vector2i_create(192 * HUD_SCALE,
					   HUD_START + 16 * HUD_SCALE));
  my_draw_num_right_hud(buffer, map->player.ammos, map->textures_num,
			my_vector2i_create(236 * HUD_SCALE,
					   HUD_START + 16 * HUD_SCALE));
  my_draw_num_right_hud(buffer, 1, map->textures_num,
			my_vector2i_create(128 * HUD_SCALE,
					   HUD_START + 16 * HUD_SCALE));
}

static void	render_bg(t_my_framebuffer *buffer, t_map *map)
{
  sfVector2i	draw_pos;
  int		texture_id;
  t_texture	*texture;

  texture = map->texture_hud_bg;
  draw_pos = my_vector2i_create(0, HUD_START);
  my_draw_texture_scaled(buffer, texture, draw_pos, HUD_SCALE);
  render_numbers(buffer, map);
  texture_id = ((t_weapon *)my_list_get(map->player.weapons, 0))->type->icon;
  texture = &map->textures_weapon_icons[texture_id];
  draw_pos = my_vector2i_create(256 * HUD_SCALE, HUD_START + 8 * HUD_SCALE);
  my_draw_texture_scaled(buffer, texture, draw_pos, HUD_SCALE);
}

void		render_hud(t_my_framebuffer *buffer, t_map *map)
{
  t_weapon	*weapon;
  t_texture	*texture;
  sfVector2i	draw_pos;
  int		texture_id;

  render_flash(buffer, map);
  render_bg(buffer, map);
  render_head(buffer, map);
  if ((weapon = my_list_get(map->player.weapons, 0)) == NULL)
    return ;
  texture_id = weapon->type->texture +
    (int)((weapon->cooldown) / weapon->type->cooldown * 3);
  texture_id += ((map->app->key_states[k_weapon_shoot]) ||
		 weapon->cooldown > 0);
  if (weapon->cooldown > 0.0f)
    {
      weapon->cooldown -= map->app->delta;
      if (weapon->cooldown < 0)
	weapon->cooldown = 0.0f;
    }
  texture = &map->textures_weapons[texture_id];
  draw_pos = my_vector2i_create(WINDOW_W / 2 - TEXTURE_RES / 2 * HUD_SCALE * 2,
				HUD_START - TEXTURE_RES * HUD_SCALE * 2);
  my_draw_texture_scaled(buffer, texture, draw_pos, HUD_SCALE * 2);
}
