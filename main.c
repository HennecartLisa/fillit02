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

	if (argc == 2)
	{
		if (*argv)
			write(1,"all good", 8);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
	{
		ft_error(1);
		return (1);
	}
	read_file(fd);
	}
	else
		ft_error(2);
	return (0);
}
