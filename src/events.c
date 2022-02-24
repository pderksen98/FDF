#include "fdf.h"

static int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	(void)vars;
	if (keycode == SCROLL_UP || keycode == SCROLL_DOWN)
		printf("TJAKKA!\n");
	return (0);
}

static int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		close_screen(keycode, vars);
	else if (keycode == Z || keycode == X)
		mlx_hook(vars->win, 2, 1L << 0, increase_z, vars);
	else if (keycode == Q || keycode == W || keycode == E || \
			keycode == R || keycode == T || keycode == Y)
		mlx_hook(vars->win, 2, 1L << 0, add_angle, vars);
	else if (keycode == LEFT || keycode == RIGHT || \
			keycode == UP || keycode == DOWN)
		mlx_hook(vars->win, 2, 1L << 0, x_and_y_shift, vars);
	return (0);
}

int	close_screen(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	exit(0);
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	mlx_hook(vars->win, RED_CROSS, 0, close_screen, vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	return (0);
}
