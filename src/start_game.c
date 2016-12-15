/*
** start_game.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 13:47:45 2016 Antoine Stempfer
** Last update Mon Dec 12 21:06:36 2016 Antoine Stempfer
*/

#include "wolf.h"

int			start_game(t_wolf *app)
{
  t_my_framebuffer	buffer;

  buffer = my_framebuffer_create(WINDOW_W, WINDOW_H);
  main_loop(&buffer, app);
  sfRenderWindow_destroy(app->window);
  return (STATUS_SUCCESS);
}
