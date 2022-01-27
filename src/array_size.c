#include "fdf.h"

char	*remove_newline(char *line)
{
	char	*newline;

	newline = ft_strdup_c(line, '\n');
	ft_check_malloc(newline);
	free(line);
	return (newline);
}

size_t	get_array_length(char **argv)
{
	int		fd;
	char	*line;
	char	**line_2d;
	size_t	x;
	size_t	y;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	line = remove_newline(line);
	line_2d = ft_split(line, ' ');
	ft_check_malloc(line_2d);
	x = ft_split_len(line_2d);
	ft_split_free(line_2d);
	y = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	close(fd);
	return (x * y);
}
