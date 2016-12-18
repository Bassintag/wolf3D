/*
** sound_utils.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Dec 18 23:39:25 2016 Antoine Stempfer
** Last update Sun Dec 18 23:43:36 2016 Antoine Stempfer
*/

#include "wolf.h"

void		play_sound(int sound_id, t_map *map)
{
  sfSound	*sound;

  sound = sfSound_create();
  sfSound_setBuffer(sound, map->sounds[sound_id]);
  sfSound_play(sound);
}
