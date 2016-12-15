/*
** init_player.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 13:42:29 2016 Antoine Stempfer
** Last update Wed Dec 14 22:28:28 2016 Antoine Stempfer
*/

#include "wolf.h"

int	init_player(t_player *player)
{
  player->position.x = 1.5f;
  player->position.y = 1.5f;
  player->dir.x = -1;
  player->dir.y = 0;
  player->cam_plane.x = 0;
  player->cam_plane.y = 0.5f;
  return (STATUS_SUCCESS);
}
