#include "fdf.h"

int	add_angle(int keycode, t_vars *vars)
{
	make_screen_black(vars);
	if (keycode == Q)
		vars->x_angle -= 0.1;
	else if (keycode == W)
		vars->x_angle += 0.1;
	else if (keycode == E)
		vars->y_angle -= 0.1;
	else if (keycode == R)
		vars->y_angle += 0.1;
	else if (keycode == T)
		vars->z_angle -= 0.1;
	else if (keycode == Y)
		vars->z_angle += 0.1;
	make_output(*vars);
	return (0);
}

int	x_and_y_shift(int keycode, t_vars *vars)
{
	make_screen_black(vars);
	if (keycode == LEFT)
		vars->x_shift -= 20;
	else if (keycode == RIGHT)
		vars->x_shift += 20;
	else if (keycode == DOWN)
		vars->y_shift -= 20;
	else if (keycode == UP)
		vars->y_shift += 20;
	make_output(*vars);
	return (0);
}

int	zoom(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == SCROLL_DOWN)
		printf("A");
	else if (keycode == SCROLL_UP)
		printf("A");
	return (0);
}
