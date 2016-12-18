/*
** wolf_objects.h for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Dec 14 17:49:20 2016 Antoine Stempfer
** Last update Sun Dec 18 23:10:31 2016 Antoine Stempfer
*/

#ifndef WOLF_OBJECTS_H_
# define WOLF_OBJECTS_H_

# include <stdlib.h>
# include "wolf.h"

# define NUM_OBJECT_DEFS	50

void				update_pickup_score(t_object *, t_map *);

void				update_pickup_food(t_object *, t_map *);

void				update_pickup_dog_food(t_object *, t_map *);

void				update_pickup_medikit(t_object *, t_map *);

void				update_pickup_ammo(t_object *, t_map *);

void				update_pickup_machine_gun(t_object *, t_map *);

void				update_pickup_chain_gun(t_object *, t_map *);

static t_object_def		g_object_defs[NUM_OBJECT_DEFS] = {
  {"demo", 0, 0, NULL},
  {"deathcam", 1, 0, NULL},
  {"puddle", 2, 0, NULL},
  {"barrel1", 3, 1, NULL},
  {"table1", 4, 1, NULL},
  {"lamp", 5, 1, NULL},
  {"chandelier", 6, 0, NULL},
  {"hanged", 7, 1, NULL},
  {"bowl", 8, 0, &update_pickup_dog_food},
  {"pillar", 9, 1, NULL},
  {"tree1", 10, 1, NULL},
  {"skeleton", 11, 1, NULL},
  {"sink", 12, 1, NULL},
  {"tree2", 13, 1, NULL},
  {"jar", 14, 1, NULL},
  {"table2", 15, 1, NULL},
  {"light", 16, 0, NULL},
  {"pans1", 17, 1, NULL},
  {"armor", 18, 1, NULL},
  {"cage", 19, 1, NULL},
  {"cage_full", 20, 1, NULL},
  {"skulls", 21, 1, NULL},
  {"key_yellow", 22, 0, NULL},
  {"key_blue", 23, 0, NULL},
  {"bed", 24, 1, NULL},
  {"pot", 25, 1, NULL},
  {"food", 26, 0, &update_pickup_food},
  {"medikit", 27, 0, &update_pickup_medikit},
  {"ammos", 28, 0, &update_pickup_ammo},
  {"gun1", 29, 0, &update_pickup_machine_gun},
  {"gun2", 30, 0, &update_pickup_chain_gun},
  {"treasure1", 31, 0, &update_pickup_score},
  {"treasure2", 32, 0, &update_pickup_score},
  {"treasure3", 33, 0, &update_pickup_score},
  {"treasure4", 34, 0, &update_pickup_score},
  {"life", 35, 0, NULL},
  {"bloody_skulls", 36, 1, NULL},
  {"barrel2", 37, 1, NULL},
  {"well_full", 38, 1, NULL},
  {"well_empty", 39, 1, NULL},
  {"blood", 40, 1, NULL},
  {"flag", 41, 1, NULL},
  {"call_apogee", 42, 1, NULL},
  {"dust1", 43, 1, NULL},
  {"dust2", 44, 1, NULL},
  {"dust3", 45, 1, NULL},
  {"pans2", 46, 1, NULL},
  {"furnace", 47, 1, NULL},
  {"spears", 48, 1, NULL},
  {"vines", 49, 0, NULL}
};

# endif /* WOLF_OBJECTS_H_ */
