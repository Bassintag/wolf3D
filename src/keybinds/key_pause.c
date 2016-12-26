/*
** key_pause.c for wolf3d in /home/antoine.stempfer/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 26 23:57:19 2016 Antoine Stempfer
** Last update Tue Dec 27 00:03:56 2016 Antoine Stempfer
*/

#include "wolf.h"

void	key_pause(t_wolf *app)
{
  if (app->current_state == screen_ingame)
    app->current_state = screen_pause;
  else if (app->current_state == screen_pause)
    app->current_state = screen_ingame;
}
