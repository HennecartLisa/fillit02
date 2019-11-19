#include "fillit.h"

int		ft_print(char tetra[4][5])
{
	int i = 0, j;

	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			write(1, &tetra[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
