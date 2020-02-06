/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_add_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:26:01 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/06 13:30:07 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_add	*new_line(t_add *p)
{
	p->add2++;
	p->add = 0;
	p->counter = 0;
	return (p);
}

t_add	*restart(t_add *p)
{
	ft_putstr("in restart");
	printf("p->add = %d befoee\n", p->add);
	p->add++;
	printf("p->add = %d after\n", p->add);
	p->counter = 0;
	return (p);
}

t_add	*initialize(t_add *p)
{
	int		i;

	i = 0;
	p->add = 0;
	p->add2 = 0;
	p->counter = 0;
	while (i < 26)
	{
		p->move[i] = 0;
		i++;
	}
	return (p);
}

t_add	*reinitialize(t_add *p)
{
	p->add = 0;
	p->add2 = 0;
	p->counter = 0;
	return (p);
}

t_add	*within_table(t_add *p)
{
	ft_putstr("in within table\n");

		p->add++;
		p->counter = 0;
	return (p);
}

void	last_move(t_add *p)
{
	int t;
ft_putstr("in last move");
	t = 0;
	if (p->move[1] == 0)
		p->counter++;
	else
		t == 1 ? p->counter++ : restart(p) && t == 1;
}
