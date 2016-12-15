/*
** key_strafe_left.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 16:06:26 2016 Antoine Stempfer
** Last update Wed Dec 14 22:08:27 2016 Antoine Stempfer
*/

#include <math.h>
#include "wolf.h"

void	key_strafe_left(t_wolf *app)
{
  float	angle;
  float	delta_x;
  float	delta_y;

  /*  angle = (app->map.player.rotation + 90) / 360.0f * M_PI * 2;
  delta_x = sinf(angle) * SPEED * app->delta;
  if (can_move(&(app->map), app->map.player.position.x + delta_x,
	       app->map.player.position.y))
    app->map.player.position.x += delta_x;
  delta_y = cosf(angle) * SPEED * app->delta;
  if (can_move(&(app->map), app->map.player.position.x,
	       app->map.player.position.y + delta_y))
	       app->map.player.position.y += delta_y;*/
}
