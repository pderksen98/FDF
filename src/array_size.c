#include "fdf.h"

//Counts and returns the number of z-values in 'line' (x_pixels)
static size_t	get_x_pix(char *line)
{
	char	**line_2d;
	size_t	x;

	line_2d = ft_split(line, ' ');
	ft_check_malloc(line_2d);
	x = ft_split_len(line_2d);
	ft_split_free(line_2d);
	return (x);
}

//Counts and returns the number of lines (y_pixels)
static size_t	get_y_pix(char *line, int fd)
{
	size_t	y;

	y = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	return (y);
}

//Removes the newline from the string
char	*remove_newline(char *line)
{
	char	*newline;

	newline = ft_strdup_c(line, '\n');
	ft_check_malloc(newline);
	free(line);
	return (newline);
}

//Opens the map to file descriptor (fd)
//Returns the total number of input values (x * y)
size_t	get_array_length(char **argv, t_array *pixel)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	line = remove_newline(line);
	pixel->x_pixels = get_x_pix(line);
	pixel->y_pixels = get_y_pix(line, fd);
	close(fd);
	return (pixel->x_pixels * pixel->y_pixels);
}
