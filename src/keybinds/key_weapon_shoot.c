/*
** key_weapon_shoot.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Dec 18 15:55:57 2016 Antoine Stempfer
** Last update Wed Dec 21 14:52:18 2016 Antoine Stempfer
*/

#include <math.h>
#include "wolf.h"
#include "my.h"

static int     	shoot_enemy(t_map *map, t_enemy *enemy,
			    float p_angle, int damage)
{
  t_entity	*entity;
  float		angle;

  entity = enemy->entity;
  angle = atan2(YPOS((*entity)) - YPOS((map->player)),
		XPOS((*entity)) - XPOS((map->player)));
  if (angle - p_angle < M_PI / 16 && angle - p_angle > -M_PI / 16)
    {
      enemy->type->on_damage(enemy, map, damage);
      return (1);
    }
  return (0);
}

void		apply_damages(t_map *map, char close_range, int damage)
{
  int		i;
  float		p_angle;
  t_entity	*entity;
  t_enemy	*enemy;

  i = my_list_len(map->entities);
  p_angle = P_ANGLE(map->player);
  while (--i >= 0 && (entity = my_list_get(map->entities, i)) != NULL)
    {
      if (entity->type == entity_enemy)
	{
	  enemy = entity->data;
	  if ((!close_range || entity->distance <= 1) &&
	      enemy->state != state_dead)
	    {
	      if (can_see(map->player.position, entity->position, map) > 0
		  && shoot_enemy(map, enemy, p_angle, damage))
		return ;
	    }
	}
    }
}

void		key_weapon_shoot(t_wolf *app)
{
  t_weapon	*weapon;
  char		close_range;

  weapon = my_list_get(app->map.player.weapons, 0);
  if (weapon == NULL)
    return ;
  close_range = weapon->type->close_range;
  if ((!close_range && app->map.player.ammos <= 0) || weapon->cooldown > 0)
    return ;
  if (!close_range)
    app->map.player.ammos -= 1;
  apply_damages(&app->map, close_range,
		(int)(app->time * 100) % weapon->type->damage);
  play_sound(weapon->type->sound, &app->map);
  weapon->cooldown = weapon->type->cooldown;
}
