/*
** update_pickup_chain_gun.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Dec 18 20:27:30 2016 Antoine Stempfer
** Last update Sun Dec 18 22:05:38 2016 Antoine Stempfer
*/

#include "wolf.h"

void	update_pickup_chain_gun(t_object *pickup, t_map *map)
{
  int	tx;
  int	ty;

  tx = TXPOS((*pickup));
  ty = TYPOS((*pickup));
  if (TXPOS(map->player) == tx && TYPOS(map->player) == ty)
    {
      if (!player_has_weapon(&map->player, &map->weapon_defs[3]))
	{
	  my_list_prepend(&map->player.weapons,
			  weapon_create(&map->weapon_defs[3]));
	  object_delete(pickup, map);
	  map->flash = 5;
	}
      else if (map->player.ammos < MAX_AMMOS)
	{
	  map->player.ammos += 6;
	  if (map->player.ammos > MAX_AMMOS)
	    map->player.ammos = MAX_AMMOS;
	  object_delete(pickup, map);
	  map->flash = 5;
	}
    }
}
