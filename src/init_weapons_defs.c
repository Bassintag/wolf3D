/*
** setup_globals.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Dec 18 20:32:17 2016 Antoine Stempfer
** Last update Mon Dec 19 00:24:03 2016 Antoine Stempfer
*/

#include "wolf.h"

static t_weapon_def	create_weapon_def(int id, float dmg, float cd, int cc)
{
  t_weapon_def		def;

  def.texture = id;
  def.damage = dmg;
  def.cooldown = cd;
  def.close_range = cc;
  return (def);
}

int	init_weapon_defs(t_map *map)
{
  int	i;

  map->weapon_defs[weapon_def_knife] =
    create_weapon_def(0, 20.0f, 0.5f, 1);
  map->weapon_defs[weapon_def_pistol] =
    create_weapon_def(5, 10.0f, 0.45f, 0);
  map->weapon_defs[weapon_def_machine_gun] =
    create_weapon_def(10, 4.0f, 0.15f, 0);
  map->weapon_defs[weapon_def_chain_gun] =
    create_weapon_def(15, 4.0f, 0.10f, 0);
  i = 0;
  while (i < weapon_def_count)
    {
      map->weapon_defs[i].icon = i;
      i++;
    }
  map->weapon_defs[weapon_def_knife].sound = sound_knife;
  map->weapon_defs[weapon_def_pistol].sound = sound_pistol;
  map->weapon_defs[weapon_def_machine_gun].sound = sound_machine_gun;
  map->weapon_defs[weapon_def_chain_gun].sound = sound_gatling_gun;
  return (STATUS_SUCCESS);
}
