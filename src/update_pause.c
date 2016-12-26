/*
** update_pause.c for wolf3d in /home/antoine.stempfer/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Dec 27 00:00:46 2016 Antoine Stempfer
** Last update Tue Dec 27 00:15:04 2016 Antoine Stempfer
*/

#include "wolf.h"

void		update_pause(t_my_framebuffer *buffer, t_wolf *app)
{
  my_clean(buffer, sfColor_fromRGB(163, 0, 0));
  gui_draw_image_centered(buffer, app->textures_gui[gui_texture_paused],
			  WINDOW_H / 8);
}
