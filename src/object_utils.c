/*
** object_utils.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Dec 14 17:53:26 2016 Antoine Stempfer
** Last update Sun Dec 18 23:11:06 2016 Antoine Stempfer
*/

#include <stdio.h>
#include "wolf_objects.h"
#include "my.h"

t_object_def	*get_object_def(char *name)
{
  int		i;

  i = 0;
  while (i < NUM_OBJECT_DEFS)
    {
      if (my_strcmp(g_object_defs[i].name, name) == 0)
	return (&g_object_defs[i]);
      i++;
    }
  return (NULL);
}

void	object_delete(t_object *object, t_map *map)
{
  my_list_remove(&map->objects, object);
  free(object);
}

t_object	*object_create(t_object_def *def, sfVector2f pos)
{
  t_object	*res;

  res = malloc(sizeof(t_object));
  res->type = def;
  res->position = pos;
  res->distance = 0;
  return (res);
}

int		compare_objects(void *elem1, void *elem2)
{
  t_object	*obj1;
  t_object	*obj2;

  obj1 = (t_object *)elem1;
  obj2 = (t_object *)elem2;
  if (obj1->distance > obj2->distance)
    return (1);
  if (obj1->distance < obj2->distance)
    return (-1);
  return (0);
}
