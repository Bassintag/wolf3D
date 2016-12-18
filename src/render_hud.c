/*
** render_hud.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Fri Dec 16 14:57:01 2016 Antoine Stempfer
** Last update Sun Dec 18 16:16:19 2016 Antoine Stempfer
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

void		render_hud(t_my_framebuffer *buffer, t_map *map)
{
  t_weapon	*weapon;
  t_texture	*texture;
  int		texture_id;

  render_flash(buffer, map);
  if ((weapon = my_list_get(map->player.weapons, 0)) == NULL)
    return ;
  texture_id = weapon->type->texture +
    (int)((weapon->cooldown) / weapon->type->cooldown * 4);
  if (weapon->cooldown > 0.0f)
    {
      weapon->cooldown -= map->app->delta;
      if (weapon->cooldown < 0)
	weapon->cooldown = 0.0f;
    }
  texture = &map->textures_weapons[texture_id];
  my_draw_texture_scaled(buffer, texture,
			 my_vector2i_create(WINDOW_W / 2 -
					    TEXTURE_RES / 2 * HUD_SCALE
					    , WINDOW_H - TEXTURE_RES *
					    HUD_SCALE),
			 HUD_SCALE);
}
