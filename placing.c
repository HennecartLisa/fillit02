/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:48:13 by zszeredi          #+#    #+#             */
/*   Updated: 2019/12/12 16:05:59 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	place(t_table *s2, t_tetra *s, int nb) 
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	int  counter = 0;
	ft_putstr("starting\n");
	while (x + i < s2->table_size && i < 4)
	{
		while(y + j < s2->table_size && j < 4)
		{
			if (s[nb].tab[i][j] == 1)
			{
				ft_putstr("charachter!\n");

				if (s2->square[x + i][y + j] != '.')
				{	
					ft_putstr("already something here\n");
					return (0); 
				}	
				else
				{
					ft_putstr("place!\n");
					s2->square[x + i][y + j] = s->letter;
					counter++;
					j++;
			//		y++;
			}
			}
			else //if (s[nb].tab[i][j] == 0)
			{
				ft_putstr("no charachter\n");
				j++;
			//	y++;
			}
			if (counter == 4)
			{
				ft_putstr("starting\n");
				ft_print_table(s2);
				return (1);
			}
		}
		if (y + j == s2->table_size)
		{
			ft_putstr("last position in line\n");
			if(j == 4 || (s[nb].tab[i][j] != 1 && s[nb].tab[i][j++] != 1))
			{	
				ft_putstr("ok, jumping line\n");
				i++;
		//		x++;
				j = 0;
			//	y = 0;
			}
			else
			{
				ft_putstr("not enough space\n");
				return (-1);
			}
		}
	}
	if (x + i == s2->table_size)
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
			return (-1);
		}
	}	
	return(1);
}
