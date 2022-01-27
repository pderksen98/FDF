#include "fdf.h"

static t_vector	*fill_array2(char **line_2d, \
		int line_len, int y, t_vector *array)
{
	t_vector	value;
	int			x;
	int			array_len;

	array_len = line_len * y;
	x = 0;
	while (x < line_len)
	{
		value.x = (float)x;
		value.y = (float)y;
		value.z = (float)ft_atoi(line_2d[x]);
		array[array_len + x] = value;
		x++;
	}
	return (array);
}

static t_vector	*fill_array(char *line, int	y, t_vector *input_array)
{
	int		line_len;
	char	**line_2d;

	line = remove_newline(line);
	line_2d = ft_split(line, ' ');
	ft_check_malloc(line_2d);
	line_len = ft_split_len(line_2d);
	input_array = fill_array2(line_2d, line_len, y, input_array);
	free(line);
	ft_split_free(line_2d);
	return (input_array);
}

t_vector	*make_input_array(char **argv, size_t array_size)
{
	int			fd;
	int			y;
	char		*line;
	t_vector	*input_array;

	input_array = malloc(sizeof(t_vector) * array_size);
	ft_check_malloc(input_array);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		input_array = fill_array(line, y, input_array);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
	return (input_array);
}
