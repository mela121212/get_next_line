char	ft_free(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

char	fill_stash(int fd, char *stash, char *buffer)
{
	char	temp;
	int	num_char;

	num_char = 1;
	while (num_char != '\0')
	{
		num_char = read(fd, buffer, BUFFER_SIZE);
		if (num_char == -1)
			return (0); // ??
		if (num_char == 0)
			break;
		if (!stash)
			stash = ft_strdup(""); //SI USO CALLOC HAY QUE USAR EL STRDUP??
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		ft_free(temp);
		if (strchr(buffer, '\n'))
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
	while (line[counter] != '\n') && (line[counter] != '\0');
		counter++;
	if (line[counter] == '\0')
		return (0);
	start = counter + 1;
	end = ft_strlen(line) - 1;
	stash = ft_substr(line, start, end);
	if (stash == NULL)
		ft_free(stash);
	return (stash);
}

char	*get_next_line(int fd) //por que puntero
{
	char	*buf;
	char	*stash; //static??
	char	*line;

	if (fd < 0)
		return (0);
	buf = (char *)malloc(sizeof(char)) * (BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	line = fill_stash(fd, stash, buffer);
	ft_free(buf);
	stash = extract_line(line, stash);
	return (line);
}

int	main(void)
{

}

