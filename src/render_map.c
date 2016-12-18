/*
** render_map.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 14:12:08 2016 Antoine Stempfer
** Last update Sun Dec 18 15:25:40 2016 Antoine Stempfer
*/

#include "wolf.h"

void		render_map(t_my_framebuffer *buffer, t_map *map)
{
  update_objects(map);
  render_walls(buffer, map);
  render_objects(buffer, map);
  render_hud(buffer, map);
}
