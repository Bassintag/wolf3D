/*
** my_destroy_texture.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Dec 13 13:43:43 2016 Antoine Stempfer
** Last update Thu Jan 12 13:00:06 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "wolf.h"

void	my_destroy_texture_farray(t_texture **textures, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      free(textures[i]->pixels);
      i++;
    }
}

void	my_destroy_texture(t_texture *texture)
{
  free(texture->pixels);
  free(texture);
}
