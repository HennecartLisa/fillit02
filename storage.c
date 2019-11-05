#include "fillit.h"

/*
 * return value 0 if correct
 * 1 if bad behaviour
 */
int		sotrage(int nb_tetriminoes, int fd)
{
	char	tetrim;
	int		i;
	int		error;

	i = 0;
	tetrim = malloc(5 * sizeof (*char));
	while (i < 4)
	{
		tetrim[i] = malloc(5 * sizeof (char));
		i++;
		if (!tetrim[1])
		{
			error = 1;
			ft_free(&tetrim
		}
	}


	read(fd, tetrim[i], 4)
}
