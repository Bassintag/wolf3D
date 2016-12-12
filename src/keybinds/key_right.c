/*
** key_right.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 16:05:36 2016 Antoine Stempfer
** Last update Mon Dec 12 16:14:14 2016 Antoine Stempfer
*/

#include "wolf.h"

void	key_right(t_wolf *app)
{
  app->map.player.rotation -= TURN_SPEED;
  if (app->map.player.rotation < 0)
      app->map.player.rotation += 360;
}
