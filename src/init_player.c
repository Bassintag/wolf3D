/*
** init_player.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 13:42:29 2016 Antoine Stempfer
** Last update Wed Dec 21 12:57:16 2016 Antoine Stempfer
*/

#include "wolf.h"

int	init_player(t_player *player, t_map *map)
{
  player->position.x = 1.5f;
  player->position.y = 1.5f;
  player->dir.x = -1;
  player->dir.y = 0;
  player->cam_plane.x = 0;
  player->cam_plane.y = 1;
  player->hit_timer = 0;
  player->score = 0;
  player->ammos = 8;
  player->health = MAX_HEALTH;
  player->weapons = NULL;
  my_list_prepend(&player->weapons, weapon_create(&map->weapon_defs[0]));
  my_list_prepend(&player->weapons, weapon_create(&map->weapon_defs[1]));
  return (STATUS_SUCCESS);
}
