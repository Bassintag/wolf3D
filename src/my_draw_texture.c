/*
** my_draw_texture.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Dec 13 14:15:48 2016 Antoine Stempfer
** Last update Tue Dec 13 14:20:31 2016 Antoine Stempfer
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
