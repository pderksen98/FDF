/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   increase_z.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 11:53:15 by pderksen      #+#    #+#                 */
/*   Updated: 2022/02/28 12:17:43 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Makes the entire screen black again by making each..
//pixel black
void	make_screen_black(t_vars *vars)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < S_HEIGHT)
	{
		j = 0;
		while (j < S_WIDTH)
		{
			my_mlx_pixel_put(&vars->img, j, i, BLACK_COLOR);
			j++;
		}
		i++;
	}
}

//Function in order to increase the z-value
//With X the value decreases by multiplying with 0.9
//With Z the value increases by multiplying with 1.1
int	increase_z(int keycode, t_vars *vars)
{
	make_screen_black(vars);
	if (keycode == X)
		vars->z_mul *= 0.9;
	else if (keycode == Z)
		vars->z_mul *= 1.1;
	make_output(*vars);
	return (0);
}
