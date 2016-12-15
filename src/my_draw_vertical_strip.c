/*
** my_draw_vertical_strip.c for wolf.h in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Dec 13 13:50:46 2016 Antoine Stempfer
** Last update Wed Dec 14 19:37:44 2016 Antoine Stempfer
*/

#include "wolf.h"
#include "my.h"

void	my_draw_vertical_strip(t_my_framebuffer *buffer, sfVector2i x_pos,
			       sfVector2i size, t_texture *texture)
{
  float	rel_size;
  float	max_y;
  int	y;

  rel_size = size.y - size.x;
  y = 0;
  y += -MIN(0, size.x);
  max_y = MIN(rel_size, buffer->height + y);
  while (y < max_y)
    {
      my_put_pixel(buffer, x_pos.x, size.x + y,
		   my_texture_get_at(texture, x_pos.y,
				     texture->height / rel_size * y));
      y++;
    }
}
