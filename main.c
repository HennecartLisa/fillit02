/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:06:07 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/25 14:32:48 by zszeredi         ###   ########.fr       */
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
	t_tetra	*s;
	t_table *s2;

	s = NULL;
	if (*argv && argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd <= 0)
			return (ft_error(1));
		if ((s = read_file(fd)) == NULL)
			return (ft_error(2));
		else
		{
			s2 = ft_allocate(s, 0);
			return (0);
		}
	}
	return (0);
}
