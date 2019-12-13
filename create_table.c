/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:49:23 by zszeredi          #+#    #+#             */
/*   Updated: 2019/12/12 16:34:02 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

// Create_table. We derive the number of tetroes from storage.c, based on that we calculate the minimum size of the table and then we allocate the space for it.

void    dot(char *s, int i)
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
		{
			return (square);
		}
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
//	ft_print_tetros(s);
	t_table *table;
	i = 0;
	if (!(table = (t_table *)malloc(sizeof(t_table))))
	{
		free(table);
		table = NULL;
	}
	table->table_size = min_table(s->total_tetroes + size);
	ft_putstr("min size table is:");
	ft_putnbr(table->table_size);
	if (!((*table).square = ft_memalloc((table->table_size * sizeof(char *)))))
		return (ltg(*(*table).square));
	while (i <= table->table_size)
	{
		if (!(table->square[i] = ft_memalloc((table->table_size * sizeof(char)))))
			return (ltg(*(table->square)));
		else
		{
		    dot(table->square[i], table->table_size);
			dot(*table->square, table->table_size);
		}
			i++;
	}
//	ft_print_tetros(s);
//	ft_print_table(table);
	solver(table, s);
	//place(table, s, 0);
	return (table);
}
