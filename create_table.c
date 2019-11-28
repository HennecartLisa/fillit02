/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:49:23 by zszeredi          #+#    #+#             */
/*   Updated: 2019/11/28 14:24:50 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

// Create_table. We derive the number of tetroes from storage.c, based on that we calculate the minimum size of the table and then we allocate the space for it.

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

t_table	*ft_allocate(t_tetra *s)
{
	int		i;
	t_table *tab;

	i = 0;
	if (!(tab = (t_table *)malloc(sizeof(t_table))))
	{
		free(tab);
		tab = NULL;
	}
	tab->nb_tetroes = min_table(s->total_tetroes);
	ft_putchar('\n');
	ft_putnbr(tab->nb_tetroes);
	if (!((*tab).square = ft_memalloc(tab->nb_tetroes * sizeof(char *))))
		return (ltg(*(*tab).square));
	while (i < tab->nb_tetroes)
	{
		if (!(tab->square[i] = ft_memalloc((tab->nb_tetroes * sizeof(char)))))
			return (ltg(*(tab->square)));
		i++;
	}
	//printf("%s\n", tab->square[i]);
	return (tab);
}
