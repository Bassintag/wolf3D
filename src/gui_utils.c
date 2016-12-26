/*
** gui_utils.c for wolf3d in /home/antoine.stempfer/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Dec 27 00:09:15 2016 Antoine Stempfer
** Last update Tue Dec 27 00:12:53 2016 Antoine Stempfer
*/

#include "wolf.h"

void		gui_draw_image_centered(t_my_framebuffer *buffer,
					t_texture *texture, int y)
{
  sfVector2i	pos;

  pos.y = y - texture->height / 2 * MENU_SCALE;
  pos.x = buffer->width / 2 - (texture->width / 2 * MENU_SCALE);
  my_draw_texture_scaled(buffer, texture, pos, MENU_SCALE);
}
