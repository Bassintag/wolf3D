/*
** update_pickup_score.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Dec 18 15:32:15 2016 Antoine Stempfer
** Last update Mon Dec 19 00:19:36 2016 Antoine Stempfer
*/

#include "wolf.h"

void	update_pickup_score(t_object *pickup, t_map *map)
{
  int	tx;
  int	ty;

  tx = TXPOS((*pickup));
  ty = TYPOS((*pickup));
  if (TXPOS(map->player) == tx && TYPOS(map->player) == ty)
    {
      play_sound(sound_pickup, map);
      map->player.score += 100;
      object_delete(pickup, map);
      map->flash = 5;
    }
}
