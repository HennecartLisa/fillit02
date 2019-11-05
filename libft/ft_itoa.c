/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:24:38 by lhenneca          #+#    #+#             */
/*   Updated: 2019/04/29 21:41:41 by lhenneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_neg(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static int	ft_tmp(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				size;
	int				neg;
	unsigned int	tmp;

	size = ft_numlen(n);
	neg = ft_neg(n);
	i = 1;
	if (!((str = (char *)malloc(sizeof(char) * ft_numlen(n) + 1))))
		return (NULL);
	tmp = ft_tmp(n);
	if (tmp == 0)
		str[tmp] = '0';
	while (tmp >= 1)
	{
		str[size - i] = (tmp % 10) + '0';
		tmp /= 10;
		i++;
	}
	if (neg)
		*str = '-';
	str[size] = '\0';
	return (str);
}
