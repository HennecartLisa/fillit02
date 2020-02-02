/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:45:35 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/02 19:31:18 by zszeredi         ###   ########.fr       */
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

int		check(t_table *s2, t_tetra *s, int nb)
{
	int i;
	int j;
i:wq
	  nt counter;
	ft_putstr("here");
	i = s[nb].cordis[counter].x;
	while ( counter < 4)
	{
	while (++i < s2->table_size)
	{	
		j = s[nb].cordis[counter].y;
		while (++j < s2->table_size)
		{
			if(s2->square[i][j] == '.')
				counter++;
			else
				return(-1);
		}
	j = -1;
	}
}
	return (1);
}

int		ft_compare(t_table *s2, t_tetra *s, int nb, t_add  *p) //checks if it would fit
{

	int t = 0;
	ft_putstr("\nin compare\n");
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
//					p->add++;
//					p->counter = 0;
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

	printf("nb3 = %d\n", nb);
	ft_letter(s2, s, nb, p); //insert letter
	tmp = tempo(s2); // save in tmp
	p->move = 0; // null move factor
	p = reinitialize(p);
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
		p = reinitialize(p);//null struct valued
		printf("nb1 = %d\n", nb);
		ft_compare(s2, s, --nb, p); //go back to previous and move it with one
		printf("nb2 = %d\n", nb);
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
		if (ft_compare(s2, s, nb, p) < 1) // if it doesn't fit
		{
			ft_putstr("no place, go back wit one\n");
			previous(s2, s, nb, p);
			next(s2, s, nb, p);
		}
		if ((ft_compare(s2, s, nb, p) == 1))// it if does fit
		{
			ft_putstr("it does fit");
			if (next(s2, s, nb, p) == 1)
				return (1);
				ft_putstr("fits\n");
				ft_letter(s2, s, nb, p); //insert letter
				tmp = tempo(s2); // save in tmp
				p->move = 0; // null move factor
				p = reinitialize(p);
				if (++nb < s->total_tetroes) //if stil tetroes go on
				place(s2, s, nb);
				else
				return (1);
		}
	}
	//if ((calc(s2, s, nb_tetros)) < 0)
	//	return (-1);	this a function to optimize/make it faster by checking if it will fit based on the dots and connections, it The connections part doesnt work.
	return (1);
}

char **make_square_bigger(int size)//spozzi's solution.
{
	int i;
	int j;
	char **board;

	i = -1;
	while (++i < size)
	{
		j = -1;
		board = (char**)malloc(sizeof(char *) * size);
		while (++j < size)
			board[j] = (char*)malloc(sizeof(char) * size);
	}
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			board[i][j] = 0;
	}
	return (board);
}

int	spozzi_is_the_best(t_table *s2, t_tetra *s, int nb, t_add *p) // model for backtracking
{
	int i;
	int j;
	int old_nb;
	char **current;
	if (nb == s->total_tetroes)
		return (1);
	i = -1;
	while (++i < s2->table_size)
	{
		j = -1;
		while (++j < s2->table_size)
		{
			p->a = i;
			p->b = j;
			if (check(s2, s, nb) < 1)//ft_compare(s2, s, nb, p)) //just checks DOESnt moveE
			{
				return (-1);
			}
			else
			{
				current = s2->square;
				printf("\nPLACED: %d @ (%d,%d)\n", nb, i, j);
				ft_letter(s2, s, nb, p); // JUST PLACES IT!!!
				ft_print_table(s2);
				old_nb = nb;
				if (spozzi_is_the_best(s2, s, ++nb, p))
					return (1);
				s2->square = current;
				nb = old_nb;
			}
		}
		i = -1;
	}
	if (nb == 0)
	{
		s2->square = make_square_bigger(++s->total_tetroes);
		spozzi_is_the_best(s2, s, 0, p);
		// ft_allocate(s, ++size);
	}
	return (0);
}
