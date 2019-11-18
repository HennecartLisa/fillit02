/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:07:03 by zszeredi          #+#    #+#             */
/*   Updated: 2019/11/15 15:04:40 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>//

//Version 8 all checks work (also checked with My's) and the norm/ To do: make it compatible with Lisa's storage.

int		ft_s_last_line(char **str)
{
	int j;
	int i;

	i = 0;
	j = 20;
	if (str[i][j] == '\n')
		return (-1);
	return (1);
}

int		ft_m_last_line(char **str, int number_tetroes)
{
	int j;
	int i;

	j = 20;
	i = 0;
	while ((str[i][j] != '\0') && (number_tetroes >= 1))
	{
		if (str[i][j] != '\n')
			return (-1);
		number_tetroes--;
		if (number_tetroes != 1)
			i++;
	}
	if (number_tetroes == 0)
	{
		if (str[i][j] == '\n')
			return (-1);
		str[i][j] = '\0';
	}
	return (1);
}

int		ft_nbt(int number_tetroes, char **str)
{
	ft_putnbr(number_tetroes);
	if (number_tetroes < 1 || number_tetroes > 26)
		return (-1);
	if (number_tetroes == 1)
		if (ft_s_last_line(str) < 0)
			return (-1);
	if (number_tetroes >= 1 && number_tetroes <= 26)
		if ((ft_m_last_line(str, number_tetroes)) < 0)
			return (-1);
	return (1);
}

char    **ft_create_double_array(int x, int y)
{
    char    **str_d;
    int     i;
    str_d = ft_memalloc((x * sizeof(char*)));
    i = 0;
    while (i < x)
    {
        str_d[i] = ft_memalloc(y * sizeof(char));
        i++;
    }
    return(str_d);
}

t_tetra *ft_store_teros(char **tetros, int nb)
{
    t_tetra *res;
    int     i;
    int     j;
    int     m;
    int     n;

    res = ft_memalloc(nb * sizeof(t_tetra));
    i = 0;
    while (i < nb - 1)
    {
        m = 0;
        j = 0;
        while (m < 4)
        {
            n = 0;
            while (n < 4)
            {
                if (tetros[i][j] == '.')
                    res[i].tab[m][n] = 0;
                else
                    res[i].tab[m][n] = 1;
                j++;
                n++;
            }
            j++;
            m++;
        }
        i++;
    }
    return (res);
}


t_tetra		*read_file(const int fd)
{
	int		i;
	int		ret;
	int		number_tetroes;
	char	buf[BUFFER_SIZE + 1];
	char	**str; // I changed the format of the function and the pointer so I could get back what you read

	number_tetroes = 0;
	i = 0;
	str = ft_create_double_array(26, 21);
	if ((fd < 0 || fd >= OPEN_MAX) || read(fd, buf, 0) < 0)
		return (NULL);
	while ((ret = read(fd, buf, BUFFER_SIZE)) && number_tetroes < 27)
	{
		buf[ret] = '\0';
		ft_strcpy(str[i], buf);
		if ((check_charachters(str[i])) < 0)
			return (NULL);
		number_tetroes++;
		i++;
	}
	ft_putnbr(number_tetroes);
	if ((ft_nbt(number_tetroes, str)) < 0)
		return (NULL);
	return (ft_store_teros(str, number_tetroes + 1));
}
