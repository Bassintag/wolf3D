/*
** update_ingame.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 26 14:40:21 2016 Antoine Stempfer
** Last update Mon Dec 26 14:44:54 2016 Antoine Stempfer
*/

#include "wolf.h"

static void		clean_screen(t_my_framebuffer *buffer,
				     sfColor ceil, sfColor floor)
{
  int			x;
  int			y;
  int			half_h;

  x = 0;
  half_h = HUD_START / 2;
  while (x < buffer->width)
    {
      y = 0;
      while (y < half_h)
	{
	  my_put_pixel(buffer, x, y, ceil);
	  y++;
	}
      while (y < HUD_START)
	{
	  my_put_pixel(buffer, x, y, floor);
	  y++;
	}
      x++;
    }
}

void		update_ingame(t_my_framebuffer *buffer, t_wolf *app)
{
  sfColor	ceil_color;
  sfColor	floor_color;

  ceil_color = sfColor_fromRGBA(42, 42, 42, 255);
  floor_color = sfColor_fromRGBA(122, 122, 122, 255);
  clean_screen(buffer, ceil_color, floor_color);
  render_map(buffer, &(app->map));
}
