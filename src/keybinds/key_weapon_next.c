/*
** key_weapon_next.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sat Dec 17 23:05:06 2016 Antoine Stempfer
** Last update Tue Dec 27 00:16:19 2016 Antoine Stempfer
*/

#include "wolf.h"

void	key_weapon_next(t_wolf *app)
{
  play_sound(sound_switch, &app->map);
  my_list_rotate(&app->map.player.weapons);
}
