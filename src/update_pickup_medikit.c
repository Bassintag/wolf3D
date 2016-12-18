/*
** update_pickup_medikit.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Dec 18 16:34:12 2016 Antoine Stempfer
** Last update Mon Dec 19 00:18:20 2016 Antoine Stempfer
*/

#include "wolf.h"

void	update_pickup_medikit(t_object *pickup, t_map *map)
{
  int	tx;
  int	ty;

  tx = TXPOS((*pickup));
  ty = TYPOS((*pickup));
  if (TXPOS(map->player) == tx && TYPOS(map->player) == ty)
    {
      if (player_update_health(&map->player, 25))
	{
	  play_sound(sound_health, map);
	  object_delete(pickup, map);
	  map->flash = 5;
	}
    }
}
