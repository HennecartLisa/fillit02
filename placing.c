/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:45:35 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/22 14:43:54 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**tempo(t_table *s2)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_create_double_array(s2->table_size + 1, s2->table_size + 1);
	while (i < s2->table_size)
	{
		tmp[i] = ft_strdup(s2->square[i]);
		i++;
	}
	//	ft_putstr("tmp:\n");
	//	ft_print_tmp(tmp, s2);
	return (tmp);
}

int		ft_letter(t_table *s2, t_tetra s, int i, int j)
{
	int counter;
	int a;
	int b;

	ft_putstr("in letter");
	counter = 0;
	while (counter < 4)
	{
		a = s.cordis[counter].x;
		b = s.cordis[counter].y;
		s2->square[b + i][a + j] = s.letter;
		counter++;
	}
	ft_print_table(s2);
	return (1);
}

int		ft_compare(t_table *s2, t_tetra s, int i, int j)
{
	int a;
	int b;
	int counter;

	counter = 0;
	ft_putstr("\nin compare\n");
	while (counter < 4)
	{
		a = s.cordis[counter].x;
		b = s.cordis[counter].y;
		if (b + i >= s2->table_size || a + j >= s2->table_size)
			return (-1);
		if (s2->square[b + i][a + j] == '.')
			counter++;
		else
		{
			ft_putstr("doesn't fit\n");
			return (-1);
		}
	}
	return (1);
}

int		ft_if_fits(t_table *s2, t_tetra s)
{
	int counter;
	int	a;
	int	b;

	counter = 0;
	while (counter < 4)
	{
		a = s.cordis[counter].x;
		b = s.cordis[counter].y;
		if (a >= s2->table_size || b >= s2->table_size)
		{
			ft_putstr("runs out of table");
			return (-1);
		}
		else
			counter++;
	}
	ft_putstr("it seems to fit\n");
	return (1);
}
