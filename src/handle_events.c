/*
** handle_events.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 15:52:51 2016 Antoine Stempfer
** Last update Tue Dec 27 00:16:28 2016 Antoine Stempfer
*/

#include "wolf_keys.h"

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
	  while (j < keybind_count)
	    {
	      if (keybinds[j].screen == -1 ||
		  keybinds[j].screen == app->current_state)
		  if (keybinds[j].key == i && (keybinds[j].can_hold ||
					       !app->prev_states[i]))
		    keybinds[j].on_event(app);
	      j++;
	    }
	}
      i++;
    }
}

static void	handle_event(t_wolf *app, sfEvent event)
{
  if (event.type == sfEvtClosed)
    sfRenderWindow_close(app->window);
  else if (event.type == sfEvtKeyPressed && event.key.code >= 0)
    app->key_states[event.key.code] = 1;
  else if (event.type == sfEvtKeyReleased && event.key.code >= 0)
    app->key_states[event.key.code] = 0;
  else if (event.type == sfEvtMouseMoved)
    {
      app->mouse.x = event.mouseMove.x;
      app->mouse.y = event.mouseMove.y;
    }
  else if (event.type == sfEvtMouseButtonPressed)
    app->mouse_states[event.mouseButton.button] = 1;
  else if (event.type == sfEvtMouseButtonReleased)
    app->mouse_states[event.mouseButton.button] = 0;
}

void		handle_events(t_wolf *app)
{
  sfEvent	event;
  int		i;

  i = -1;
  while (++i < sfKeyCount)
    app->prev_states[i] = app->key_states[i];
  i = -1;
  while (++i < sfMouseButtonCount)
    app->prev_mouse_states[i] = app->mouse_states[i];
  while (sfRenderWindow_pollEvent(app->window, &event))
    handle_event(app, event);
  handle_keys(app);
}
