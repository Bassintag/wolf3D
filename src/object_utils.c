/*
** object_utils.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Dec 14 17:53:26 2016 Antoine Stempfer
** Last update Tue Dec 20 13:44:20 2016 Antoine Stempfer
*/

#include "wolf_objects.h"
#include "my.h"

t_object_def	*get_object_def(char *name)
{
  int		i;

  i = 0;
  while (i < object_def_count)
    {
      if (my_strcmp(g_object_defs[i].name, name) == 0)
	return (&g_object_defs[i]);
      i++;
    }
  return (NULL);
}

void		object_delete(t_object *object, t_map *map)
{
  my_list_remove(&map->entities, object->entity);
  free(object);
}

t_entity	*object_create(t_object_def *def, sfVector2f pos, t_map *map)
{
  t_entity	*res;
  t_object	*data;

  data = malloc(sizeof(t_object));
  res = malloc(sizeof(t_entity));
  data->type = def;
  data->entity = res;
  res->type = entity_object;
  res->position = pos;
  res->distance = 0;
  res->texture = def->texture;
  res->tileset = map->textures_objects;
  res->data = data;
  res->on_update = &update_object;
  return (res);
}

void		update_object(t_object *object, t_map *map)
{
  void	(*f)();

  if ((f = object->type->on_update) != NULL)
    f(object, map);
}
