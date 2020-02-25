/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:09:02 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/25 14:32:50 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			move_up(t_tetra *tetra)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (tetra->tab[0][i] == 1)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i != 3)
				tetra->tab[i][j] = tetra->tab[i + 1][j];
			else
				tetra->tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

int			move_left(t_tetra *tetra)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (tetra->tab[i][0] == 1)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (j != 3)
				tetra->tab[i][j] = tetra->tab[i][j + 1];
			else
				tetra->tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

void		move_up_left(t_tetra **t, int nb)
{
	int		possible;
	t_tetra *tetros;

	tetros = *t;
	while (nb)
	{
		possible = 1;
		while (possible)
			possible = move_left(tetros) | move_up((tetros));
		tetros++;
		nb--;
	}
}

/*
 **  Take index and create a double char array set to NULL and return it
 */

char		**ft_create_double_array(int x, int y)
{
	char	**str_d;
	int		i;

	str_d = ft_memalloc((x * sizeof(char*)));
	i = 0;
	while (i < x)
	{
		str_d[i] = ft_memalloc(y * sizeof(char));
		i++;
	}
	return (str_d);
}
void		**ft_delete_double_array(void **str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_memdel(&str[i]);
		i++;
	}
	ft_memdel(str);
	str = NULL;

	return (str);
}

/*
 ** take a double char array full with tetrominos and the number of tetrominos
 ** and return a t_tetra structure array whit in each dimention
 **      tab[4][4] fot the tetro and the total number of tetros
 */

t_tetra		*ft_store_teros(char **tetros, int nb)
{
	t_tetra *res;
	int		i;
	int		j;
	int		m;
	int		n;

	if (!(res = malloc((nb) * sizeof(t_tetra))))
		return (NULL);
	i = -1;
	while (++i < nb - 1)
	{
		m = -1;
		j = 0;
		res[i].total_tetroes = nb - 1;
		res[i].letter = 'A' + i;
		while (++m < 4)
		{
			n = -1;
			while (++n < 4)
				res[i].tab[m][n] = tetros[i][j++] != '.';
			j++;
		}
	}
	move_up_left(&res, res[0].total_tetroes);
	save_cordis(&res, nb);
	ft_delete_double_array((void **)tetros);
	return (res);
}
