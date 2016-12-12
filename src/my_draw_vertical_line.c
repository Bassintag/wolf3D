/*
** my_draw_vertical_line.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 15:18:09 2016 Antoine Stempfer
** Last update Mon Dec 12 15:20:08 2016 Antoine Stempfer
*/

#include "my_framebuffer.h"

void	my_draw_vertical_line(t_my_framebuffer *buffer, int x,
			      sfVector2i size, sfColor color)
{
  while (size.x < size.y)
    {
      my_put_pixel(buffer, x, size.x, color);
      size.x += 1;
    }
}
