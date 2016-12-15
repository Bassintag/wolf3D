/*
** my_texture_get_at.c for wolf.h in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Dec 13 13:57:36 2016 Antoine Stempfer
** Last update Wed Dec 14 14:11:47 2016 Antoine Stempfer
*/

#include "wolf.h"

sfColor		my_texture_get_at(t_texture *texture, int x, int y)
{
  sfColor	res;
  char		*start;

  res.a = 255;
  start = &texture->pixels[(y + x * texture->height) * 4];
  res.r = start[0];
  res.g = start[1];
  res.b = start[2];
  res.a = start[3];
  return (res);
}
