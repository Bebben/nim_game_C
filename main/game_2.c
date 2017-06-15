/*
** game_2.c for matchstick in /home/benoit.pingris/delivery/CPE_2016_matchstick
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Feb 14 12:02:05 2017 benoit pingris
** Last update Wed Feb 15 11:52:51 2017 benoit pingris
*/

#include <time.h>
#include <stdlib.h>

int	get_random(int min, int max)
{
  static int random;

  if (random == 0)
    {
      srand(time(NULL));
      random = 1;
    }
  return (rand() % (max + min - 1) + min);
}

int	number_of_stick(char **tab, int line)
{
  int	j;
  int	nb;

  nb = 0;
  j = 0;
  while (tab[line][j] != '\0')
    {
      if (tab[line][j] == '|')
	nb++;
      j++;
    }
  return (nb);
}

int	is_won(char **tab)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i] != NULL)
    {
      j = 0;
      while (tab[i][j] != '\0')
	{
	  if (tab[i][j] == '|')
	    return (1);
	  j++;
	}
      i++;
    }
  return (0);
}

int	min(int nb1, int nb2)
{
  if (nb1 > nb2)
    return (nb2);
  else
    return (nb1);
}
