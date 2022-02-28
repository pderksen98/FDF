/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 11:53:25 by pderksen      #+#    #+#                 */
/*   Updated: 2022/02/28 12:23:18 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
The Mouse hook function is called in the MLX library and renders for certain
such as scrolling up or down. Scrolling up zooms in, while 
down zooms out.
 */
static int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	(void)vars;
	if (keycode == SCROLL_UP || keycode == SCROLL_DOWN)
		zoom(keycode, vars);
	return (0);
}

/*
This function renders for the keyhooks called in the function 
render_next_frame() Exit the porgram if ESC is pressed
The 'QWERTY' keys rotate the points around the x-y-z axis
The arrows shift the creen in all 4 directions
-Z increases z-value, -X decreaes z-value
 */
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

/*
Exit the program if the red cross or ESC is pressed
this function is called so the program is terminated
 */
int	close_screen(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	exit(0);
	return (0);
}

/*
Inside this function certain hooks are activated. The first one is to close
the screen when the red cross is activated and the function close screen is 
to the MLX function. The second, renders for key hooks such as ESC button. 
The the third function is an mlx function where the function mouse hook is 
passed where the actions of the mouse such as scrolling and clicking are
rendered.
 */
int	render_next_frame(t_vars *vars)
{
	mlx_hook(vars->win, RED_CROSS, 0, close_screen, vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	return (0);
}
