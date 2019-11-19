/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 13:22:39 by lhenneca          #+#    #+#             */
/*   Updated: 2019/04/29 16:18:55 by lhenneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*cp;

	if (!s || !f)
		return (NULL);
	cp = ft_memalloc((size_t)ft_strlen(s) + 1);
	i = 0;
	while (cp && s[i])
	{
		cp[i] = f(i, s[i]);
		i++;
	}
	return (cp);
}
