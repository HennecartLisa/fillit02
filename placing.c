/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:45:35 by zszeredi          #+#    #+#             */
/*   Updated: 2020/01/19 19:39:33 by zszeredi         ###   ########.fr       */
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
  }*/

char **tempo(t_table *s2)
{
	char **tmp;
	int i;

	i = 0;
	tmp = ft_create_double_array(s2->table_size + 1, s2->table_size + 1);
	while (i < s2->table_size)
	{
		tmp[i] = ft_strdup(s2->square[i]);
		i++;
	}
	return(tmp);
}

char	*let_tmp(char **str)
{
	int i;

	i = 0;
	free(&str[i]);
	//	while( str[i] != '\0')		
	//	{
	//		free(str[i]);
	//		i++;
	//	}
	//	free(str);
	return(NULL);
}
int		ft_letter(t_table *s2, t_tetra *s, int nb, int letter, int add, int add2)
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

int		ft_compare(t_table *s2, t_tetra *s, int nb)
{
	int counter;
	int a;
	int b;
	int add;
	int i;
	int j;
	int add2;
//	int  tmp[4][2];
	//	a = 0;
	//	b = 0;
	add = 0;
	counter = 0;
	i = 0;
	j = 0;
	add2 = 0;
	printf("nb  is  %d \n", nb);
	while (counter < 4)
	{

			a = s[nb].cordis[counter].x;
		if ( b == 0)			
			b = s[nb].cordis[counter].y;

		ft_putnbr(1);
		if ( b + add2  <= s2->table_size)
		{
			if( a  + add < s2->table_size)
			{
				
				b = s[nb].cordis[counter].y;
				printf("cordis[%d][%d]\n", s[nb].cordis[counter].y, s[nb].cordis[counter].x);
				printf("square[%d + %d][%d + %d]\n", b, add2, a, add);
				if (a == 0 && b == 0 && s2->square[b][a] == '.' && s2->square[0][1] != '.' && s2->square[1][0] != '.')
				{
					ft_putstr("standalone .");
					add++;
				}
			/*	if (s2->square[b + add2][a + add] != '.')
				{
					ft_putstr("no dot!");	
					add++;
					printf("%d\n", add + a);
				}*/
				if (s2->square[b + add2][a + add] == '.')
				{
					ft_putstr("dot");	
					//tmp[j][i] = b + add2;
					//printf("tmp[j = %d]",tmp[j][i]);
					//i++;
					//tmp[j][i] = a + add;
					//printf("[i =%d]\n",tmp[j][i]);
					counter++;
					printf("b = %d\n", a);
				}
				else
					add++;
				//	printf("\nadd = %d\n", add);
			}
			else
			{
				ft_putstr("jumping line");
				add2++;
				counter = 0;
		//		b = s[nb].cordis[counter].y;
				//printf("\nadd2 = %d\n", add2);
				a = s[nb].cordis[counter].x;
				add = 0;
			}
		}
		else
		{	
			ft_putstr("too much");
			return(-1);
		}
	}
	printf("add is  %d \n", add);
	printf("add2 is  %d \n", add2);
	if ((ft_letter(s2, s, nb, s->letter, add, add2)) == 0)
		return (1);
	ft_putnbr(4);
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

int		place(t_table *s2, t_tetra *s, int nb)
{
	int i;
	int j;
	int counter;
	static int nb_tetros;
	char **tmp;
	counter = 3;
	i = 0;
	j = 0;
	if (nb == 0)
	{
		if ((ft_if_fits(s2, s[nb])) < 0)
			return (-1);
		else
		{
			if ((ft_letter(s2, s, nb, s->letter, 0,  0)) == 0) // letter might has to be incremented elswhere
				nb_tetros++;
			tmp = tempo(s2);
			return (1);
		}
	}
	else  	// if we are not at the first one
	{
		ft_putstr("here");
		if ((ft_if_fits(s2, s[nb])) < 0)
			return (-1);
		
		else
			ft_putstr("didnt work");
		if ((ft_compare(s2, s, nb)) <  0)
			return (-1);
		//if ((calc(s2, s, nb_tetros)) < 0)
		//	return (-1);	this a function to optimize/make it faster by checking if it will fit based on the dots and connections, it The connections part doesnt work.

	}
	//compare if fits and see if it would fit with moving*/
	return (1);
}
