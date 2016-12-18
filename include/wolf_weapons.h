/*
** wolf_weapons.h for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Fri Dec 16 14:41:54 2016 Antoine Stempfer
** Last update Sun Dec 18 16:06:35 2016 Antoine Stempfer
*/

#ifndef WOLF_WEAPONS_H_
# define WOLF_WEAPONS_H_

# include "wolf.h"

# define NUM_WEAPON_DEFS	4

static t_weapon_def	weapon_defs[NUM_WEAPON_DEFS] = {
  {0, 20.0f, 0.5f, 1},
  {5, 10.0f, 0.45f, 1},
  {10, 4.0f, 0.15f, 1},
  {15, 4.0f, 0.10f, 1}
};

#endif /* WOLF_WEAPONS_H_ */
