/*
** my_framebuffer.c for bswireframe in /home/bassintag/delivery/CGP_2016/bswireframe/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Nov 14 21:43:18 2016 Antoine Stempfer
** Last update Mon Dec 12 14:06:48 2016 Antoine Stempfer
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_framebuffer.h"

t_my_framebuffer	my_framebuffer_create(int width, int height)
{
  t_my_framebuffer	buffer;
  sfColor		clear;
  int			x;
  int			y;

  clear = sfColor_fromRGBA(0, 0, 0, 255);
  buffer.width = width;
  buffer.height = height;
  buffer.pixels = malloc(sizeof(sfUint8) * width * height * 4);
  buffer.buffer_texture = sfTexture_create(width, height);
  buffer.buffer_sprite = sfSprite_create();
  sfSprite_setTexture(buffer.buffer_sprite, buffer.buffer_texture, sfTrue);
  x = 0;
  while (x < width)
    {
      y = 0;
      while (y < height)
	{
	  my_put_pixel(&buffer, x, y, clear);
	  y++;
	}
      x++;
    }
  return (buffer);
}

void			my_framebuffer_flip(t_my_framebuffer *buffer,
					    sfRenderWindow *window)
{
  sfTexture_updateFromPixels(buffer->buffer_texture, buffer->pixels,
			     buffer->width, buffer->height, 0, 0);
  sfRenderWindow_drawSprite(window, buffer->buffer_sprite, 0);
}
