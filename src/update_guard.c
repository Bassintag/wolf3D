/*
** update_guard.c for wolf3d.c in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Dec 20 14:54:39 2016 Antoine Stempfer
** Last update Sun Jan 15 20:17:04 2017 Antoine Stempfer
*/

#include <math.h>
#include "wolf.h"
#include "my.h"

static void	on_shoot(t_enemy *guard, t_map *map, float dist)
{
  if (dist > -1 && dist < 6)
    {
      if (player_update_health(&map->player, -guard->type->damage))
	{
	  if ((int)(map->app->time * 10) % 2 == 0)
	    play_sound(sound_player_pain_1, map);
	  else
	    play_sound(sound_player_pain_2, map);
	  map->flash = 5;
	}
    }
  guard->attack_timer = guard->type->attack_speed - map->app->delta;
  guard->state = state_searching;
  play_sound(sound_pistol, map);
}

static void    	update_guard_state(t_enemy *guard, t_map *map)
{
  float		dist;

  if (guard->state == state_dead)
    return ;
  dist = can_see(guard->entity->position, map->player.position, map);
  if (guard->state == state_idle && dist > -1)
    {
      guard->state = state_chasing;
      play_sound(sound_halt, map);
    }
  if (guard->state == state_shooting && guard->attack_timer <= 0)
    on_shoot(guard, map, dist);
  else if (guard->state == state_shooting)
    guard->attack_timer -= map->app->delta;
  if(guard->state == state_searching && dist > -1)
    guard->state = state_chasing;
  if (guard->state == state_chasing && dist <= 3 && dist > -1)
    {
      guard->attack_timer = guard->type->attack_speed - map->app->delta;
      guard->state = state_shooting;
    }
  if (guard->state != state_idle && dist < 0)
    guard->state = state_searching;
}

static void    	update_texture(t_enemy *guard, t_map *map,
			       int *id, float angle)
{
  if (guard->state == state_chasing)
    *id = 8 * ((int)(map->app->time * 8) % 4) + 8;
  else if (guard->state == state_shooting)
    *id = 50 - (int)(guard->attack_timer / guard->type->attack_speed * 3);
  else if (guard->state == state_dead)
    *id = 44;
  else
    *id = ABS((int)((angle - guard->angle + M_PI) / M_PI * 4) % 8);
  if (guard->hit_timer > 0)
    {
      if (guard->state == state_dead)
	*id = 44 - (int)(guard->hit_timer / HIT_CD * 4);
      else
	*id = 47;
      guard->hit_timer -= map->app->delta;
    }
}

void		update_guard(t_enemy *guard, t_map *map)
{
  float		angle;
  float		mult;
  int		texture_id;

  update_guard_state(guard, map);
  angle = atan2(XPOS(map->player) - XPOS((*guard->entity)),
		YPOS(map->player) - YPOS((*guard->entity)));
  update_texture(guard, map, &texture_id, angle);
  if (guard->state == state_chasing || guard->state == state_shooting)
    {
      guard->angle = angle - M_PI;
      if (guard->state == state_chasing)
	{
	  mult = guard->type->speed * map->app->delta;
	  XPOS((*guard->entity)) += sinf(angle) * mult;
	  YPOS((*guard->entity)) += cosf(angle) * mult;
	}
    }
  guard->entity->texture = texture_id;
}
