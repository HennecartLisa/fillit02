/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baktracking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:35:22 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/06 19:30:41 by zszeredi         ###   ########.fr       */
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
char    **tetri_del(t_table *s2, int letter)
{
	int a;
	int b;

	ft_putstr("in tetri_del");
	a = 0;
	b = 0;
	while (b < s2->table_size)
	{
		a = 0;
		while (a < s2->table_size)
		{
			if (s2->square[b][a] == letter)
				s2->square[b][a] = '.';
			else
				a++;
		}
		b++;
	}
	ft_putstr("table now is\n");
	ft_print_table(s2);
	return (s2->square);
}

void	delete_table(t_table *s2)
{
	int i;

	ft_putstr("in delete table");
	i = 0;
	while (i < s2->table_size)
	{
		ft_strdel(&s2->square[i]);
		i++;
	}
	ft_strdel(s2->square);
	s2 = NULL;
}

int		solver(t_table *s2, t_tetra *s, int nb)
{
	static int			nb;
	int 		counter;
	static int	size;

	counter = 0;
	ft_putstr("printing table:\n");
	printf("nb = %d\n", nb);
	ft_print_table(s2);

	if (nb == s->total_tetroes)
		return (1);
	if (counter == 1 && nb == 0) 
	{
		ft_putstr("deleting here\n");
		delete_table(s2);
		return (0);
	}
	else
	{  
		if((ft_if_fits(s2, s[nb], s2->move[nb])) < 0)//check if within table
		{
			delete_table(s2);
			ft_allocate(s, ++size);
			return (0);
		}
		else if((ft_compare(s2, s[nb], s2->move[nb]) < 1))//check if table is dot
		{
			counter = 1;
			ft_putstr("going to next\n");
			nb++;
			solver(s2, s);
		}
		else
		{
			(s2->move[nb]) += 1;
			solver(s2, &s[nb]);
		}
		/*else //cannot move anymore
		  {
		  s2->move[nb] = 0;
		  s2->move[--nb] += 1;
		  tetri_del(s2, s->letter);
		  solver(s2, &s[nb]); //go back to previous and try moving it
		  }*/
	}
	return (1);
}
