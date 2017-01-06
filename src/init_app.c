/*
** init_app.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 13:00:59 2016 Antoine Stempfer
** Last update Fri Jan  6 10:24:59 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"
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
      load_gui_texture(app, gui_texture_paused, TEXTURE_GUI_PAUSED_PATH) ||
      load_gui_texture(app, gui_texture_bedel, TEXTURE_GUI_BEDEL_PATH))
    return (STATUS_FAILURE);
  return (STATUS_SUCCESS);
}

static int	init_quests(t_wolf *app, char *path)
{
  if ((app->flags & FLAG_CAMPAIGN) != 0)
    {
      my_printf("Found campaign mode flag, loading campaign file..\n");
      if (load_quests_file(app, path) == STATUS_FAILURE)
	return (STATUS_FAILURE);
      return (STATUS_SUCCESS);
    }
  else
    {
      if ((app->quests = malloc(sizeof(char *) * 2)) ==  NULL)
	return (STATUS_FAILURE);
      app->quest_count = 1;
      app->quests[0] = my_strdup(path);
      app->quests[1] = NULL;
    }
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
  if (init_quests(app, path) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  init_key_states(app);
  app->current_state = screen_main_menu;
  app->time = 0.0f;
  app->delta = 0.0f;
  app->mouse.x =  0;
  app->mouse.y =  0;
  return (STATUS_SUCCESS);
}
