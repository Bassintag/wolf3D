/*
** wolf_states.h for wolf3d in /home/antoine.stempfer/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 26 14:31:26 2016 Antoine Stempfer
** Last update Tue Dec 27 00:00:15 2016 Antoine Stempfer
*/

#ifndef WOLF_STATES_H_
# define WOLF_STATES_H_

# include "wolf.h"

void				update_main_menu(t_wolf *app);

void				update_ingame(t_wolf *app);

void				update_pause(t_wolf *app);

static const t_game_state	g_game_states[screen_count] = {
  {NULL, &update_main_menu, NULL},
  {NULL, &update_ingame, NULL},
  {NULL, &update_pause, NULL},
  {NULL, NULL, NULL},
};

#endif /* WOLF_STATES_H_ */
