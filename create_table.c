/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:49:23 by zszeredi          #+#    #+#             */
/*   Updated: 2019/11/28 14:00:25 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

// Create_table. We derive the number of tetroes from storage.c, based on that we calculate the minimum size of the table and then we allocate the space for it. 
 
int ft_sqrt(int nb)
{
	int square;

	square = 1;
	ft_putchar('a');
	while (nb > 1 && square <= nb / 2)
	{
		if 	(square * square >= nb)
		{
			ft_putchar('y');
return(square);
		}
		square++;
	}

	ft_putchar('y');
	return (2);
}

int		min_table(int i)
{
	int size;

	size = ft_sqrt(i * 4);
		return (size);
}

t_table	*ft_allocate(t_tetra *s)
{
	int		i;
	int		size;
	t_table *tab;

	i = 0;
	size = min_table(s->total_tetroes);
	tab = (t_table *)malloc(sizeof(t_table));
	(*tab).square = ft_memalloc(size * sizeof(char *));
	while (i < size)
	{
		tab->square[i] = ft_memalloc((size * sizeof(char)));
		i++;
	}
	//printf("%s\n", tab->square[i]);
	return (tab);
}
