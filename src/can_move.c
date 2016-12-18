/*
** can_move.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 16:37:37 2016 Antoine Stempfer
** Last update Fri Dec 16 13:28:37 2016 Antoine Stempfer
*/

#include "wolf.h"

char		can_move(t_map *map, float x, float y)
{
  int		tx;
  int		ty;
  t_object	*object;

  tx = (int)x;
  ty = (int)y;
  if (tx < 0 || ty < 0 || tx >= map->size.x || ty >= map->size.y)
    return (0);
  if ((object = get_object_at(map, tx, ty)) != NULL && object->type->solid)
    return (0);
  return (map->tiles[ty][tx] == 0);
}
