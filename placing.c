/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:48:13 by zszeredi          #+#    #+#             */
/*   Updated: 2019/11/28 19:31:03 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**place(t_table *s2, t_tetra *s, int nb)
{
	int i = 0;
	int j = 0;
	int a = 0;
	int	b = 0;
	int n = 0;
	char c = 65;
	int counter = 0;
	//	ft_putchar('\n');*/
	ft_putstr("what");
	while (s[n].tab[)
	{
	while (counter < nb && counter < nb)
	{
		while (b < 4)
		{
			ft_putstr(" ");
			if(s[n].tab[a][b] == 1)
				s2->square[i][j] = c;
			else
				s2->square[i][j] = '.';
			b++;
			j++;
			ft_putstr("going");
		}
		a++;
		i++;
		j = 0;
		b = 0;

		ft_putstr("on");
		if (a == 4 && s2->square != '\0')
		{
			n++;
			c++;
			place(s2, s, nb);
		}
	}
	}
	//	ft_memcpy(s2->square[i], s->tab[a],20);
	//ft_putnbr(nb);
	ft_print_tetros(s2);
	return(s2->square);

}
