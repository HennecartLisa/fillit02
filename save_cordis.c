/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cordis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:54:42 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/25 13:38:01 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_c_var		declare(t_c_var *p)
{
	p->i = 0;
	p->counter = 0;
	return (*p);
}

t_tetra		cordi(t_tetra s, t_c_var *p)
{
	s.cordis[p->counter].x = p->j;
	s.cordis[p->counter].y = p->i;
	return (s);
}

void		save_cordis(t_tetra **s, int nb)
{
	t_c_var	*p;
	t_tetra	*xd;

	xd = *s;
	p = malloc(sizeof(t_c_var));
	p->m = 0;
	while (p->m < nb - 1)
	{
		*p = declare(p);
		while (p->i < 4)
		{
			p->j = 0;
			while (p->j < 4)
			{
				if (xd[p->m].tab[p->i][p->j] == 1)
				{
					xd[p->m] = cordi(xd[p->m], p);
					p->counter++;
				}
				p->j++;
			}
			p->i++;
		}
		p->m++;
	}
}
