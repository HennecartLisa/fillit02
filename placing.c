/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:48:13 by zszeredi          #+#    #+#             */
/*   Updated: 2019/12/01 16:32:40 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	delete_table(t_table *s2)
{
	ft_putstr("start of deletion");
	int i = 0;
	while (i < s2->nb_tetroes)
	{
		ft_strdel(&s2->square[i]);
		i++;
	}
	ft_strdel(s2->square);
	free(s2);
	s2 = NULL;
	ft_putstr(" deleted fine");

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
	ft_putstr("min_size of table is:");
	ft_putnbr(s2->nb_tetroes);
	ft_putchar('\n');
	ft_putchar('o');
	while (a < s2->nb_tetroes) 
	{
		ft_putchar('k');
		while(b < s2->nb_tetroes)
		{
			if (counter == 4)
			{
				ft_putstr("no need to go further already found all 4 chars");
				s->tab[i][j] = '\0';
				s2->square[a][b] = '\0';
				ft_print_tetros(s2);
			}
			ft_putstr("i\n");
			if (s[nb].tab[i][j] == 1)
			{
				ft_putstr("this one I am converting\n");
				s2->square[a][b] = c;
				counter++;
				ft_putnbr(counter);
				j++;
				b++;

				ft_putstr(" converted\n");
			}
			else
			{
				ft_putstr(" this one I am  not converting\n");
				j++;
				b++;
				ft_putstr(" instead I go to the next one\n");
			}

		}	
		if (b == s2->nb_tetroes)
		{
			ft_putstr(" what to do now?\n");
			if(s[nb].tab[i][j++] != 1 && s[nb].tab[i][j + 2] != 1)
			{

				ft_putstr(" there is no more 1, so i can just go to next line\n");
				i++;
				a++;
				j = 0;
				b = 0;

			}
			else
			{
				ft_putstr(" ok, I have no place I reallocate\n");
				delete_table(s2);
				ft_putstr("size is:");
				ft_putnbr(size);
				ft_allocate(s, ++size);
			}
		}
	}
	if (a == s2->nb_tetroes)
	{
		ft_putstr(" I am at the last line line, last position of my square\n");
		if(s[nb].tab[i++][j] != 1 && s[nb].tab[i][j++] != 1)
		{
			ft_putnbr(i);
			ft_putnbr(j);
			s[nb].tab[i][j] = '\0';
			s2->square[a][b] = '\0';
			ft_putstr("ok copied first tetro\n");
			ft_print_tetros(s2);
		}
		else
		{
			ft_putstr(" shit no place, need more space\n");
			delete_table(s2);
			ft_allocate(s, ++size);
		}
	}	
	return(s2->square);
}
