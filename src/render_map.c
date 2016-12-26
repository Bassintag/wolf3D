/*
** render_map.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 14:12:08 2016 Antoine Stempfer
** Last update Wed Dec 21 13:00:44 2016 Antoine Stempfer
*/

#include "wolf.h"

static void	update_entities(t_map *map)
{
  int		i;
  t_entity	*entity;
  void		(*f)();

  i = 0;
  while ((entity = my_list_get(map->entities, i++)) != NULL)
    {
      f = entity->on_update;
      if (f != NULL)
	f(entity->data, map);
    }
}

void		render_map(t_my_framebuffer *buffer, t_map *map)
{
  update_player(&map->player, map);
  update_entities(map);
  render_walls(buffer, map);
  render_objects(buffer, map);
  render_hud(buffer, map);
}
