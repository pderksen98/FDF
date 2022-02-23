#include "fdf.h"

void	make_output(t_array array, t_vars vars)
{
	t_output	*output;

	output = make_first_square(array);
	call_plot_function(output, array, &vars.img);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	free (output);
}



int	main(int argc, char **argv)
{
	t_array	array;
	t_vars	vars;

	if (argc != 2)
		return (0);
	array.input_len = get_array_length(argv, &array);
	array.input = make_input_array(argv, array.input_len);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, S_WIDTH, S_HEIGHT, "FDF");
	vars.img.img = mlx_new_image(vars.mlx, S_WIDTH, S_HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, \
						&vars.img.line_length, &vars.img.endian);
	make_output(array, vars);
	render_next_frame(&vars);
	mlx_loop(vars.mlx);
	free(array.input);
	return (0);
}
