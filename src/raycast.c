/*
** raycast.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 14:18:26 2016 Antoine Stempfer
** Last update Tue Dec 13 14:08:01 2016 Antoine Stempfer
*/

#include "wolf.h"
#include <math.h>

static void    	calculate_delta_dist(sfVector2f *delta_dist, sfVector2f dir)
{
  delta_dist->x = sqrt(1 + (dir.y * dir.y) / (dir.x * dir.x));
  delta_dist->y = sqrt(1 + (dir.x * dir.x) / (dir.y * dir.y));
}

static sfVector2i	calculate_side_dist(sfVector2f *side_dist,
					    sfVector2f dir,
					    sfVector2f pos,
					    sfVector2f delta_dist)
{
  sfVector2i		step;

  if (dir.x < 0)
    {
      step.x = -1;
      side_dist->x = (pos.x - (int)pos.x) * delta_dist.x;
    }
  else
    {
      step.x = 1;
      side_dist->x = ((int)pos.x + 1.0 - pos.x) * delta_dist.x;
    }
  if (dir.y < 0)
    {
      step.y = -1;
      side_dist->y = (pos.y - (int)pos.y) * delta_dist.y;
    }
  else
    {
      step.y = 1;
      side_dist->y = ((int)pos.y + 1.0 - pos.y) * delta_dist.y;
    }
  return (step);
}

int		perform_DDA(sfVector2f *side_dist, sfVector2f *delta_dist,
			    sfVector2i *step, sfVector2i *map_pos)
{
  int		side;

  if (side_dist->x < side_dist->y)
    {
      side_dist->x += delta_dist->x;
      map_pos->x += step->x;
      side = 0;
    }
  else
    {
      side_dist->y += delta_dist->y;
      map_pos->y += step->y;
      side = 1;
    }
  return (side);
}

static char	in_bounds(sfVector2i pos, sfVector2i size)
{
  if (pos.x < 0 || pos.x >= size.x)
    return (0);
  if (pos.y < 0 || pos.y >= size.y)
    return (0);
  return (1);
}

t_raycast_hit	raycast(sfVector2f pos, float direction,
			int **map, sfVector2i map_size)
{
  sfVector2f	dir;
  sfVector2f	side_dist;
  sfVector2f	delta_dist;
  sfVector2i	step;
  sfVector2i	map_pos;
  t_raycast_hit	hit;

  dir.x = sinf(direction);
  dir.y = cosf(direction);
  map_pos.x = (int)pos.x;
  map_pos.y = (int)pos.y;
  calculate_delta_dist(&delta_dist, dir);
  step = calculate_side_dist(&side_dist, dir, pos, delta_dist);
  hit.side = 0;
  while (in_bounds(map_pos, map_size) && map[map_pos.y][map_pos.x] == 0)
    hit.side = perform_DDA(&side_dist, &delta_dist, &step, &map_pos);
  hit.id = map[map_pos.y][map_pos.x];
  if (hit.side == 0)
    hit.dist = (map_pos.x - pos.x + (1 - step.x) / 2) / dir.x;
  else
    hit.dist = (map_pos.y - pos.y + (1 - step.y) / 2) / dir.y;
  hit.texture_x = (hit.side == 0 ? pos.y : pos.x) + hit.dist *
    (hit.side == 0 ? dir.y : dir.x);
  hit.texture_x = (hit.texture_x - (int)hit.texture_x) * TEXTURE_RES;
  return (hit);
}
