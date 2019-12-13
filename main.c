/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:06:07 by zszeredi          #+#    #+#             */
/*   Updated: 2019/12/13 10:05:52 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(int n)
{
	if (n == 1)
		write(1, "usage", 5);
	if (n == 2)
		write(1, "wrong file", 10);
	else
		write(1, "else", 4);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_tetra	*tetros;
	int		*connect;
	t_table *s;
	int size;

	connect = ft_memalloc(26 * sizeof(int));
	if (*argv && argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd <= 0)
		{
			ft_error(1);
			return (1);
		}
		if ((tetros = read_file(fd, connect)) == NULL)
		{
			ft_error(2);
			return (1);
		}
		else
        {
		    size = 0;
          	s = ft_allocate(tetros, size);
	 	/*	while (solver(s,tetros))
            {
                if (s)
                    delete_table(s);
                s = ft_allocate(tetros, size++);

            }*/
        }
	//	ft_print_tetros(tetros);
		//	tetrim = storage(4, fd);
		//	else
		//		ft_error(3);
	}
	return (0);
}
