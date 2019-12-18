#include "fillit.h"
#include <stdio.h>

int		save_number(int j)
{
	int n;

	n = j;
	ft_putstr("moving with: ");
	ft_putnbr(n);
	ft_putchar('\n');
	return (n);
}

char    **temporary(char **table)
{
	char **tmp;

	tmp = (char **)malloc(sizeof(table));
	tmp = table;

	return (tmp);
}
char	**clear_tetro(char **square, int l, int i , int j)
{

	while (i >= 0 && j >= 0)
	{
		if (square[i][j] == l)
			square[i][j] = '.';
		j--;
	}
	i--;
	return(square);
}
t_tetra *move_tab(t_tetra *s, int nb, int n) // not working
{
	int i = 0;
	int j = 0;
	ft_putstr("moving table!");
	while(s[nb].tab[i][j] != '\0')
	{	
		if (s[nb].tab[i][j] == 0)
			j++;
		if (s[nb].tab[i][j] == 1)
		{
			if(s[nb].tab[i][j + n] != '\0')
			{
				s[nb].tab[i][j + n] = s[nb].tab[i][j];
				s[nb].tab[i][j + n] = 0;
				j++;
			}
			else
				return (0);			
		}	
	}
	i++;
	//	s[nb].tab[i][j] = '\0';
	ft_print_tetros(s);
	ft_putstr("moved tab");
	return (&s[nb]);
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
		if(y < s2->table_size && j < 4)
		{
			if (s[nb].tab[i][j] == 1)
			{
				while (s2->square[x][y] != '.' )
				{    
					ft_putstr("already something here\n");//to work out
					y++;
					//move++; 
					if (y)
						n = save_number(y);
				//n = 0;
				}
				ft_putstr("place by:!\n");	
				if (nb < 1 ||(s2->square[x][y] == '.' && s2->square[x][y - 1] != '.' && s2->square[x][y - 1] != '\0'))

				{
					ft_putstr("not moving");
						if((chara_find(s2, x, y, l, counter)) == 1)
						{    
							counter++;
							j++;
					//	y++;
						}
						else
							return (-1);
				}
				else
				{	
					//	//ft_print_tetros(s);
						//s[nb] = *move_tab(s, nb, n);
						//	s2->square = clear_tetro(s2->square, l, i ,j);
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
						//	y++;
						}
						else
							return (-1);
					}
				y++;
				/*	if(s->tab[i][j  - 1] == 1)
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
					}*/
			}
				else //if (s[nb].tab[i][j] == 0)
			{
				y++;
				ft_putstr("can go forward");
				j++;

			}
				if (counter == 4)
			{
				ft_putstr("4 chars!\n");
				tmp = temporary(s2->square);
				ft_print_table(s2);
				return (1);
			}
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
	return(1);
}
