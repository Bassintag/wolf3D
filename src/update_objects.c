/*
** update_objects.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Dec 18 15:20:07 2016 Antoine Stempfer
** Last update Mon Dec 19 13:17:19 2016 Antoine Stempfer
*/

#include "wolf.h"

void		update_objects(t_map *map, t_object *object)
{
  void		(*f)();

  f = object->type->on_update;
  if (f != NULL)
    f(object, map);
}
