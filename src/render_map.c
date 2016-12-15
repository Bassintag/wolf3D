/*
** render_map.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 14:12:08 2016 Antoine Stempfer
** Last update Wed Dec 14 22:23:24 2016 Antoine Stempfer
*/

#include <math.h>
#include <stdio.h>
#include "wolf.h"

static void	calc_draw_pos(int height, int line_height,
			      sfVector2i *draw_pos)
{
  draw_pos->x = -line_height / 2 + height / 2;
  draw_pos->y = line_height / 2 + height / 2;
}

void		render_map(t_my_framebuffer *buffer, t_map *map)
{
  float		angle;
  t_raycast_hit	hit;
  int		x;
  float		cam_x;
  sfVector2i	draw_pos;

  x = 0;
  while (x < WINDOW_W)
    {
      cam_x = 2 * (WINDOW_W - x) / (float)WINDOW_W - 1;
      angle = atan2(map->player.dir.x + map->player.cam_plane.x * cam_x,
		    map->player.dir.y + map->player.cam_plane.y * cam_x);
      hit = raycast(map->player.position, angle, map->tiles, map->size);
      map->z_buffer[x] = hit.dist;
      calc_draw_pos(buffer->height, (int)(buffer->height / hit.dist),
		    &draw_pos);
      my_draw_vertical_strip(buffer, my_vector2i_create(x, hit.texture_x),
			     draw_pos, hit.side == 1 ?
			     &map->textures_walls[(hit.id - 1) * 2] :
			     &map->textures_walls[(hit.id - 1) * 2 + 1]);
      x++;
    }
  render_objects(buffer, map);
}
