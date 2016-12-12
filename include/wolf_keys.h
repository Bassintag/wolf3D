/*
** wolf_keys.h for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 15:57:21 2016 Antoine Stempfer
** Last update Mon Dec 12 16:02:47 2016 Antoine Stempfer
*/

#ifndef WOLF3D_KEYS_H_
#define WOLF3D_KEYS_H_

#include "wolf.h"

#define NUM_KEYBINDS	5

struct			s_keybind
{
  sfKeyCode		key;
  void			(*on_event)(t_wolf *);
};

void			key_close(t_wolf *);

void			key_forward(t_wolf *);

void			key_back(t_wolf *);

void			key_left(t_wolf *);

void			key_right(t_wolf *);

struct s_keybind	keybinds[NUM_KEYBINDS] = {
  {sfKeyEscape, &key_close},
  {sfKeyQ, &key_right},
  {sfKeyD, &key_left},
  {sfKeyZ, &key_forward},
  {sfKeyS, &key_back}
};

#endif
