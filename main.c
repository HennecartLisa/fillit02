/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:06:07 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/22 18:45:19 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(int n)
{
	if (n == 1)
		write(1, "usage", 5);
	else
		ft_putstr("error\n");
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_tetra	*tetros;
	int		*connect;
	t_table *s;

	s = NULL;
	connect = ft_memalloc(26 * sizeof(int));
	if (*argv && argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd <= 0)
			return (ft_error(1));
		if ((tetros = read_file(fd, connect)) == NULL)
			return (ft_error(2));
		else
		{
			ft_allocate(tetros, 0);
			return (0);
		}
	}
	return (0);
}
