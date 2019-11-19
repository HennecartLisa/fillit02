/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:32:10 by lhenneca          #+#    #+#             */
/*   Updated: 2019/04/29 13:08:27 by lhenneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*res;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(src) + 1;
	res = malloc(size * sizeof(char));
	if (!res)
		return (NULL);
	res = ft_strcpy(res, src);
	return (res);
}
