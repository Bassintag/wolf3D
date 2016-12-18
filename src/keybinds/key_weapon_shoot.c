/*
** key_weapon_shoot.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Dec 18 15:55:57 2016 Antoine Stempfer
** Last update Mon Dec 19 00:05:35 2016 Antoine Stempfer
*/

#include "wolf.h"

void		key_weapon_shoot(t_wolf *app)
{
  t_weapon	*weapon;
  char		close_range;

  weapon = my_list_get(app->map.player.weapons, 0);
  if (weapon == NULL)
    return ;
  close_range = weapon->type->close_range;
  if ((!close_range && app->map.player.ammos <= 0) || weapon->cooldown > 0)
    return ;
  if (!close_range)
    app->map.player.ammos -= 1;
  play_sound(weapon->type->sound, &app->map);
  weapon->cooldown = weapon->type->cooldown;
}
