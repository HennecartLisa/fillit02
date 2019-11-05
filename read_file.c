#include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <limits.h>

//started function to check for '#', '.', and '\n'.
int		ft_check_file(char **str)
{
	int i;
	char a;
	char b;
	char c;
	a = '#';
	b = '.';
	c = '\n';
	i = 0;

	ft_putstr(&str[0][0]);
	while (str[1][i] != '\0')
	{
		i++;
		if (str[1][4] != c)
			return (-1);
		if(str[1][9] != c)
			return (-1);
		if (str[1][14] != c)
			return (-1);
		if(str[1][19] != c)
			return (-1);
	}
	str[1][i] = '\0';
		/*if (a != 4)
		return (-1);
	if (b != 12)
		return (-1);
	if (c != 5)
		return (-1);*/
	return (0);
}

//Made it go in a loop//
int		read_file(const int fd)
{
	int ret;
	char buf[22];
	char **str;
	int i;

	i = -1;

	if(!(str = (char **)malloc(sizeof(char *) * 21 + 1)))
		return (-1);


	if ((fd < 0 || fd >= OPEN_MAX) || read(fd, buf, 0) < 0)
		return (-1);
	
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
	//	ft_putstr(buf);
		str[++i] = ft_strdup(buf);
	//	ft_putstr(str[1]);
		ft_check_file(str);
	}
	return (1);
}

int main ()
{
	int fd;

	fd = open("tests/invalid_multiple/invalid_multiple_2", O_RDONLY);

	read_file(fd);
	return (0);
}	
