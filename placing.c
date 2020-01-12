/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:45:35 by zszeredi          #+#    #+#             */
/*   Updated: 2020/01/12 20:48:09 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*int		ft_move_all(t_table *s2, t_tetra *s, int nb, int m)
  {

  }

  int		ft_move(t_table *s2, int a, int b)
  {
  int m;

  m = 0;
  while (s2->square[a][++b] != '.')
  m++;
  return (m);
  }

  int		ft_compare(t_table *s2, t_tetra *s, int nb)
  {
  int counter;
  int a;
  int b;
  int	m;

  a = 0;
  b = 0;
  counter = 0;
  while (counter <= 4)
  {
  while ((s2->square[a][b] != '\0') || (a < s2->table_size && y < s2->table_size))
  {
  if(s2->square[a][b] == 0)  
  {

  }
  */

int		remaining_dots(t_table *s2, int nb_tetros)
{
	int r_d;
	int	i;
	int j;

	r_d= 0;
	i = 0;
	j = 0;
	while (s2->square[i][j] != '\0')
	{
		while ( i < s2->table_size)
		{
			j = 0;
			while ( j < s2->table_size)
			{
				if (s2->square[i][j] == '.')
				{
					r_d++;
					j++;
				}
				else
					j++;
			}
			i++;	
		}
		break;
	}
	printf("r_d is %d\n", r_d);
	return(r_d - (nb_tetros * 4));
}

int		dots_needed(t_tetra *s, int nb_tetros)
{
	int d_n;

	d_n = (s->total_tetroes - nb_tetros) * 4;
	printf("d_n is %d\n", d_n);
	return(d_n);
}

int		remaining_connections(t_table *s2)
{
	int i;
	int j;
	int r_c;
	//	char c;

	i = 0;
	j = 0;
	r_c = 0;
	//	c = '.';
	ft_putnbr(0);
	while (s2->square[i][j] != '\0')
	{
		while (i < s2->table_size)
		{
			ft_putnbr(1);
			j = 0;
			while(j < s2->table_size)
			{
				ft_putnbr(2);
				printf("j = %d\n", j);
				if(s2->square[i][j] == '.')
				{	
					ft_putstr("found dot\n");
					if ((i > 0  && s2->square[i - 1][j] == '.') || s2->square[i + 1][j]== '.')	
					{
						ft_putstr("above and below");
						r_c++;
						printf("r_c beabove = %d\n", r_c);
					}
					ft_putstr("here");
					if (j > 0 && (s2->square[i][j - 1] == '.' || s2->square[i][j + 1] == '.'))					{
						ft_putstr("on the side\n");
						r_c++;
						printf("r_c on side = %d\n", r_c);
					}
					j++;
					ft_putstr("next");
				}
				else
					j++;
			}
			ft_putstr("new line\n");
			i++;
			ft_putnbr(7);
		}
		break;
		ft_putnbr(8);
	}
	printf("r_c is %d\n", r_c);
	return (r_c * 2);
}

int		all_connections (t_tetra *s)
{
	int a_c;
	int nb;
	nb = 0;
	a_c = 0;
	while(nb < s->total_tetroes)
	{
		a_c = s[nb].connections + a_c;
		nb++;
	}
	return (a_c);
}


int 	calc(t_table *s2, t_tetra *s, int nb_tetros)
{
	nb_tetros = 0;
	//	if (dots_needed(s, nb_tetros) > remaining_dots(s2, nb_tetros))
	//		return (-1);
	ft_putstr("\nhere\n");
	if (all_connections(s) > remaining_connections(s2))
		return (-1);

	ft_putstr("done");
	return (1);
}
int		ft_letter(t_table *s2, t_tetra *s, int nb, int letter)
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
		s2->square[b][a] = letter;
		counter++;
	}
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
	return (1);
}

int		place(t_table *s2, t_tetra *s, int nb)
{
	int i;
	int j;
	int counter;
	static int nb_tetros;
	counter = 3;
	i = 0;
	j = 0;
	if (nb == 0)
	{
		if ((ft_if_fits(s2, s[nb])) < 0)
			return (-1);
		else
		{
			if ((ft_letter(s2, s, nb, s->letter++)) == 0) // letter might has to be incremented elswhere
				nb_tetros++;
			return (1);
		}
	}
	else  	// if we are not at the first one
	{
		if ((calc(s2, s, nb_tetros)) < 0)
			return (-1);	

	}
	//compare if fits and see if it would fit with moving
	return (1);
}
