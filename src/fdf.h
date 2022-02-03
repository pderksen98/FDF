#ifndef FDF_H
# define FDF_H
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define S_WIDTH 2000
# define S_HEIGHT 1250
# define R_WIDTH (S_WIDTH * 0.5)
# define R_HEIGHT (S_HEIGHT * 0.5)
//# define D_COLOR 16711680 //red
# define D_COLOR 65280 //green
# define _USE_MATH_DEFINES // for C
# include <math.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_array
{
	t_vector	*input;
	size_t		input_len;
	int			x_dis;
	int			y_dis;
	int			x_pixels;
	int			y_pixels;
}	t_array;

typedef struct s_rotation
{
	float	x_origen;
	float	y_origen;
	int		x_0;
	int		y_0;
	int		x_1;
	int		y_1;
	int		z_1;
	int		x_final;
	int		y_final;
	float	angle;	
}	t_rotation;

size_t		get_array_length(char **argv, t_array *pixel);
char		*remove_newline(char *line);
t_vector	*make_input_array(char **argv, size_t array_size);
void		print_test(t_array array);
void		determine_line_lenght(t_array *length);
void		make_first_square(t_data *img, t_array array);
void		rotate_z_axis(int x, int y, int z, t_data *img);
void		rotate_x_axis(int x, int y, int z, t_data *img);
void		rotate_y_axis(int x, int y, int z, t_data *img);
#endif
