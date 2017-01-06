/*
** my_draw_line.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Fri Jan  6 09:25:02 2017 Antoine Stempfer
** Last update Fri Jan  6 09:29:58 2017 Antoine Stempfer
*/

#include "wolf.h"

void	my_draw_line(t_my_framebuffer *buffer, sfVector2i from,
		     sfVector2i to, sfColor color)
{
  int	x;
  int	y;
  int	to_x;
  int	to_y;

  x = MIN(from.x, to.x);
  to_x = MAX(from.x, to.x);
  while (x <= to_x)
    {
      my_put_pixel(buffer, x, y, color);
      x++;
    }
}
