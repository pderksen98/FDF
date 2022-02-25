#include "fdf.h"

void	modify_line_length(t_vars *vars)
{
	float		old_line_length;
	float		new_line_lenght;
	float		ratio;

	old_line_length = vars->line_length;
	new_line_lenght = vars->line_length + vars->length_mod;
	if (new_line_lenght < 1)
		new_line_lenght = 1;
	vars->line_length = new_line_lenght;
	ratio = new_line_lenght / old_line_length;
	vars->z_mod = ratio;
}

//Determines the number of pixels (x_dis & y_dis) between the x & y points
//Depends on S_WIDTH, S_HEIGHT and on the max length between x & y points
void	determine_line_lenght(t_vars *length)
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
	length->line_length = max_len_x;
}

//Fills and returns the output array by calling the 'rotate' function 
//for each set of x,y,z coordinates
//Calculates start point for x & y in order to be centred
//x and y coordinates with correct distance (x_dis & y_dis) between the pixels
t_output	*make_first_square(t_vars vars)
{
	int			x_start;
	int			y_start;
	size_t		i;
	t_output	*output;
	t_point		point;

	output = malloc(sizeof(t_output) * vars.input_len);
	ft_check_malloc(output);
	determine_line_lenght(&vars);
	modify_line_length(&vars);
	x_start = (S_WIDTH - ((vars.line_length) * vars.x_pixels * X_MUL)) / 2;
	y_start = (S_HEIGHT - ((vars.line_length) * vars.y_pixels * Y_MUL)) / 2;
	i = 0;
	while (i < vars.input_len)
	{	
		point.x = x_start + (int)vars.input[i].x + \
			(int)vars.input[i].x * vars.line_length;
		point.y = y_start + (int)vars.input[i].y + \
			(int)vars.input[i].y * vars.line_length;
		point.z = (int)vars.input[i].z * vars.z_mul * vars.z_mod;
		rotate_z_axis(point, &output[i], vars);
		i++;
	}
	return (output);
}
