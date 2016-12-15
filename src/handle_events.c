/*
** handle_events.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 15:52:51 2016 Antoine Stempfer
** Last update Mon Dec 12 21:18:52 2016 Antoine Stempfer
*/

#include "wolf_keys.h"

static void	handle_keys(t_wolf *app)
{
  int		i;
  int		j;

  i = 0;
  while (i < sfKeyCount)
    {
      if (app->key_states[i] == 1)
	{
	  j = 0;
	  while (j < NUM_KEYBINDS)
	    {
	      if (keybinds[j].key == i)
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

  while (sfRenderWindow_pollEvent(app->window, &event))
    {
      if (event.type == sfEvtClosed)
	sfRenderWindow_close(app->window);
      else if (event.type == sfEvtKeyPressed)
	app->key_states[event.key.code] = 1;
      else if (event.type == sfEvtKeyReleased)
	app->key_states[event.key.code] = 0;
    }
  handle_keys(app);
}
