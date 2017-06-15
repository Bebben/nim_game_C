/*
** my.h for iazdji in /home/benoit.pingris/delivery/CPE_2016_matchstick_bootstrap
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Feb 13 13:04:57 2017 benoit pingris
** Last update Fri Feb 17 20:18:17 2017 benoit pingris
*/

#ifndef MY_H_
# define MY_H_

# include <SFML/Audio.h>

# define ERROR 84
# define BLUE "\033[1;34m"
# define RED "\033[1;31m"
# define RED2 "\033[31m"
# define WHITE "\033[0m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"

typedef struct	s_music
{
  sfMusic	*hitmarker;
  sfMusic	*godno;
}		t_music;

typedef struct	s_game
{
  char		**tab;
  int		size;
  int		max;
  int		win;
}		t_game;

void	draw_map(char **tab);
void	set_musics(t_music *musics);
void	my_putchar(char a);
void	my_show_wordtab(char **tab);
void	my_show_wordtab_2(char **tab, int i);
void	my_putstr(char *str, int canal);
void	free_game(t_game info);
void	free_tab(char **tab);

int	my_strlen(char *str);
int	my_getnbr(char *str);
int	is_won(char **tab);
int	my_str_isnum(char *str);
int	number_of_stick(char **tab, int line);
int	get_random(int min, int max);
int	min(int nb1, int nb2);

char	*my_strcpy(char *s1, char *s2);
char	*get_next_line(int fd);

char	**create_map(int nb);
char	**ai_round(char **tab, int nb, int stick, sfMusic *s);
char	**player_round(char **tab, int nb, int stick, sfMusic *s);

int	my_printf(char *s, ...);

#endif /* !MY_H_ */
