/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:32:56 by lhenneca          #+#    #+#             */
/*   Updated: 2019/11/05 18:59:22 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFFER_SIZE 21
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include "libft/libft.h"

/*
 * read_file.h
 */
int		read_file(const int fd);
int		ft_check_nl(char **str, int i);
int		ft_check_charachters(char **str, int i);

/*
 * storage.c
 */
int		sotrage(int nb_tetriminoes, int fd);
int		ft_create_double_array(int x, int y, char **array);
int		ft_free(char **pt, int nb);

/*
 *
 */
#endif
