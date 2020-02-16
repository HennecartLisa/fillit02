/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baktracking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:35:22 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/16 18:44:55 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char    **tetri_del(t_table *s2, int letter)
{
	int a;
	int b;

	ft_putstr("in tetri_del");
	a = 0;
	b = 0;
	while (b < s2->table_size)
	{
		a = 0;
		while (a < s2->table_size)
		{
			if (s2->square[b][a] == letter)
				s2->square[b][a] = '.';
			else
				a++;
		}
		b++;
	}
	ft_putstr("table now is\n");
	ft_print_table(s2);
	return (s2->square);
}

void	delete_table(t_table *s2)
{
	int i;

	ft_putstr("in delete table");
	i = 0;
	while (i < s2->table_size)
	{
		ft_strdel(&s2->square[i]);
		i++;
	}
	ft_strdel(s2->square);
	s2 = NULL;
}

int		solver(t_table *s2, t_tetra *s)
{
	static  int	nb;
	int 		counter;
	static int	size;
	int i = 0;
	int j;
	counter = 0;
	ft_putstr("in solver, printing table:\n");
	printf("TOTAL TETROES = %d nb = %d\n", s->total_tetroes, nb);
	ft_print_table(s2);
	if (nb == s->total_tetroes)
	{
		ft_putstr("mic drop\n");
		return (1);
	}
	else//while (nb <=  s->total_tetroes)
	{
		if (counter == 1 && nb == 0) 
		{
			ft_putstr("deleting here\n");
			nb = 0;
			delete_table(s2);
			return (0);
		}
		while (i < s2->table_size)
		{
			j = 0;
			while (j < s2->table_size)
			{
				printf(" i = %d j = %d \n", i ,j);
				if (ft_if_fits(s2, s[nb]) < 1)
				{
					ft_putstr("deleting table\n");
					nb = 0;
					delete_table(s2);
					ft_allocate(s, ++size);

				}
				if (ft_compare(s2, s[nb], i , j) == 1)
				{
					ft_letter(s2, s[nb], i, j);
					nb++;
					solver(s2, s);
				}
				else
				{
					ft_putstr("moving in line\n");
					j++;
				}
			}
			i++;
		}
	}
	if (i == s2->table_size)
	{	ft_putstr("deleting table\n");
		nb = 0;
		delete_table(s2);
		ft_allocate(s, ++size);
	}
	return (0);
}



/*	else
	{  
	printf("m = %u\n", s2->move[nb]);
	if ((ft_if_fits(s2, s[nb], s2->move[nb])) < 0)//check if within table
	{
	ft_putstr("deleting table\n");
	nb = 0;
	delete_table(s2);
	ft_allocate(s, ++size);
	counter++;
	}
	else if((ft_compare(s2, s[nb], s2->move[nb]) == 1))//check if table is dot
	{
	counter = 1;
	ft_putstr("going to next\n");
	nb++;
	solver(s2, s);
	}
	else
	{
	ft_putstr("moving");
	(s2->move[nb]) += 1;
	solver(s2, s);
	}
	else //cannot move anymore
	{
	s2->move[nb] = 0;
	s2->move[--nb] += 1;
	tetri_del(s2, s->letter);
	solver(s2, &s[nb]); //go back to previous and try moving it
	}
	}*/

