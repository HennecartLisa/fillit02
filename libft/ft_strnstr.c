/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:46:04 by lhenneca          #+#    #+#             */
/*   Updated: 2019/04/29 21:42:17 by lhenneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		i;
	int			j;
	int			k;

	if (to_find[0] == '\0')
		return ((char*)(str));
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		k = i;
		while (i < len && str[i] != '\0' && to_find[j] != '\0' &&
				str[i] == to_find[j])
		{
			j++;
			i++;
		}
		if (to_find[j] == '\0')
			return (char *)(&str[k]);
		i = k;
		i++;
	}
	return (NULL);
}
