/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 10:24:02 by zszeredi          #+#    #+#             */
/*   Updated: 2020/01/11 18:34:38 by zszeredi         ###   ########.fr       */
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

//TO DELETE !!!
#include <stdio.h>

/*
 ** Global structures
 */

typedef struct	s_coords
{
	short x;
	short y;
}				t_coords;

typedef	struct	s_tetra
{
	int			tab[4][4];
	int			total_tetroes;
	int			letter;
	int			connections;
	t_coords	cordis[4];
}				t_tetra;

typedef struct	s_table
{
	char		**square;
	int			table_size;
	int			left_connections;
}				t_table;

int				ft_print(char tetra[4][5]);
/*
 * read_file.c
 */
t_tetra			*read_file(const int fd, int *connect);
int				ft_nbt(int number_tetroes, char **str);
int				ft_m_last_line(char **str, int number_tetroes);
int				ft_s_last_line(char **str);
int				check_charachters(char *str, int *connect);
int				ft_check_nl(char *str);
t_tetra			*let_it_go(char *str);
int				ft_check_for_charachter(char *str, int x, int *connect);
int				ft_charachter(char *str, int j, int n, char c);
int				ft_check_connections(char *str, char c);

/*
 * storage.c
 */
char			**ft_create_double_array(int x, int y);
t_tetra			*ft_store_teros(char **tetros, int nb, int *connect);
void			save_cordis(t_tetra **s, int nb);
void			ft_print_table(t_table *t);
void			ft_print_tetros(t_tetra *t);

/*
 * create_table.c
 */
t_table			*ft_allocate(t_tetra *s, int size);
int				min_table(int i);
int				ft_sqrt(int nb);
t_table			*ltg(char *str);

/*
 * backtracking.c
 */
int solver(t_table *s2, t_tetra *s);
//int        tetri_del(t_tetra *s, t_table *s2 ,int x ,int y);
void		delete_table (t_table *s2);
//int verif (t_tetra *s, t_table *s2, int x, int y, int nb);
void main_insert(t_table *s2, t_tetra *s,  int size);
int main_if_possible(t_table *s2, t_tetra *s, int size);
/*
 * placing.c
 */
char 		**temporary(char **table);
char		**clear_tetro(char **table, int l, int i, int j);
int			chara_find(t_table *s2, int x,int y, int l, int counter);
int			total_chars(int counter);
void			last(int x, int y, int j, int l, int nb, t_table *s2, t_tetra *s);
int 		insert_tetro(int x, int i, int nb, int l, t_table *s2, t_tetra *s);
int			check_if_possible(t_table *s2, int x, t_tetra *s, int nb);
int		place(t_table *s2, t_tetra *s, int nb);//, int l);
void		delete_table (t_table *s2);


#endif
