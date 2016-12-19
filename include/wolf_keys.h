/*
** wolf_keys.h for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 15:57:21 2016 Antoine Stempfer
** Last update Mon Dec 19 12:01:33 2016 Antoine Stempfer
*/

#ifndef WOLF3D_KEYS_H_
#define WOLF3D_KEYS_H_

#include "wolf.h"

struct			s_keybind
{
  sfKeyCode		key;
  void			(*on_event)(t_wolf *);
  int			can_hold;
};

void			key_close(t_wolf *);

void			key_forward(t_wolf *);

void			key_back(t_wolf *);

void			key_left(t_wolf *);

void			key_right(t_wolf *);

void			key_strafe_left(t_wolf *);

void			key_strafe_right(t_wolf *);

void			key_weapon_next(t_wolf *);

void			key_weapon_shoot(t_wolf *);

struct s_keybind	keybinds[keybind_count] = {
  {sfKeyEscape, &key_close, 1},
  {sfKeyRight, &key_right, 1},
  {sfKeyLeft, &key_left, 1},
  {sfKeyE, &key_strafe_right, 1},
  {sfKeyA, &key_strafe_left, 1},
  {sfKeyUp, &key_forward, 1},
  {sfKeyDown, &key_back, 1},
  {sfKeyF, &key_weapon_next, 0},
  {sfKeyX, &key_weapon_shoot, 1}
};

#endif
