#include "fdf.h"

//Puts pixel in input color to the window on place x, y
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < S_WIDTH) && (y >= 0 && y < S_HEIGHT))
	{
		 dst = data->addr + (y * data->line_length + \
		 	 x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

//For lines with: slope < -1 and slope > 1
void	plot_line_high(t_data *img, t_output p, t_output p1)
{
	t_plot	plot;

	plot.dx = p1.x - p.x;
	plot.dy = p1.y - p.y;
	plot.x_increment = 1;
	if (plot.dx < 0)
	{
		plot.x_increment = -1;
		plot.dx = -plot.dx;
	}
	plot.D = (2 * plot.dx) - plot.dy;
	while (p.y <= p1.y)
	{
		my_mlx_pixel_put(img, p.x, p.y, GREEN_COLOR);
		if (plot.D > 0)
		{
			p.x = p.x + plot.x_increment;
			plot.D = plot.D + (2 * (plot.dx - plot.dy));
		}
		else
			plot.D = plot.D + (2 * plot.dx);
		p.y++;
	}
}

//For lines with: -1 > slope < 1; 
void	plot_line_low(t_data *img, t_output p, t_output p1)
{
	t_plot	plot;

	plot.dx = p1.x - p.x;
	plot.dy = p1.y - p.y;
	plot.y_increment = 1;
	if (plot.dy < 0)
	{
		plot.y_increment = -1;
		plot.dy = -plot.dy;
	}
	plot.D = (2 * plot.dy) - plot.dx;
	while (p.x <= p1.x)
	{
		my_mlx_pixel_put(img, p.x, p.y, GREEN_COLOR);
		if (plot.D > 0)
		{
			p.y = p.y + plot.y_increment;
			plot.D = plot.D + (2 * (plot.dy - plot.dx));
		}
		else
			plot.D = plot.D + (2 * plot.dy);
		p.x++;
	}
}

//Plots line between point (x0, y0) and point (x1, y1)
//Points get also drawn by pixel
//Depending on the slope of the line,... 
//either plot_line_high or plot_line_low is called
void	plot_line(t_data *img, t_output p, t_output p1)
{
	if (abs(p1.y - p.y) < abs(p1.x - p.x))
	{
		if (p1.x > p.x)
			plot_line_low(img, p, p1);
		else
			plot_line_low(img, p1, p);
	}
	else
	{
		if (p1.y > p.y)
			plot_line_high(img, p, p1);
		else
			plot_line_high(img, p1, p);
	}
}

//Goes through the output array and determines wich...
//coordinates need to be connected
//Calls the plot line function with correct pixels/coordinates
void	call_plot_function(t_output *output, t_vars vars, t_data *img)
{
	size_t	i;
	size_t	end;

	end = vars.x_pixels - 1;
	i = 0;
	while (i < (vars.input_len - 1))
	{
		if (i < (vars.input_len - vars.x_pixels))
		{
			plot_line(img, output[i], output[i + vars.x_pixels]);
			if (i != end)
				plot_line(img, output[i], output[i + 1]);
		}
		if (i == end)
			end = end + vars.x_pixels;
		else
			plot_line(img, output[i], output[i + 1]);
		i++;
	}
}
