/*
** weapon_utils.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Fri Dec 16 14:49:48 2016 Antoine Stempfer
** Last update Fri Dec 16 14:52:02 2016 Antoine Stempfer
*/

#include <stdlib.h>
#include "wolf.h"

t_weapon	*create_weapon(t_weapon_def *def, int ammos)
{
  t_weapon	*res;

  res = malloc(sizeof(t_weapon));
  res->type = def;
  res->ammos = ammos;
  res->cooldown = 0;
  return (res);
}
