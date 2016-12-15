/*
** my_destroy_texture.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Dec 13 13:43:43 2016 Antoine Stempfer
** Last update Tue Dec 13 13:45:01 2016 Antoine Stempfer
*/

#include <stdlib.h>
#include "wolf.h"

void	my_destroy_texture(t_texture *texture)
{
  free(texture->pixels);
  free(texture);
}
