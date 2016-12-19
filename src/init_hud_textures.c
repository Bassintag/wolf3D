/*
** init_hud_textures.c for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Sun Dec 18 16:55:01 2016 Antoine Stempfer
** Last update Mon Dec 19 11:56:35 2016 Antoine Stempfer
*/

#include "wolf.h"

int		init_hud_textures(t_map *map)
{
  t_texture	*tileset;

  if ((map->texture_hud_bg = my_load_texture(HUD_BG_PATH)) == NULL)
    return (STATUS_FAILURE);
  if ((tileset = my_load_texture(TILESET_HEAD_PATH)) == NULL)
    return (STATUS_FAILURE);
  if ((map->textures_head =
       my_slice_texture(tileset, TEXTURE_HEAD_W, TEXTURE_HEAD_H)) == NULL)
    return (STATUS_FAILURE);
  my_destroy_texture(tileset);
  if ((tileset = my_load_texture(TILESET_NUM_PATH)) == NULL)
    return (STATUS_FAILURE);
  if ((map->textures_num =
       my_slice_texture(tileset, TEXTURE_NUM_W, TEXTURE_NUM_H)) == NULL)
    return (STATUS_FAILURE);
  my_destroy_texture(tileset);
  if ((tileset = my_load_texture(TILESET_W_ICONS_PATH)) == NULL)
    return (STATUS_FAILURE);
  if ((map->textures_weapon_icons =
       my_slice_texture(tileset, TEXTURE_W_ICONS_W,
			TEXTURE_W_ICONS_H)) == NULL)
    return (STATUS_FAILURE);
  my_destroy_texture(tileset);
  return (STATUS_SUCCESS);
}
