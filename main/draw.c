/*
** draw.c for matchstick in /home/benoit.pingris/save/bonus_matchstick/main
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Feb 17 20:10:55 2017 benoit pingris
** Last update Fri Feb 17 20:15:44 2017 benoit pingris
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my.h"

void	draw_map(char **tab)
{
  int	b;
  int	lines;

  lines = 0;
  b = 0;
  while (tab[lines] != NULL)
    lines++;
  while (tab[b] != NULL)
    {
      move((LINES - lines) / 2 + b, ((COLS - my_strlen(tab[0])) / 2));
      printw(tab[b]);
      b++;
    }
}
