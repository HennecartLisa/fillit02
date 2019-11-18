#include "fillit.h"


int		ft_error(int n)
{
	if (n == 1)
		write (1, "usage", 5);
	if (n == 2)
		write (1, "wrong file", 10);
	else
		write(1, "else", 4);
	return (0);
}

void     ft_print_tetros(t_tetra *t)
{
    int m;
    int i;
    int j;

    ft_putchar('\n');
    m = 0;
    while (m < t[0].nb_tetros )
    {
        i = 0;
        while (i < 4)
        {
            j = 0;
            while (j < 4)
            {
                ft_putnbr(t[m].tab[i][j]);
                j++;
            }
            ft_putchar('\n');
            i++;
        }
        ft_putchar('\n');
        m++;
    }
}

int		main(int argc, char **argv)
{
	int fd;
	t_tetra	*tetros;

	if (*argv && argc == 2)
	{
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_error(1);
		return (1);
	}
	if ((tetros = read_file(fd)) == NULL)
	{
		ft_error(2);
		return (1);
	}
	ft_print_tetros(tetros);
//	tetrim = storage(4, fd);
//	else
//		ft_error(3);
	}
	return (0);
}
