/*
** my_draw_num.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Dec 18 19:43:35 2016 Antoine Stempfer
** Last update Sun Dec 18 19:51:52 2016 Antoine Stempfer
*/

#include "wolf.h"

void		my_draw_num_left_hud(t_my_framebuffer *buffer, int num,
				     t_texture *font, sfVector2i pos)
{
  int		i;

  i = 0;
  while (i++ == 0 || num > 0)
    {
      my_draw_texture_scaled(buffer, &font[num % 10], pos, HUD_SCALE);
      i++;
      num /= 10;
      pos.x += TEXTURE_NUM_W * HUD_SCALE;
    }
}

void		my_draw_num_right_hud(t_my_framebuffer *buffer, int num,
				      t_texture *font, sfVector2i pos)
{
  int		i;

  i = 0;
  while (i++ == 0 || num > 0)
    {
      pos.x -= TEXTURE_NUM_W * HUD_SCALE;
      my_draw_texture_scaled(buffer, &font[num % 10], pos, HUD_SCALE);
      i++;
      num /= 10;
    }
}
