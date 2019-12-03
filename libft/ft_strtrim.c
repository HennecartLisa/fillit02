/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:59:28 by lhenneca          #+#    #+#             */
/*   Updated: 2019/04/29 21:42:31 by lhenneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	size_t	i;
	char	*cp;

	if (s)
	{
		start = 0;
		while (s[start] && (s[start] == '\t' || s[start] == ' ' ||
					s[start] == '\n'))
			start++;
		i = start;
		if (i > 0 && i == (size_t)ft_strlen(s))
			return (ft_strnew(1));
		i = ft_strlen(s);
		i--;
		while (i > 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i--;
		cp = ft_strsub(s, start, i - start + 1);
		return (cp);
	}
	return (NULL);
}
