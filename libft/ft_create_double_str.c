/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_double_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:40:48 by lhenneca          #+#    #+#             */
/*   Updated: 2019/04/30 12:37:41 by lhenneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_alloc(int w, int l, char **res)
{
	res[w] = malloc(l * sizeof(char));
	if (!res[w])
	{
		while (w >= 0)
		{
			free(res[w]);
			w--;
		}
	}
	else
		w++;
	return (w);
}

int			ft_create_double_str(const char *str, char **res, char c)
{
	int		i;
	int		w;
	int		l;

	w = 0;
	i = 0;
	while (res && str && str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == c))
			i++;
		if (str[i] != '\0')
			l = 1;
		while (str[i] != '\0' && str[i] != c && l++)
			i++;
		if (l > 1)
			w = ft_alloc(w, l, res);
		if (w == -1)
			return (0);
		while (str[i] != '\0' && (str[i] == c))
			i++;
		l = 1;
	}
	return (1);
}
