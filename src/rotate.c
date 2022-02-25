#include "fdf.h"

//Rotates the square with angle (in radians) around y-axis w.r.t origen
//*_0 are coordinates relative to the origen
//puts correct x,y value in the output array
void	rotate_y_axis(t_rotation rot, t_output *output, t_vars vars)
{
	rot.x_origen = (S_WIDTH / 2);
	rot.y_origen = (S_HEIGHT / 2);
	rot.angle = 0 + vars.y_angle;
	rot.x_1 = rot.x_0 * cos(rot.angle) + rot.z_0 * sin(rot.angle);
	rot.y_1 = rot.y_0;
	rot.x_final = rot.x_1 + rot.x_origen;
	rot.y_final = rot.y_1 + rot.y_origen;
	output->x = rot.x_final + vars.x_shift;
	output->y = rot.y_final + vars.y_shift;
}

//Rotates the square with angle (in radians) around x-axis w.r.t origen
//*_0 are coordinates relative to the origen
void	rotate_x_axis(t_rotation rot, t_output *output, t_vars vars)
{
	rot.angle = M_PI_4 + vars.x_angle;
	rot.x_0 = rot.x_1;
	rot.y_0 = rot.y_1 * cos(rot.angle) - rot.z_1 * sin(rot.angle);
	rot.z_0 = rot.y_1 * sin(rot.angle) + rot.z_1 * cos(rot.angle);
	rotate_y_axis(rot, output, vars);
}

//Recieves x, y coordinates of square
//Calculates x, y coordinates of origen of the square
//Rotates the square with angle (in radians) around z-axis w.r.t origen
void	rotate_z_axis(t_point point, t_output *output, t_vars vars)
{
	t_rotation	rot;

	rot.x_origen = (S_WIDTH / 2);
	rot.y_origen = (S_HEIGHT / 2);
	rot.x_0 = point.x - rot.x_origen;
	rot.y_0 = point.y - rot.y_origen;
	rot.angle = M_PI_4 + vars.z_angle;
	rot.x_1 = rot.x_0 * cos(rot.angle) - rot.y_0 * sin(rot.angle);
	rot.y_1 = rot.y_0 * cos(rot.angle) + rot.x_0 * sin(rot.angle);
	rot.z_1 = point.z;
	rotate_x_axis(rot, output, vars);
}
