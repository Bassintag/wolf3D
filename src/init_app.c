/*
** init_app.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 13:00:59 2016 Antoine Stempfer
** Last update Sun Dec 18 15:31:04 2016 Antoine Stempfer
*/

#include "wolf.h"

void		init_key_states(t_wolf *app)
{
  int		i;

  i = 0;
  while (i < sfKeyCount)
    app->key_states[i++] = 0;
}

int		init_app(t_wolf *app, char *path)
{
  sfVideoMode	mode;

  mode.width = WINDOW_W;
  mode.height = WINDOW_H;
  mode.bitsPerPixel = sizeof(int) * 4;
  if (!(app->window = sfRenderWindow_create(mode, WINDOW_TITLE, sfClose, 0)))
    return (STATUS_FAILURE);
  if (init_map(&(app->map), path, app) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  init_key_states(app);
  return (STATUS_SUCCESS);
}
