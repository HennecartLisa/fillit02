#include "fillit.h"

int		ft_error(int n)
{
	if (n == 1)
		write (1, "usage", 5);
	else
		write(1, "else", 4);
	return (0);
}

int		main(int argc, char **argv)
{
	int fd;
	char	**tetrim;

	if (*argv && argc == 2)
	{
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_error(1);
		return (1);
	}
	vim read_file(fd);
	tetrim = storage(4, fd);
	}
	else
		ft_error(2);
	return (0);
}
