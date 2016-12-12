/*
** handle_events.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 15:52:51 2016 Antoine Stempfer
** Last update Mon Dec 12 16:01:52 2016 Antoine Stempfer
*/

#include "wolf_keys.h"

void		handle_events(t_wolf *app)
{
  sfEvent	event;
  int		i;

  while (sfRenderWindow_pollEvent(app->window, &event))
    {
      if (event.type == sfEvtClosed)
	sfRenderWindow_close(app->window);
      if (event.type == sfEvtKeyPressed)
	{
	  i = 0;
	  while (i < NUM_KEYBINDS)
	    {
	      if (keybinds[i].key == event.key.code)
		keybinds[i].on_event(app);
	      i++;
	    }
	}
    }
}
