/*
** init_entities.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Dec 20 13:59:33 2016 Antoine Stempfer
** Last update Tue Dec 20 14:04:50 2016 Antoine Stempfer
*/

#include "wolf.h"

int	init_entities(t_map *map, char *path)
{
  if (init_objects(map, path) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  if (init_enemies(map, path) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  return (STATUS_SUCCESS);
}
