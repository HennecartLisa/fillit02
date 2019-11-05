#include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <limits.h>

int		read_file(const int fd)
{
	int ret;
	char buf[22];

	if ((fd < 0 || fd >= OPEN_MAX) || read(fd, buf, 0) < 0)
		return (-1);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
	//	file_checker();
	}
	ft_putstr(buf);
	return (1);
}
int main ()
{
	int fd;

	fd = open("tests/invalid_single/invalid_single_6", O_RDONLY);

	read_file(fd);
	return (0);
}	
