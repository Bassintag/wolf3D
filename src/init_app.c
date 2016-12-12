/*
** init_app.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 13:00:59 2016 Antoine Stempfer
** Last update Mon Dec 12 14:10:48 2016 Antoine Stempfer
*/

#include "wolf.h"

int		init_app(t_wolf *app, char *path)
{
  sfVideoMode	mode;

  mode.width = WINDOW_W;
  mode.height = WINDOW_H;
  mode.bitsPerPixel = sizeof(int) * 4;
  if (!(app->window = sfRenderWindow_create(mode, WINDOW_TITLE, sfClose, 0)))
    return (STATUS_FAILURE);
  if (init_map(&(app->map), path) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  return (STATUS_SUCCESS);
}
