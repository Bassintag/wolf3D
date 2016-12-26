/*
** map_utils.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Fri Dec 16 13:24:25 2016 Antoine Stempfer
** Last update Mon Dec 19 15:18:59 2016 Antoine Stempfer
*/

#include "wolf.h"

t_object	*get_object_at(t_map *map, int x, int y)
{
  t_entity	*obj;
  int		i;

  i = 0;
  while ((obj = my_list_get(map->entities, i++)) != NULL)
    if ((int)obj->position.x == x && (int)obj->position.y == y &&
	obj->type == entity_object)
      return (obj->data);
  return (NULL);
}
