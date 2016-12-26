/*
** init_enemies_textures.c for wolf3d in /home/antoine.stempfer/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Dec 20 13:44:55 2016 Antoine Stempfer
** Last update Tue Dec 20 13:54:35 2016 Antoine Stempfer
*/

#include "wolf.h"

static int	load_enemy_tileset(t_map *map, char *path, int *id)
{
  t_texture	*tileset;

  if ((tileset = my_load_texture(path)) == NULL)
    return (STATUS_FAILURE);
  if ((map->textures_enemies[*id] =
       my_slice_texture(tileset, TEXTURE_RES, TEXTURE_RES)) == NULL)
    return (STATUS_FAILURE);
  *id += 1;
  return (STATUS_SUCCESS);
}

int		init_enemies_textures(t_map *map)
{
  int		id;

  id = 0;
  if (load_enemy_tileset(map, TILESET_ENEMIES_1_PATH, &id) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  if (load_enemy_tileset(map, TILESET_ENEMIES_2_PATH, &id) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  return (STATUS_SUCCESS);
}
