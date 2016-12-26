/*
** main_loop.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 21:04:42 2016 Antoine Stempfer
** Last update Mon Dec 26 14:48:03 2016 Antoine Stempfer
*/

#include <unistd.h>
#include "my.h"
#include "wolf_states.h"

static void    		update_current_state(t_my_framebuffer *buffer,
					     t_wolf *app)
{
  g_game_states[app->current_state].on_update(buffer, app);
}

void			main_loop(t_my_framebuffer *buffer, t_wolf *app)
{
  sfClock		*clock;

  clock = sfClock_create();
  while (sfRenderWindow_isOpen(app->window))
    {
      app->delta = sfTime_asSeconds(sfClock_getElapsedTime(clock));
      app->time += app->delta;
      sfClock_restart(clock);
      handle_events(app);
      update_current_state(buffer, app);
      my_framebuffer_flip(buffer, app->window);
      sfRenderWindow_display(app->window);
    }
  sfClock_destroy(clock);
}
