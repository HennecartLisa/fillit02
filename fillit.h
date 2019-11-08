/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:42:59 by zszeredi          #+#    #+#             */
/*   Updated: 2019/11/08 18:28:13 by zszeredi         ###   ########.fr       */
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

int		ft_print(char tetra[4][5]);
/*
 * read_file.c
 */
int		read_file(const int fd);
int		ft_check_nl(char *str);//, int i);
int		ft_check_charachters(char *str);// int i);

/*
 * storage.c
 */
char**		storage(int nb_tetriminoes, int fd);
int		ft_create_double_array(int x, int y, char **array);
int		ft_free(char **pt, int nb);

/*
 *
 */
#endif
