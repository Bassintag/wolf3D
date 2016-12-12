/*
** init_entities.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 19:42:43 2016 Antoine Stempfer
** Last update Mon Dec 12 20:22:31 2016 Antoine Stempfer
*/

#include <stdlib.h>
#include "wolf.h"
#include "my.h"
#include "myio.h"

static int	parse_position(char *pos, sfVector2f *pos_vec)
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

static int	parse_entity(t_map *map, char *name, char *pos)
{
  sfVector2f	pos_vec;

  if (parse_position(pos, &pos_vec) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  if (my_strcmp(name, "player") == 0)
    {
      map->player.position.x = pos_vec.x;
      map->player.position.y = pos_vec.y;
    }
  return (STATUS_SUCCESS);
}

static int	parse_entities(t_map *map, char *buffer)
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
	  parse_entity(map, split[0], split[1]);
	}
      my_free_strtab(split);
      i++;
    }
  my_free_strtab(lines);
  return (STATUS_SUCCESS);
}

int	init_entities(t_map *map, char *path)
{
  char	*file_path;
  char	*buffer;

  file_path = my_strconcat(path, "_entities");
  if ((buffer = my_buff_file(file_path, BUFFER_SIZE)) == NULL)
    {
      free(file_path);
      return (STATUS_SUCCESS);
    }
  if (parse_entities(map, buffer) == STATUS_FAILURE)
    {
      free(file_path);
      free(buffer);
      return (STATUS_FAILURE);
    }
  free(file_path);
  free(buffer);
  return (STATUS_SUCCESS);
}
