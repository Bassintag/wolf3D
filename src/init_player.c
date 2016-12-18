/*
** init_player.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 13:42:29 2016 Antoine Stempfer
** Last update Sat Dec 17 23:21:39 2016 Antoine Stempfer
*/

#include "wolf_weapons.h"

int	init_player(t_player *player)
{
  player->position.x = 1.5f;
  player->position.y = 1.5f;
  player->dir.x = -1;
  player->dir.y = 0;
  player->cam_plane.x = 0;
  player->cam_plane.y = ((float)WINDOW_W / WINDOW_H) / 2;
  player->weapons = NULL;
  my_list_prepend(&player->weapons, create_weapon(&weapon_defs[0], 1));
  my_list_prepend(&player->weapons, create_weapon(&weapon_defs[3], 1));
  my_list_prepend(&player->weapons, create_weapon(&weapon_defs[2], 1));
  my_list_prepend(&player->weapons, create_weapon(&weapon_defs[1], 1));
  return (STATUS_SUCCESS);
}
