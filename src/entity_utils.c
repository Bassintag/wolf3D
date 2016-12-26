/*
** entity_utils.c for wolf3d in /home/antoine.stempfer/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 19 15:21:45 2016 Antoine Stempfer
** Last update Mon Dec 19 15:21:52 2016 Antoine Stempfer
*/

#include "wolf.h"

int		compare_entities(void *elem1, void *elem2)
{
  t_entity	*obj1;
  t_entity	*obj2;

  obj1 = (t_entity *)elem1;
  obj2 = (t_entity *)elem2;
  if (obj1->distance > obj2->distance)
    return (1);
  if (obj1->distance < obj2->distance)
    return (-1);
  return (0);
}
