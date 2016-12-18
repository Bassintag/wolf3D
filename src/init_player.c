/*
** init_player.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 13:42:29 2016 Antoine Stempfer
** Last update Sun Dec 18 20:45:50 2016 Antoine Stempfer
*/

#include "wolf_weapons.h"

t_weapon_def	g_weapon_defs[NUM_WEAPON_DEFS];

int	init_player(t_player *player)
{
  player->position.x = 1.5f;
  player->position.y = 1.5f;
  player->dir.x = -1;
  player->dir.y = 0;
  player->cam_plane.x = 0;
  player->cam_plane.y = 1;
  player->score = 0;
  player->ammos = 8;
  player->health = 1;
  player->weapons = NULL;
  my_list_prepend(&player->weapons, weapon_create(&g_weapon_defs[0]));
  my_list_prepend(&player->weapons, weapon_create(&g_weapon_defs[1]));
  return (STATUS_SUCCESS);
}
