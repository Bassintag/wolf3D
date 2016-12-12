/*
** my_framebuffer.h for bswireframe in /home/bassintag/delivery/CGP_2016/bswireframe/src
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Nov 14 21:40:38 2016 Antoine Stempfer
** Last update Mon Dec 12 14:06:36 2016 Antoine Stempfer
*/

#ifndef MY_FRAMEBUFFER_H_
#define MY_FRAMEBUFFER_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>

typedef struct 	s_my_framebuffer
{
  sfUint8	*pixels;
  sfTexture	*buffer_texture;
  sfSprite	*buffer_sprite;
  int		width;
  int		height;
}		t_my_framebuffer;

t_my_framebuffer	my_framebuffer_create(int, int);

void			my_put_pixel(t_my_framebuffer *, int, int, sfColor);

void			my_framebuffer_flip(t_my_framebuffer *,
					    sfRenderWindow *window);

#endif
