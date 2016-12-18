/*
** handle_events.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 15:52:51 2016 Antoine Stempfer
** Last update Sat Dec 17 23:21:09 2016 Antoine Stempfer
*/

#include "wolf_keys.h"
#include <stdio.h>

static void	handle_keys(t_wolf *app)
{
  int		i;
  int		j;

  i = 0;
  while (i < sfKeyCount)
    {
      if (app->key_states[i])
	{
	  j = 0;
	  while (j < NUM_KEYBINDS)
	    {
	      if (keybinds[j].key == i && (keybinds[j].can_hold ||
					   !app->prev_states[i]))
		keybinds[j].on_event(app);
	      j++;
	    }
	}
      i++;
    }
}

void		handle_events(t_wolf *app)
{
  sfEvent	event;
  int		i;

  i = 0;
  while (i < sfKeyCount)
    {
      app->prev_states[i] = app->key_states[i];
      i++;
    }
  while (sfRenderWindow_pollEvent(app->window, &event))
    {
      if (event.type == sfEvtClosed)
	sfRenderWindow_close(app->window);
      else if (event.type == sfEvtKeyPressed && event.key.code >= 0)
	app->key_states[event.key.code] = 1;
      else if (event.type == sfEvtKeyReleased && event.key.code >= 0)
	app->key_states[event.key.code] = 0;
    }
  handle_keys(app);
}
