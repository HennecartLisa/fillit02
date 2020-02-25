/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:41:46 by zszeredi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/02/22 18:42:30 by aben-azz         ###   ########.fr       */
=======
/*   Updated: 2020/02/22 19:25:43 by zszeredi         ###   ########.fr       */
>>>>>>> 013b98f415153171ca627e0bde26d963b20acdb3
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_table	*ft_print_table(t_table *t)
{
	int		m;
	int		j;

	m = 0;
	while (t->square[m] && m < t->table_size)
	{
		j = 0;
		while (t->square[m][j] && j < t->table_size)
		{
			ft_putchar(t->square[m][j]);
			j++;
		}
		ft_putchar('\n');
		m++;
	}
	return (t);
}

void	ft_print_tetros(t_tetra *t)
{
	int m;
	int i;
	int j;

	ft_putchar('\n');
	m = 0;
	while (m < t->total_tetroes)
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				ft_putnbr(t[m].tab[i][j]);
				j++;
			}
			ft_putchar('\n');
			i++;
		}
		ft_putchar('\n');
		m++;
	}
}
