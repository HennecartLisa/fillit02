#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (*argv)
			write(1,"all good", 8);
	}
	else
		write (1, "usage", 5);
	return (0);
}
