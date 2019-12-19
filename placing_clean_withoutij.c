#include "fillit.h"
#include <stdio.h>

int		save_number(int j)
{
	int n;
	n = j;
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
/*t_tetra *move_tab(t_tetra *s, int nb, int n) // not working
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
}*/
int    chara_find(t_table *s2, int x, int y, int l, int counter)
{
	if (counter == 3)
	{
		s2->square[x][y] = l;
		return (1);
	}
	if((s2->square[x][y + 1] != l || s2->square[x + 1][y] != l) || (s2->square[x][y + 1] != '\0' || s2->square[x + 1][y] != '\0'))
	{        
		s2->square[x][y] = l;
		return (1);
	}
	else    
		return (-1);
	return (1);
}
int    place(t_table *s2, t_tetra *s, int nb)//,int l) 
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
//	static    int n;
	//    int move = 0;
	int  counter = 0;
//	char **tmp;

	while (x < s2->table_size && i < 4 && counter < 4)
	{
		while(y < s2->table_size && j < 4)
		{
			if (s[nb].tab[i][j] == 1)
			{
				if (s2->square[x][y] != '.' )
				{    
					y++;
				//	if (y)
				//		n = save_number(y);
				}
				if (s2->square[x][y] == '.')
				{
					/*if (n)
					{	
						//	s[nb] = *move_tab(s, nb, n);
						//	s2->square = clear_tetro(s2->square, l, i ,j);
						//	place(s2, s, nb, l);
						//	counter++;
						//	j++;
						//n++;*
						if((chara_find(s2, x, n, l, counter)) == 1)
						{    
							counter++;
							j++;
							y++;
						}
						else
							return (-1);
					}*/
					//else
				//	{
				//if((chara_find(s2, x, y, l, counter)) == 1)
				//		{    
						//	counter++;
							j++;
							y++;
				//	}g
				//		else
				//			return (-1);
				//	}
				}
			}
			else //if (s[nb].tab[i][j] == 0)
			{
				y++;
				j++;
			}
		/*	if (counter == 4)
			{
				tmp = temporary(s2->square);
				ft_print_table(s2);
				return (1);
			}*/
}
		if (j == 4 || y == s2->table_size)
		{
			if(j == 4 || (s[nb].tab[i][j] != 1 && s[nb].tab[i][j++] != 1))
			{    
				x++;
				i++;
				j = 0;
				y = 0;
			}
			else
				return (-1);
		}
	}
	if (x == s2->table_size)
	{
		i++;
		if(s[nb].tab[i][j] != 1 && s[nb].tab[i][j++] != 1 && s[nb].tab[i][j + 2] != 1 && s[nb].tab[i][j + 3] != 1)
		{
		//	tmp = temporary(s2->square);
			ft_print_table(s2);
			return (1);
		}
		else
			return (-1);
	}    
	return(1);
}
