/*
** init_enemies.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Dec 20 14:05:59 2016 Antoine Stempfer
** Last update Tue Dec 20 14:46:30 2016 Antoine Stempfer
*/

#include <stdlib.h>
#include "wolf.h"
#include "my.h"
#include "myio.h"

static int	parse_data(char *pos, sfVector2f *pos_vec)
{
  char		**split;

  split = my_split(pos, ',');
  if (my_strtablen(split) != 2)
    return (STATUS_FAILURE);
  pos_vec->x = (float) my_getnbr(split[0]) + 0.5f;
  pos_vec->y = (float) my_getnbr(split[1]) + 0.5f;
  my_free_strtab(split);
  return (STATUS_SUCCESS);
}

static int	parse_enemy(t_map *map, char *name, char *pos)
{
  sfVector2f	pos_vec;
  t_enemy_def	*def;

  if (parse_data(pos, &pos_vec) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  if ((def = get_enemy_def(name)) != NULL)
    my_list_append(&map->entities, enemy_create(def, pos_vec, map));
  else
    return (STATUS_FAILURE);
  return (STATUS_SUCCESS);
}

static int	parse_enemies(t_map *map, char *buffer)
{
  char		**lines;
  char		**split;
  int		i;

  if ((lines = my_readlines(buffer)) == NULL)
    return (STATUS_FAILURE);
  i = 0;
  while (lines[i])
    {
      split = my_split(lines[i], '=');
      if (my_strtablen(split) == 2)
	{
	  parse_enemy(map, split[0], split[1]);
	}
      my_free_strtab(split);
      i++;
    }
  my_free_strtab(lines);
  return (STATUS_SUCCESS);
}

int	init_enemies(t_map *map, char *path)
{
  char	*file_path;
  char	*buffer;

  file_path = my_strconcat(path, "_enemies");
  if ((buffer = my_buff_file(file_path, BUFFER_SIZE)) == NULL)
    {
      my_putstr("WARNING: no enemy file found for this level\n");
      free(file_path);
      return (STATUS_SUCCESS);
    }
  if (parse_enemies(map, buffer) == STATUS_FAILURE)
    {
      free(file_path);
      free(buffer);
      return (STATUS_FAILURE);
    }
  my_putstr("Successfully loaded enemies\n");
  free(file_path);
  free(buffer);
  return (STATUS_SUCCESS);
}
