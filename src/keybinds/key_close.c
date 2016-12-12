/*
** key_close.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 16:03:14 2016 Antoine Stempfer
** Last update Mon Dec 12 16:03:53 2016 Antoine Stempfer
*/

#include "wolf.h"

void	key_close(t_wolf *app)
{
  sfRenderWindow_close(app->window);
}
