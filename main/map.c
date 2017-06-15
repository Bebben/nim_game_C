/*
** map.c for matchstick in /home/benoit.pingris/delivery/CPE_2016_matchstick
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Feb 14 10:17:34 2017 benoit pingris
** Last update Tue Feb 14 19:51:07 2017 benoit pingris
*/

#include <stdlib.h>
#include "my.h"

char	**put_sticks_on_map(char **tab, int nb)
{
  int	i;
  int	tmp_min;
  int	min;
  int	max;

  i = 1;
  tmp_min = my_strlen(tab[i]) / 2;
  max = tmp_min;
  min = tmp_min;
  while (i <= nb)
    {
      min = tmp_min;
      while (min <= max)
	{
	  tab[i][min] = '|';
	  min++;
	}
      tmp_min--;
      max++;
      i++;
    }
  return (tab);
}

char	*put_stars(int nb)
{
  char	*str;
  int	i;

  i = 0;
  str = malloc(sizeof(char) * (nb * 2 + 4));
  while (i != nb * 2 + 1)
    {
      str[i] = '*';
      i++;
    }
  str[i] = '\0';
  return (str);
}

char	**create_map(int nb)
{
  char	**tab;
  int	i;
  int	j;

  i = 0;
  if ((tab = malloc(sizeof(char *) * (nb + 3))) == NULL)
    return (NULL);
  tab[i++] = put_stars(nb);
  while (i <= nb)
    {
      if ((tab[i] = malloc(sizeof(char) * (nb * 2 + 2))) == NULL)
	return (NULL);
      j = 0;
      tab[i][j++] = '*';
      while (j < nb * 2 + 1)
	tab[i][j++] = ' ';
      tab[i][--j] = '*';
      tab[i][++j] = '\0';
      i++;
    }
  tab[i] = put_stars(nb);
  tab[++i] = NULL;
  tab = put_sticks_on_map(tab, nb);
  return (tab);
}
