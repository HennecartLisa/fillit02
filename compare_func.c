/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_add_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:26:01 by zszeredi          #+#    #+#             */
/*   Updated: 2020/01/26 19:29:27 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_add    *new_line(t_add *p)
{
	p->add2++;
	p->add = 0;
	return(p);
}

t_add *restart(t_add *p)
{
	p->add++;
	p->counter = 0;
	return (p);
}

t_add *initialize(t_add *p)
{
	p->add = 0;
	p->add2 = 0;
	p-> counter = 0;
	return (p);
}
void    last_move( t_add *p, int m)
{
	int t;

	t = 0;
	if ( m == 0)
		p->counter++;
	else
		t  == 1 ? p->counter++ : restart(p) && t == 1;
}
