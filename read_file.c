/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:07:03 by zszeredi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/02/25 14:32:55 by zszeredi         ###   ########.fr       */
=======
/*   Updated: 2020/02/22 18:42:38 by aben-azz         ###   ########.fr       */
>>>>>>> 013b98f415153171ca627e0bde26d963b20acdb3
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_s_last_line(char **str)
{
	int j;
	int i;

	i = 0;
	j = 19;
	if (str[i][j] == '\n')
		return (-1);
	return (1);
}

int		ft_m_last_line(char **str, int number_tetroes)
{
	int j;
	int i;

	j = 19;
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
	if (number_tetroes < 1 || number_tetroes > 26)
		return (-1);
	if (number_tetroes == 1)
		if (ft_s_last_line(str) < 0)
			return (-1);
	if (number_tetroes > 1 && number_tetroes <= 26)
		if ((ft_m_last_line(str, number_tetroes)) < 1)
			return (-1);
	return (1);
}

t_tetra	*let_it_go(char *str)
{
	ft_strdel(&str);
	return (NULL);
}

t_tetra	*read_file(const int fd)
{
	int		i;
	int		ret;
	int		number_tetroes;
	char	buf[BUFFER_SIZE + 1];
	char	**str;

	number_tetroes = 0;
	i = 0;
	str = ft_create_double_array(27, 21);
	if ((fd < 0 || fd >= OPEN_MAX) || read(fd, buf, 0) < 0)
		return (let_it_go(str[i]));
	while ((ret = read(fd, buf, BUFFER_SIZE)) && number_tetroes <= 26)
	{
		buf[ret] = '\0';
		str[i] = ft_strdup(buf);
		if ((check_charachters(str[i])) < 1)
			return (let_it_go(str[i]));
		number_tetroes++;
		i++;
	}
	if ((ft_nbt(number_tetroes, str)) < 1)
		return (let_it_go(str[i]));
	return (ft_store_teros(str, number_tetroes + 1));
}
