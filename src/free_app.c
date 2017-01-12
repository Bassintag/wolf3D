/*
** free_app.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Jan 12 12:33:28 2017 Antoine Stempfer
** Last update Thu Jan 12 13:13:23 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "mylists.h"
#include "myio.h"
#include "wolf.h"

static void	free_entities(t_map *map)
{
  while (map->entities != NULL)
    {
      free(my_list_delete(&map->entities, 0));
    }
}

void	free_app(t_wolf *app)
{
  int	i;
  t_map	*map;

  my_destroy_texture_farray(app->textures_gui, gui_texture_count);
  my_free_strtab(app->quests);
  map = &app->map;
  if (map->init)
    {
      my_destroy_texture_farray(map->textures_enemies, enemy_def_count);
      free(map->textures_walls);
      free(map->textures_objects);
      free(map->textures_weapons);
      free(map->textures_head);
      free(map->textures_num);
      free(map->textures_weapon_icons);
      free(map->texture_hud_bg);
      i = 0;
      while (i < sound_count)
	{
	  sfSoundBuffer_destroy(map->sounds[i]);
	  i++;
	}
      free_entities(map);
    }
}
