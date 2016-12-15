/*
** init_map.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 13:07:57 2016 Antoine Stempfer
** Last update Wed Dec 14 19:45:17 2016 Antoine Stempfer
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

int		init_map(t_map *map, char *path)
{
  t_texture	*tileset_walls;
  t_texture	*tileset_objs;

  if (load_map(map, path) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  if (init_player(&(map->player)) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  if (init_entities(map, path) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  if ((tileset_walls = my_load_texture(TILESET_WALLS_PATH)) == NULL)
    return (STATUS_FAILURE);
  if ((tileset_objs = my_load_texture(TILESET_OBJECTS_PATH)) == NULL)
    return (STATUS_FAILURE);
  if ((map->textures_walls =
       my_slice_texture(tileset_walls, TEXTURE_RES, TEXTURE_RES)) == NULL)
    return (STATUS_FAILURE);
  if ((map->textures_objects =
       my_slice_texture(tileset_objs, TEXTURE_RES, TEXTURE_RES)) == NULL)
    return (STATUS_FAILURE);
  if ((map->z_buffer = malloc(sizeof(float) * WINDOW_W)) == NULL)
    return (STATUS_FAILURE);
  return (STATUS_SUCCESS);
}
