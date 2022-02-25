#ifndef FDF_H
# define FDF_H
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define X_MUL 1
# define Y_MUL 1
# define Z_MUL 1
# define S_WIDTH 2300
# define S_HEIGHT 1300
# define R_WIDTH 1000 //(S_WIDTH * 0.7)
# define R_HEIGHT 650 //(S_HEIGHT * 0.7)
# define GREEN_COLOR 65280
# define BLACK_COLOR 0
# define _USE_MATH_DEFINES // for C

typedef enum e_keys {
	ESC = 53,
	RED_CROSS = 17,
	Z = 6,
	X = 7,
	LEFT = 123,
	RIGHT = 124,
	DOWN = 126,
	UP = 125,
	Q = 12,
	W = 13,
	E = 14,
	R = 15,
	T = 17,
	Y = 16,
	SCROLL_UP = 5,
	SCROLL_DOWN = 4
}			t_keys;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x0;
}	t_data;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_output
{
	int	x;
	int	y;
}	t_output;

typedef struct s_plot
{
	int	dx;
	int	dy;
	int	x_increment;
	int	y_increment;
	int	D;
}	t_plot;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		img;
	size_t		input_len;
	int			line_length;
	int			x_pixels;
	int			y_pixels;
	t_vector	*input;
	float		z_mul;
	float		x_angle;
	float		y_angle;
	float		z_angle;
	size_t		x_shift;
	size_t		y_shift;
	int			length_mod;
	float		z_mod;
}	t_vars;

typedef struct s_rotation
{
	float	x_origen;
	float	y_origen;
	int		x_0;
	int		y_0;
	int		z_0;
	int		x_1;
	int		y_1;
	int		z_1;
	int		x_final;
	int		y_final;
	float	angle;
}	t_rotation;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

size_t		get_array_length(char **argv, t_vars *pixel);
char		*remove_newline(char *line);
t_vector	*make_input_array(char **argv, size_t array_size);
void		determine_line_lenght(t_vars *length);
t_output	*make_first_square(t_vars vars);
void		rotate_z_axis(t_point point, t_output *output, t_vars vars);
void		rotate_x_axis(t_rotation rot, t_output *output, t_vars vars);
void		rotate_y_axis(t_rotation rot, t_output *output, t_vars vars);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		call_plot_function(t_output *output, t_vars vars, t_data *img);
int			render_next_frame(t_vars *vars);
int			close_screen(int keycode, t_vars *vars);
void		make_screen_black(t_vars *vars);
int			increase_z(int keycode, t_vars *vars);
void		make_output(t_vars vars);
int			add_angle(int keycode, t_vars *vars);
int			x_and_y_shift(int keycode, t_vars *vars);
int			zoom(int keycode, t_vars *vars);
#endif
