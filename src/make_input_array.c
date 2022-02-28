/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_input_array.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 11:52:53 by pderksen      #+#    #+#                 */
/*   Updated: 2022/02/28 11:52:54 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Recieves the 'line_2d' array with z-values and corresponding y-value
//Fills 'vector_array' by looping through 'line_2d'
static t_vector	*fill_array2(char **line_2d, \
		int total_x, int y, t_vector *vector_array)
{
	t_vector	vector;
	int			x;
	int			array_start;

	array_start = total_x * y;
	x = 0;
	while (x < total_x)
	{
		vector.x = (float)x * X_MUL;
		vector.y = (float)y * Y_MUL;
		vector.z = (float)ft_atoi(line_2d[x]) * Z_MUL;
		vector_array[array_start + x] = vector;
		x++;
	}
	return (vector_array);
}

//Recieves 'line' with corresponding y-value and the 'vector_array'
//Makes a 2d array ('line_2d') with all z-values from 'line'
//The row number of 'line_2d' is equal to the x-value 
static t_vector	*fill_array(char *line, int	y, t_vector *vector_array)
{
	int		total_x;
	char	**line_2d;

	line = remove_newline(line);
	line_2d = ft_split(line, ' ');
	ft_check_malloc(line_2d);
	total_x = ft_split_len(line_2d);
	vector_array = fill_array2(line_2d, total_x, y, vector_array);
	free(line);
	ft_split_free(line_2d);
	return (vector_array);
}

//Makes and returns the input array: 'vector_array'
t_vector	*make_input_array(char **argv, size_t array_size)
{
	int			fd;
	int			y;
	char		*line;
	t_vector	*vector_array;

	vector_array = malloc(sizeof(t_vector) * array_size);
	ft_check_malloc(vector_array);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		vector_array = fill_array(line, y, vector_array);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
	return (vector_array);
}
