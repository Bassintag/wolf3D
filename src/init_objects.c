/*
** init_objects.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 19:42:43 2016 Antoine Stempfer
** Last update Tue Dec 20 14:09:35 2016 Antoine Stempfer
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

static int	parse_object(t_map *map, char *name, char *pos)
{
  sfVector2f	pos_vec;
  t_object_def	*def;

  if (parse_data(pos, &pos_vec) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  if (my_strcmp(name, "player") == 0)
    {
      map->player.position.x = pos_vec.x;
      map->player.position.y = pos_vec.y;
    }
  else if ((def = get_object_def(name)) != NULL)
    my_list_append(&map->entities, object_create(def, pos_vec, map));
  else
    return (STATUS_FAILURE);
  return (STATUS_SUCCESS);
}

static int	parse_objects(t_map *map, char *buffer)
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
	  parse_object(map, split[0], split[1]);
	}
      my_free_strtab(split);
      i++;
    }
  my_free_strtab(lines);
  return (STATUS_SUCCESS);
}

int	init_objects(t_map *map, char *path)
{
  char	*file_path;
  char	*buffer;

  file_path = my_strconcat(path, "_objects");
  if ((buffer = my_buff_file(file_path, BUFFER_SIZE)) == NULL)
    {
      my_putstr("WARNING: no object file found for this level\n");
      free(file_path);
      return (STATUS_SUCCESS);
    }
  map->entities = NULL;
  if (parse_objects(map, buffer) == STATUS_FAILURE)
    {
      free(file_path);
      free(buffer);
      return (STATUS_FAILURE);
    }
  my_putstr("Successfully loaded objects\n");
  free(file_path);
  free(buffer);
  return (STATUS_SUCCESS);
}
