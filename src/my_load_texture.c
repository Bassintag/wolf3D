/*
** my_load_texture.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 12 21:48:00 2016 Antoine Stempfer
** Last update Mon Dec 19 00:13:45 2016 Antoine Stempfer
*/

#include <stdlib.h>
#include "my.h"
#include "myio.h"
#include "wolf.h"

static int	read_header(t_texture *texture, char *header)
{
  char		**split;

  split = my_split(header, ',');
  if (my_strtablen(split) != 2)
    return (STATUS_FAILURE);
  texture->width = my_getnbr(split[0]);
  texture->height = my_getnbr(split[1]);
  if (texture->width <= 0 || texture->height <= 0)
    return (STATUS_FAILURE);
  return (STATUS_SUCCESS);
}

static int	read_pixels(t_texture *texture, char *pixels, int size)
{
  int		i;
  int		j;
  char		px[4];

  i = 0;
  px[3] = '\0';
  texture->pixels = malloc(sizeof(char) * size);
  if (size * 3 > my_strlen(pixels) || texture->pixels == NULL)
    return (EXIT_FAILURE);
  i = 0;
  while (i < size)
    {
      j = 0;
      while (j < 3)
	{
	  px[j] = pixels[i * 3 + j];
	  j++;
	}
      texture->pixels[i] = my_getnbr(px);
      i++;
    }
  return (EXIT_SUCCESS);
}

static int	parse_texture(t_texture *texture, char *buffer)
{
  char		**split;
  int		size;

  split = my_split(buffer, '\n');
  if (my_strtablen(split) != 2)
    return (STATUS_FAILURE);
  if (read_header(texture, split[0]) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  size = texture->width * texture->height * 4;
  if (read_pixels(texture, split[1], size) == STATUS_FAILURE)
    return (STATUS_FAILURE);
  free(split);
  return (STATUS_SUCCESS);
}

t_texture	*my_load_texture(char *path)
{
  char		*buffer;
  t_texture    	*texture;

  my_printf("Loading texture: %s\n", path);
  if ((buffer = my_buff_file(path, BUFFER_SIZE)) == NULL)
    return (NULL);
  texture = malloc(sizeof(t_texture));
  if (parse_texture(texture, buffer) == STATUS_FAILURE)
    {
      free(buffer);
      free(texture);
      return (NULL);
    }
  free(buffer);
  return (texture);
}
