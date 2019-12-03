/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 12:39:39 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/16 11:40:46 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*ptr;
	size_t			i;

	i = 0;
	ptr = (char *)b;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return ((void *)b);
}
