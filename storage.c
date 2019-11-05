#include "fillit.h"

/*
 * free pointer or array of pointers
 * -1 if free went wrong && 0 if free when right
 */
int		ft_free(char **pt, int nb)
{
	int		i;
	int		error;

	i = 0;
	error = 0;
	while (pt && nb > 1 && !error && pt[i] && i < nb)
	{
		free(pt[i]);
		if (pt[i])
			error = 1;
		i++;
	}
	if (pt)
		free(pt);
	if (*pt || error)
		return (-1);
	return (0);
}

/*
 * create array[x][y]
 * return -1 if there has been an error and free what was allocated
 * return 0 is good behaviour
 */
int		ft_create_double_array(int x, int y, char **array)
{
	int		i;
	int		error;

	i = 0;
	array = malloc(x * sizeof (char*));
	while (!error && i < (x - 1))
	{
		array[i] = malloc(y * sizeof (char));
		if (!array[i])
		{
			error = 1;
			ft_free(array, (i - 1));
		}
		i++;
	}
	if (!error)
		array[x - 1] = 0;
	else
		return (-1);
	return (0);
}

/*
 * return value 0 if correct
 * 1 if bad behaviour
 */
int		sotrage(int nb_tetriminoes, int fd)
{
	char	**tetrim;
	int		i;

	if (!ft_create_double_array(5, 5, tetrim))
		return (-1);
	i = 0;
	while (i < 4)
	{
		if (read(fd, tetrim[i], 4) != 4)
			tetrim[i][4] = '\0';
		else
			ft_free(tetrim, 5);
			return (-1);
		i++;
	}
	return (0);
}
