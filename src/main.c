#include "fdf.h"

//Creates the window
//Calls the 'make_first_square' function
//Adds the image to the window
void	make_window_and_image(t_data *img, t_array array)
{
	void		*mlx;
	void		*mlx_win;
	t_output	*output;
	// size_t		i;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, S_WIDTH, S_HEIGHT, "FDF");
	img->img = mlx_new_image(mlx, S_WIDTH, S_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
								&img->line_length, &img->endian);
	output = make_first_square(array);
	print_test(array, output);
	call_plot_function(output, array, img);

	// i = 0;
	// while (i < array.input_len)
	// {
	// 	my_mlx_pixel_put(img, output[i].x, output[i].y, D_COLOR);
	// 	i++;
	// }
	
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	mlx_loop(mlx);
	free (output);
}

int	main(int argc, char **argv)
{
	t_array	array;
	t_data	mlx;

	if (argc != 2)
		return (0);
	array.input_len = get_array_length(argv, &array);
	array.input = make_input_array(argv, array.input_len);
	// print_test(array);
	make_window_and_image(&mlx, array);
	free(array.input);
	return (0);
}
