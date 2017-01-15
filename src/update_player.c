/*
** update_player.c for wolf3d in /home/antoine.stempfer/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Dec 21 12:58:25 2016 Antoine Stempfer
** Last update Sun Jan 15 20:20:35 2017 Antoine Stempfer
*/

#include "wolf.h"

void	update_player(t_player *player, t_map *map)
{
  if (player->hit_timer > 0)
    player->hit_timer -= map->app->delta;
  if (player->health <= 0)
    sfRenderWindow_close(map->app->window);
}
