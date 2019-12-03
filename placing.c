/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:48:13 by zszeredi          #+#    #+#             */
/*   Updated: 2019/12/01 17:45:41 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	delete_table(t_table *s2)
{
	int i = 0;
	while (i < s2->table_size)
	{
		ft_strdel(&s2->square[i]);
		i++;
	}
	ft_strdel(s2->square);
	free(s2);
	s2 = NULL;

}

int	place(t_table *s2, t_tetra *s, int nb)
{
	int i = 0;
	int j = 0;
	int a = 0;
	int b = 0;
	int  counter = 0;
	static int size = 0;
	while (a < s2->table_size)
	{
		while(b < s2->table_size)
		{
			if (s[nb].tab[i][j] == 1)
			{
				s2->square[a][b] = 65 + nb;
				counter++;
				j++;
				b++;
			}
			else //if (s[nb].tab[i][j] == 0)
			{
                s2->square[a][b] = '.';
				j++;
				b++;
			}
			if (counter == 4)
			{
				ft_print_tetros(s2);
				return (1);
			}
		}
		if (b == s2->table_size)
		{
			if(j == 4 || (s[nb].tab[i][j] != 1 && s[nb].tab[i][j++] != 1))
			{
				i++;
				a++;
				j = 0;
				b = 0;
			}
			else
			{
				delete_table(s2);
				ft_allocate(s, ++size);
				return (0);
			}
		}
	}
	if (a == s2->table_size)
	{
		i++;
		if(s[nb].tab[i][j] != 1 && s[nb].tab[i][j++] != 1 && s[nb].tab[i][j + 3] != 1)
		{
			ft_print_tetros(s2);
            return (1);
		}
		else
		{	
			delete_table(s2);
			ft_allocate(s, ++size);
			return (0);
		}
	}	
	return(0);
}
