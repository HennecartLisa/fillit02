/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 21:27:38 by lhenneca          #+#    #+#             */
/*   Updated: 2019/04/30 12:10:59 by lhenneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_fill_array(const char *str, char **res, int i, char c)
{
	int		l;
	int		w;

	w = 0;
	l = 0;
	while (str && res && str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == c))
		{
			i++;
			l = 0;
		}
		if (str[i] == '\0')
			return (w);
		while (str[i] != '\0' && !(str[i] == c))
		{
			res[w][l] = str[i];
			i++;
			l++;
		}
		if (l > 0)
			res[w][l] = '\0';
		w++;
	}
	return (w);
}
