/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:49:23 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/22 19:12:50 by aben-azz         ###   ########.fr       */
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
	t_table *table;

	i = -1;
	if (!(table = (t_table *)malloc(sizeof(t_table))))
	{
		free(table);
		table = NULL;
	}
	table->table_size = min_table(s->total_tetroes + size);
	if (!(table->square = ft_memalloc(table->table_size * sizeof(char *))))
		return (ltg(*(*table).square));
	while (++i < table->table_size)
	{
		if (!(table->square[i] = ft_memalloc(table->table_size * sizeof(char))))
			return (ltg(*(table->square)));
		else
		{
			dot(table->square[i], table->table_size);
			dot(*table->square, table->table_size);
		}
	}
	if (solver(table, s) == 1)
		return (ft_print_table(table));
	return (NULL);
}
