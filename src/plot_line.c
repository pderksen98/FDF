#include "fdf.h"

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
		my_mlx_pixel_put(img, x0, y0, L_COLOR);
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
		my_mlx_pixel_put(img, x0, y0, L_COLOR);
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
