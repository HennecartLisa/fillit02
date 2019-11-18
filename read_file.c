#include "fillit.h"

//started function to check for '#', '.', and '\n'.
int		ft_checl_nl(char **str, int i)
{
		if (str[i][5] != '\n' || str[i][9] != '\n' || str[i][14] != '\n' || str[i][19] != '\n' || str[i][20] != '\n')
			return (-1);
		return(0);
}

int		ft_check_charachters(char **str, int i)
{
	int counter1;
	int counter2;
	int counter3;
	int j;
	j = 0;
	counter1 = 0;
	counter2 = 0;
	counter3 = 0;
	ft_putchar('\n');
	ft_putstr(str[i]);
	while (str[i][j] != '\0')
	{
		if (str[i][j] == '#')
			counter1++;
		if (str[i][j] == '.')
			counter2++;
		if (str[i][j] == '\n')
			counter3++;
		j++;
	}
	str[i][j] = '\0';
	if (counter1 != 4 || counter2 != 12 || counter3 != 5)
	{
		ft_putnbr(counter1);
		return (-1);
	}
		return (0);
}
//have to make it go in a loop until the whole file is read//
int		read_file(const int fd)
{
	int ret;
	char buf[BUFFER_SIZE + 1];
	char **str;
	int i;
	int j;

	i = -1;
	j = 0;
	if(!(str = (char **)malloc(sizeof(char *) * BUFFER_SIZE + 1)))
		return (-1);
	if ((fd < 0 || fd >= OPEN_MAX) || read(fd, buf, 0) < 0)
		return (-1);
	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';	
	//	ft_putstr(buf);
	str[++i] = ft_strdup(buf);
	//	ft_putstr(str[1]);
	ft_check_charachters(&str[i], i);
	ft_check_nl(&str[i], i);
	return (0);
}
