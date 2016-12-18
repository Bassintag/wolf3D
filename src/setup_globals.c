/*
** setup_globals.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Dec 18 20:32:17 2016 Antoine Stempfer
** Last update Sun Dec 18 21:04:49 2016 Antoine Stempfer
*/

#include "wolf_weapons.h"

t_weapon_def		g_weapon_defs[NUM_WEAPON_DEFS];

static t_weapon_def	create_weapon_def(int id, float dmg, float cd, int cc)
{
  t_weapon_def		def;

  def.texture = id;
  def.damage = dmg;
  def.cooldown = cd;
  def.close_range = cc;
  return (def);
}

void	setup_globals()
{
  int	i;

  g_weapon_defs[0] = create_weapon_def(0, 20.0f, 0.5f, 1);
  g_weapon_defs[1] = create_weapon_def(5, 10.0f, 0.45f, 0);
  g_weapon_defs[2] = create_weapon_def(10, 4.0f, 0.15f, 0);
  g_weapon_defs[3] = create_weapon_def(15, 4.0f, 0.10f, 0);
  i = 0;
  while (i < 4)
    {
      g_weapon_defs[i].icon = i;
      i++;
    }
}
