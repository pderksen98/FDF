/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_angle.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 12:18:04 by pderksen      #+#    #+#                 */
/*   Updated: 2022/02/28 12:26:03 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//-Q and -W rotate points around the x-axis
//-E and -R rotate points around the y-axis
//-T and -Y rotate points around the z-axis
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

//LEFT and RIGHT arrows shift the screen in L,R dir
//UP and DOWN arrows shift the screen in U,D dir
int	x_and_y_shift(int keycode, t_vars *vars)
{
	make_screen_black(vars);
	if (keycode == LEFT)
		vars->x_shift += 20;
	else if (keycode == RIGHT)
		vars->x_shift -= 20;
	else if (keycode == DOWN)
		vars->y_shift += 20;
	else if (keycode == UP)
		vars->y_shift -= 20;
	make_output(*vars);
	return (0);
}

//When mouse scrolls down, zoom out
//When mouse scrools up, zoom in 
int	zoom(int keycode, t_vars *vars)
{
	make_screen_black(vars);
	if (keycode == SCROLL_DOWN)
		vars->length_mod++;
	else if (keycode == SCROLL_UP)
		vars->length_mod--;
	make_output(*vars);
	return (0);
}
