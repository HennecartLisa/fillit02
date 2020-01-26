/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:45:35 by zszeredi          #+#    #+#             */
/*   Updated: 2020/01/26 15:19:20 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**tetri_del(t_table *s2, int letter)
{
	int a;
	int b;

	ft_putstr("hellooo");
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

int		ft_letter(t_table *s2, t_tetra *s, int nb, int letter, int add, int add2)//inserts
{
	int counter;
	int a;
	int b;
	int c;

	counter = 0;
	c = 0;
	ft_putstr("have u been here?");
	while (counter < 4)
	{
		a = s[nb].cordis[counter].x;
		b = s[nb].cordis[counter].y;
		if (s2->square[b + add2][a + add] == '.')
		{
			s2->square[b + add2][a + add] = letter;
			counter++;
		}
		else
			return (-1);
	}
	ft_print_table(s2);
	return (0);
}


int		ft_compare(t_table *s2, t_tetra *s, int nb,  int m) //checks if it would fit
{
	int counter;
	int a;
	int b;
	int add;
	int add2;
	char **tmp;
	int t;
	add = 0;
	counter = 0;
	add2 = 0;
	printf("m = %d\n", m);
	printf("nb = %d\n", nb);
	while (counter < 4)
	{
		a = s[nb].cordis[counter].x;
		if (b + add2 < s2->table_size)
		{
			if (a + add + m < s2->table_size)
			{
				b = s[nb].cordis[counter].y;
				if (b + add2 == s2->table_size)
					return (-1);
				if (a == 0 && b == 0 && s2->square[b][a] == '.' && s2->square[0][1] != '.' && s2->square[1][0] != '.')
				{
					add++;
					counter = 0;
				}
				if (s2->square[b + add2][a + add + m] == '.')
				{		
					if ( m == 0)	
						counter++;
					else
					{
						if (t == 1)
							counter++;
						else
						{
							add++;
							counter = 0;
							t = 1;
						}
					}
				}
				else
				{
					add++;
					counter = 0;
				}
			}
			else
			{
				add2++;
				counter = 0;
				a = s[nb].cordis[counter].x;
				add = 0;
			}
		}
		else
			return (-1);
	}
	if ((ft_letter(s2, s, nb, s->letter++, add + m, add2)) < 0)
	{	
			//s2->square = tetri_del(s2, --s->letter);
		//while (ft_compare(s2, s, --nb, ++m) < 1)
		return (-1);
		//			// go back to previous tetro 
	}
	if ( a + add + m == s2->table_size - 1 && b + add2 == s2->table_size - 1)
		{
			ft_putstr("arggh");
			if((place(s2, s, ++nb)) < 1)
				ft_compare(s2, s, nb - 2, m = 0);
		}
	if (++nb < s->total_tetroes)
	{	
		tmp = tempo(s2);
		return (place(s2, s, nb));
	}
	return (1);
}

int		ft_if_fits(t_table *s2, t_tetra tab)
{
	int counter;
	int	a;
	int	b;

	counter = 0;
	while (counter < 4)
	{
		a = tab.cordis[counter].x;
		b = tab.cordis[counter].y;
		if (a >= s2->table_size || b >= s2->table_size)
			return (-1);
		else
			counter++;
	}
	return (0);
}

int		place(t_table *s2, t_tetra *s, int nb) // for some reason does not go back to backtracking via the return in case of multiple tetros
{
	char **tmp;
	static int  m;

	if ((ft_if_fits(s2, s[nb])) < 0)
	{
		ft_putstr(":(");
		return (-1);
	}
	if (nb == 0)
	{
		if ((ft_letter(s2, s, nb, s->letter, 0, 0)) == 0)//letter might has to be incremented elswhere
			tmp = tempo(s2);
		return (1);
	}
	else// if we are not at the first one
	{
		while ((ft_compare(s2, s, nb, m)) < 0 && nb > 0)
		{	
			tetri_del(s2, --s->letter);
			nb--;
			ft_putstr("DECREMENTING\n");
			while((ft_compare(s2, s, nb, ++m)) < 1) 
			{
				 nb--;
				 m = 0;
			}

			//ft_compare(s2, s, --nb, ++m);	
			//	return (-1);
		}
		//try moving each if cannot, increase table size

		return (1);
		//if ((calc(s2, s, nb_tetros)) < 0)
		//	return (-1);	this a function to optimize/make it faster by checking if it will fit based on the dots and connections, it The connections part doesnt work.
	}
	return (1);
}
