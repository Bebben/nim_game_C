/*
** test.c for matchstick in /home/benoit.pingris
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Feb 13 19:07:39 2017 benoit pingris
** Last update Mon Feb 20 09:48:45 2017 benoit pingris
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int		disp_err(char *str)
{
  my_putstr(str, 2);
  return (ERROR);
}

int		disp_help()
{
  my_putstr("USAGE\n\t./matchstick [size] [sticks]\n\nDESCRIPTION\n\t", 1);
  my_putstr("size\tsize of the map\n\tsticks\tmaximum of sticks that can", 1);
  my_putstr(" be removed per turn\n", 1);
}

int		game_2(t_game *i, sfMusic *s, int turn)
{
  if (turn == 1)
    {
      turn = 2;
      if ((i->tab = player_round(i->tab, i->size, i->max, s)) == NULL)
	return (0);
      my_show_wordtab(i->tab);
      i->win = is_won(i->tab);
      if (i->win != 0)
	sleep(1);
    }
  else if (turn == 2)
    {
      turn  = 1;
      if ((i->tab = ai_round(i->tab, i->size, i->max, s)) == NULL)
	return (0);
      i->win = is_won(i->tab);
      my_show_wordtab(i->tab);
    }
  return (turn);
}

int		game(t_game info, int turn, t_music musics)
{
  while (info.win != 0)
    {
      system("clear");
      my_show_wordtab(info.tab);
      turn = game_2(&info, musics.hitmarker, turn);
      info.win = is_won(info.tab);
    }
  if (turn == 1)
    {
      sfMusic_play(musics.godno);
      my_putstr(RED2, 1);
      my_putstr("NO GOD PLEASE NO !!\n", 1);
      my_putstr(WHITE, 1);
      sleep(2);
    }
  else if (turn == 2)
    my_putstr("You lost, too bad...\n", 1);
  free_game(info);
  sfMusic_destroy(musics.godno);
  sfMusic_destroy(musics.hitmarker);
  endwin();
  return (turn);
}

int		main(int ac, char **av)
{
  t_music	musics;
  t_game	info;
  int		turn;

  turn = 1;
  if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
    return (disp_help());
  if (ac != 3)
    return (disp_err("Error: use -h to see how to play this game.\n"));
  if ((info.size = my_getnbr(av[1])) <= 0 || info.size > 10)
    return (disp_err("Error: the size must be between 1 and 10.\n"));
  info.max = my_getnbr(av[2]);
  if ((info.tab = create_map(info.size)) == NULL)
    return (ERROR);
  set_musics(&musics);
  info.win = is_won(info.tab);
  return (game(info, turn, musics));
}
