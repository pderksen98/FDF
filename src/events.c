#include "fdf.h"

static int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		close_screen(keycode, vars);
	else if (keycode == Z || keycode == X)
		mlx_hook(vars->win, 2, 1L<<0, increase_z, vars);
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
	return (0);
}
