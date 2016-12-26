/*
** damge_guard.c for wolf3d in /home/antoine.stempfer/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Wed Dec 21 13:25:42 2016 Antoine Stempfer
** Last update Wed Dec 21 14:35:19 2016 Antoine Stempfer
*/

#include "wolf.h"

void	damage_guard(t_enemy *guard, t_map *map, int damage)
{
  if (guard->state == state_dead)
    return ;
  guard->health -= damage;
  guard->hit_timer = HIT_CD;
  guard->attack_timer = guard->type->attack_speed;
  guard->state = state_chasing;
  if (guard->health <= 0)
    {
      map->player.score += 100;
      guard->state = state_dead;
      my_list_prepend(&map->entities, object_create(get_object_def("ammos"),
						    guard->entity->position,
						    map));
      if ((int)(map->app->time * 10) % 2 == 0)
	play_sound(sound_death_1, map);
      else
	play_sound(sound_death_2, map);
    }
  else
    play_sound(sound_enemy_pain, map);
}
