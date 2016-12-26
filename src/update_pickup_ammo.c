/*
** update_pickup_ammo.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Dec 18 20:24:04 2016 Antoine Stempfer
** Last update Mon Dec 19 13:28:27 2016 Antoine Stempfer
*/

#include "wolf.h"

void	update_pickup_ammo(t_object *pickup, t_map *map)
{
  int	tx;
  int	ty;

  tx = TXPOS((*pickup->entity));
  ty = TYPOS((*pickup->entity));
  if (TXPOS(map->player) == tx && TYPOS(map->player) == ty)
    {
      if (map->player.ammos < MAX_AMMOS)
	{
	  map->player.ammos += 6;
	  if (map->player.ammos > MAX_AMMOS)
	    map->player.ammos = MAX_AMMOS;
	  play_sound(sound_ammo, map);
	  object_delete(pickup, map);
	  map->flash = 5;
	}
    }
}
