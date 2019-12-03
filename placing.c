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
	while (i < s2->nb_tetroes)
	{
		ft_strdel(&s2->square[i]);
		i++;
	}
	ft_strdel(s2->square);
	free(s2);
	s2 = NULL;

}

char	**place(t_table *s2, t_tetra *s, int nb)
{
	int i = 0;
	int j = 0;
	int a = 0;
	int b = 0;
	int  counter = 0;
	int c = 65;
	static int size = 0;
	while (a < s2->nb_tetroes)
	{
		while(b < s2->nb_tetroes)
		{
			if (s[nb].tab[i][j] == 1)
			{
				s2->square[a][b] = c;
				counter++;
				j++;
				b++;
			}
			else //if (s[nb].tab[i][j] == 0)
			{
				j++;
				b++;
			}
			if (counter == 4)
			{
				s->tab[i][j] = '\0';
				s2->square[a][b] = '\0';
				ft_print_tetros(s2);
			}
		}
		if (b == s2->nb_tetroes)
		{
			if(s[nb].tab[i][j] != 1 && s[nb].tab[i][j++] != 1)
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
			}
		}
	}
	if (a == s2->nb_tetroes)
	{
		i++;
		if(s[nb].tab[i][j] != 1 && s[nb].tab[i][j++] != 1 && s[nb].tab[i][j + 3] != 1)
		{

			s[nb].tab[i][j] = '\0';
			s2->square[a][b] = '\0';
			ft_print_tetros(s2);
		}
		else
		{	
			delete_table(s2);
			ft_allocate(s, ++size);
		}
	}	
	return(s2->square);
}
