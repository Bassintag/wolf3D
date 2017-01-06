/*
** move_forward.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Dec 14 13:02:56 2016 Antoine Stempfer
** Last update Fri Jan  6 09:21:43 2017 Antoine Stempfer
*/

#include <math.h>
#include "wolf.h"

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  pos.x += cosf(distance) * direction;
  pos.y += sinf(distance) * direction;
  return (pos);
}
