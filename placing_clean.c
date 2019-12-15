#include "fillit.h"
#include <stdio.h>

int        save_number(int j)
{
	int n;
	n = j;
	return (n);
}
int    chara_find(t_table *s2, int i, int j, int l, int counter)
{
	int x = 0;
	int y = 0;
	if (counter == 3)
	{	
		s2->square[x + i][y + j] = l;
		return (1);
	}
	if((s2->square[x + i][y + j + 1] != l || s2->square[x + i + 1][y + j] != l) || (s2->square[x + i][y +  j + 1] != '\0' || s2->square[x + i + 1][y + j] != '\0'))
	{        
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
	int  counter = 0;
	char **tmp;
	while (x + i < s2->table_size && i < 4 && counter < 4)
	{
		while(y + j < s2->table_size && j < 4)
		{
			if (s[nb].tab[i][j] == 1)
			{
				while (s2->square[x + i][y + j] != '.' )
				{    
					j++;
					if (j)
						n =    save_number(j);
				}
				if (s2->square[x + i][y + j] == '.')
				{
					if (n)
					{
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
				if (!n)
					j++;
				else
				{
					//if (s2->square[x + i][y + j] != '.' && s2->square[x + i][y + j + 1] != '.') 
					//	n = 1;
					chara_find(s2,i, n, l, counter);
					j++;
				}
			}
			if (counter == 4)
			{
				tmp = (char **)malloc(sizeof(s2->square));
				tmp = s2->square;
				ft_print_table(s2);
				return (1);
			}
		}
		if (j == 4 || y + j == s2->table_size)
		{
			if(j == 4 || (s[nb].tab[i][j] != 1 && s[nb].tab[i][j++] != 1))
			{    
				i++;
				j = 0;
			}
			else
				return (-1);
		}
	}
	if (x + i == s2->table_size)
	{
		i++;
		if(s[nb].tab[i][j] != 1 && s[nb].tab[i][j++] != 1 && s[nb].tab[i][j + 2] != 1 && s[nb].tab[i][j + 3] != 1)
		{
			tmp = (char **)malloc(sizeof(s2->square));
			tmp = s2->square;
			ft_print_table(s2);
			return (1);
		}
		else
			return (-1);
	}    
	return(1);
}
