char	*ft_free(char *str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	fill_stash(int fd, char *stash, char *buffer)
{
	char	temp;
	char	num_char;

	num_char = 1;
	while (num_char != '\0')
	{
		if (num_char = -1)
			return (0); // ??
		if (num_char = 0)
			break;
		if (!(stash))
			stash = strdup(""); //SI USO CALLOC HAY QUE USAR EL STRDUP??
		num_char = read(fd, buffer, BUFFER_SIZE);
		temp = stash;
		stash = strjoin(buffer, temp);
		ft_free(temp);
		if (strchr(buffer, '\n')) // != 0??
			break;
	}
	return (stash);
}

char	extract_line(char *line, char *stash)
{
	int	counter;
	int	start;
	int	end;

	counter = 0;
	while (line[counter] != '\n') || (line['\0'] != '\0');
		counter++;
	if (line[counter] ==  '\0')
		return (0);
	start = counter + 1;
	end = ft_strlen - 1;
	stash = substr(line, start, end);
	if (stash == '\0')
		ft_free(stash);
	return (stash);
}

char	get_next_line(int fd)
{
	char	*buf;
	char	*stash; //static??
	char	*line;

	buf = (char *)malloc(char) * (BUFFER_SIZE + 1);
	if (!(buf))
		return ;
	line = fill_stash(line, stash, buf);
	stash = extract_line(line, stash);
	return (stash);
	
}

int	main(void)
{

}

