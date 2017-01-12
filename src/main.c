/*
** main.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 11:20:03 2016 Antoine Stempfer
** Last update Thu Jan 12 13:01:19 2017 Antoine Stempfer
*/

#include "my.h"
#include "wolf.h"

static int	parse_flags(t_wolf *app, int ac, char **av)
{
  int		i;
  int		flags;

  flags = 0;
  i = 1;
  while (i < ac)
    {
      if (my_strcmp(av[i], "-c") == 0)
	app->flags |= FLAG_CAMPAIGN;
      else if (my_strcmp(av[i], "-m") == 0)
	app->flags |= FLAG_NO_MENU;
      else if (my_strcmp(av[i], "-t") == 0)
	app->flags |= FLAG_NO_TEXTURES;
      else
	flags--;
      flags++;
      i++;
    }
  return (flags);
}

int		main(int ac, char **av)
{
  t_wolf	app;
  int		flags;

  app.flags = 0;
  app.map.init = 0;
  if ((flags = parse_flags(&app, ac, av)) != ac - 2)
    return (STATUS_FAILURE);
  if (init_app(&app, av[flags + 1]) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  if (start_game(&app) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  free_app(&app);
  return (STATUS_SUCCESS);
}
