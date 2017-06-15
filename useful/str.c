/*
** str.c for matchstick in /home/benoit.pingris/delivery/CPE_2016_matchstick/useful
** 
41;324;0c** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Feb 14 09:58:35 2017 benoit pingris
** Last update Fri Feb 17 20:16:26 2017 benoit pingris
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int		my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void		my_putstr(char *str, int canal)
{
  write(canal, str, my_strlen(str));
}

void		my_show_wordtab(char **tab)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (tab[i])
    {
      my_show_wordtab_2(tab, i);
      my_putchar('\n');
      i++;
      j++;
    }
}

int		my_getnbr(char *str)
{
  int	nb;
  int	i;
  int	sign;

  nb = 0;
  i = 0;
  sign = 1;
  if (str == NULL || my_str_isnum(str) == 0 || str[0] == '\0')
    return (-1);
  while ((str[i] < '0') || (str[i] > '9'))
    {
      if (str[i] == '-')
	sign = sign * (-1);
      i++;
    }
  while ((str[i] >= '0') && (str[i] <= '9'))
    {
      nb = nb * 10 + (str[i] - 48);
      i++;
    }
  nb = nb * sign;
  return (nb);
}
