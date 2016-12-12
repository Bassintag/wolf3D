/*
** main.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 11:20:03 2016 Antoine Stempfer
** Last update Mon Dec 12 14:11:39 2016 Antoine Stempfer
*/

#include "wolf.h"

int		main(int ac, char **av)
{
  t_wolf	app;

  if (ac != 2)
    return (STATUS_FAILURE);
  if (init_app(&app, av[1]) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  if (start_game(&app) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  return (STATUS_SUCCESS);
}
