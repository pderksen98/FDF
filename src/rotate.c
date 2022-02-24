#include "fdf.h"

//Rotates the square with angle (in radians) around y-axis w.r.t origen
//*_0 are coordinates relative to the origen
//puts correct x,y value in the output array
void	rotate_y_axis(int x_0, int y_0, int z_0, t_output *output, t_vars vars)
{
	t_rotation	rot;

	rot.x_origen = (S_WIDTH / 2);
	rot.y_origen = (S_HEIGHT / 2);
	rot.angle = 0 + vars.y_angle;
	rot.x_1 = x_0 * cos(rot.angle) + z_0 * sin(rot.angle);
	rot.y_1 = y_0;
	rot.x_final = rot.x_1 + rot.x_origen;
	rot.y_final = rot.y_1 + rot.y_origen;
	output->x = rot.x_final + vars.x_shift;
	output->y = rot.y_final + vars.y_shift;
}

//Rotates the square with angle (in radians) around x-axis w.r.t origen
//*_0 are coordinates relative to the origen
void	rotate_x_axis(int x_0, int y_0, int z_0, t_output *output, t_vars vars)
{
	t_rotation	rot;

	rot.angle = M_PI_4 + vars.x_angle;
	rot.x_1 = x_0;
	rot.y_1 = y_0 * cos(rot.angle) - z_0 * sin(rot.angle);
	rot.z_1 = y_0 * sin(rot.angle) + z_0 * cos(rot.angle);
	rotate_y_axis(rot.x_1, rot.y_1, rot.z_1, output, vars);
}

//Recieves x, y coordinates of square
//Calculates x, y coordinates of origen of the square
//Rotates the square with angle (in radians) around z-axis w.r.t origen
void	rotate_z_axis(int x, int y, int z, t_output *output, t_vars vars)
{
	t_rotation	rot;

	rot.x_origen = (S_WIDTH / 2);
	rot.y_origen = (S_HEIGHT / 2);
	rot.x_0 = x - rot.x_origen;
	rot.y_0 = y - rot.y_origen;
	rot.angle = M_PI_4 + vars.z_angle;
	rot.x_1 = rot.x_0 * cos(rot.angle) - rot.y_0 * sin(rot.angle);
	rot.y_1 = rot.y_0 * cos(rot.angle) + rot.x_0 * sin(rot.angle);
	rotate_x_axis(rot.x_1, rot.y_1, z, output, vars);
}
