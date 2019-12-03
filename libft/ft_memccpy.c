/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:32:05 by lhenneca          #+#    #+#             */
/*   Updated: 2019/04/29 12:40:04 by lhenneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	f;

	f = '\0';
	f = (unsigned char)c;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	i = 0;
	while (i < (int)n)
	{
		d[i] = s[i];
		if (s[i] == f)
			return ((void*)(dst + i + 1));
		i++;
	}
	return (NULL);
}
