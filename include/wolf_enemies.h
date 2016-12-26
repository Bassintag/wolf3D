/*
** wolf_enemies.h for wolf3d in /home/antoine.stempfer/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 19 15:44:27 2016 Antoine Stempfer
** Last update Mon Dec 26 14:35:52 2016 Antoine Stempfer
*/

#ifndef WOLF3D_ENEMIES_H_
# define WOLF3D_ENEMIES_H_

# include <stdlib.h>
# include "wolf.h"

void		       	update_guard(t_enemy *, t_map *);

void			damage_guard(t_enemy *, t_map *, int);

static t_enemy_def	g_enemy_defs[enemy_def_count] = {
  {"dog", 0, 20, 10, 1, 2.0f, 0.5f, NULL, NULL},
  {"guard", 1, 20, 10, 0, 2.0f, 0.5f, &update_guard, &damage_guard}
};

#endif
