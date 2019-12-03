/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:06:10 by lhenneca          #+#    #+#             */
/*   Updated: 2019/04/29 16:08:00 by lhenneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int j;
	int	res;
	int	isneg;

	j = 0;
	while (str[j] != '\0' && (str[j] == ' ' || str[j] == '\t' ||
	str[j] == '\r' || str[j] == '\n' || str[j] == '\v' || str[j] == '\f'))
		j++;
	i = j;
	res = 0;
	isneg = 0;
	if (str[i] == '-')
		isneg = 1;
	while (str && str[i] != '\0' && ((str[i] >= '0' && str[i] <= '9') ||
				(i == j && (str[i] == '-' || str[i] == '+'))))
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = (res * 10) + (str[i] - 48);
		++i;
	}
	if (isneg == 1)
		res = res * (-1);
	return (res);
}
