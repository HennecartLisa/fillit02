/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:42:59 by zszeredi          #+#    #+#             */
/*   Updated: 2019/11/22 17:20:39 by zszeredi         ###   ########.fr       */
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
 ** Global structures
 */

typedef	struct	s_tetra
{
	int	tab[4][4];
	int total_tetros;
}				t_tetra;

int				ft_print(char tetra[4][5]);
/*
 * read_file.c
 */
t_tetra			*read_file(const int fd);
int				ft_nbt(int number_tetroes, char **str);
int				ft_m_last_line(char **str, int number_tetroes);
int				ft_s_last_line(char **str);
int				check_charachters(char *str);
int				ft_check_nl(char *str);
t_tetra			*let_it_go(char *str);
int				ft_check_for_charachter(char *str, int x);
int				ft_charachter(char *str, int j, int n, char c);
int				ft_check_connections(char *str);

/*
 * storage.c
 */
char			**ft_create_double_array(int x, int y);
t_tetra			*ft_store_teros(char **tetros, int nb);
void			ft_print_tetros(t_tetra *t);

/*
 *
 */
#endif
