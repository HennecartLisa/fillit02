#include "fillit.h"

void        ft_print_table(t_table *t)
{
	int    m;
	int    j;

	m = 0;
	ft_putchar('\n');
	while (m < t->table_size)
	{
		j = 0;
		while (j < t->table_size)
		{
			ft_putchar(t->square[m][j]);
			j++;
		}
		ft_putchar('\n');
		m++;
	}
	ft_putchar('\n');
}

void        ft_print_tetros(t_tetra *t)
{
	int m;
	int i;
	int j;

	ft_putchar('\n');
	m = 0;
	while (m < t->total_tetroes)
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				ft_putnbr(t[m].tab[i][j]);
				j++;
			}
			ft_putchar('\n');
			i++;
		}
		ft_putchar('\n');
		m++;
	}
}

void  ft_print_tmp(char **str, t_table *s2)
{
	int i = 0;
	int j = 0;
	while (i < s2->table_size)
	{
		j = 0;
		while ( j < s2->table_size)
		{
			ft_putchar(str[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}
