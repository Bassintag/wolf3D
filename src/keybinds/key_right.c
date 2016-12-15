/*
** key_right.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 16:05:36 2016 Antoine Stempfer
** Last update Wed Dec 14 22:23:52 2016 Antoine Stempfer
*/

#include <math.h>
#include "wolf.h"

void	key_right(t_wolf *app)
{
  float	dir_x;
  float	plane_x;
  float	turn;

  turn = -TURN_SPEED * app->delta;
  dir_x = app->map.player.dir.x;
  app->map.player.dir.x = app->map.player.dir.x * cosf(turn)
    - app->map.player.dir.y * sinf(turn);
  app->map.player.dir.y = dir_x * sinf(turn)
    + app->map.player.dir.y * cosf(turn);
  plane_x = app->map.player.cam_plane.x;
  app->map.player.cam_plane.x =
    app->map.player.cam_plane.x * cosf(turn)
    - app->map.player.cam_plane.y * sinf(turn);
  app->map.player.cam_plane.y = plane_x * sinf(turn)
    + app->map.player.cam_plane.y * cosf(turn);
}
