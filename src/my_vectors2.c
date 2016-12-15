/*
** vectors.c for wireframe in /home/bassintag/delivery/CGP_2016/bswireframe
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Nov 14 18:38:01 2016 Antoine Stempfer
** Last update Tue Dec 13 13:33:54 2016 Antoine Stempfer
*/

#include <SFML/Graphics.h>

sfVector2i	my_vector2i_create(int x, int y)
{
  sfVector2i	result;

  result.x = x;
  result.y = y;
  return (result);
}
