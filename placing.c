/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:45:35 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/08 13:50:13 by zszeredi         ###   ########.fr       */
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

int		ft_letter(t_table *s2, t_tetra s, int m, int j_l)
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
		s2->square[b + j_l][a + m] = s.letter;
		counter++;
	}

	ft_print_table(s2);
	return (1);
}

int		ft_compare(t_table *s2, t_tetra s, int m) 
{
	ft_putstr("\nin compare\n");
	int a;
	int b;
	int j_l;
	int counter = 0;

	j_l = 0;
	while (counter < 4)
	{
		a = s.cordis[counter].x;
		b = s.cordis[counter].y;			

		if(s2->square[b + j_l][a + m] == '.')
			counter++;
		else
		{
			if (a + m = s2->table_size)
			{
			j_l++;
			counter = 0;
			}
			else
			{
			ft_putstr("doesn't fit\n");
			return (-1);
		}
	}
	}
	return (ft_letter(s2, s, m, j_l));
}

int		ft_if_fits(t_table *s2, t_tetra s, int m)
{
	int counter;
	int	a;
	int	b;

	counter = 0;
	while (counter < 4)
	{
		a = s.cordis[counter].x;
		b = s.cordis[counter].y;
		if (a + m >= s2->table_size || b >= s2->table_size)
		{

			ft_putstr("runs out of table");
			return (-1);
		}
			else
			counter++;
	}
	ft_putstr("it fits\n");
	return (1);
}
