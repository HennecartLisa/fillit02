/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:46:04 by lhenneca          #+#    #+#             */
/*   Updated: 2019/04/29 15:38:12 by lhenneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	if (to_find[i] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		k = i;
		while (str[i] != '\0' && to_find[j] != '\0' && str[i] == to_find[j])
		{
			j++;
			i++;
		}
		if (to_find[j] == '\0')
			return (char*)(&str[k]);
		i = k;
		i++;
	}
	return (NULL);
}
