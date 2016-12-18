/*
** key_weapon_next.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sat Dec 17 23:05:06 2016 Antoine Stempfer
** Last update Sat Dec 17 23:17:03 2016 Antoine Stempfer
*/

#include <stdio.h>
#include "wolf.h"

void	key_weapon_next(t_wolf *app)
{
  my_list_rotate(&app->map.player.weapons);
}
