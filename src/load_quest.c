/*
** load_quest.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Fri Jan  6 09:48:28 2017 Antoine Stempfer
** Last update Fri Jan  6 10:36:04 2017 Antoine Stempfer
*/

#include "wolf.h"

int	load_next_quest(t_wolf *app)
{
  return (load_quest(app, app->quest + 1));
}

int	load_quest(t_wolf *app, int id)
{
  if (id >= app->quest_count)
    return (STATUS_FAILURE);
  if (load_map(&app->map, app->quests[id]))
    return (STATUS_FAILURE);
  app->quest = id;
  return (STATUS_SUCCESS);
}
