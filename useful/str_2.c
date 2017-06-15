/*
** str_2.c for navy in /home/benoit.pingris/delivery/CPE_2016_matchstick
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Feb 14 10:54:41 2017 benoit pingris
** Last update Fri Feb 17 14:58:44 2017 benoit pingris
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char a)
{
  write(1, &a, 1);
}

void	my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= 0 && nb <= 9)
    my_putchar(nb + '0');
  if (nb > 9)
    {
      my_putnbr(nb / 10);
      my_putnbr(nb % 10);
    }
}

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (!(str[i] >= '0' && str[i] <= '9'))
	return (0);
      i++;
    }
  return (1);
}

void	my_show_wordtab_2(char **tab, int i)
{
  int	j;

  j = 0;
  while (tab[i][j])
    {
      if (tab[i][j] == '|')
	{
	  my_putstr(CYAN, 1);
	  my_putchar(tab[i][j]);
	  my_putstr(WHITE, 1);
	}
      else
	{
	  my_putstr(GREEN, 1);
	  my_putchar(tab[i][j]);
	  my_putstr(WHITE, 1);
	}
      j++;
    }
}
