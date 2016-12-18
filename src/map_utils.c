/*
** map_utils.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Fri Dec 16 13:24:25 2016 Antoine Stempfer
** Last update Fri Dec 16 13:26:38 2016 Antoine Stempfer
*/

#include "wolf.h"

t_object	*get_object_at(t_map *map, int x, int y)
{
  t_object	*obj;
  int		i;

  i = 0;
  while ((obj = my_list_get(map->objects, i++)) != NULL)
    if ((int)obj->position.x == x && (int)obj->position.y == y)
      return (obj);
  return (NULL);
}
