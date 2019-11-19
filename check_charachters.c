/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_charachters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:36:54 by zszeredi          #+#    #+#             */
/*   Updated: 2019/11/15 15:04:28 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//V. 7. Works with all checks and passes the norm..

int		ft_check_connections(char *str)
{
	int j;
	int connections;

	connections = 0;
	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == '#')
		{
			if (str[j + -1] == '#')
				connections++;
			if (str[j + -5] == '#')
				connections++;
		}
		j++;
	}
	str[j - 1] = '\0';
	if (connections < 3)
		return (-1);
	return (1);
}

int		ft_charachter(char *str, int j, int n, char c)
{
	if (str[j] == c)
		n++;
	return (n);
}

int		ft_check_for_charachter(char *str, int x)
{
	int j;
	int counter1;
	int counter2;
	int counter3;

	counter1 = 0;
	counter2 = 0;
	counter3 = 0;
	j = 0;
	while (str[j] != '\0')
	{
		counter1 = ft_charachter(str, j, counter1, '#');
		counter2 = ft_charachter(str, j, counter2, '.');
		counter3 = ft_charachter(str, j, counter3, '\n');
		j++;
	}
	str[j] = '\0';
	if (counter1 != 4 || counter2 != 12 || counter3 != x)
		return (-1);
	if ((ft_check_connections(str)) < 0)
		return (-1);
	return (1);
}

int		ft_check_nl(char *str)
{
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
		return (-1);
	return (1);
}

int		check_charachters(char *str)
{
    int len;

    len = ft_strlen(str);
	if (len < 20)
		return (-1);
	if ((ft_check_nl(str) < 0))
		return (-1);
	if (len == 20)
		if ((ft_check_for_charachter(str, 4)) < 0)
			return (-1);
	if (len == 21)
		if ((ft_check_for_charachter(str, 5)) < 0)
			return (-1);
	return (1);
}
