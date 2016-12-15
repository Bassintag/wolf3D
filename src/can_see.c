/*
** can_see.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Dec 14 21:04:20 2016 Antoine Stempfer
** Last update Wed Dec 14 21:10:25 2016 Antoine Stempfer
*/

#include <math.h>
#include "wolf.h"

float	can_see(sfVector2f pos1, sfVector2f pos2, t_map *map)
{
  float	angle;
  float	dist;
  float	rel_x;
  float	rel_y;

  rel_x = pos2.x - pos1.x;
  rel_y = pos2.y - pos1.y;
  dist = sqrtf((rel_x * rel_x) + (rel_y * rel_y));
  angle = atan2(rel_x, rel_y);
  if (raycast(pos1, angle, map->tiles, map->size).dist >= dist)
    return (dist);
  return (-1);
}
