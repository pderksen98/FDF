#include "fdf.h"

//Creates the window
//Calls the 'make_first_square' function
//Adds the image to the window
void	make_window_and_image(t_data *img, t_array array)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, S_WIDTH, S_HEIGHT, "FDF");
	img->img = mlx_new_image(mlx, S_WIDTH, S_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
								&img->line_length, &img->endian);
	make_first_square(img, array);
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	mlx_loop(mlx);
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
