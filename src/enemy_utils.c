/*
** enemy_utils.c for wolf3d in /home/antoine.stempfer/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Dec 20 13:23:55 2016 Antoine Stempfer
** Last update Mon Dec 26 23:43:42 2016 Antoine Stempfer
*/

#include "wolf_enemies.h"
#include "my.h"

t_enemy_def	*get_enemy_def(char *name)
{
  int		i;

  i = 0;
  while (i < enemy_def_count)
    {
      if (my_strcmp(g_enemy_defs[i].name, name) == 0)
	return (&g_enemy_defs[i]);
      i++;
    }
  return (NULL);
}

void		enemy_delete(t_enemy *enemy, t_map *map)
{
  my_list_remove(&map->entities, enemy->entity);
  free(enemy);
}

t_entity	*enemy_create(t_enemy_def *def, sfVector2f pos, t_map *map)
{
  t_entity	*res;
  t_enemy	*data;

  data = malloc(sizeof(t_enemy));
  res = malloc(sizeof(t_entity));
  data->state = state_idle;
  data->type = def;
  data->entity = res;
  data->angle = 0.0f;
  data->health = def->health;
  data->hit_timer = 0.0f;
  data->attack_timer = 0.0f;
  res->type = entity_enemy;
  res->position = pos;
  res->distance = 0;
  res->texture = 0;
  res->tileset = map->textures_enemies[def->tileset];
  res->data = data;
  res->on_update = update_enemy;
  return (res);
}

void		update_enemy(t_enemy *enemy, t_map *map)
{
  void		(*f)();

  if ((f = enemy->type->on_update) != NULL)
    f(enemy, map);
}
