/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:49:23 by zszeredi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/02/25 14:28:50 by zszeredi         ###   ########.fr       */
=======
/*   Updated: 2020/02/22 19:12:50 by aben-azz         ###   ########.fr       */
>>>>>>> 013b98f415153171ca627e0bde26d963b20acdb3
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	dot(char *s, int i)
{
	while (i > 0)
	{
		i--;
		s[i] = '.';
	}
}

int		ft_sqrt(int nb)
{
	int square;

	square = 1;
	while (nb > 1 && square <= nb / 2)
	{
		if (square * square >= nb)
			return (square);
		square++;
	}
	return (2);
}



int		min_table(int i)
{
	int size;

	size = ft_sqrt(i * 4);
	return (size);
}

t_table	*ltg(char *str)
{
	ft_strdel(&str);
	return (NULL);
}

t_table	*ft_allocate(t_tetra *s, int size)
{
	int		i;
	t_table *s2;

	i = -1;
<<<<<<< HEAD
	if (!(s2 = (t_table *)malloc(sizeof(t_table))))
=======
	if (!(table = (t_table *)malloc(sizeof(t_table))))
>>>>>>> 013b98f415153171ca627e0bde26d963b20acdb3
	{
		free(s2);
		s2 = NULL;
	}
<<<<<<< HEAD
	s2->table_size = min_table(s->total_tetroes + size);
	if (!(s2->square = ft_memalloc(s2->table_size * sizeof(char *))))
		return (ltg(*(*s2).square));
	while (++i < s2->table_size)
=======
	table->table_size = min_table(s->total_tetroes + size);
	if (!(table->square = ft_memalloc(table->table_size * sizeof(char *))))
		return (ltg(*(*table).square));
	while (++i < table->table_size)
>>>>>>> 013b98f415153171ca627e0bde26d963b20acdb3
	{
		if (!(s2->square[i] = ft_memalloc(s2->table_size * sizeof(char))))
			return (ltg(*(s2->square)));
		else
		{
			dot(s2->square[i], s2->table_size);
			dot(*s2->square, s2->table_size);
		}
	}
<<<<<<< HEAD
	if (solver(s2, s) == 1)
		return (ft_print_table(s2));
=======
	if (solver(table, s) == 1)
		return (ft_print_table(table));
>>>>>>> 013b98f415153171ca627e0bde26d963b20acdb3
	return (NULL);
}
