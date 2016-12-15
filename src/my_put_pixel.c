/*
** my_put_pixel.c for autograder-wireframe in /home/bassintag/delivery/CGP_2016/wireframe/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Nov 24 10:02:44 2016 Antoine Stempfer
** Last update Wed Dec 14 14:51:00 2016 Antoine Stempfer
*/

#include "my_framebuffer.h"

void	my_put_pixel(t_my_framebuffer* buffer, int x, int y, sfColor color)
{
  if (x < 0 || y < 0 || x >= buffer->width || y >= buffer->height)
    return ;
  if (color.a == 0)
    return ;
  (buffer->pixels)[(x + y * buffer->width) * 4] = color.r;
  (buffer->pixels)[(x + y * buffer->width) * 4 + 1] = color.g;
  (buffer->pixels)[(x + y * buffer->width) * 4 + 2] = color.b;
  (buffer->pixels)[(x + y * buffer->width) * 4 + 3] = 255;
}
