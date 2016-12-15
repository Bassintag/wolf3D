/*
** render_objects.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Dec 14 19:39:09 2016 Antoine Stempfer
** Last update Thu Dec 15 10:36:44 2016 Antoine Stempfer
*/

#include <math.h>
#include "my.h"
#include "wolf.h"

static sfVector2f	calculate_transform(t_player *cam, sfVector2f pos)
{
  float			inv_determinent;
  sfVector2f		transform;

  inv_determinent = 1.0f / (cam->cam_plane.x * cam->dir.y -
			    cam->dir.x * cam->cam_plane.y);
  transform.x = -inv_determinent * (cam->dir.y * pos.x -
				   cam->dir.x * pos.y);
  transform.y = inv_determinent * (-cam->cam_plane.y * pos.x +
				   cam->cam_plane.x * pos.y);
  return (transform);
}

static sfVector2i	calculate_draw_start(int object_h, int object_w,
					     float screen_x)
{
  sfVector2i		draw_start;

  draw_start.x = (-object_w / 2 + screen_x);
  draw_start.y = (-object_h / 2 + WINDOW_H / 2);
  return (draw_start);
}

static sfVector2i	calculate_draw_end(int object_h, int object_w,
					   float screen_x)
{
  sfVector2i		draw_end;

  draw_end.x = (object_w / 2 + screen_x);
  draw_end.y = (object_h / 2 + WINDOW_H / 2);
  return (draw_end);
}

void		render_objects(t_my_framebuffer *buffer, t_map *map)
{
  int		i;
  float		screen_x;
  t_object	*object;
  sfVector2f	object_pos;
  sfVector2f	object_wh;
  sfVector2i	draw_start;
  sfVector2i	draw_end;
  sfVector2f	transform;
  t_player	*cam;
  int		stripe;

  cam = &map->player;
  i = 0;
  while ((object = my_list_get(map->objects, i++)) != NULL)
    {
      object_pos.x = object->position.x - cam->position.x;
      object_pos.y = object->position.y - cam->position.y;
      transform = calculate_transform(cam, object_pos);
      screen_x = (int)(WINDOW_W / 2) * (1 + transform.x / transform.y);
      object_wh.x = ABS((int)(WINDOW_H / transform.y));
      object_wh.y = ABS((int)(WINDOW_H / transform.y));
      draw_start = calculate_draw_start(object_wh.y, object_wh.x, screen_x);
      draw_end = calculate_draw_end(object_wh.y, object_wh.x, screen_x);
      stripe = draw_start.x;
      while (stripe < draw_end.x)
	{
	  int	x = (int)(((float)stripe - draw_start.x) / (draw_end.x - draw_start.x) * TEXTURE_RES);
	  if (transform.y > 0 && stripe > 0 && stripe < WINDOW_W &&
	      transform.y < map->z_buffer[stripe])
	    my_draw_vertical_strip(buffer, my_vector2i_create(stripe, x),
				   my_vector2i_create(draw_start.y, draw_end.y)
				   , &map->textures_objects[object->type->texture]);
	  stripe++;
	}
    }
}
