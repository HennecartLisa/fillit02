int		read_file(const int fd)
{
	int ret;
	char buf[22];

	if ((fd < 0 || fd >= OPEN_MAX) || read(fd, buf, 0) < 0)
		return (-1);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		file_checker();
	}
	return (1);
}

