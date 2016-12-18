/*
** key_weapon_shoot.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Dec 18 15:55:57 2016 Antoine Stempfer
** Last update Sun Dec 18 16:00:01 2016 Antoine Stempfer
*/

#include "wolf.h"

void		key_weapon_shoot(t_wolf *wolf)
{
  t_weapon	*weapon;

  weapon = my_list_get(wolf->map.player.weapons, 0);
  if (weapon == NULL)
    return ;
  if (weapon->ammos <= 0 || weapon->cooldown > 0)
    return ;
  weapon->cooldown = weapon->type->cooldown;
}
