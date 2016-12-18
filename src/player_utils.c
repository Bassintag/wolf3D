/*
** player_utils.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Dec 18 16:37:12 2016 Antoine Stempfer
** Last update Sun Dec 18 16:39:33 2016 Antoine Stempfer
*/

#include "wolf.h"

int	player_update_health(t_player *player, int amount)
{
  if (player->health <= 0 || player->health >= 100)
    return (0);
  player->health += amount;
  if (player->health < 0)
    player->health = 0;
  if (player->health > 100)
    player->health = 100;
  return (1);
}
