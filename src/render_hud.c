/*
** render_hud.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Fri Dec 16 14:57:01 2016 Antoine Stempfer
** Last update Fri Dec 16 15:09:25 2016 Antoine Stempfer
*/

#include "wolf.h"

void		render_hud(t_my_framebuffer *buffer, t_map *map)
{
  t_weapon	*weapon;
  t_texture	*texture;

  if ((weapon = my_list_get(map->player.weapons, 0)) == NULL)
    return ;
  texture = &map->textures_weapons[weapon->type->texture];
  my_draw_texture_scaled(buffer, texture,
			 my_vector2i_create(WINDOW_W / 2 -
					    TEXTURE_RES / 2 * HUD_SCALE
					    , WINDOW_H - TEXTURE_RES *
					    HUD_SCALE),
			 HUD_SCALE);
}
