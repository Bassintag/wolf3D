/*
** update_main_menu.c for wold3d in /home/antoine.stempfer/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 26 14:54:24 2016 Antoine Stempfer
** Last update Mon Dec 26 23:50:00 2016 Antoine Stempfer
*/

#include "wolf.h"

static int	in_bounds(sfVector2i start, sfVector2i end, sfVector2f pos)
{
  if (pos.x < start.x || pos.x > end.x)
    return (0);
  if (pos.y < start.y || pos.y > end.y)
    return (0);
  return (1);
}

static void	draw_menu_item(t_wolf *app, t_my_framebuffer *buffer,
			       t_texture *texture, int y)
{
  sfVector2i	pos;
  sfVector2i	top_left;
  sfVector2i	bottom_right;
  sfColor	bg;

  pos.y = y - texture->height / 2 * MENU_SCALE;
  top_left = my_vector2i_create(WINDOW_W / 4, pos.y - 10);
  bottom_right = my_vector2i_create(WINDOW_W / 4 * 3,
				    pos.y + texture->height * MENU_SCALE + 10);
  bg = in_bounds(top_left, bottom_right, app->mouse) ?
    (app->mouse_states[sfMouseLeft] ? sfBlue : sfColor_fromRGB(186, 86, 0))
     : sfBlack;
  pos.x = buffer->width / 2 - (texture->width / 2 * MENU_SCALE);
  my_draw_rect(buffer, top_left, bottom_right, bg);
  my_draw_texture_scaled(buffer, texture, pos, MENU_SCALE);
}

static char	is_hovered(t_texture *texture, int ty, int y)
{
  if (y < ty - texture->height * MENU_SCALE / 2 - 10)
    return (0);
  if (y > ty + texture->height * MENU_SCALE / 2 + 10)
    return (0);
  return (1);
}

static char	on_click(t_wolf *app, sfVector2f *pos)
{
  if (pos->x < WINDOW_W / 4)
    return (0);
  if (pos->x > WINDOW_W / 4 * 3)
    return (0);
  if (is_hovered(app->textures_gui[gui_texture_play],
		 WINDOW_H / 4, pos->y))
    {
      app->current_state = screen_ingame;
      return (1);
    }
  if (is_hovered(app->textures_gui[gui_texture_credits],
		 WINDOW_H / 2, pos->y))
    {
      return (1);
    }
  if (is_hovered(app->textures_gui[gui_texture_exit],
		 WINDOW_H / 4 * 3, pos->y))
    {
      sfRenderWindow_close(app->window);
      return (1);
    }
  return (0);
}

void		update_main_menu(t_my_framebuffer *buffer, t_wolf *app)
{
  sfColor	background;

  background = sfColor_fromRGB(163, 0, 0);
  my_clean(buffer, background);
  draw_menu_item(app, buffer, app->textures_gui[gui_texture_play],
		 WINDOW_H / 4);
  draw_menu_item(app, buffer, app->textures_gui[gui_texture_credits],
		 WINDOW_H / 2);
  draw_menu_item(app, buffer, app->textures_gui[gui_texture_exit],
		 WINDOW_H / 4 * 3);
  if (!app->mouse_states[sfMouseLeft] && app->prev_mouse_states[sfMouseLeft])
    if (on_click(app, &app->mouse))
      play_sound(sound_menu_select, &app->map);
}
