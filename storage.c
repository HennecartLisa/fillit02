#include "fillit.h"

/*
 * return **tetrim
 * 0 if bad behaviour
 */
char**		storage(int nb_tetriminoes, int fd)
{
	int		i, p;
	char tetrim[4][5];

	i = 0;
	while (i < nb_tetriminoes)
	{
		ft_putstr("\nHERE\n");
		if ((p = read(fd, tetrim[i], 5)) != 5)
		{
			ft_putnbr(p);
			tetrim[i][4] = '\0';
		}
		else
		//	ft_free(tetrim, 5);
			return (0);
		i++;
	}
	ft_print(tetrim);
	return (0);
}
