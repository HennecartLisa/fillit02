/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:45:35 by zszeredi          #+#    #+#             */
/*   Updated: 2020/01/19 20:09:46 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	while (counter < 4)
	{
		a = s[nb].cordis[counter].x;
		b = s[nb].cordis[counter].y;
		s2->square[b + add2][a + add] = letter;
		counter++;
	}
	ft_print_table(s2);
	return (0);
}

int		ft_compare(t_table *s2, t_tetra *s, int nb) //checks if it would fit
{
	int counter;
	int a;
	int b;
	int add;
	int add2;

	add = 0;
	counter = 0;
	add2 = 0;
	while (counter < 4)
	{
		a = s[nb].cordis[counter].x;
		if (b == 0)
			b = s[nb].cordis[counter].y;
		if (a + add < s2->table_size)
		{
			b = s[nb].cordis[counter].y;
			if (b + add2 == s2->table_size)
				return (-1);
			if (a == 0 && b == 0 && s2->square[b][a] == '.' && s2->square[0][1] != '.' && s2->square[1][0] != '.')
				add++;
			if (s2->square[b + add2][a + add] == '.')
				counter++;
			else
				add++;
		}
		else
		{
			add2++;
			counter = 0;
			a = s[nb].cordis[counter].x;
			add = 0;
		}
	}
	if ((ft_letter(s2, s, nb, s->letter, add, add2)) == 0)
		return (0);
	return (0);
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

	if ((ft_if_fits(s2, s[nb])) < 0)
		return (-1);
	if (nb == 0)
	{
		if ((ft_letter(s2, s, nb, s->letter, 0, 0)) == 0)//letter might has to be incremented elswhere
			tmp = tempo(s2);
		return (1);
	}
	else// if we are not at the first one
	{
		if ((ft_compare(s2, s, nb)) < 0)
		{
			ft_putstr(":(");
			return (-1);
		}
		else
			return (1);
		//if ((calc(s2, s, nb_tetros)) < 0)
		//	return (-1);	this a function to optimize/make it faster by checking if it will fit based on the dots and connections, it The connections part doesnt work.
	}
	return (1);
}
