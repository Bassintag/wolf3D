/*
** update_pause.c for wolf3d in /home/antoine.stempfer/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Dec 27 00:00:46 2016 Antoine Stempfer
** Last update Tue Dec 27 01:06:40 2016 Antoine Stempfer
*/

#include "wolf.h"

static int	get_tile_id(t_map *map, t_player *player, int x, int y)
{
  int		xpos;
  int		ypos;

  xpos = x + (int)(XPOS((*player)) - MINIMAP_W / 2);
  ypos = y + (int)(YPOS((*player)) - MINIMAP_H / 2);
  if (xpos < 0 || xpos >= map->size.x)
    return (0);
  if (ypos < 0 || ypos >= map->size.y)
    return (0);
  return (map->tiles[ypos][xpos]);
}

static void	draw_tile_at(t_my_framebuffer *buffer, t_wolf *app,
			     int id, sfVector2i pos)
{
  t_texture	*texture;

  if (id > 0)
    {
      texture = &app->map.textures_walls[id * 2 - 1];
      my_draw_texture_downscaled(buffer, texture, pos, MINIMAP_SCALE);
    }
  else
    my_draw_rect(buffer, pos,
		 my_vector2i_add(pos, TEXTURE_RES / MINIMAP_SCALE,
				 TEXTURE_RES / MINIMAP_SCALE),
		 sfBlack);
}

static void	draw_minimap(t_my_framebuffer *buffer, t_wolf *app)
{
  int		x;
  int		y;
  sfVector2i	pos;

  x = 0;
  while (x < MINIMAP_W)
    {
      pos.x = WINDOW_W / 2 - TEXTURE_RES / MINIMAP_SCALE * MINIMAP_W / 2 +
	TEXTURE_RES  / MINIMAP_SCALE * x;
      y = 0;
      while (y < MINIMAP_H)
	{
	  pos.y = WINDOW_H / 2 - TEXTURE_RES / MINIMAP_SCALE * MINIMAP_H / 2 +
	    TEXTURE_RES / MINIMAP_SCALE * y + WINDOW_H / 8;
	  draw_tile_at(buffer, app,
		       get_tile_id(&app->map, &app->map.player, x, y), pos);
	  y++;
	}
      x++;
    }
}

void		update_pause(t_my_framebuffer *buffer, t_wolf *app)
{
  sfVector2i	pos;

  my_clean(buffer, sfColor_fromRGB(163, 0, 0));
  gui_draw_image_centered(buffer, app->textures_gui[gui_texture_paused],
			  WINDOW_H / 8);
  draw_minimap(buffer, app);
  pos.x = WINDOW_W / 2 - TEXTURE_RES / MINIMAP_SCALE / 4 + 1;
  pos.y = WINDOW_H / 2 - TEXTURE_RES / MINIMAP_SCALE / 4 + WINDOW_H / 8 + 1;
  my_draw_rect(buffer, pos,
	       my_vector2i_add(pos, TEXTURE_RES / MINIMAP_SCALE / 2,
			       TEXTURE_RES / MINIMAP_SCALE / 2),
	       sfColor_fromRGB(163, 0, 0));
}
