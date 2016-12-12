/*
** init_player.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 13:42:29 2016 Antoine Stempfer
** Last update Mon Dec 12 15:40:04 2016 Antoine Stempfer
*/

#include "wolf.h"

int	init_player(t_player *player)
{
  player->position.x = 17;
  player->position.y = 12;
  player->rotation = 0;
  return (STATUS_SUCCESS);
}
