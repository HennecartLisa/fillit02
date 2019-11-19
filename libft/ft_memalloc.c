/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:44:48 by lhenneca          #+#    #+#             */
/*   Updated: 2019/04/29 16:12:50 by lhenneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*r;

	r = (void *)malloc(size);
	if (!r)
		return (NULL);
	ft_bzero(r, size);
	return (r);
}
