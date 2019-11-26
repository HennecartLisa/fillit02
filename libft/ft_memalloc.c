/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 13:23:03 by zszeredi          #+#    #+#             */
/*   Updated: 2019/06/16 12:27:08 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *s;

	if (!(s = malloc(sizeof(*s) * (size))))
		return (NULL);
	ft_memset(s, 0, size);
	return (s);
}
