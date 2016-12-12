/*
** my_draw_rect.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 16:44:06 2016 Antoine Stempfer
** Last update Mon Dec 12 16:49:45 2016 Antoine Stempfer
*/

#include "wolf.h"

void	my_draw_rect(t_my_framebuffer *buffer, sfVector2i start,
		     sfVector2i end, sfColor color)
{
  int	x;
  int	y;

  x = start.x;
  while (x < end.x)
    {
      y = start.y;
      while (y < end.y)
	{
	  my_put_pixel(buffer, x, y, color);
	  y++;
	}
      x++;
    }
}
