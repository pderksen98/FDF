#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	make_window_and_image(t_data *img)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, S_WIDTH, S_HEIGHT, "FDF");
	img->img = mlx_new_image(mlx, S_WIDTH, S_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	my_mlx_pixel_put(img, 5, 5, D_COLOR);
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	t_array	array;
	t_data	mlx;

	if (argc != 2)
		return (0);
	array.input_len = get_array_length(argv);
	array.input = make_input_array(argv, array.input_len);
	print_test(array);
	free(array.input);
	make_window_and_image(&mlx);
	return (0);
}
