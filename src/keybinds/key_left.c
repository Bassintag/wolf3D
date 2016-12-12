/*
** key_left.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 16:04:13 2016 Antoine Stempfer
** Last update Mon Dec 12 16:13:47 2016 Antoine Stempfer
*/

#include "wolf.h"

void	key_left(t_wolf *app)
{
  app->map.player.rotation += TURN_SPEED;
  if (app->map.player.rotation > 360)
      app->map.player.rotation -= 360;
}
