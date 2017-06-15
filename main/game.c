/*
** make_human_and_ai_play.c for diazndazi in /home/benoit.pingris/delivery/CPE_2016_matchstick_bootstrap
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Feb 13 14:09:17 2017 benoit pingris
** Last update Fri Feb 17 20:16:15 2017 benoit pingris
*/

#include <unistd.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"

char	**updated_board(int line, int number, char **tab, sfMusic *music)
{
  int	i;

  i = my_strlen(tab[line]);
  while (tab[line][i] != '|')
    i--;
  while (number != 0)
    {
      tab[line][i] = ' ';
      sfMusic_play(music);
      system("clear");
      my_show_wordtab(tab);
      usleep(100000);
      number--;
      i--;
    }
  system("clear");
  return (tab);
}

int	which_line(char **tab, int nb, int sticks)
{
  int	line;
  char	*str;

  my_putstr("Line: ", 1);
  if ((str = get_next_line(0)) == NULL)
    return (-2);
  if (str[0] == '\0')
    {
      my_putstr(RED, 1);
      my_putstr("Error: invalid output\n", 1);
      my_putstr(WHITE, 1);
      return (-1);
    }
  line = my_getnbr(str);
  if (line <= 0 || line > nb)
    {
      my_putstr(RED, 1);
      my_putstr("Error: this line is out of range\n", 1);
      my_putstr(WHITE, 1);
      return (-1);
    }
  else if (number_of_stick(tab, line) == 0)
    {
      my_putstr(RED, 1);
      my_putstr("Error: there is no matches on this line\n", 1);
      my_putstr(WHITE, 1);
      return (-1);
    }
  free(str);
  return (line);
}

int	which_number(char **tab, int nb, int sticks, int line)
{
  int	number;
  char	*str;

  my_putstr("Matches: ", 1);
  str = get_next_line(0);
  number = my_getnbr(str);
  if (number <= 0)
    {
      my_putstr(RED, 1);
      my_putstr("Error: you have to remove at least one match\n", 1);
      my_putstr(WHITE, 1);
      return (-1);
    }
  else if (number > sticks)
    {
      my_putstr(RED, 1);
      my_printf("Error: you cannot remove more than");
      my_printf(" %d matches per turn\n", sticks);
      my_putstr(WHITE, 1);
      return (-1);
    }
  else if (number > number_of_stick(tab, line))
    {
      my_putstr(RED, 1);
      my_putstr("Error: not enough matches on this line\n", 1);
      my_putstr(WHITE, 1);
      return (-1);
    }
  free(str);
  return (number);
}

char	**player_round(char **tab, int nb, int sticks, sfMusic *music)
{
  int	line;
  int	number;

  line = -1;
  number -1;
  my_putstr("\nYour turn:\n", 1);
  while (line == -1 || number == -1)
    {
      if ((line = which_line(tab, nb, sticks)) == -2)
	return (NULL);
      if (line != -1)
	if ((number = which_number(tab, nb, sticks, line)) == -2)
	  return (NULL);
    }
  return (updated_board(line, number, tab, music));
}

char	**ai_round(char **tab, int nb, int sticks, sfMusic *music)
{
  int	line;
  int	number;

  my_putstr("\nAI's turn...\n", 1);
  line = get_random(1, nb);
  while (number_of_stick(tab, line) == 0)
    line = get_random(1, nb);
  number = get_random(1, min(number_of_stick(tab, line), sticks));
  return (updated_board(line, number, tab, music));
}
