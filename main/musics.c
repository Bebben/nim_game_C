/*
** musics.c for matchstick in /home/benoit.pingris/save/bonus_matchstick
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Feb 17 09:30:21 2017 benoit pingris
** Last update Fri Feb 17 09:40:50 2017 benoit pingris
*/

#include "my.h"

void	set_musics(t_music *musics)
{
  musics->hitmarker = sfMusic_createFromFile("sound/hitmarker.wav");
  musics->godno = sfMusic_createFromFile("sound/godno.wav");
}
