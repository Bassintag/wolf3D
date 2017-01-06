/*
** wolf_keys.h for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 15:57:21 2016 Antoine Stempfer
** Last update Fri Jan  6 10:29:28 2017 Antoine Stempfer
*/

#ifndef WOLF3D_KEYS_H_
# define WOLF3D_KEYS_H_

# include "wolf.h"

struct				s_keybind
{
  sfKeyCode			key;
  void				(*on_event)(t_wolf *);
  int				screen;
  int				can_hold;
};

void				key_close(t_wolf *);

void				key_pause(t_wolf *);

void				key_forward(t_wolf *);

void				key_back(t_wolf *);

void				key_left(t_wolf *);

void				key_right(t_wolf *);

void				key_strafe_left(t_wolf *);

void				key_strafe_right(t_wolf *);

void				key_weapon_next(t_wolf *);

void				key_weapon_shoot(t_wolf *);

void				key_interact(t_wolf *);

static const struct s_keybind	keybinds[keybind_count] = {
  {k_close, &key_close, -1, 1},
  {k_pause, &key_pause, -1, 0},
  {k_right, &key_right, screen_ingame, 1},
  {k_left, &key_left, screen_ingame, 1},
  {k_strafe_right, &key_strafe_right, screen_ingame, 1},
  {k_strafe_left, &key_strafe_left, screen_ingame, 1},
  {k_forward, &key_forward, screen_ingame, 1},
  {k_back, &key_back, screen_ingame, 1},
  {k_weapon_next, &key_weapon_next, screen_ingame, 0},
  {k_weapon_shoot, &key_weapon_shoot, screen_ingame, 1},
  {k_interact, &key_interact, screen_ingame, 0}
};

#endif /* WOLF3D_KEYS_H_ */
