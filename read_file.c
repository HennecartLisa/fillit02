#include "fillit.h"
#include <stdio.h>//

//started function to check for '#', '.', and '\n'.
int		ft_check_nl(char *str)
{	
	ft_putchar('2');
	ft_putchar('\n');
	if (str[5] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
		return (-1);
	return(1);
}

int		ft_check_charachters(char *str)//, int i)
{
	int counter1;
	int counter2;
	int counter3;
	int j;
	j = 0;
	counter1 = 0;
	counter2 = 0;
	counter3 = 0;

	ft_putchar('1');
	ft_putchar('\n');
	while (str[j] != '\0')
	{
		if (str[j] == '#')
			counter1++;
		if (str[j] == '.')
			counter2++;
		if (str[j] == '\n')
			counter3++;

		j++;
	}	
	str[j] = '\0';
	if (counter1 != 4 || counter2 != 12 || counter3 != 4)
	{
		ft_putnbr(counter1);
		ft_putchar('\n');
		ft_putnbr(counter2);
		ft_putchar('\n');
		ft_putnbr(counter3);
		ft_putchar('\n');
		return (-1);
	}
	ft_check_nl(str);
	return (1);
}
//it reads all and 
int		read_file(const int fd)
{
	int ret;
	char buf[BUFFER_SIZE + 1];
	char str[26][21];
	int i;
	int j;
	int number_tetros;

	number_tetros = 0;

	i = 0;
	j = 0;
	if ((fd < 0 || fd >= OPEN_MAX) || read(fd, buf, 0) < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) /*|| number_tetros >= 1 || number_tetros <= 26 */ )
	{
		buf[ret] = '\0';
		ft_strcpy(str[i], buf);
		ft_putstr(str[i]);
		if((ft_check_charachters(str[i])) < 0)
			return (-1);
		number_tetros++;
		i++;
	}
	ft_putstr(*str);
	return (0);
}
