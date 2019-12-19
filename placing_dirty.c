#include "fillit.h"
#include <stdio.h>

char    **temporary(char **table)
{
	char **tmp;

	tmp = (char **)malloc(sizeof(table));
	tmp = table;

	return (tmp);
}

char	**clear_tetro(char **square, int l, int x , int y)
{

	while (x >= 0) 
	{
		while (y >= 0)
		{
			if (square[x][y] == l)
				square[x][y] = '.';
			y--;
		}
		x--;
	}
	return(square);
}

int    chara_find(t_table *s2, int x, int y, int l, int counter)
{

	ft_putstr("\ntrying to insert\n");
	if (counter == 3)
	{
		ft_putstr("inserted 1\n");
		s2->square[x][y] = l;
		return (1);
	}
	if((s2->square[x][y + 1] != l || s2->square[x + 1][y] != l) || (s2->square[x][y + 1] != '\0' || s2->square[x + 1][y] != '\0'))
	{        

		ft_putstr("inserted\n");
		s2->square[x][y] = l;
		return (1);
	}
	else    
		return (-1);
	return (1);
}

void    delete_table(t_table *s2)
{
	int i;
	i = 0;

	while (i < s2->table_size)
	{
		ft_strdel(&s2->square[i]);
		i++;
	}
	ft_strdel(s2->square);
	free(s2);
	s2 = NULL;
}
int		total_chars( int counter)
{
	if (counter == 4)
		return (1);
	return (0);
}
void	last(int x, int y, int j, int l, int nb, t_table *s2, t_tetra *s)
{
	int i;

	i = x;
	if ( x == 4)
		i++;
	if (j == 4 && y < s2->table_size)
	{	
		if(j == 4 || (s[nb].tab[i][j] != 1 && s[nb].tab[i][j++] != 1))
		{    
			ft_putstr("ok, jumping line\n");
		}
		else
		{
			ft_putstr("not enough space\n");
		}
	}
	insert_tetro(x++, i++, nb, l, s2, s);
}

int	insert_tetro(int x, int i, int nb, int l, t_table *s2, t_tetra *s)
{
	int j = 0;
	int y = 0;
	int counter = 0;
	ft_putstr("starting insert");
	while (x < s2->table_size && i < 4)
	{
		while (y < s2->table_size && j < 4)
		{
			while (s2->square[x][y] != '.' && s[nb].tab[i][j] == 1)
			{		
				if(s[nb].tab[i][j] == 1 && s2->square[x][y] == '.')
				{
					s2->square[x][y] = l;
					counter++;
					j++;
				}
				y++;
			}
			total_chars(counter);
		}
		ft_putstr("last chcrachter");
		last(x, y,j, l, nb, s2, s);
	}
	if ( x == 4)
	{
		ft_putstr("last line");
		last(4, y, j, l, nb, s2, s);
	}
	return (1);
}

int	check_if_possible(t_table *s2, int x, t_tetra *s, int nb)
{
	int y = 0;
	int i = 0;
	int j = 0;
	ft_putstr("is it possible?");
	while ( y < s2->table_size && j < 4)
	{
		if (s[nb].tab[i][j] == 1)
		{
			if (s2->square[x][y] == '.')

			{
				ft_putstr("ok");
				y++;
				j++;
			}
			else
				y++;
		}
		else
		{
			j++;
			ft_putstr("not a char");
			return (-1);
		}
	}
	return (1);
}

int    place(t_table *s2, t_tetra *s, int nb, int l) 
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	static    int n;
	//    int move = 0;
	int  counter = 0;
	char **tmp;
	ft_putstr("starting\n");
	while (x < s2->table_size && i < 4 && counter < 4)
	{
		while(y < s2->table_size && j < 4)
		{
			if (s[nb].tab[i][j] == 1)
			{
				while (s2->square[x][y] != '.' )
				{    
					ft_putstr("already something here\n");//to work out
					y++;
					n = y;
				}

				if (s2->square[x][y] == '.')
				{
					ft_putstr("place by:!\n");	
					if (n)
					{	
						//	//ft_print_tetros(s);
						//	*move_tab(s, nb, n);
						//	s2->square = clear_tetro(s2->square, l, x ,y);
						//	place(s2, s, nb, l);
						//	counter++;
						//	j++;
						//	ft_print_tetros(s);
						//n++;
						ft_putstr("moving");
						ft_putstr("n is:");
						ft_putnbr(n);
						if((chara_find(s2, x, n, l, counter)) == 1)
						{    
							counter++;
							j++;
							y++;
						}
						else
							return (-1);
					}
					else //if(s->tab[i][j  - 1] == 1)
					{
						ft_putstr("not moving");
						if((chara_find(s2, x, y, l, counter)) == 1)
						{    
							counter++;
							j++;
							y++;
						}
						else
							return (-1);
					}
				}
				else //if (s[nb].tab[i][j] == 0)
				{
					y++;
					ft_putstr("can go forward");
					j++;

				}
			}
			if (counter == 4)
			{
				ft_putstr("4 chars!\n");
				tmp = temporary(s2->square);
				ft_print_table(s2);
				return (1);
			}
			if (j == 4 || y == s2->table_size)
			{
				ft_putstr("last position in line\n");
				if(j == 4 || (s[nb].tab[i][j] != 1 && s[nb].tab[i][j++] != 1))
				{    
					ft_putstr("ok, jumping line\n");
					x++;
					i++;
					j = 0;
					y = 0;
				}
				else
				{
					ft_putstr("not enough space\n");
					return (-1);
				}
			}
		}
		if (x == s2->table_size)
		{
			ft_putstr("last line\n");
			i++;
			if(s[nb].tab[i][j] != 1 && s[nb].tab[i][j++] != 1 && s[nb].tab[i][j + 2] != 1 && s[nb].tab[i][j + 3] != 1)
			{
				ft_putstr("no more chars\n");
				tmp = temporary(s2->square);
				ft_print_table(s2);
				return (1);
			}
			else
			{    
				ft_putstr("not enough place\n");
				return (-1);
			}
		}    
	}

	return(1);
}
