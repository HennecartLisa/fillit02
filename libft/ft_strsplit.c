/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:13:59 by lhenneca          #+#    #+#             */
/*   Updated: 2019/11/08 12:47:18 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**res;
	int		w;

	if (s && ft_isascii(c))
	{
		res = malloc(ft_words_count(s, c) * sizeof(char *));
		w = 0;
		i = 0;
		if (res)
		{
			w = ft_create_double_str(s, res, c);
			if (w == 0)
			{
				free(res);
				return (NULL);
			}
			w = ft_fill_array(s, res, i, c);
			res[w] = NULL;
			return (res);
		}
	}
	return (NULL);
}
