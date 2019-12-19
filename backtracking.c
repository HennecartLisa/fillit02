#include "fillit.h"

/*void	main_insert(t_table *s2, t_tetra *s, int size)
{
	int x = 0;
	int i = 0;
	int nb = 0;
	int result;
	int y = 0;
	ft_putstr("trigger insert");
	main_if_possible(s2, s, nb);
	{
		result = insert_tetro(x, i, nb, s->letter, s2, s);
		if (result < 1)
		{
			delete_table(s2);
			ft_allocate(s, ++size);
		}
		if (result == 0)
		{
			if (nb == s->total_tetroes)
				s2->square[x][y] = '\0';
			if (nb < s->total_tetroes)
			{
				main_if_possible(s2, s, nb);
				insert_tetro(x, i, nb++, s->letter++, s2 ,s);
			}
		}	
		ft_print_table(s2);
	}	
}*/

int		main_if_possible(t_table *s2, t_tetra *s, int size)
{
	static int x= 0;
	int result;
	int nb = 0;
	ft_putstr("starting");
	//ft_print_table(s2);
	while (x < s2->table_size)
	//	if (check_if_possible(s2, x, s, nb) < 1)
		result = check_if_possible(s2, x, s, nb);	
	
	if (result == 1)
	{

		ft_putstr("result is 1");
		if (x < s2->table_size)
		{
		ft_putstr("moving to next line");
			x++;
		}	
		if ( x == s2->table_size)
		{
			ft_putstr("end of tetro");
				return (1);
			}
	}
		if (result  == -1)
		{
			delete_table(s2);
			ft_allocate(s, ++size);
		}
	return (1);
}
