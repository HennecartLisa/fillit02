/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:48:13 by zszeredi          #+#    #+#             */
/*   Updated: 2019/11/26 19:07:22 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	place(t_tetra *tetro)
{
	t_table *table;
	
	table->nb_tetroes = tetro->total_tetros;
	create_table(table->nb_tetroes);
	ft_putstr("number of tetroes is:");
	ft_putnbr(table->nb_tetroes);

	return(table->nb_tetroes);
	
}
