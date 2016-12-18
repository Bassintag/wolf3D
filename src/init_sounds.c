/*
** init_sounds.c for wold3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Dec 18 23:17:29 2016 Antoine Stempfer
** Last update Sun Dec 18 23:49:07 2016 Antoine Stempfer
*/

#include "my.h"
#include "wolf_sounds.h"

int	init_sounds(t_map *map)
{
  int	i;

  i = 0;
  while (i < sound_count)
    {
      my_printf("Loading sound: %s\n", g_sound_files[i]);
      map->sounds[i] = sfSoundBuffer_createFromFile(g_sound_files[i]);
      if (map->sounds[i] == NULL)
	return (STATUS_FAILURE);
      i++;
    }
  return (STATUS_SUCCESS);
}
