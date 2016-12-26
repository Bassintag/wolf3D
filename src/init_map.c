/*
** init_map.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 13:07:57 2016 Antoine Stempfer
** Last update Tue Dec 20 13:54:10 2016 Antoine Stempfer
*/

#include <stdlib.h>
#include "myio.h"
#include "my.h"
#include "wolf.h"

static int	parse_line(t_map *map, char *line, int y)
{
  char		**split;
  int		x;
  int		width;

  split = my_split(line, ',');
  width = my_strtablen(split);
  if (y == 0)
    map->size.x = width;
  else if (width != map->size.x)
    return (STATUS_FAILURE);
  map->tiles[y] = malloc(sizeof(int) * width);
  x = 0;
  while (x < width)
    {
      map->tiles[y][x] = my_getnbr(split[x]);
      x++;
    }
  return (STATUS_SUCCESS);
}

static int	load_map(t_map *map, char *path)
{
  char		*buffer;
  char		**lines;
  int		y;

  if ((buffer = my_buff_file(path, BUFFER_SIZE)) == NULL)
    return (STATUS_FAILURE);
  if ((lines = my_readlines(buffer)) == NULL)
    return (STATUS_FAILURE);
  map->size.y = my_strtablen(lines);
  map->tiles = malloc(sizeof(int *) * map->size.y);
  y = 0;
  while (y < map->size.y)
    {
      if (parse_line(map, lines[y], y) == STATUS_FAILURE)
	return (STATUS_FAILURE);
      y++;
    }
  my_free_strtab(lines);
  free(buffer);
  return (STATUS_SUCCESS);
}

int		init_map(t_map *map, char *path, t_wolf *app)
{
  if (load_map(map, path) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  if (init_walls_textures(map) == STATUS_FAILURE ||
      init_objects_textures(map) == STATUS_FAILURE ||
      init_enemies_textures(map) == STATUS_FAILURE ||
      init_weapons_textures(map) == STATUS_FAILURE ||
      init_hud_textures(map) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  if (init_weapon_defs(map) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  if (init_player(&(map->player), map) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  if (init_entities(map, path) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  if (init_sounds(map) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  if ((map->z_buffer = malloc(sizeof(float) * WINDOW_W)) == NULL)
    return (STATUS_FAILURE);
  if (map->size.x < 3 || map->size.y < 3)
    return (STATUS_FAILURE);
  map->app = app;
  map->flash = 0;
  return (STATUS_SUCCESS);
}
