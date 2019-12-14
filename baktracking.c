/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baktracking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:35:22 by zszeredi          #+#    #+#             */
/*   Updated: 2019/12/14 16:44:48 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*int     verif(t_tetra *s, t_table *s2, int x, int y, int placeit)
{
	int     i;
	int     j;

	i = 0;
	if (placeit == -1)
		return (0);
	while (x + i < s2->table_size && i < 4)
	{
		j = 0;
		while (y + j < s2->table_size && j < 4)
		{
			if (s->tab[i][j] == 1)
			{
				if (s2->square[x + i][y + j] == '.')
					placeit ? s2->square[x + i][y + j] = s->letter : 0;
				else
					return (-1);

			}
			j++;
		}
		i++;
	}
	return (1);
}
int		tetri_del(t_tetra *s, t_table *s2 ,int x ,int y)
{
	int     i;
	int     j;

	i = 0;
	while (x + i < s2->table_size && i < 4)
	{
		j = 0;
		while (y + j < s2->table_size && j < 4)
		{
			if (s2->square[x + i][y + j] == s->letter)
				s2->square[x + i][y + j] = '.';
			j++;
		}
		i++;
	}
	return (1);
}*/
void	delete_table(t_table *s2)
{
	int i;
	i = 0;

	while (i < s2->table_size)
	{
		ft_strdel(&s2->square[i]);
		i++;
	}
	ft_strdel(s2->square);
	free(s2);
	s2 = NULL;
}
/*
 * char **map == t_table *s2
 * t_tetriminos *tetri == t_tetra *s
 */
//increment table ,what if table is too small needs end of the table
int		solver(t_table *s2, t_tetra *s)
{
	int  x;
	int  y;
	int nb;
	int end;
	//	int i = 0;
	//	int j = 0;
	static int size = 0;
	nb = 0;
	x = 0;
	//		ft_print_tetros(s);
	//	ft_print_table(s2);
	//if (!s) // condition for the end of the table
	//	return (0);
	//	while (x <= s2->table_size)
	//	{
	y = 0;
	//	while (y <= 4) // s2->table_size)
	//	{
	end = place(s2, s, nb, s->letter);
	ft_putnbr(end);
	ft_putstr("i am back to solver\n");	
	nb++;
	ft_putnbr(nb);
	{
		if (end  == -1)//not enough space //verif(s, s2, x, y, 0)))
		{	
			ft_putstr("end is -1\n");	
			delete_table(s2);
			ft_allocate(s, ++size);
		}
		if (end == 0)//position already has char
		{
			ft_putstr("end is 0\n");	
			return (-1);
		}
		if (end == 1)
		{
			ft_putstr("end is 1\n");	
			if (nb < s->total_tetroes)//if I still have tetroes
			{
				ft_putstr("i have to go to next tetro\n");	
				s->letter++;
				end = place(s2, s, nb, s->letter);
			}
			else //for last line
			{
				ft_putstr("end of file, I am done");
				s2->square[x][y] = '\0';
				return (1);
			}
		}
		//	if (place(s, s2, x, nb) == 0)
		//if 0, already something there move away 
		//	if (place(s, s2, x, nb) == 1)
		//go to next tetro
		//				if (solver(s2, s + 1))
		//					return (1);
		//	else
		//	tetri_del(s, s2, x, y);

		//	}
		//	y++;
		//	ft_print_tetros(s);
		//	ft_print_table(s2);	
}
//	}
//x++	
return (1);
}
