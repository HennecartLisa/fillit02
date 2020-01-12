/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:24:02 by zszeredi          #+#    #+#             */
/*   Updated: 2020/01/11 17:21:19 by zszeredi         ###   ########.fr       */
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

  counter = 0;
  while (counter <= 4)
  {
  a = s->cordis[counter++].y;
  b = s->cordis[counter++].x;
  if (s2->square[a][b] != '.')
  {
  m = ft_move(s2, a, b)
  if (m > 0)
  {
//try moving
//	ft_if_fits(s2, a + m, b + m);
ft_move_all(s2, s, nb, m);		
}
}
*/

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

int        ft_if_fits(t_table *s2, t_tetra tab)
{
	int counter;
	int	a;
	int	b;

	counter = 0;
	while(counter < 4)
	{
		a = tab.cordis[counter].x;
		b = tab.cordis[counter].y;
		if (a >= s2->table_size || b >= s2->table_size)
			return (-1);
		else
			counter++;
	}
	return(1);
}

int		place(t_table *s2, t_tetra *s, int nb)
{
	int i;
	int j;
	int counter;

	counter = 3;
	i = 0;
	j = 0;
	if ( nb == 0)
	{
		if ((ft_if_fits(s2, s[nb])) < 0)
			return (-1);
		else
		{
			if ((ft_letter(s2, s, nb, s->letter++)) == 0) // letter might has to be incremented elswhere
				return (1);
		}
	}
	/*	else // if we are not at the first one
		{
	//compare if fits and see if with moving it would still fit)
	ft_compare(s2, s, nb);

	while (y <  s2->table_size)
	{
	while ( x < s2->table_size)
	{
	ft_compare(t_table *s2, t_tetra *s, int nb);
	{
	if (s2->square[y][x] != '.' || s2->square[)
	x++;
	*/
	return (1);
}
