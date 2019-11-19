/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:06:05 by lhenneca          #+#    #+#             */
/*   Updated: 2019/04/29 16:07:03 by lhenneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n - 1 && (s1[i] != '\0' && s2[i] != '\0') && (s1[i] == s2[i]))
		i++;
	if (n > 0)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (0);
}
