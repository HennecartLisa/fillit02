/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:35:22 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/25 14:18:59 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**tetri_del(t_table *s2, int letter)
{
	int a;
	int b;

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
	return (s2->square);
}

t_table		*delete_table(t_table *s2)
{
	int i;

	i = 0;
	while (i < s2->table_size)
	{
		ft_strdel(&s2->square[i]);
		i++;
	}
	ft_strdel(s2->square);
	s2 = NULL;
	return (s2);
}

int			solver(t_table *s2, t_tetra *s)
{
	static int	nb;
	static int	size;
	int			i;
	int			j;

	i = 0;
	while (nb != s->total_tetroes && i < s2->table_size)
	{
		j = -1;
		while (++j < s2->table_size)
			if (ft_compare(s2, s[nb], i, j) == 1)
			{
				ft_letter(s2, s[nb], i, j) && nb++;
				if ((solver(s2, s) == 1) && nb--)
					return (1);
				tetri_del(s2, s[nb].letter);
			}
		i++;
	}
	nb == 0 ? ft_allocate(s, ++size) && delete_table(s2) : 0;
	if (nb == s->total_tetroes || nb == 0)
		return (1);
	if (i == s2->table_size)
		nb--;
	return (i == s2->table_size ? -1 : 0);
}
