/*
** object_utils.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Dec 14 17:53:26 2016 Antoine Stempfer
** Last update Thu Dec 15 13:31:04 2016 Antoine Stempfer
*/

#include "wolf_objects.h"
#include "my.h"

t_object_def	*get_object_def(char *name)
{
  int		i;

  i = 0;
  while (i < NUM_OBJECT_DEFS)
    {
      if (my_strcmp(object_defs[i].name, name) == 0)
	return (&object_defs[i]);
      i++;
    }
  return (NULL);
}

t_object	*object_create(t_object_def *def, sfVector2f pos)
{
  t_object	*res;

  res = malloc(sizeof(t_object));
  res->type = def;
  res->position = pos;
  return (res);
}
