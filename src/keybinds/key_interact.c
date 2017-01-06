/*
** key_interact.c for wolf3d in /home/antoine.stempfer/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Fri Jan  6 10:28:05 2017 Antoine Stempfer
** Last update Fri Jan  6 10:35:22 2017 Antoine Stempfer
*/

#include <math.h>
#include "wolf_keys.h"

void		key_interact(t_wolf *app)
{
  t_player	*player;
  float		angle;
  t_raycast_hit	hit;

  player = &app->map.player;
  angle = atan2(player->dir.x, player->dir.y);
  hit = raycast(player->position, angle, app->map.tiles, app->map.size);
  if (hit.id == END_TILE_ID)
    load_next_quest(app);
}
