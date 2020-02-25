/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:45:35 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/22 19:12:18 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_letter(t_table *s2, t_tetra s, int i, int j)
{
	int counter;
	int a;
	int b;

	counter = 0;
	while (counter < 4)
	{
		a = s.cordis[counter].x;
		b = s.cordis[counter].y;
		s2->square[b + i][a + j] = s.letter;
		counter++;
	}
	return (1);
}

int		ft_compare(t_table *s2, t_tetra s, int i, int j)
{
	int a;
	int b;
	int counter;

	counter = 0;
	while (counter < 4)
	{
		a = s.cordis[counter].x;
		b = s.cordis[counter].y;
		if (b + i >= s2->table_size || a + j >= s2->table_size)
			return (-1);
		if (s2->square[b + i][a + j] == '.')
			counter++;
		else
			return (-1);
	}
	return (1);
}
