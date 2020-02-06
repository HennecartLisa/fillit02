/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:45:35 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/06 12:26:47 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**tetri_del(t_table *s2, int letter)
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

int		ft_letter(t_table *s2, t_tetra *s, int nb, t_add *p)
{
	int counter;
	int a;
	int b;
	printf("nb = %d\n", nb);
	printf("m = %d\n", p->move);

	counter = 0;
	while (counter < 4)
	{
		a = s[nb].cordis[counter].x;
		b = s[nb].cordis[counter].y;
		if (s2->square[b + p->add2][a + p->add + p->move] == '.')
		{
			s2->square[b + p->add2][a + p->add + p->move] = s->letter;
			counter++;
		}
		else
			return (-1);
	}
	ft_print_table(s2);
	return (0);
}

int		ft_compare(t_table *s2, t_tetra *s, int nb, t_add  *p) //checks if it would fit
{

	int t = 0;
	ft_putstr("\nin compare\n");
	printf("move = %d\n", p->move);
	while (p->counter < 4)
	{
		if (p->b + p->add2 < s2->table_size)
		{
			p->a = s[nb].cordis[p->counter].x;
			if (p->a + p->add + p->move < s2->table_size)
			{
				p->b = s[nb].cordis[p->counter].y;
							if (p->a + p->add + p->move == s2->table_size - 1 && p->b + p->add2 == s2->table_size - 1)
				{
					return (0);
				}
				if (p->b + p->add2 == s2->table_size)
				{
					
					return (-1);
					//p->add++;
				//	p->counter = 0;
				}
				if (s2->square[p->b + p->add2][p->a + p->add + p->move] == '.')
				{
					if ( p->move == 0)
						p->counter++;
					else
					{
						if (t == 1)
							p->counter++;
						else
						{
							p->add++;
							p->counter = 0;
							t = 1;
						}
					}
				}
				else
				{
					p->add++;
					p->counter = 0;
				}
			}
			else
			{
				p->add2++;
				p->counter = 0;
				p->add = 0;
			}
		}
		else
			return (-1);
	}
	/*	if (p->a + p->add + p->move == s2->table_size - 1 && p->b + p->add2 == s2->table_size - 1)
		{
		if ((place(s2, s, ++nb)) < 1)
		ft_compare(s2, s, nb - 2, m = 0);
		}*/
	ft_putstr("done mic drop");
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

int		next(t_table *s2, t_tetra *s, int nb, t_add *p)
{
	char **tmp;

	ft_letter(s2, s, nb, p); //insert letter
	tmp = tempo(s2); // save in tmp
	p = reinitialize(p);
	p->move = 0; // null move factor
	if (++nb < s->total_tetroes) //if stil tetroes go on
		place(s2, s, nb);
	else
		return (1);
	return (0);
}

void	previous(t_table *s2, t_tetra *s, int nb, t_add *p)
{
		s2->square = tetri_del(s2, --s->letter);
		++p->move; // increment moving
		p = reinitialize(p);//null struct values
		ft_putstr("gkgkg");
		ft_compare(s2, s, --nb, p); //go back to previous and move it with one
}

int		place(t_table *s2, t_tetra *s, int nb) // for some reason does not go back to backtracking via the return in case of multiple tetros
{
	char		**tmp;
	t_add		*p;

	p = malloc(sizeof(t_add));
	p = initialize(p);
	if ((ft_if_fits(s2, s[nb])) < 0)
	{
		ft_putstr(":(");
		return (-1);
	}
	if (nb == 0)
	{
		if ((ft_letter(s2, s, nb, p)) == 0)
			tmp = tempo(s2);
		return (1);
	}
	else // if we are not at the first one
	{
		s->letter++;
		ft_putstr("placing call\n");	
		while  ((ft_compare(s2, s, nb, p) == 1))// it if does fit
		{
			if (next(s2, s, nb, p) == 1)
				return (1);
	}
		if (ft_compare(s2, s, nb, p) < 1) // if it doesn't fit
		{
			ft_putstr("no place, go back wit one\n");
			previous(s2, s, nb, p);
			next(s2, s, nb, p);
		}
		}
	//if ((calc(s2, s, nb_tetros)) < 0)
	//	return (-1);	this a function to optimize/make it faster by checking if it will fit based on the dots and connections, it The connections part doesnt work.
	return (1);
}
