/*
** my_draw_texture.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Dec 13 14:15:48 2016 Antoine Stempfer
** Last update Tue Dec 27 00:51:32 2016 Antoine Stempfer
*/

#include "wolf.h"

void	my_draw_texture(t_my_framebuffer *buffer, t_texture *texture,
			int sx, int sy)
{
  int	x;
  int	y;

  x = 0;
  while (x < texture->width)
    {
      y = 0;
      while (y < texture->height)
	{
	  my_put_pixel(buffer, sx + x, sy + y,
		       my_texture_get_at(texture, x, y));
	  y++;
	}
      x++;
    }
}

void	my_draw_texture_downscaled(t_my_framebuffer *buffer,
				   t_texture *texture,
				   sfVector2i pos, int scale)
{
  int	x;
  int	y;

  x = -1;
  while (++x * scale < texture->width)
    {
      y = -1;
      while (++y * scale < texture->height)
	{
	  my_put_pixel(buffer, pos.x + x, pos.y + y,
		       my_texture_get_at(texture, x * scale, y * scale));
	}
    }
}

void	my_draw_texture_scaled(t_my_framebuffer *buffer, t_texture *texture,
			       sfVector2i pos, int scale)
{
  int	x;
  int	y;
  int	dx;
  int	dy;

  x = -1;
  while (++x < texture->width)
    {
      y = -1;
      while (++y < texture->height)
	{
	  dx = -1;
	  while (++dx < scale)
	    {
	      dy = -1;
	      while (++dy < scale)
		my_put_pixel(buffer, pos.x + dx + x * scale,
			     pos.y + dy + y * scale,
			     my_texture_get_at(texture, x, y));
	    }
	}
    }
}
