/*
** key_back.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 16:07:03 2016 Antoine Stempfer
** Last update Mon Dec 12 16:42:21 2016 Antoine Stempfer
*/

#include <math.h>
#include "wolf.h"

void	key_back(t_wolf *app)
{
  float	angle;
  float	delta_x;
  float	delta_y;

  angle = app->map.player.rotation / 360.0f * M_PI * 2;
  delta_x = sinf(angle) * SPEED;
  if (can_move(&(app->map), app->map.player.position.x - delta_x,
	       app->map.player.position.y))
    app->map.player.position.x -= delta_x;
  delta_y = cosf(angle) * SPEED;
  if (can_move(&(app->map), app->map.player.position.x,
	       app->map.player.position.y - delta_y))
    app->map.player.position.y -= delta_y;
}
