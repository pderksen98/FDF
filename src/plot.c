#include "fdf.h"

//Puts pixel in input color to the window on place x, y
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x <= S_WIDTH) && (y >= 0 && y <= S_HEIGHT))
	{
		 dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

//For lines with: slope < -1 and slope > 1
void	plot_line_high(t_data *img, int x0, int y0, int x1, int y1)
{
	t_plot	plot;

	plot.dx = x1 - x0;
	plot.dy = y1 - y0;
	plot.x_increment = 1;
	if (plot.dx < 0)
	{
		plot.x_increment = -1;
		plot.dx = -plot.dx;
	}
	plot.D = (2 * plot.dx) - plot.dy;
	while (y0 <= y1)
	{
		my_mlx_pixel_put(img, x0, y0, D_COLOR);
		if (plot.D > 0)
		{
			x0 = x0 + plot.x_increment;
			plot.D = plot.D + (2 * (plot.dx - plot.dy));
		}
		else
			plot.D = plot.D + (2 * plot.dx);
		y0++;
	}
}

//For lines with: -1 > slope < 1; 
void	plot_line_low(t_data *img, int x0, int y0, int x1, int y1)
{
	t_plot	plot;

	plot.dx = x1 - x0;
	plot.dy = y1 - y0;
	plot.y_increment = 1;
	if (plot.dy < 0)
	{
		plot.y_increment = -1;
		plot.dy = -plot.dy;
	}
	plot.D = (2 * plot.dy) - plot.dx;
	while (x0 <= x1)
	{
		my_mlx_pixel_put(img, x0, y0, D_COLOR);
		if (plot.D > 0)
		{
			y0 = y0 + plot.y_increment;
			plot.D = plot.D + (2 * (plot.dy - plot.dx));
		}
		else
			plot.D = plot.D + (2 * plot.dy);
		x0++;
	}
}

//Plots line between point (x0, y0) and point (x1, y1)
//Points get also drawn by pixel
//Depending on the slope of the line, either plot_line_high or plot_line_low is called
void	plot_line(t_data *img, int x0, int y0, int x1, int y1)
{
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x1 > x0)
			plot_line_low(img, x0, y0, x1, y1);
		else
			plot_line_low(img, x1, y1, x0, y0);
	}
	else
	{
		if (y1 > y0)
			plot_line_high(img, x0, y0, x1, y1);
		else
			plot_line_high(img, x1, y1, x0, y0);
	}
}

//Goes through the output array and determines wich coordinates need to be connected
//Calls the plot line function with correct pixels/coordinates
void	call_plot_function(t_output *output, t_array array, t_data *img)
{
	size_t	i;
	size_t	row;
	size_t	end;

	end = array.x_pixels - 1;
	i = 0;
	row = 1;
	while (i < (array.input_len - 1))
	{
		if (i < (array.input_len - array.x_pixels))
		{
			plot_line(img, output[i].x, output[i].y, output[i + array.x_pixels].x, output[i + array.x_pixels].y);
			if (i != end)
				plot_line(img, output[i].x, output[i].y, output[i + 1].x, output[i + 1].y);
		}
		if (i == end)
			end = end + array.x_pixels;
		else
			plot_line(img, output[i].x, output[i].y, output[i + 1].x, output[i + 1].y);
		i++;
	}
}
