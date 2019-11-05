/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:21:26 by zszeredi          #+#    #+#             */
/*   Updated: 2019/11/05 13:38:36 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fillit_read(const int fd)
{
	int ret;
	char buf[22];

	if ((fd < 0 || fd >= OPEN_MAX) || read(fd, buf, 0) < 0)
		return (-1);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		file_checker();
	}
	return (1);
}

