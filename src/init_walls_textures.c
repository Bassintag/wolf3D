/*
** init_walls_textures.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Fri Dec 16 14:27:49 2016 Antoine Stempfer
** Last update Fri Dec 16 14:35:31 2016 Antoine Stempfer
*/

#include "wolf.h"

int		init_walls_textures(t_map *map)
{
  t_texture	*tileset;

  if ((tileset = my_load_texture(TILESET_WALLS_PATH)) == NULL)
    return (STATUS_FAILURE);
  if ((map->textures_walls =
       my_slice_texture(tileset, TEXTURE_RES, TEXTURE_RES)) == NULL)
    return (STATUS_FAILURE);
  return (STATUS_SUCCESS);
}
