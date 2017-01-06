/*
** wolf_types.h for wolf3d in /home/bassintag/delivery/MUL_2016/wolf3d
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Mon Dec 19 12:40:07 2016 Antoine Stempfer
** Last update Fri Jan  6 10:26:51 2017 Antoine Stempfer
*/

#ifndef WOLF3D_TYPES_H_
# define WOLF3D_TYPES_H_

enum {
  screen_main_menu,
  screen_ingame,
  screen_pause,
  screen_credits,
  screen_count
};

enum {
  gui_texture_play,
  gui_texture_exit,
  gui_texture_credits,
  gui_texture_paused,
  gui_texture_bedel,
  gui_texture_count
};

enum {
  entity_object,
  entity_enemy
};

enum {
  weapon_def_knife,
  weapon_def_pistol,
  weapon_def_machine_gun,
  weapon_def_chain_gun,
  weapon_def_count
};

enum {
  sound_achtung,
  sound_all_right,
  sound_ammo,
  sound_boss_gun,
  sound_boss_speak1,
  sound_boss_speak2,
  sound_death_1,
  sound_death_2,
  sound_dog,
  sound_dog_death,
  sound_door,
  sound_enemy_pain,
  sound_gatling_gun,
  sound_guten_tag,
  sound_halt,
  sound_halt_2,
  sound_halten_sie,
  sound_health,
  sound_key,
  sound_knife,
  sound_machine_gun,
  sound_mechahitler_hoof,
  sound_menu_select,
  sound_menu_toggle,
  sound_metal_hoof,
  sound_oof,
  sound_pickup,
  sound_pistol,
  sound_player_death,
  sound_player_pain_1,
  sound_player_pain_2,
  sound_secret_entrance,
  sound_sheisse,
  sound_sheisse_koph,
  sound_switch,
  sound_thud,
  sound_yeeeah,
  sound_count
};

enum {
  enemy_dog,
  enemy_guard,
  enemy_def_count
};

enum {
  state_idle,
  state_chasing,
  state_shooting,
  state_searching,
  state_dying,
  state_dead,
  state_count
};

enum {
  object_demo,
  object_deathcam,
  object_puddle,
  object_barrel1,
  object_table1,
  object_lamp,
  object_chandelier,
  object_hanged,
  object_bowl,
  object_pillar,
  object_tree1,
  object_skeleton,
  object_sink,
  object_tree2,
  object_jar,
  object_table2,
  object_light,
  object_pans1,
  object_armor,
  object_cage,
  object_cage_full,
  object_skulls,
  object_key_yellow,
  object_key_blue,
  object_bed,
  object_pot,
  object_food,
  object_medikit,
  object_ammos,
  object_gun1,
  object_gun2,
  object_treasure1,
  object_treasure2,
  object_treasure3,
  object_treasure4,
  object_life,
  object_bloody_skulls,
  object_barrel2,
  object_well_full,
  object_well_empty,
  object_blood,
  object_flag,
  object_call_apogee,
  object_dust1,
  object_dust2,
  object_dust3,
  object_pans2,
  object_furnace,
  object_spears,
  object_vines,
  object_def_count
};

enum {
  k_close = sfKeyEscape,
  k_pause = sfKeyP,
  k_right = sfKeyRight,
  k_left = sfKeyLeft,
  k_strafe_right = sfKeyE,
  k_strafe_left = sfKeyA,
  k_forward = sfKeyUp,
  k_back = sfKeyDown,
  k_weapon_next = sfKeyF,
  k_weapon_shoot = sfKeyX,
  k_interact = sfKeyW,
  keybind_count
};

#endif /* WOLF_TYPES_H_ */
