/*
** init_weapons_textures.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Fri Dec 16 14:37:10 2016 Antoine Stempfer
** Last update Fri Dec 16 14:39:09 2016 Antoine Stempfer
*/

#include "wolf.h"

int		init_weapons_textures(t_map *map)
{
  t_texture	*tileset;

  if ((tileset = my_load_texture(TILESET_WEAPONS_PATH)) == NULL)
    return (STATUS_FAILURE);
  if ((map->textures_weapons =
       my_slice_texture(tileset, TEXTURE_RES, TEXTURE_RES)) == NULL)
    return (STATUS_FAILURE);
  return (STATUS_SUCCESS);
}
