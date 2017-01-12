/*
** my_slice_texture.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Tue Dec 13 12:57:16 2016 Antoine Stempfer
** Last update Thu Jan 12 12:47:05 2017 Antoine Stempfer
*/

#include <stdlib.h>
#include "wolf.h"

static int		load_from_texture(t_texture *texture, t_texture *res,
					  sfVector2i start, sfVector2i end)
{
  int			i;
  int			x;
  int			y;

  x = start.x;
  res->width = end.x - start.x;
  res->height = end.y - start.y;
  res->pixels = malloc(sizeof(char) * res->width * res->height * 4);
  while (x < end.x)
    {
      y = start.y;
      while (y < end.y)
	{
	  i = 0;
	  while (i < 4)
	    {
	      res->pixels[((x - start.x) * res->height + y - start.y) * 4 + i]
		= texture->pixels[(x * texture->height + y) * 4 + i];
	      i++;
	    }
	  y++;
	}
      x++;
    }
  return (STATUS_SUCCESS);
}

t_texture	*my_slice_texture(t_texture *texture, int w, int h)
{
  int		count_x;
  int		count_y;
  int		count;
  t_texture	*textures;

  count_x = texture->width / w;
  count_y = texture->height / h;
  if (count_x == 0 || count_y == 0)
    return (NULL);
  count = count_x * count_y;
  if ((textures = malloc(sizeof(t_texture) * count)) == NULL)
    return (NULL);
  while (--count >= 0)
    {
      load_from_texture(texture, &textures[count],
			my_vector2i_create(w * (count % count_x),
					   h * (count / (count_x))),
			my_vector2i_create(w * (count % count_x) + w,
					   h * (count / (count_x)) + h));
    }
  return (textures);
}
