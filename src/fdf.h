#ifndef FDF_H
# define FDF_H
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define S_WIDTH 1000
# define S_HEIGHT 1000
//# define D_COLOR 16711680 //red
# define D_COLOR 65280 //green
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
}	t_array;

size_t		get_array_length(char **argv);
char		*remove_newline(char *line);
t_vector	*make_input_array(char **argv, size_t array_size);
void		print_test(t_array array); //remove
#endif
