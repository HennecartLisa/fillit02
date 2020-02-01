/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 10:24:02 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/01 15:46:58 by zszeredi         ###   ########.fr       */
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

typedef	struct	s_c_var
{
	int i;
	int j;
	int m;
	int counter;
}				t_c_var;
typedef	struct	s_add // struct used in ft_compare to go through string. Needed to for saving lines.
{
	int a;
	int b;
	int add;
	int add2;
	int counter;
	int move;
}				t_add;

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

int				move_up(t_tetra *tetra);
int				move_left(t_tetra *tetra);
void			move_up_left(t_tetra **t, int nb);
char			**ft_create_double_array(int x, int y);
t_tetra			*ft_store_teros(char **tetros, int nb, int *connect);

/*
 * save_cordis.c
 */

t_c_var			declare(t_c_var *p);
t_tetra			cordi (t_tetra s, t_c_var *p);
void			save_cordis(t_tetra **s, int nb);

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

int				solver(t_table *s2, t_tetra *s);
//int        tetri_del(t_tetra *s, t_table *s2 ,int x ,int y);
void			delete_table (t_table *s2);

/*
 * placing.c
 */

char			**tempo(t_table *s2);
int				ft_letter(t_table *s2, t_tetra *s, int nb, t_add *p);
int				ft_compare(t_table *s2, t_tetra *s, int nb, int m);
int				ft_if_fits(t_table *s2, t_tetra tab);
int				place(t_table *s2, t_tetra *s, int nb);

/*
 * compare_func.c
*/

t_add			*new_line(t_add *p);
t_add			*restart(t_add *p);
t_add			*initialize(t_add *p);
int				within_table(t_table *s2, t_add *p);
void			last_move(t_add *p, int m);

/*
 * printing.c
 */

void			ft_print_table(t_table *t);
void			ft_print_tetros(t_tetra *t);
void			ft_print_tmp(char **str, t_table *s2);

#endif
