/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:26:33 by lhenneca          #+#    #+#             */
/*   Updated: 2019/04/30 10:31:16 by lhenneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	res = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1 * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ((ft_strlen(s1) + ft_strlen(s2))))
	{
		if (i < ft_strlen(s1))
			res[i] = s1[i];
		else
		{
			res[i] = s2[j];
			j++;
		}
		i++;
	}
	res[i] = '\0';
	return (res);
}
