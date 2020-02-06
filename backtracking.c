/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baktracking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:35:22 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/06 12:13:49 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*int     verif(t_tetra *s, t_table *s2, int x, int y, int placeit)
  {
  int     i;
  int     j;

  i = 0;
  if (placeit == -1)
  return (0);
  while (x + i < s2->table_size && i < 4)
  {
  j = 0;
  while (y + j < s2->table_size && j < 4)
  {
  if (s->tab[i][j] == 1)
  {
  if (s2->square[x + i][y + j] == '.')
  placeit ? s2->square[x + i][y + j] = s->letter : 0;
  else
  return (-1);

  }
  j++;
  }
  i++;
  }
  return (1);
  }
  int		tetri_del(t_tetra *s, t_table *s2 ,int x ,int y)
  {
  int     i;
  int     j;

  i = 0;
  while (x + i < s2->table_size && i < 4)
  {
  j = 0;
  while (y + j < s2->table_size && j < 4)
  {
  if (s2->square[x + i][y + j] == s->letter)
  s2->square[x + i][y + j] = '.';
  j++;
  }
  i++;
  }
  return (1);
  }*/

void	delete_table(t_table *s2)
{
	int i;

	i = 0;
	while (i < s2->table_size)
	{
		ft_strdel(&s2->square[i]);
		i++;
	}
	ft_strdel(s2->square);
	free(s2);
	s2 = NULL;
}

int		solver(t_table *s2, t_tetra *s)
{
	int			nb;
	int			end;
	static int	size;

	nb = 0;
	ft_print_tetros(s);
	ft_print_table(s2);
	printf("nb of total tetroes = %d\n", s->total_tetroes);
	end = place(s2, s, nb);//, s->letter);
	ft_print_table(s2);
	ft_putstr("i am back to solver\n");
	nb++;
	{
		if (end == -1)//not enough space //verif(s, s2, x, y, 0)))
		{
			ft_putstr("end is -1\n");
			delete_table(s2);
			ft_allocate(s, ++size);
		}
		if (end == 0)//position already has char
		{
			ft_putstr("end is 0\n");
			return (-1);
		}
		if (end == 1)
		{
			ft_putstr("end is 1\n");
			if (nb < s->total_tetroes)//if I still have tetroes
			{
				ft_putstr("i have to go to next tetro\n");
				end = place(s2, s, nb);
			}
			else //for last line
			{
				ft_putstr("end of file, I am done");
				ft_print_table(s2);
				return (1);
			}
		}
	}
	return (1);
}
