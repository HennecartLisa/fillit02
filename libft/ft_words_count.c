/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordscount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:26:31 by lhenneca          #+#    #+#             */
/*   Updated: 2019/04/29 20:50:40 by lhenneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_words_count(const char *str, char c)
{
	int		i;
	int		w;

	w = 0;
	i = 0;
	while (str && str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == c))
			i++;
		if (str[i] != '\0')
			w++;
		while (str[i] != '\0' && !(str[i] == c))
			i++;
	}
	w++;
	return (w);
}
