/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:49:23 by zszeredi          #+#    #+#             */
/*   Updated: 2019/11/26 19:07:19 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
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

	ft_putchar('k');
	size = ft_sqrt(i * 4);
		return (size);
}

t_table	*ft_allocate(t_tetra *s)
{
	int		i;
	int 	j;
	int		size;
	t_table *tab;

	ft_putstr("number of tetroes:");
	ft_putnbr(s->total_tetroes);
	ft_putchar('o');
	size = min_table(s->total_tetroes);
	ft_putchar('\n');
	ft_putnbr(size);
	i = 0;
	j = 0;
	ft_putstr("its working");
	tab = ft_memalloc(sizeof(t_table));
	//tab->square[i] = ft_memalloc(size * sizeof(char *));
	ft_putstr("still here");
	tab->square = ft_memalloc(size * sizeof(char *));
	ft_putstr("and still");
	while (tab->square[i] <= size)
	{
		tab->square[j] = ft_memalloc((size * sizeof(char)) + 8);
		i++;
	}
	printf("%c\n", tab->square[i][j]);
	ft_putstr("still");
	return (tab);
}
