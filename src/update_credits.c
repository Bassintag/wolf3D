/*
** update_credits.c for wolf3d in /home/antoine.stempfer/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Dec 27 21:44:30 2016 Antoine Stempfer
** Last update Tue Dec 27 22:24:46 2016 Antoine Stempfer
*/

#include <math.h>
#include "wolf.h"

void		update_credits(t_my_framebuffer *buffer, t_wolf *app)
{
  t_texture	*bedel;

  bedel = app->textures_gui[gui_texture_bedel];
  my_clean(buffer, sfColor_fromRGB(163, 0, 0));
  my_draw_texture(buffer, bedel, WINDOW_W / 2 - bedel->width / 2 +
		  sinf(app->time) * 300,
		  WINDOW_H / 3 - bedel->height / 2 +
		  cosf(app->time) * 75);
  draw_menu_item(app, buffer, app->textures_gui[gui_texture_exit],
		 WINDOW_H / 4 * 3);
 if (!app->mouse_states[sfMouseLeft] && app->prev_mouse_states[sfMouseLeft])
   if (is_hovered(app->textures_gui[gui_texture_exit], WINDOW_H / 4 * 3,
		  app->mouse.y))
     {
       app->current_state = screen_main_menu;
       play_sound(sound_menu_select, &app->map);
     }
}
