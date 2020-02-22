/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baktracking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:35:22 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/22 15:40:21 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**tetri_del(t_table *s2, int letter)
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

void		delete_table(t_table *s2)
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

int			solver(t_table *s2, t_tetra *s)
{
	static int	nb;
	int			counter;
	static int	size;
	int			i;
	int			j;

	i = 0;
	counter = 0;
	ft_putstr("in solver, printing table:\n");
	printf("TOTAL TETROES = %d nb = %d\n", s->total_tetroes, nb);
	ft_print_table(s2);
	if (nb == s->total_tetroes)
	{
		ft_putstr("mic drop\n");
		return (1);
	}
	else//while (nb <=  s->total_tetroes)
	{
		while (i < s2->table_size)
		{
			j = 0;
			while (j < s2->table_size)
			{
				printf(" i = %d j = %d \n", i, j);
				if (ft_if_fits(s2, s[nb]) < 1)
				{
					ft_putstr("deleting table\n");
					nb = 0;
					delete_table(s2);
					ft_allocate(s, ++size);
					return (1);
				}
				if (ft_compare(s2, s[nb], i, j) == 1)
				{
					ft_letter(s2, s[nb], i, j);
					counter = 1;
					nb++;
					if ((solver(s2, s) == 1))
					{
						nb--;
						return (1);
					}
				}
				else
				{
					ft_putstr("moving in line\n");
					j++;
				}
			}
			i++;
		}
	}
	if (i == s2->table_size)
	{
		ft_putstr("deleting table\n");
		nb = 0;
		delete_table(s2);
		ft_allocate(s, ++size);
		return (1);
	}
	return (0);
}
