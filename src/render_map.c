/*
** render_map.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 14:12:08 2016 Antoine Stempfer
** Last update Mon Dec 12 16:30:22 2016 Antoine Stempfer
*/

#include <math.h>
#include <stdio.h>
#include "wolf.h"

static void	calc_draw_pos(int height, int line_height,
			      sfVector2i *draw_pos)
{
  draw_pos->x = -line_height / 2 + height / 2;
  if (draw_pos->x < 0)
    draw_pos->x = 0;
  draw_pos->y = line_height / 2 + height / 2;
  if (draw_pos->y > height)
    draw_pos->y = height;
}

void		render_map(t_my_framebuffer *buffer, t_map *map)
{
  float		angle;
  t_raycast_hit	hit;
  int		x;
  sfVector2i	draw_pos;

  x = 0;
  while (x < buffer->width)
    {
      angle = (map->player.rotation - FOV / 2 + FOV *
	       ((float)x / buffer->width)) / 360.0f *  M_PI * 2;
      hit = raycast(map->player.position, angle, map->tiles, map->size);
      calc_draw_pos(buffer->height, (int)(buffer->height / hit.dist),
		    &draw_pos);
      my_draw_vertical_line(buffer, x, draw_pos, hit.side == 1 ?
			    sfGreen : hit.side == 2 ? sfBlue : hit.side == 3 ?
			    sfYellow : sfRed);
      x++;
    }
}
