/*
** wolf_objects.h for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Dec 14 17:49:20 2016 Antoine Stempfer
** Last update Thu Dec 15 13:52:24 2016 Antoine Stempfer
*/

#ifndef WOLF_OBJECTS_H_
# define WOLF_OBJECTS_H_

# include <stdlib.h>
# include "wolf.h"

# define NUM_OBJECT_DEFS	50

static t_object_def		object_defs[NUM_OBJECT_DEFS] = {
  {"demo", 0, NULL},
  {"deathcam", 1, NULL},
  {"puddle", 2, NULL},
  {"barrel1", 3, NULL},
  {"table1", 4, NULL},
  {"lamp", 5, NULL},
  {"chandelier", 6, NULL},
  {"hanged", 7, NULL},
  {"bowl", 8, NULL},
  {"pillar", 9, NULL},
  {"tree1", 10, NULL},
  {"skeleton", 11, NULL},
  {"sink", 12, NULL},
  {"tree2", 13, NULL},
  {"jar", 14, NULL},
  {"table2", 15, NULL},
  {"light", 16, NULL},
  {"pans1", 17, NULL},
  {"armor", 18, NULL},
  {"cage", 19, NULL},
  {"cage_full", 20, NULL},
  {"skulls", 21, NULL},
  {"key_yellow", 22, NULL},
  {"key_blue", 23, NULL},
  {"bed", 24, NULL},
  {"pot", 25, NULL},
  {"food", 26, NULL},
  {"medikit", 27, NULL},
  {"ammos", 28, NULL},
  {"gun1", 29, NULL},
  {"gun2", 30, NULL},
  {"treasure1", 31, NULL},
  {"treasure2", 31, NULL},
  {"treasure3", 33, NULL},
  {"treasure4", 34, NULL},
  {"life", 35, NULL},
  {"bloody_skulls", 36, NULL},
  {"barrel2", 37, NULL},
  {"well_full", 38, NULL},
  {"well_empty", 39, NULL},
  {"blood", 40, NULL},
  {"flag", 41, NULL},
  {"call_apogee", 42, NULL},
  {"dust1", 43, NULL},
  {"dust2", 44, NULL},
  {"dust3", 45, NULL},
  {"pans2", 46, NULL},
  {"furnace", 47, NULL},
  {"spears", 48, NULL},
  {"vines", 49, NULL}
};

# endif /* WOLF_OBJECTS_H_ */
