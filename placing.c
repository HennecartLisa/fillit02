/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:48:13 by zszeredi          #+#    #+#             */
/*   Updated: 2019/12/12 15:34:14 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	delete_table(t_table *s2)
{
	int i = 0;
	while (i < s2->table_size)
	{
		ft_strdel(&s2->square[i]);
		i++;
	}
	ft_strdel(s2->square);
	free(s2);
	s2 = NULL;

}

int	place(t_table *s2, t_tetra *s, int nb) 
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	int  counter = 0;
	ft_putstr("starting\n");
	while (x < s2->table_size)
	{
		while(y < s2->table_size)
		{
			if (s[nb].tab[i][j] == 1)
			{
				ft_putstr("charachter!\n");

				if (s2->square[x][y] != '.')
				{	
					ft_putstr("already something here\n");
					return (0); 
				}	
				else
				{
					ft_putstr("place!\n");
					s2->square[x][y] = s->letter;
					counter++;
					j++;
					y++;
			}
			}
			else //if (s[nb].tab[i][j] == 0)
			{
				ft_putstr("no charachter\n");
				j++;
				y++;
			}
			if (counter == 4)
			{
				ft_putstr("starting\n");
				ft_print_table(s2);
				return (1);
			}
		}
		if (y == s2->table_size)
		{
			ft_putstr("last position in line\n");
			if(j == 4 || (s[nb].tab[i][j] != 1 && s[nb].tab[i][j++] != 1))
			{	
				ft_putstr("ok, jumping line\n");
				i++;
				x++;
				j = 0;
				y = 0;
			}
			else
			{
				ft_putstr("not enough space\n");
//delete_table(s2);
				//ft_allocate(s, ++size);
				return (-1);
			}
		}
	}
	if (x == s2->table_size)
	{
		ft_putstr("last line\n");
i++;
		if(s[nb].tab[i][j] != 1 && s[nb].tab[i][j++] != 1 && s[nb].tab[i][j + 3] != 1)
		{
			ft_putstr("no more chars\n");

			ft_print_table(s2);
            return (1);
		}
		else
		{	
			ft_putstr("not enough place\n");

			//delete_table(s2);
			//ft_allocate(s, ++size);
			return (-1);
		}
	}	
	return(1);
}
