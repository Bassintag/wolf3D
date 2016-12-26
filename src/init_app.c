/*
** init_app.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 13:00:59 2016 Antoine Stempfer
** Last update Tue Dec 27 00:06:04 2016 Antoine Stempfer
*/

#include "wolf.h"

static void    	init_key_states(t_wolf *app)
{
  int		i;

  i = 0;
  while (i < sfKeyCount)
    app->key_states[i++] = 0;
  i = 0;
  while (i < sfMouseButtonCount)
    app->mouse_states[i++] = 0;
}

static int	load_gui_texture(t_wolf *app, int id, char *path)
{
  if ((app->textures_gui[id] = my_load_texture(path)) == NULL)
    return (1);
  return (0);
}

static int	init_gui_textures(t_wolf *app)
{
  if (load_gui_texture(app, gui_texture_play, TEXTURE_GUI_PLAY_PATH) ||
      load_gui_texture(app, gui_texture_exit, TEXTURE_GUI_EXIT_PATH) ||
      load_gui_texture(app, gui_texture_credits, TEXTURE_GUI_CREDITS_PATH) ||
      load_gui_texture(app, gui_texture_paused, TEXTURE_GUI_PAUSED_PATH))
    return (STATUS_FAILURE);
  return (STATUS_SUCCESS);
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
  if (init_gui_textures(app) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  init_key_states(app);
  app->current_state = screen_main_menu;
  app->time = 0.0f;
  app->delta = 0.0f;
  app->mouse.x =  0;
  app->mouse.y =  0;
  return (STATUS_SUCCESS);
}
