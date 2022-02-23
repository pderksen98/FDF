#include "fdf.h"


//Determines the number of pixels (x_dis & y_dis) between the x & y points
//Depends on S_WIDTH, S_HEIGHT and on the max length between x & y points
void	determine_line_lenght(t_array *length)
{
	int	max_len_x;
	int	max_len_y;
	int	y_dis;
	int	x_dis;

	max_len_x = 25;
	max_len_y = 25;
	x_dis = R_WIDTH / length->x_pixels;
	while (x_dis < max_len_x && max_len_x > 1)
		max_len_x--;
	
	y_dis = R_HEIGHT / length->y_pixels;
	while (y_dis < max_len_y && max_len_y > 1)
		max_len_y--;
	if (max_len_x > max_len_y)
		max_len_x = max_len_y;
	if (max_len_y > max_len_x)
		max_len_y = max_len_x;
	length->y_dis = max_len_y - 1;
	length->x_dis = max_len_x - 1;
}

//Fills and returns the output array by calling the 'rotate' function for each set of x,y,z coordinates
//Calculates start point for x & y in order to be centred
//x and y coordinates with correct distance (x_dis & y_dis) between the pixels
t_output	*make_first_square(t_array array)
{
	int		x_start;
	int		y_start;
	size_t	i;
	t_output	*output;

	output = malloc(sizeof(t_output) * array.input_len);
	ft_check_malloc(output);
	determine_line_lenght(&array);
	x_start = (S_WIDTH - ((array.x_dis + 1) * array.x_pixels * X_MUL)) / 2;
	y_start = (S_HEIGHT - ((array.y_dis + 1) * array.y_pixels * Y_MUL)) / 2;
	i = 0;
	while (i < array.input_len)
	{	
		rotate_z_axis(x_start + (int)array.input[i].x + \
			(int)array.input[i].x * array.x_dis, \
			 y_start + (int)array.input[i].y + \
			 (int)array.input[i].y * array.y_dis, \
			 (int)array.input[i].z, &output[i]);
		i++;
	}
	return (output);
}
