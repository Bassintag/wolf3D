/*
** update_pickup_machine_gun.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Dec 18 20:27:30 2016 Antoine Stempfer
** Last update Mon Dec 19 13:28:44 2016 Antoine Stempfer
*/

#include "wolf.h"

void	update_pickup_machine_gun(t_object *pickup, t_map *map)
{
  int	tx;
  int	ty;
  int	id;

  id = weapon_def_machine_gun;
  tx = TXPOS((*pickup->entity));
  ty = TYPOS((*pickup->entity));
  if (TXPOS(map->player) == tx && TYPOS(map->player) == ty)
    {
      if (!player_has_weapon(&map->player, &map->weapon_defs[id]))
	my_list_prepend(&map->player.weapons,
			weapon_create(&map->weapon_defs[id]));
      else if (map->player.ammos < MAX_AMMOS)
	{
	  map->player.ammos += 6;
	  if (map->player.ammos > MAX_AMMOS)
	    map->player.ammos = MAX_AMMOS;
	}
      else
	return ;
      object_delete(pickup, map);
      map->flash = 5;
      play_sound(sound_ammo, map);
    }
}
