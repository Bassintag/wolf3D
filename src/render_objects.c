/*
** render_objects.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Dec 14 19:39:09 2016 Antoine Stempfer
** Last update Mon Dec 19 15:19:18 2016 Antoine Stempfer
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
  draw_start.y = (-object_h / 2 + HUD_START / 2);
  return (draw_start);
}

static sfVector2i	calculate_draw_end(int object_h, int object_w,
					   float screen_x)
{
  sfVector2i		draw_end;

  draw_end.x = (object_w / 2 + screen_x);
  draw_end.y = (object_h / 2 + HUD_START / 2);
  return (draw_end);
}

static void	draw_object(t_my_framebuffer *buffer, t_map *map,
			    t_object_render_data data)
{
  int		x;
  int		stripe;
  t_texture	*texture;

  stripe = data.draw_start.x;
  while (stripe < data.draw_end.x)
    {
      x = (int)(((float)stripe - data.draw_start.x) /
		(data.draw_end.x - data.draw_start.x) * TEXTURE_RES);
      if (data.transform.y > 0 && stripe > 0 && stripe < WINDOW_W &&
	  data.transform.y < map->z_buffer[stripe])
	{
	  texture = &data.entity->tileset[data.entity->texture];
	  my_draw_vertical_strip_cam(buffer, my_vector2i_create(stripe, x),
				 my_vector2i_create(data.draw_start.y,
						    data.draw_end.y),
				 texture);
	}
      stripe++;
    }
}

void			render_objects(t_my_framebuffer *buffer, t_map *map)
{
  int			i;
  float			screen_x;
  sfVector2f		object_pos;
  sfVector2f		object_wh;
  t_object_render_data	d;
  t_player		*cam;

  cam = &map->player;
  i = 0;
  if (map->entities != NULL)
    my_list_sort(&map->entities, &compare_entities, -1);
  while ((d.entity = my_list_get(map->entities, i++)) != NULL)
    {
      d.entity->distance = SQUARE(XPOS((*d.entity)) - XPOS(map->player)) +
	SQUARE(YPOS((*d.entity)) - YPOS(map->player));
      object_pos.x = d.entity->position.x - cam->position.x;
      object_pos.y = d.entity->position.y - cam->position.y;
      d.transform = calculate_transform(cam, object_pos);
      screen_x = (int)(WINDOW_W / 2) * (1 + d.transform.x / d.transform.y);
      object_wh.x = ABS((int)(WINDOW_H / d.transform.y));
      object_wh.y = ABS((int)(WINDOW_H / d.transform.y));
      d.draw_start = calculate_draw_start(object_wh.y, object_wh.x, screen_x);
      d.draw_end = calculate_draw_end(object_wh.y, object_wh.x, screen_x);
      draw_object(buffer, map, d);
    }
}
