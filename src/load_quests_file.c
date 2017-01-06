/*
** load_quest_file.c for wolf3d in /home/antoine.stempfer/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Fri Jan  6 10:07:19 2017 Antoine Stempfer
** Last update Fri Jan  6 10:12:07 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "myio.h"
#include "my.h"
#include "wolf.h"

int	load_quests_file(t_wolf *app, char *path)
{
  char	*buffer;
  char	**lines;

  if ((buffer = my_buff_file(path, BUFFER_SIZE)) == NULL)
    return (STATUS_FAILURE);
  if ((lines = my_readlines(buffer)) == NULL)
    return (STATUS_FAILURE);
  app->quest_count = my_strtablen(lines);
  app->quests = lines;
  free(buffer);
  return (STATUS_SUCCESS);
}
