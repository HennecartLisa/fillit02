/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:48:13 by zszeredi          #+#    #+#             */
/*   Updated: 2019/11/26 16:17:55 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_sqrt(int nb)
{
	int square;

	square = 1;
	while (nb > 1 && square <= nb / 2)
	{
		if 	(square * square >= nb)
		{
			return(square);
		}
		square++;
	}
	return (2);
}

int		min_table(t_table number_tetroes)
{
	int size;

	size = ft_sqrt(number_tetroes * 4)
		return (size);

}

t_table	**ft_allocate()
{
	int		i;
	int		size;
	t_table **tab;

	size = min_table(t_table number_tetroes);
	i = 0;

	t_table = ft_memalloc(size * sizeof(int *));
	while (i <= size)
	{
		tab[i] = ft_memmalloc(size * sizeof(int));
		i++;
	}
	return (tab);
}
