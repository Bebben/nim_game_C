/*
** free.c for matchstick in /home/benoit.pingris/delivery/CPE_2016_matchstick
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Feb 15 11:48:40 2017 benoit pingris
** Last update Wed Feb 15 11:51:00 2017 benoit pingris
*/

#include <stdlib.h>
#include "my.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    free(tab[i++]);
  free(tab);
}

void	free_game(t_game info)
{
  free_tab(info.tab);
}
