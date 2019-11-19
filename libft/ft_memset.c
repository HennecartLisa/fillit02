/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:56:50 by lhenneca          #+#    #+#             */
/*   Updated: 2019/04/29 12:16:08 by lhenneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*str;
	size_t				i;

	i = 0;
	str = b;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	b = (void *)str;
	return (b);
}
