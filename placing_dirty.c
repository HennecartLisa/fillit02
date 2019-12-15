#include "fillit.h"
#include <stdio.h>

int        save_number(int j)
{
	int n;

	n = j;
	ft_putstr("number is: ");
	ft_putnbr(n);
	return (n);
}
int    chara_find(t_table *s2, int i, int j, int l, int counter)
{
	int x = 0;
	int y = 0;
	ft_putstr("\ntrying to insert\n");
	if (counter == 3)
		ft_putstr("inserted 1\n");
	s2->square[x + i][y + j] = l;
	return (1);
	if((s2->square[x + i][y + j + 1] != l || s2->square[x + i + 1][y + j] != l) || (s2->square[x + i][y +  j + 1] != '\0' || s2->square[x + i + 1][y + j] != '\0'))
	{        
		ft_putstr("inserted\n");
		s2->square[x + i][y + j] = l;
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
	//    int t;
	ft_putstr("starting\n");
	while (x + i < s2->table_size && i < 4 && counter < 4)
	{
		while(y + j < s2->table_size && j < 4)
		{
			if (s[nb].tab[i][j] == 1)
			{
				ft_putstr("charachter!\n");
				while (s2->square[x + i][y + j] != '.' )
				{    
					ft_putstr("already something here\n");//to work out
					j++;
					//move++; 
					if (j)
						n =    save_number(j);
				}
				if (s2->square[x + i][y + j] == '.')
				{
					ft_putstr("place!\n");
					ft_putnbr(n);
					if (n)
					{
						ft_putstr("moving");
						if((chara_find(s2, i, n, l, counter)) == 1)
						{    
							counter++;
							j++;
						}
						else
							return (-1);
					}

					else
					{
						ft_putstr("not moving");
						if((chara_find(s2, i, j, l, counter)) == 1)
						{    
							counter++;
							j++;
						}
						else
							return (-1);
					}
				}
			}
			else //if (s[nb].tab[i][j] == 0
			{
				ft_putstr("can go forward");
				if (!n)
				{
					j++;
					ft_putstr("increment i");
				}
				else
				{
					ft_putstr("there is n");
					ft_putnbr(n);        
					if (s2->square[x + i][y + j] != '.' && s2->square[x + i][y + j + 1] != '.') 
						n =1;
					ft_putnbr(n);
					chara_find(s2,i, n, l, counter);
					j++;
				}
			}
			if (counter == 4)
			{
				ft_putstr("4 chars!\n");
				tmp = (char **)malloc(sizeof(s2->square));
				tmp = s2->square;
				ft_print_table(s2);
				return (1);
			}
		}
		if (j == 4 || y + j == s2->table_size)
		{
			ft_putstr("last position in line\n");
			if(j == 4 || (s[nb].tab[i][j] != 1 && s[nb].tab[i][j++] != 1))
			{    
				ft_putstr("ok, jumping line\n");
				i++;
				j = 0;
			}
			else
			{
				ft_putstr("not enough space\n");
				return (-1);
			}
		}
	}
	if (x + i == s2->table_size)
	{
		ft_putstr("last line\n");
		i++;
		if(s[nb].tab[i][j] != 1 && s[nb].tab[i][j++] != 1 && s[nb].tab[i][j + 2] != 1 && s[nb].tab[i][j + 3] != 1)
		{
			ft_putstr("no more chars\n");
			tmp = (char **)malloc(sizeof(s2->square));
			tmp = s2->square;
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
