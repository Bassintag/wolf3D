/*
** main_loop.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 21:04:42 2016 Antoine Stempfer
** Last update Wed Dec 14 20:29:50 2016 Antoine Stempfer
*/

#include "wolf.h"

static void		clean_screen(t_my_framebuffer *buffer,
				     sfColor ceil, sfColor floor)
{
  int			x;
  int			y;
  int			half_h;

  x = 0;
  half_h = buffer->height / 2;
  while (x < buffer->width)
    {
      y = 0;
      while (y < half_h)
	{
	  my_put_pixel(buffer, x, y, ceil);
	  y++;
	}
      while (y < buffer->height)
	{
	  my_put_pixel(buffer, x, y, floor);
	  y++;
	}
      x++;
    }
}

void			main_loop(t_my_framebuffer *buffer, t_wolf *app)
{
  sfColor		ceil_color;
  sfColor		floor_color;
  sfClock		*clock;

  clock = sfClock_create();
  ceil_color = sfColor_fromRGBA(86, 86, 86, 255);
  floor_color = sfColor_fromRGBA(166, 166, 166, 255);
  while (sfRenderWindow_isOpen(app->window))
    {
      app->delta = sfTime_asSeconds(sfClock_getElapsedTime(clock));
      sfClock_restart(clock);
      clean_screen(buffer, ceil_color, floor_color);
      render_map(buffer, &(app->map));
      my_framebuffer_flip(buffer, app->window);
      sfRenderWindow_display(app->window);
      handle_events(app);
    }
  sfClock_destroy(clock);
}
