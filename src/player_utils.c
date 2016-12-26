/*
** player_utils.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Dec 18 16:37:12 2016 Antoine Stempfer
** Last update Wed Dec 21 13:01:57 2016 Antoine Stempfer
*/

#include "wolf.h"

int		player_has_weapon(t_player *player, t_weapon_def *def)
{
  int		i;
  t_weapon	*weapon;

  i = 0;
  while ((weapon = my_list_get(player->weapons, i++)) != NULL)
    if (weapon->type == def)
      return (1);
  return (0);
}

int	player_update_health(t_player *player, int amount)
{
  if (player->health <= 0 || (player->health >= MAX_HEALTH && amount > 0))
    return (0);
  if (amount < 0)
    {
      if (player->hit_timer > 0)
	return (0);
      player->hit_timer = HIT_CD;
    }
  player->health += amount;
  if (player->health < 0)
    player->health = 0;
  if (player->health > MAX_HEALTH)
    player->health = MAX_HEALTH;
  return (1);
}
