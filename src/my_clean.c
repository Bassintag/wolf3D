/*
** my_clean.c for wireframe in /home/bassintag/delivery/CGP_2016/wireframe/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Nov 16 17:00:54 2016 Antoine Stempfer
** Last update Mon Dec 12 15:30:52 2016 Antoine Stempfer
*/

#include "wolf.h"

void	my_clean(t_my_framebuffer *buffer, sfColor color)
{
  int	x;
  int	y;

  x = 0;
  while (x < buffer->width)
    {
      y = 0;
      while (y < buffer->height)
	{
	  my_put_pixel(buffer, x, y, color);
	  y++;
	}
      x++;
    }
}
